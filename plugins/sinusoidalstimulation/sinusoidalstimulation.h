#ifndef SINUSOIDALSTIMULATION_H
#define SINUSOIDALSTIMULATION_H

#include <QWidget>

namespace Ui {
class SinusoidalStimulation;
}

class SinusoidalStimulation : public QWidget {
	Q_OBJECT

  public:
	explicit SinusoidalStimulation(QWidget *parent = nullptr);
	~SinusoidalStimulation();

  private:
	Ui::SinusoidalStimulation *ui;
};

#endif // SINUSOIDALSTIMULATION_H
