#include "sinusoidalstimulation.h"
#include "ui_sinusoidalstimulation.h"

SinusoidalStimulation::SinusoidalStimulation(QWidget *parent)
	: QWidget(parent), ui(new Ui::SinusoidalStimulation) {
	ui->setupUi(this);
}

SinusoidalStimulation::~SinusoidalStimulation() { delete ui; }
