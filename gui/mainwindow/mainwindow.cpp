#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QFileDialog>
#include <QIntValidator>

#include "luaapi.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
	ui->setupUi(this);

	setValidators();
	makeConnections();
	update_timer->start(100);

	initDeviceInfo();
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::updateInputParameters() {
	QString str_pos = ui->target_input->text();
	QString str_speed = ui->high_speed_input->text();
	QString str_accel = ui->acceleration_input->text();

	if (str_pos.isEmpty()) {
		return;
	}
	if (!str_speed.isEmpty()) {
		device.setHighSpeed(str_speed.toInt());
		ui->speed_output->setText(str_speed);
	}
	if (!str_accel.isEmpty()) {
		device.setAccelerationTime(str_accel.toInt());
	}
}

void MainWindow::motorToggle() {
	if (ui->enable_motor_button->isChecked()) {
		device.turnMotorOn();
	} else {
		device.turnMotorOff();
	}
}

void MainWindow::movementModeToggle() {
	if (ui->absolute_movement_button->isChecked()) {
		device.setAbsoluteMovement();
	} else {
		device.setIncrementalMovement();
	}
}

void MainWindow::jogUp() {
	device.stop();
	updateInputParameters();
	device.waitForMotorIdle();

	device.moveUp();
}

void MainWindow::jogDown() {
	device.stop();
	updateInputParameters();
	device.waitForMotorIdle();

	device.moveDown();
}

void MainWindow::move() {
	device.stop();
	updateInputParameters();
	device.waitForMotorIdle();

	device.moveTo(ui->target_input->text().toInt());
}

void MainWindow::loadProgram() {
	QString file_name = ui->program_input->text();
	if (file_name.isEmpty()) {
		file_name = QFileDialog::getOpenFileName(this, "", ".", "");
		ui->program_input->setText(file_name);
	}

	QFile file(file_name);
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
		return;
	}

	QString contents = file.readAll();
	ui->program_edit->setPlainText(contents);
}

void MainWindow::runProgram() {
	QString program = ui->program_edit->toPlainText();
	setButtonsEnabled(false);
	luaapi_runProgram(program.toStdString(), &device);
	setButtonsEnabled(true);
}

void MainWindow::abort() {
	device.turnMotorOff();
	ui->enable_motor_button->setEnabled(false);
}

void MainWindow::setButtonsEnabled(bool enabled) {
	ui->absolute_movement_button->setEnabled(enabled);
	ui->jog_down_button->setEnabled(enabled);
	ui->jog_up_button->setEnabled(enabled);
	ui->move_button->setEnabled(enabled);
	ui->stop_button->setEnabled(enabled);
	ui->zero_position_button->setEnabled(enabled);
	ui->enable_motor_button->setEnabled(enabled);
	ui->file_browser_button->setEnabled(enabled);
	ui->incremental_movement_button->setEnabled(enabled);
	ui->load_program_button->setEnabled(enabled);
	ui->run_program_button->setEnabled(enabled);
}

void MainWindow::makeConnections() {
	connect(update_timer, &QTimer::timeout, this, [&]() {
		ui->position_output->setText(device.pulse_position);
		ui->encoder_output->setText(device.encoder_position);
	});

	connect(ui->enable_motor_button, &QRadioButton::toggled, this,
			&MainWindow::motorToggle);

	connect(ui->absolute_movement_button, &QRadioButton::toggled, this,
			&MainWindow::movementModeToggle);

	connect(ui->jog_up_button, &QPushButton::released, this, &MainWindow::jogUp);

	connect(ui->jog_down_button, &QPushButton::released, this, &MainWindow::jogDown);

	connect(ui->stop_button, &QPushButton::released, this, [&]() {
		device.stop();
		updateInputParameters();
	});

	connect(ui->move_button, &QPushButton::released, this, &MainWindow::move);

	connect(ui->zero_position_button, &QPushButton::released, this, [&]() {
		updateInputParameters();
		device.setPulsePosition(0);
		device.setEncoderPosition(0);
	});

	connect(ui->file_browser_button, &QPushButton::released, this, [&]() {
		QString file_name = QFileDialog::getOpenFileName(this, "", ".", "");
		ui->program_input->setText(file_name);
	});

	connect(ui->load_program_button, &QPushButton::released, this,
			&MainWindow::loadProgram);

	connect(ui->run_program_button, &QPushButton::released, this,
			&MainWindow::runProgram);

	connect(ui->abort_program_button, &QPushButton::released, this, &MainWindow::abort);
}

void MainWindow::setValidators() {
	ui->target_input->setValidator(new QIntValidator(this));
	ui->high_speed_input->setValidator(new QIntValidator(this));
	ui->acceleration_input->setValidator(new QIntValidator(this));
}

void MainWindow::initDeviceInfo() {
	device.turnMotorOff();
	ui->enable_motor_button->setChecked(false);

	device.setAbsoluteMovement();
	ui->absolute_movement_button->setChecked(true);

	int high_speed = device.getHighSpeed();
	ui->speed_output->setText(QString::number(high_speed));
	ui->high_speed_input->setText(QString::number(high_speed));

	ui->acceleration_input->setText(QString::number(device.getAccelerationTime()));

	ui->target_input->setText(QString::number(device.getPulsePosition()));
}
