/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QPushButton *AbilityCheck_Result;
    QGroupBox *groupBox;
    QRadioButton *TaskDifficulty_vEasy;
    QRadioButton *TaskDifficulty_Easy;
    QRadioButton *TaskDifficulty_Medium;
    QRadioButton *TaskDifficulty_Hard;
    QRadioButton *TaskDifficulty_vHard;
    QRadioButton *TaskDifficulty_Extreme;
    QGroupBox *groupBox_2;
    QRadioButton *Advantage_positive;
    QRadioButton *Advantage_neutral;
    QRadioButton *Advantage_negative;
    QGroupBox *groupBox_3;
    QRadioButton *Contest_Single;
    QRadioButton *radioButton_2;
    QGroupBox *groupBox_4;
    QLabel *label;
    QPushButton *pushButton;
    QGroupBox *groupBox_5;
    QListWidget *listWidget;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *addPlayerLineEdit;
    QPushButton *addPlayerButton;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(468, 477);
        AbilityCheck_Result = new QPushButton(Widget);
        AbilityCheck_Result->setObjectName("AbilityCheck_Result");
        AbilityCheck_Result->setGeometry(QRect(370, 310, 80, 18));
        groupBox = new QGroupBox(Widget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(10, 300, 131, 161));
        TaskDifficulty_vEasy = new QRadioButton(groupBox);
        TaskDifficulty_vEasy->setObjectName("TaskDifficulty_vEasy");
        TaskDifficulty_vEasy->setGeometry(QRect(0, 20, 69, 18));
        TaskDifficulty_Easy = new QRadioButton(groupBox);
        TaskDifficulty_Easy->setObjectName("TaskDifficulty_Easy");
        TaskDifficulty_Easy->setGeometry(QRect(0, 40, 69, 18));
        TaskDifficulty_Medium = new QRadioButton(groupBox);
        TaskDifficulty_Medium->setObjectName("TaskDifficulty_Medium");
        TaskDifficulty_Medium->setGeometry(QRect(0, 60, 69, 18));
        TaskDifficulty_Hard = new QRadioButton(groupBox);
        TaskDifficulty_Hard->setObjectName("TaskDifficulty_Hard");
        TaskDifficulty_Hard->setGeometry(QRect(0, 80, 69, 18));
        TaskDifficulty_vHard = new QRadioButton(groupBox);
        TaskDifficulty_vHard->setObjectName("TaskDifficulty_vHard");
        TaskDifficulty_vHard->setGeometry(QRect(0, 100, 69, 18));
        TaskDifficulty_Extreme = new QRadioButton(groupBox);
        TaskDifficulty_Extreme->setObjectName("TaskDifficulty_Extreme");
        TaskDifficulty_Extreme->setGeometry(QRect(0, 120, 69, 18));
        groupBox_2 = new QGroupBox(Widget);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(150, 380, 61, 80));
        Advantage_positive = new QRadioButton(groupBox_2);
        Advantage_positive->setObjectName("Advantage_positive");
        Advantage_positive->setGeometry(QRect(0, 20, 69, 18));
        Advantage_neutral = new QRadioButton(groupBox_2);
        Advantage_neutral->setObjectName("Advantage_neutral");
        Advantage_neutral->setGeometry(QRect(0, 40, 69, 18));
        Advantage_negative = new QRadioButton(groupBox_2);
        Advantage_negative->setObjectName("Advantage_negative");
        Advantage_negative->setGeometry(QRect(0, 60, 69, 18));
        groupBox_3 = new QGroupBox(Widget);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setGeometry(QRect(220, 380, 71, 61));
        Contest_Single = new QRadioButton(groupBox_3);
        Contest_Single->setObjectName("Contest_Single");
        Contest_Single->setGeometry(QRect(0, 20, 69, 18));
        radioButton_2 = new QRadioButton(groupBox_3);
        radioButton_2->setObjectName("radioButton_2");
        radioButton_2->setGeometry(QRect(0, 40, 69, 18));
        groupBox_4 = new QGroupBox(Widget);
        groupBox_4->setObjectName("groupBox_4");
        groupBox_4->setGeometry(QRect(150, 300, 141, 80));
        label = new QLabel(Widget);
        label->setObjectName("label");
        label->setGeometry(QRect(50, 260, 241, 21));
        pushButton = new QPushButton(Widget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(20, 50, 71, 20));
        groupBox_5 = new QGroupBox(Widget);
        groupBox_5->setObjectName("groupBox_5");
        groupBox_5->setGeometry(QRect(20, 80, 101, 41));
        listWidget = new QListWidget(Widget);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(130, 60, 81, 101));
        listWidget->setStyleSheet(QString::fromUtf8("font: 7pt \"Segoe UI\";"));
        label_2 = new QLabel(Widget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(150, 40, 37, 12));
        label_3 = new QLabel(Widget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(30, 10, 241, 21));
        addPlayerLineEdit = new QLineEdit(Widget);
        addPlayerLineEdit->setObjectName("addPlayerLineEdit");
        addPlayerLineEdit->setGeometry(QRect(240, 70, 154, 26));
        addPlayerButton = new QPushButton(Widget);
        addPlayerButton->setObjectName("addPlayerButton");
        addPlayerButton->setGeometry(QRect(240, 110, 93, 29));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        AbilityCheck_Result->setText(QCoreApplication::translate("Widget", "Result", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Widget", "Task Difficulty", nullptr));
        TaskDifficulty_vEasy->setText(QCoreApplication::translate("Widget", "Very Easy", nullptr));
        TaskDifficulty_Easy->setText(QCoreApplication::translate("Widget", "Easy", nullptr));
        TaskDifficulty_Medium->setText(QCoreApplication::translate("Widget", "Medium", nullptr));
        TaskDifficulty_Hard->setText(QCoreApplication::translate("Widget", "Hard", nullptr));
        TaskDifficulty_vHard->setText(QCoreApplication::translate("Widget", "Very Hard", nullptr));
        TaskDifficulty_Extreme->setText(QCoreApplication::translate("Widget", "Extreme", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("Widget", "Adv", nullptr));
        Advantage_positive->setText(QCoreApplication::translate("Widget", "+", nullptr));
        Advantage_neutral->setText(QCoreApplication::translate("Widget", "0", nullptr));
        Advantage_negative->setText(QCoreApplication::translate("Widget", "(-)", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("Widget", "Contest", nullptr));
        Contest_Single->setText(QCoreApplication::translate("Widget", "Single", nullptr));
        radioButton_2->setText(QCoreApplication::translate("Widget", "Duel **", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("Widget", "Skill Being Checked", nullptr));
        label->setText(QCoreApplication::translate("Widget", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt; font-weight:700;\">Skill Check</span></p></body></html>", nullptr));
        pushButton->setText(QCoreApplication::translate("Widget", "Roll", nullptr));
        groupBox_5->setTitle(QCoreApplication::translate("Widget", "Lock/Unlock", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "Players", nullptr));
        label_3->setText(QCoreApplication::translate("Widget", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt; font-weight:700;\">Initiative Roll</span></p></body></html>", nullptr));
        addPlayerLineEdit->setPlaceholderText(QCoreApplication::translate("Widget", "Add a player URL", nullptr));
        addPlayerButton->setText(QCoreApplication::translate("Widget", "Add Player", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
