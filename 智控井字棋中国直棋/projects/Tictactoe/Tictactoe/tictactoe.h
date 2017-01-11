#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <QtWidgets/QMainWindow>
#include<QtWidgets/QPushButton>
#include<qtimer.h>
#include<qpushbutton.h>
#include<qmessagebox.h>
#include "ui_tictactoe.h"

class Tictactoe : public QMainWindow
{
	Q_OBJECT

public:
	Tictactoe(QWidget *parent = 0);
	~Tictactoe();
	QString TimeMSConvert(int i);

private slots:

void on_pushButton_Return_clicked();
void on_pushButton_HvsH_clicked();
void on_pushButton_HvsM_clicked();
void on_pushButton__SwapHvsH_clicked();
void on_pushButton_SwapHvsH_clicked();
void timerHvsH_slot();
void timerHvsM_slot();
void timerCountHvsH_slot();
void timerCountHvsM_slot();

private:
	Ui::TictactoeClass ui;
	QTimer *timerHvsH;
	QTimer *timerHvsM;
	QTimer *timerCountHvsH;
	QTimer *timerCountHvsM;
	QPushButton *piece1;
	QPushButton *piece2;
	QMessageBox* messageDisplay;
};

#endif // TICTACTOE_H
