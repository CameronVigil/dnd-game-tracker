#include "widget.h"
#include "skillcheck.h"
#include "./ui_widget.h"
#include <QDebug>
#include <QString>
#include <string>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

//Result of Skill Check
void Widget::on_AbilityCheck_Result_clicked()
{
    //Outputs to console (for now)
    check.playerSkill_t = 0;    // clear 'buffer' between button clicks
    check.playerSkill_t += check.AdvScore;
    //check.playerSkill_t += skillMatch(skill);     //MISSING MISSING MISING
    //check.playerSkill_t += profBonus(skill);      //MISSING MISSING MISING
    //if single == true
    if(check.playerSkill_t - check.TD > 0)
    {
        qDebug() << "Passed";
    }
    else
    {
        qDebug() << "Failed";
    }
    //else if single == false
    //Compare two players or a player and an entity

}

//Task Difficulty - Very Easy
void Widget::on_TaskDifficulty_vEasy_toggled(bool checked)
{
    if(checked == true)
    {
        check.TD += 5;
    }
    else
    {
        check.TD -= 5;
    }
}

//Task Difficulty - Easy
void Widget::on_TaskDifficulty_Easy_toggled(bool checked)
{
    if(checked == true)
    {
        check.TD += 10;
    }
    else
    {
        check.TD -= 10;
    }
}

//Task Difficulty Medium
void Widget::on_TaskDifficulty_Medium_toggled(bool checked)
{
    if(checked == true)
    {
        check.TD += 15;
    }
    else
    {
        check.TD -= 15;
    }
}

//Task Difficulty Hard
void Widget::on_TaskDifficulty_Hard_toggled(bool checked)
{
    if(checked == true)
    {
        check.TD += 20;
    }
    else
    {
        check.TD -= 20;
    }
}

//Task Difficulty Very Hard
void Widget::on_TaskDifficulty_vHard_toggled(bool checked)
{
    if(checked == true)
    {
        check.TD += 25;
    }
    else
    {
        check.TD -= 25;
    }
}

//Task Difficulty Extreme AKA Nearly Impossible
void Widget::on_TaskDifficulty_Extreme_toggled(bool checked)
{
    if(checked == true)
    {
        check.TD += 30;
    }
    else
    {
        check.TD -= 30;
    }
}

//Advantage - Player has advantage
void Widget::on_Advantage_positive_toggled(bool checked)
{
    check.AdvScore = 0; //clear 'buffer'

    if(checked == true)
    {
        check.AdvScore += check.ProcessAd(1);
    }
}

//Advantage - Situation is neutral
void Widget::on_Advantage_neutral_toggled(bool checked)
{
    check.AdvScore = 0; //clear 'buffer'

    if(checked == true)
    {
        check.AdvScore += check.ProcessAd(0);
    }
}

//Advantage - Player has disadvantage
void Widget::on_Advantage_negative_toggled(bool checked)
{

    check.AdvScore = 0; //clear 'buffer'

    if(checked == true)
    {
        check.AdvScore += check.ProcessAd(-1);
    }
}

void Widget::on_Contest_Single_toggled(bool checked)
{
    check.contest = 0;  //clear 'buffer'

    if(checked == true)
    {
        check.contest = true;
    }
}

//Roll for initiative list
void Widget::on_pushButton_clicked()
{
    //Clears (but doesn't delete) names from the display list
    while(ui->listWidget->count()>0)
    {
        ui->listWidget->takeItem(0);//handle the item if you don't
                              //have a pointer to it elsewhere
    }

    //---->placeholder
    //Populates name list
    init.TEMPnames();

    //Assign Initiative
    init.AssignInit();
    for(int i = 0; i<init.num_p; i++)
    {

        //convert std string to QString to then be sent to the widget
        string order = init.combatOrder[i];
        QString str = QString::fromLocal8Bit(order.c_str());
        //Add the QString to widget's display
        ui->listWidget->addItem(str);


        qDebug() << init.p[i].initiative;
    }

    //Reset Initiative for next button press
    init.resetInit();
}

