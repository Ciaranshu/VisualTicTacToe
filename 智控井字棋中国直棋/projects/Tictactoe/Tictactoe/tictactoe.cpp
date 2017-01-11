#include "tictactoe.h"
#include"ui_tictactoe.h"
#include<qtimer.h>
#include <iostream>
#include<qpushbutton.h>
#include<stdlib.h>
#include<QtGui>
#include<qstring.h>
#include<qmessagebox.h>

#include "opencv2/highgui/highgui.hpp"  
#include "opencv2/imgproc/imgproc.hpp"  

#include"AI.h"
#include"CV4.h"
#include"check.h"

static long timeRecord = 0;
static int blueCount = 0;
static int redCount = 0;

Tictactoe::Tictactoe(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	piece1 = new QPushButton[9];
	piece2 = new QPushButton[9];

	for (int i = 0;i<9;i++) {
		piece1[i].setFlat(true);
		piece1[i].setParent(ui.groupBox_BroadHvsH);

		if (i == 0) {
			piece1[i].setGeometry(30, 20,110,110 );
			continue;
		}
		int x = i / 3;
		switch (x) {
		case 0:
			piece1[i].setGeometry(piece1[i - 1].x() + 155,20 , 110, 110);
			break;
		case 1:
			piece1[i].setGeometry(piece1[i - 3].x(), 20+130, 110, 110);
			break;
		case 2:
			piece1[i].setGeometry(piece1[i - 3].x(), 20+260, 110,110);
			break;
		}

	}

	for (int i = 0;i<9;i++) {
		piece2[i].setFlat(true);
		piece2[i].setParent(ui.groupBox_BroadHvsM);

		if (i == 0) {
			piece2[i].setGeometry(30, 20, 110, 110);
			continue;
		}
		int x = i / 3;
		switch (x) {
		case 0:
			piece2[i].setGeometry(piece2[i - 1].x() + 155, 20, 110, 110);
			break;
		case 1:
			piece2[i].setGeometry(piece2[i - 3].x(), 20 + 130, 110, 110);
			break;
		case 2:
			piece2[i].setGeometry(piece2[i - 3].x(), 20 + 260, 110, 110);
			break;
		}

	}

	timerHvsH = new QTimer(this);//Human Vs Human timer
	timerHvsM = new QTimer(this);//Human Vs Machine timer
	timerCountHvsH = new QTimer(this); 
	timerCountHvsM = new QTimer(this);
	messageDisplay = new QMessageBox;


	connect(ui.pushButton_Return, SIGNAL(clicked()), this, SLOT(on_pushButton_Return_clicked()));
	connect(ui.pushButton_OptionHvsH, SIGNAL(clicked()), this, SLOT(on_pushButton_HvsH_clicked()));
	connect(ui.pushButton_OptionHvsM, SIGNAL(clicked()), this, SLOT(on_pushButton_HvsM_clicked()));
	connect(ui.pushButton_swapHvsH, SIGNAL(clicked()), this, SLOT(on_pushButton_SwapHvsH_clicked()));
	connect(ui.pushButton_swapHvsM, SIGNAL(clicked()), this, SLOT(on_pushButton_SwapHvsM_clicked()));

	
}

Tictactoe::~Tictactoe()
{

}


void Tictactoe::on_pushButton_Return_clicked() {
	timeRecord = 0;
	blueCount = 0;
	redCount = 0;
	ui.stackedWidget->setCurrentIndex(0);
	timerHvsH->stop();
	timerHvsM->stop();
}

void Tictactoe::on_pushButton_HvsH_clicked() {
	timeRecord = 0;
	blueCount = 0;
	redCount = 0;
	ui.stackedWidget->setCurrentIndex(1);
	timerHvsH->start(30);
	timerCountHvsH->start(1000);
	connect(timerHvsH, SIGNAL(timeout()), this, SLOT(timerHvsH_slot()));
	connect(timerCountHvsH, SIGNAL(timeout()), this, SLOT(timerCountHvsH_slot()));

}

void Tictactoe::on_pushButton_HvsM_clicked() {
	timeRecord = 0;
	blueCount = 0;
	redCount = 0;
	ui.stackedWidget->setCurrentIndex(2);
	timerHvsM->start(30);
	timerCountHvsM->start(1000);
	connect(timerHvsM, SIGNAL(timeout()), this, SLOT(timerHvsM_slot()));
	connect(timerCountHvsM, SIGNAL(timeout()), this, SLOT(timerCountHvsH_slot()));

}

void Tictactoe::on_pushButton__SwapHvsH_clicked() {
	timeRecord = 0;

}

void Tictactoe::on_pushButton_SwapHvsH_clicked() {
	timeRecord = 0;
}

