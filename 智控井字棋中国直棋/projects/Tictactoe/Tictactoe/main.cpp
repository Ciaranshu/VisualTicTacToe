#include "tictactoe.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Tictactoe w;
	w.show();
	return a.exec();
}
