#include "mainwindow.h"

#include <QApplication>
#include <qfont.h>

int main(int argc, char *argv[]) {
	// Change 1
	// Change 2
	QApplication a(argc, argv);
	MainWindow w;
	w.show();
	return a.exec();
}