void Tictactoe::timerHvsH_slot() {

	VideoCapture cap(0); //capture the video from web cam  

	if (!cap.isOpened())  // if not success, exit program  
	{
		cout << "Cannot open the web cam" << endl;
		exit(-1);
	}

	Mat imgOriginal;

	bool bSuccess = cap.read(imgOriginal); // read a new frame from video  

	if (!bSuccess) //if not success, break loop  
	{
		cout << "Cannot read a frame from video stream" << endl;
		exit(0);
	}

	imshow("Original", imgOriginal); //show the original image

	int* pieceMatrix = GetCV();

	for (int i = 0;i < 9;++i) {
		if (pieceMatrix[i] == 1) {
			piece1[i].setStyleSheet("QPushButton{border-image: url(:/Tictactoe/Resources/circle.png);}");
		}
		else if (pieceMatrix[i] == -1) {
			piece1[i].setStyleSheet("QPushButton{border-image: url(:/Tictactoe/Resources/cross.png);}");
		}
		else {
			piece1[i].setStyleSheet("");
		}
	}

	int flag = check(pieceMatrix);
	/*
	-1：蓝赢了
	0:继续
	1:红赢了
	2:平局
	*/
	switch (flag)
	{
	case -1:
		messageDisplay->setDetailedText(QString::fromStdString("蓝赢了"));
		++blueCount;
		messageDisplay->show();
		ui.lcdNumber_counterHvsH->display(QString("%1:%2").arg(blueCount, 2).arg(redCount, 2));
		break;
	case 0:
		break;
	case 1:
		messageDisplay->setDetailedText(QString::fromStdString("红赢了"));
		++redCount;
		messageDisplay->show();
		ui.lcdNumber_counterHvsH->display(QString("%1:%2").arg(blueCount, 2).arg(redCount, 2));
		break;
	case 2:
		messageDisplay->setDetailedText(QString::fromStdString("平局"));
		messageDisplay->show();
		break;
	default:
		break;
	}
	
	delete pieceMatrix;

}

void Tictactoe::timerHvsM_slot() {

	VideoCapture cap(0); //capture the video from web cam  

	if (!cap.isOpened())  // if not success, exit program  
	{
		cout << "Cannot open the web cam" << endl;
		exit(-1);
	}

	Mat imgOriginal;

	bool bSuccess = cap.read(imgOriginal); // read a new frame from video  

	if (!bSuccess) //if not success, break loop  
	{
		cout << "Cannot read a frame from video stream" << endl;
		exit(0);
	}

	imshow("Original", imgOriginal); //show the original image

	int* pieceMatrix = machineMatrix(GetCV());

	for (int i = 0;i < 9;++i) {
		if (pieceMatrix[i] == 1) {
			piece2[i].setStyleSheet("QPushButton{border-image: url(:/Tictactoe/Resources/circle.png);}");
		}
		else if (pieceMatrix[i] == -1) {
			piece2[i].setStyleSheet("QPushButton{border-image: url(:/Tictactoe/Resources/cross.png);}");
		}
		else {
			piece2[i].setStyleSheet("");
		}
	}

	int flag = check(pieceMatrix);
	/*
	-1：蓝赢了
	0:继续
	1:红赢了
	2:平局
	*/
	switch (flag)
	{
	case -1:
		messageDisplay->setDetailedText(QString::fromStdString("蓝赢了"));
		++blueCount;
		messageDisplay->show();
		ui.lcdNumber_counterHvsH->display(QString("%1:%2").arg(blueCount, 2).arg(redCount, 2));
		break;
	case 0:
		break;
	case 1:
		messageDisplay->setDetailedText(QString::fromStdString("红赢了"));
		++redCount;
		messageDisplay->show();
		ui.lcdNumber_counterHvsH->display(QString("%1:%2").arg(blueCount, 2).arg(redCount, 2));
		break;
	case 2:
		messageDisplay->setDetailedText(QString::fromStdString("平局"));
		messageDisplay->show();
		break;
	default:
		break;
	}

	delete pieceMatrix;


}

void Tictactoe::timerCountHvsH_slot(){

	timeRecord += 1000;
	ui.lcdNumber_TimerHvsH->display(TimeMSConvert(timeRecord));
}

void Tictactoe::timerCountHvsM_slot(){
	timeRecord += 1000;
	ui.lcdNumber_TimerHvsM->display(TimeMSConvert(timeRecord));
}


QString Tictactoe::TimeMSConvert(int i)
{

	int nMinute = i / 60000 % 60;

	int nSec = i / 1000 % 60;

	QString strTime = QString("%1:%2").arg(nMinute, 2, 10, QChar('0')).arg(nSec, 2, 10, QChar('0'));

	return strTime;
}
