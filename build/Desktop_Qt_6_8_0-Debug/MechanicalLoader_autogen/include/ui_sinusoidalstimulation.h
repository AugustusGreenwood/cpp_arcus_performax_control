/********************************************************************************
** Form generated from reading UI file 'sinusoidalstimulation.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SINUSOIDALSTIMULATION_H
#define UI_SINUSOIDALSTIMULATION_H

#include <QtCharts/QChartView>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SinusoidalStimulation
{
public:
    QGridLayout *gridLayout;
    QChartView *graphicsView;

    void setupUi(QWidget *SinusoidalStimulation)
    {
        if (SinusoidalStimulation->objectName().isEmpty())
            SinusoidalStimulation->setObjectName("SinusoidalStimulation");
        SinusoidalStimulation->resize(400, 300);
        gridLayout = new QGridLayout(SinusoidalStimulation);
        gridLayout->setObjectName("gridLayout");
        graphicsView = new QChartView(SinusoidalStimulation);
        graphicsView->setObjectName("graphicsView");

        gridLayout->addWidget(graphicsView, 0, 0, 1, 1);


        retranslateUi(SinusoidalStimulation);

        QMetaObject::connectSlotsByName(SinusoidalStimulation);
    } // setupUi

    void retranslateUi(QWidget *SinusoidalStimulation)
    {
        SinusoidalStimulation->setWindowTitle(QCoreApplication::translate("SinusoidalStimulation", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SinusoidalStimulation: public Ui_SinusoidalStimulation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SINUSOIDALSTIMULATION_H
