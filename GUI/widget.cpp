#include "widget.h"
#include "skillcheck.h"
#include "player.h"
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
/*
//Roll for initiative list
void Widget::on_pushButton_clicked(bool checked)
{
    //Clears (but doesn't delete) names from the display list
    while(ui->listWidget->count()>0)
    {
        ui->listWidget->takeItem(0);//handle the item if you don't
                              //have a pointer to it elsewhere
    }


    //Assign Initiative
    AssignInit(&players);
    int i = 0;
    for(auto it = players.begin(); it != players.end(); ++it)
    {

        //convert std string to QString to then be sent to the widget
        string order = combatOrder[i];
        QString str = QString::fromLocal8Bit(order.c_str());
        //Add the QString to widget's display
        ui->listWidget->addItem(str);


        qDebug() << it->getInitiative();
        i++;
    }

    //Reset Initiative for next button press
    resetAllInitiatives(&players);
}
*/

//add player
void Widget::on_addPlayer_clicked()
{
    QString url;
    url = ui->playerURL->text();

    //add player to players vector

    bool notEntered = true;
    //checks if url is null or not
    if(url != ""){
        //checks if url is already entered
        for(auto it = players.begin(); it != players.end(); ++it){
            if(it->url == url.toStdString()){
                    notEntered = false;
            }
        }
        if(notEntered == true){
            addPlayer(url.toStdString(),&players);
            for(auto it = players.begin(); it != players.end(); ++it){
                if(it->url == url.toStdString()){
                        ui->playerList->addItem(QString::fromStdString(it->name));
                }
            }

        }
    }
    ui->playerURL->clear();

}





//Delete Player from display and from vector<struct>
void Widget::on_delPlayer_clicked()
{
    //get selected string from player list widget as QString
    QString str;
    QModelIndex index = ui->playerList->currentIndex();
    str = index.data(Qt::DisplayRole).toString();

    //searches selected name and deletes element in vector by value, deletes, reduces size
    for(auto it = players.begin(); it!= players.end(); ++it)
    {
        if(it->name == str.toStdString())
        {
            removePlayer(str.toStdString(),&players);
            break;
        }
    }

    //deletes highlighted item from playerList widget
    qDeleteAll(ui->playerList->selectedItems());
}
//Add player's STR
void Widget::on_SkillCheck_STR_toggled(bool checked)
{
    //clear buffer
    check.selectedSkill = "";

    if(checked == true)
    {
        check.selectedSkill = "STR";
    }
    else
    {
        check.selectedSkill = "";
    }
}

//Add player's DEX
void Widget::on_SkillCheck_DEX_toggled(bool checked)
{
    //clear buffer
    check.selectedSkill = "";

    if(checked == true)
    {
        check.selectedSkill = "DEX";
    }
    else
    {
        check.selectedSkill = "";
    }
}


//Add player's INT
void Widget::on_SkillCheck_INT_toggled(bool checked)
{
    //clear buffer
    check.selectedSkill = "";

    if(checked == true)
    {
        check.selectedSkill = "INT";
    }
    else
    {
        check.selectedSkill = "";
    }
}

//Add player's WIS
void Widget::on_SkillCheck_WIS_toggled(bool checked)
{
    //clear buffer
    check.selectedSkill = "";

    if(checked == true)
    {
        check.selectedSkill = "WIS";
    }
    else
    {
        check.selectedSkill = "";
    }
}
//Add player's CHA
void Widget::on_SkillCheck_CHA_toggled(bool checked)
{
    //clear buffer
    check.selectedSkill = "";

    if(checked == true)
    {
        check.selectedSkill = "CHA";
    }
    else
    {
        check.selectedSkill = "";
    }
}

//competitor advantage positive
void Widget::on_cAdvantage_positive_toggled(bool checked)
{
    check.c_AdvScore = 0; //clear 'buffer'

    if(checked == true)
    {
        check.c_AdvScore += check.ProcessAd(1);
    }
}


//competitor advantage neutral
void Widget::on_cAdvantage_neutral_toggled(bool checked)
{
    check.c_AdvScore = 0; //clear 'buffer'

    if(checked == true)
    {
        check.c_AdvScore += check.ProcessAd(0);
    }
}

//competitor advantage negative
void Widget::on_cAdvantage_negative_toggled(bool checked)
{
    check.c_AdvScore = 0; //clear 'buffer'

    if(checked == true)
    {
        check.c_AdvScore += check.ProcessAd(-1);
    }
}

//competitor proficiency
void Widget::on_SkillCheck_cProfBonus_valueChanged(int arg1)
{
    //clear 'buffer'
    check.c_profBonus = 0;
    //apply new value
    check.c_profBonus += arg1;
}


