#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "device.h"

#include <QMainWindow>
#include <QTimer>
#include <lua.hpp>

// TODO: remove these
// These should almost certainly not just be hardcoded here
const int VENDOR_ID = 0x1589;
const int PRODUCT_ID = 0xa101;

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

// TODO: Maybe make this cleaner?
// Now, I don't know if this is me not loving C++ style, but I just don't like these
// functions and this style. Especially the source file feels clunky and cluttered. Maybe
// need to seek out some examples for inspiriation
class MainWindow : public QMainWindow {
	Q_OBJECT

  public:
	MainWindow(QWidget *parent = nullptr);
	~MainWindow();

  private:
	Ui::MainWindow *ui;

	void makeConnections();
	void setValidators();
	void initDeviceInfo();

	void updateInputParameters();
	void updatePulseEncoderPosition();
	void motorToggle();
	void movementModeToggle();
	void jogUp();
	void jogDown();
	void move();
	void loadProgram();
	void runProgram();
	void setButtonsEnabled(bool enabled);
	void abort();

	Device device = Device(PRODUCT_ID, VENDOR_ID);
	QTimer *update_timer = new QTimer(this);
};
#endif // MAINWINDOW_H
