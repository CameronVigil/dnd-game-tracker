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
#include <QtWidgets/QSpinBox>
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
    QRadioButton *Contest_Duel;
    QGroupBox *groupBox_4;
    QRadioButton *SkillCheck_STR;
    QRadioButton *SkillCheck_DEX;
    QRadioButton *SkillCheck_INT;
    QRadioButton *SkillCheck_WIS;
    QRadioButton *SkillCheck_CHA;
    QLabel *label;
    QPushButton *initRoll;
    QGroupBox *groupBox_5;
    QListWidget *listWidget;
    QLabel *label_2;
    QListWidget *listWidget2;
    QPushButton *SkillCheck_Clear;
    QPushButton *addPlayer;
    QPushButton *delPlayer;
    QGroupBox *groupBox_6;
    QSpinBox *SkillCheck_ProfBonus;
    QListWidget *playerList;
    QLineEdit *playerURL;
    QLabel *label_3;
    QListWidget *compList;
    QSpinBox *SkillCheck_cProfBonus;
    QGroupBox *groupBox_7;
    QRadioButton *cAdvantage_positive;
    QRadioButton *cAdvantage_neutral;
    QRadioButton *cAdvantage_negative;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(411, 527);
        AbilityCheck_Result = new QPushButton(Widget);
        AbilityCheck_Result->setObjectName("AbilityCheck_Result");
        AbilityCheck_Result->setGeometry(QRect(310, 280, 80, 18));
        QFont font;
        font.setPointSize(7);
        AbilityCheck_Result->setFont(font);
        groupBox = new QGroupBox(Widget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(20, 200, 131, 161));
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
        groupBox_2->setGeometry(QRect(160, 280, 61, 80));
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
        groupBox_3->setGeometry(QRect(20, 370, 71, 61));
        Contest_Single = new QRadioButton(groupBox_3);
        Contest_Single->setObjectName("Contest_Single");
        Contest_Single->setGeometry(QRect(0, 20, 69, 18));
        Contest_Duel = new QRadioButton(groupBox_3);
        Contest_Duel->setObjectName("Contest_Duel");
        Contest_Duel->setGeometry(QRect(0, 40, 69, 18));
        groupBox_4 = new QGroupBox(Widget);
        groupBox_4->setObjectName("groupBox_4");
        groupBox_4->setGeometry(QRect(160, 200, 141, 80));
        SkillCheck_STR = new QRadioButton(groupBox_4);
        SkillCheck_STR->setObjectName("SkillCheck_STR");
        SkillCheck_STR->setGeometry(QRect(0, 20, 69, 18));
        SkillCheck_DEX = new QRadioButton(groupBox_4);
        SkillCheck_DEX->setObjectName("SkillCheck_DEX");
        SkillCheck_DEX->setGeometry(QRect(0, 40, 69, 18));
        SkillCheck_INT = new QRadioButton(groupBox_4);
        SkillCheck_INT->setObjectName("SkillCheck_INT");
        SkillCheck_INT->setGeometry(QRect(0, 60, 69, 18));
        SkillCheck_WIS = new QRadioButton(groupBox_4);
        SkillCheck_WIS->setObjectName("SkillCheck_WIS");
        SkillCheck_WIS->setGeometry(QRect(70, 20, 69, 18));
        SkillCheck_CHA = new QRadioButton(groupBox_4);
        SkillCheck_CHA->setObjectName("SkillCheck_CHA");
        SkillCheck_CHA->setGeometry(QRect(70, 40, 69, 18));
        label = new QLabel(Widget);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 170, 131, 21));
        initRoll = new QPushButton(Widget);
        initRoll->setObjectName("initRoll");
        initRoll->setGeometry(QRect(220, 50, 71, 20));
        groupBox_5 = new QGroupBox(Widget);
        groupBox_5->setObjectName("groupBox_5");
        groupBox_5->setGeometry(QRect(220, 70, 71, 41));
        groupBox_5->setFont(font);
        listWidget = new QListWidget(Widget);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(300, 50, 81, 101));
        listWidget->setStyleSheet(QString::fromUtf8("font: 7pt \"Segoe UI\";"));
        label_2 = new QLabel(Widget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(160, 30, 37, 12));
        label_2->setFont(font);
        listWidget2 = new QListWidget(Widget);
        listWidget2->setObjectName("listWidget2");
        listWidget2->setGeometry(QRect(140, 170, 161, 31));
        SkillCheck_Clear = new QPushButton(Widget);
        SkillCheck_Clear->setObjectName("SkillCheck_Clear");
        SkillCheck_Clear->setGeometry(QRect(310, 300, 80, 18));
        SkillCheck_Clear->setFont(font);
        addPlayer = new QPushButton(Widget);
        addPlayer->setObjectName("addPlayer");
        addPlayer->setGeometry(QRect(20, 50, 80, 18));
        addPlayer->setFont(font);
        delPlayer = new QPushButton(Widget);
        delPlayer->setObjectName("delPlayer");
        delPlayer->setGeometry(QRect(20, 90, 80, 18));
        delPlayer->setFont(font);
        groupBox_6 = new QGroupBox(Widget);
        groupBox_6->setObjectName("groupBox_6");
        groupBox_6->setGeometry(QRect(310, 200, 81, 81));
        SkillCheck_ProfBonus = new QSpinBox(groupBox_6);
        SkillCheck_ProfBonus->setObjectName("SkillCheck_ProfBonus");
        SkillCheck_ProfBonus->setGeometry(QRect(10, 20, 61, 51));
        QFont font1;
        font1.setPointSize(12);
        SkillCheck_ProfBonus->setFont(font1);
        playerList = new QListWidget(Widget);
        playerList->setObjectName("playerList");
        playerList->setGeometry(QRect(130, 50, 81, 101));
        playerList->setFont(font);
        playerURL = new QLineEdit(Widget);
        playerURL->setObjectName("playerURL");
        playerURL->setGeometry(QRect(22, 70, 91, 20));
        label_3 = new QLabel(Widget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(320, 30, 51, 16));
        label_3->setFont(font);
        compList = new QListWidget(Widget);
        compList->setObjectName("compList");
        compList->setGeometry(QRect(100, 390, 101, 21));
        compList->setFont(font);
        SkillCheck_cProfBonus = new QSpinBox(Widget);
        SkillCheck_cProfBonus->setObjectName("SkillCheck_cProfBonus");
        SkillCheck_cProfBonus->setGeometry(QRect(170, 420, 61, 51));
        SkillCheck_cProfBonus->setFont(font1);
        groupBox_7 = new QGroupBox(Widget);
        groupBox_7->setObjectName("groupBox_7");
        groupBox_7->setGeometry(QRect(100, 410, 61, 80));
        cAdvantage_positive = new QRadioButton(groupBox_7);
        cAdvantage_positive->setObjectName("cAdvantage_positive");
        cAdvantage_positive->setGeometry(QRect(0, 20, 69, 18));
        cAdvantage_neutral = new QRadioButton(groupBox_7);
        cAdvantage_neutral->setObjectName("cAdvantage_neutral");
        cAdvantage_neutral->setGeometry(QRect(0, 40, 69, 18));
        cAdvantage_negative = new QRadioButton(groupBox_7);
        cAdvantage_negative->setObjectName("cAdvantage_negative");
        cAdvantage_negative->setGeometry(QRect(0, 60, 69, 18));

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
        Contest_Duel->setText(QCoreApplication::translate("Widget", "Duel", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("Widget", "Skill Being Checked", nullptr));
        SkillCheck_STR->setText(QCoreApplication::translate("Widget", "STR", nullptr));
        SkillCheck_DEX->setText(QCoreApplication::translate("Widget", "DEX", nullptr));
        SkillCheck_INT->setText(QCoreApplication::translate("Widget", "INT", nullptr));
        SkillCheck_WIS->setText(QCoreApplication::translate("Widget", "WIS", nullptr));
        SkillCheck_CHA->setText(QCoreApplication::translate("Widget", "CHA", nullptr));
        label->setText(QCoreApplication::translate("Widget", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:700;\">Skill Check for</span></p></body></html>", nullptr));
        initRoll->setText(QCoreApplication::translate("Widget", "Roll", nullptr));
        groupBox_5->setTitle(QCoreApplication::translate("Widget", "Lock/Unlock", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "Players", nullptr));
        SkillCheck_Clear->setText(QCoreApplication::translate("Widget", "Clear", nullptr));
        addPlayer->setText(QCoreApplication::translate("Widget", "Add Player/NPC", nullptr));
        delPlayer->setText(QCoreApplication::translate("Widget", "Del Player/NPC", nullptr));
        groupBox_6->setTitle(QCoreApplication::translate("Widget", "Proficiency", nullptr));
        label_3->setText(QCoreApplication::translate("Widget", "Turn Order", nullptr));
        groupBox_7->setTitle(QCoreApplication::translate("Widget", "Adv", nullptr));
        cAdvantage_positive->setText(QCoreApplication::translate("Widget", "+", nullptr));
        cAdvantage_neutral->setText(QCoreApplication::translate("Widget", "0", nullptr));
        cAdvantage_negative->setText(QCoreApplication::translate("Widget", "(-)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
