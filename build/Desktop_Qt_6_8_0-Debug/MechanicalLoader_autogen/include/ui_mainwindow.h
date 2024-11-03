/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QLineEdit *position_output;
    QLabel *position_label;
    QFrame *control_line_asth;
    QLineEdit *encoder_output;
    QPlainTextEdit *program_edit;
    QGridLayout *button_grid_layout;
    QPushButton *move_button;
    QPushButton *jog_up_button;
    QPushButton *jog_down_button;
    QPushButton *zero_position_button;
    QPushButton *stop_button;
    QLineEdit *program_input;
    QPushButton *abort_program_button;
    QLabel *encoder_label;
    QLabel *program_label;
    QLabel *speed_label;
    QPushButton *load_program_button;
    QPushButton *file_browser_button;
    QLineEdit *speed_output;
    QRadioButton *enable_motor_button;
    QLabel *control_label;
    QPushButton *run_program_button;
    QGridLayout *input_grid_layout;
    QLabel *acceleration_input_label;
    QLineEdit *acceleration_input;
    QLineEdit *high_speed_input;
    QLineEdit *target_input;
    QLabel *target_input_label;
    QLabel *high_speed_input_label;
    QSpacerItem *verticalSpacer;
    QRadioButton *absolute_movement_button;
    QRadioButton *incremental_movement_button;
    QSpacerItem *horizontalSpacer;
    QMenuBar *menubar;
    QStatusBar *statusbar;
    QButtonGroup *movement_type_button_group;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(700, 1002);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        position_output = new QLineEdit(centralwidget);
        position_output->setObjectName("position_output");
        QFont font;
        font.setPointSize(14);
        position_output->setFont(font);
        position_output->setReadOnly(true);

        gridLayout->addWidget(position_output, 0, 1, 1, 5);

        position_label = new QLabel(centralwidget);
        position_label->setObjectName("position_label");
        position_label->setFont(font);
        position_label->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout->addWidget(position_label, 0, 0, 1, 1);

        control_line_asth = new QFrame(centralwidget);
        control_line_asth->setObjectName("control_line_asth");
        control_line_asth->setFont(font);
        control_line_asth->setLineWidth(2);
        control_line_asth->setFrameShape(QFrame::Shape::HLine);
        control_line_asth->setFrameShadow(QFrame::Shadow::Sunken);

        gridLayout->addWidget(control_line_asth, 4, 1, 1, 5);

        encoder_output = new QLineEdit(centralwidget);
        encoder_output->setObjectName("encoder_output");
        encoder_output->setFont(font);
        encoder_output->setReadOnly(true);

        gridLayout->addWidget(encoder_output, 1, 1, 1, 5);

        program_edit = new QPlainTextEdit(centralwidget);
        program_edit->setObjectName("program_edit");
        program_edit->setFont(font);

        gridLayout->addWidget(program_edit, 11, 0, 1, 6);

        button_grid_layout = new QGridLayout();
        button_grid_layout->setObjectName("button_grid_layout");
        move_button = new QPushButton(centralwidget);
        move_button->setObjectName("move_button");
        move_button->setFont(font);

        button_grid_layout->addWidget(move_button, 0, 1, 1, 1);

        jog_up_button = new QPushButton(centralwidget);
        jog_up_button->setObjectName("jog_up_button");
        jog_up_button->setFont(font);

        button_grid_layout->addWidget(jog_up_button, 0, 0, 1, 1);

        jog_down_button = new QPushButton(centralwidget);
        jog_down_button->setObjectName("jog_down_button");
        jog_down_button->setFont(font);

        button_grid_layout->addWidget(jog_down_button, 1, 0, 1, 1);

        zero_position_button = new QPushButton(centralwidget);
        zero_position_button->setObjectName("zero_position_button");
        zero_position_button->setFont(font);

        button_grid_layout->addWidget(zero_position_button, 1, 1, 1, 1);

        stop_button = new QPushButton(centralwidget);
        stop_button->setObjectName("stop_button");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(stop_button->sizePolicy().hasHeightForWidth());
        stop_button->setSizePolicy(sizePolicy);
        stop_button->setFont(font);

        button_grid_layout->addWidget(stop_button, 0, 2, 2, 1);


        gridLayout->addLayout(button_grid_layout, 9, 0, 1, 6);

        program_input = new QLineEdit(centralwidget);
        program_input->setObjectName("program_input");
        program_input->setFont(font);

        gridLayout->addWidget(program_input, 10, 1, 1, 3);

        abort_program_button = new QPushButton(centralwidget);
        abort_program_button->setObjectName("abort_program_button");
        abort_program_button->setFont(font);

        gridLayout->addWidget(abort_program_button, 12, 5, 1, 1);

        encoder_label = new QLabel(centralwidget);
        encoder_label->setObjectName("encoder_label");
        encoder_label->setFont(font);
        encoder_label->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout->addWidget(encoder_label, 1, 0, 1, 1);

        program_label = new QLabel(centralwidget);
        program_label->setObjectName("program_label");
        program_label->setFont(font);
        program_label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(program_label, 10, 0, 1, 1);

        speed_label = new QLabel(centralwidget);
        speed_label->setObjectName("speed_label");
        speed_label->setFont(font);
        speed_label->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout->addWidget(speed_label, 2, 0, 1, 1);

        load_program_button = new QPushButton(centralwidget);
        load_program_button->setObjectName("load_program_button");
        load_program_button->setFont(font);

        gridLayout->addWidget(load_program_button, 10, 5, 1, 1);

        file_browser_button = new QPushButton(centralwidget);
        file_browser_button->setObjectName("file_browser_button");
        file_browser_button->setFont(font);

        gridLayout->addWidget(file_browser_button, 10, 4, 1, 1);

        speed_output = new QLineEdit(centralwidget);
        speed_output->setObjectName("speed_output");
        speed_output->setFont(font);
        speed_output->setReadOnly(true);

        gridLayout->addWidget(speed_output, 2, 1, 1, 5);

        enable_motor_button = new QRadioButton(centralwidget);
        enable_motor_button->setObjectName("enable_motor_button");
        enable_motor_button->setFont(font);

        gridLayout->addWidget(enable_motor_button, 5, 0, 1, 1);

        control_label = new QLabel(centralwidget);
        control_label->setObjectName("control_label");
        control_label->setFont(font);
        control_label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(control_label, 4, 0, 1, 1);

        run_program_button = new QPushButton(centralwidget);
        run_program_button->setObjectName("run_program_button");
        run_program_button->setFont(font);

        gridLayout->addWidget(run_program_button, 12, 0, 1, 5);

        input_grid_layout = new QGridLayout();
        input_grid_layout->setObjectName("input_grid_layout");
        acceleration_input_label = new QLabel(centralwidget);
        acceleration_input_label->setObjectName("acceleration_input_label");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(acceleration_input_label->sizePolicy().hasHeightForWidth());
        acceleration_input_label->setSizePolicy(sizePolicy1);
        acceleration_input_label->setFont(font);

        input_grid_layout->addWidget(acceleration_input_label, 0, 2, 1, 1);

        acceleration_input = new QLineEdit(centralwidget);
        acceleration_input->setObjectName("acceleration_input");
        sizePolicy1.setHeightForWidth(acceleration_input->sizePolicy().hasHeightForWidth());
        acceleration_input->setSizePolicy(sizePolicy1);
        acceleration_input->setFont(font);

        input_grid_layout->addWidget(acceleration_input, 1, 2, 1, 1);

        high_speed_input = new QLineEdit(centralwidget);
        high_speed_input->setObjectName("high_speed_input");
        sizePolicy1.setHeightForWidth(high_speed_input->sizePolicy().hasHeightForWidth());
        high_speed_input->setSizePolicy(sizePolicy1);
        high_speed_input->setFont(font);

        input_grid_layout->addWidget(high_speed_input, 1, 1, 1, 1);

        target_input = new QLineEdit(centralwidget);
        target_input->setObjectName("target_input");
        sizePolicy1.setHeightForWidth(target_input->sizePolicy().hasHeightForWidth());
        target_input->setSizePolicy(sizePolicy1);
        target_input->setFont(font);

        input_grid_layout->addWidget(target_input, 1, 0, 1, 1);

        target_input_label = new QLabel(centralwidget);
        target_input_label->setObjectName("target_input_label");
        sizePolicy1.setHeightForWidth(target_input_label->sizePolicy().hasHeightForWidth());
        target_input_label->setSizePolicy(sizePolicy1);
        target_input_label->setFont(font);

        input_grid_layout->addWidget(target_input_label, 0, 0, 1, 1);

        high_speed_input_label = new QLabel(centralwidget);
        high_speed_input_label->setObjectName("high_speed_input_label");
        sizePolicy1.setHeightForWidth(high_speed_input_label->sizePolicy().hasHeightForWidth());
        high_speed_input_label->setSizePolicy(sizePolicy1);
        high_speed_input_label->setFont(font);

        input_grid_layout->addWidget(high_speed_input_label, 0, 1, 1, 1);


        gridLayout->addLayout(input_grid_layout, 8, 0, 1, 6);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        gridLayout->addItem(verticalSpacer, 3, 0, 1, 6);

        absolute_movement_button = new QRadioButton(centralwidget);
        movement_type_button_group = new QButtonGroup(MainWindow);
        movement_type_button_group->setObjectName("movement_type_button_group");
        movement_type_button_group->addButton(absolute_movement_button);
        absolute_movement_button->setObjectName("absolute_movement_button");
        absolute_movement_button->setFont(font);

        gridLayout->addWidget(absolute_movement_button, 5, 5, 1, 1);

        incremental_movement_button = new QRadioButton(centralwidget);
        movement_type_button_group->addButton(incremental_movement_button);
        incremental_movement_button->setObjectName("incremental_movement_button");
        incremental_movement_button->setFont(font);

        gridLayout->addWidget(incremental_movement_button, 6, 5, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer, 5, 1, 1, 4);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 700, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        position_label->setText(QCoreApplication::translate("MainWindow", "Pulse Position", nullptr));
        move_button->setText(QCoreApplication::translate("MainWindow", "Move", nullptr));
        jog_up_button->setText(QCoreApplication::translate("MainWindow", "Jog+", nullptr));
        jog_down_button->setText(QCoreApplication::translate("MainWindow", "Jog-", nullptr));
        zero_position_button->setText(QCoreApplication::translate("MainWindow", "Zero Position", nullptr));
        stop_button->setText(QCoreApplication::translate("MainWindow", "Stop", nullptr));
        abort_program_button->setText(QCoreApplication::translate("MainWindow", "Abort", nullptr));
        encoder_label->setText(QCoreApplication::translate("MainWindow", "Encoder Position", nullptr));
        program_label->setText(QCoreApplication::translate("MainWindow", "Program:", nullptr));
        speed_label->setText(QCoreApplication::translate("MainWindow", "High Speed", nullptr));
        load_program_button->setText(QCoreApplication::translate("MainWindow", "Load", nullptr));
        file_browser_button->setText(QCoreApplication::translate("MainWindow", "Browser", nullptr));
        enable_motor_button->setText(QCoreApplication::translate("MainWindow", "Enable Motor", nullptr));
        control_label->setText(QCoreApplication::translate("MainWindow", "Control", nullptr));
        run_program_button->setText(QCoreApplication::translate("MainWindow", "Run", nullptr));
        acceleration_input_label->setText(QCoreApplication::translate("MainWindow", "Acceleration\n"
"(ms)", nullptr));
        target_input_label->setText(QCoreApplication::translate("MainWindow", "Target\n"
"(pulses)", nullptr));
        high_speed_input_label->setText(QCoreApplication::translate("MainWindow", "High Speed\n"
"(pulses/s)", nullptr));
        absolute_movement_button->setText(QCoreApplication::translate("MainWindow", "Absolute", nullptr));
        incremental_movement_button->setText(QCoreApplication::translate("MainWindow", "Incremental", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
