#include "widget.h"
#include "skillcheck.h"
#include "./ui_widget.h"
#include <QDebug>
#include <QString>
#include <string>
#include <QListWidgetItem>
#include <QButtonGroup>
#include <QModelIndex>

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
    check.playerSkill_t = 0;    // clear 'buffer' between button clicks
    check.enemySkill_t = 0;
    int index = 0;              //location of player's data
    int strength = 0;
    int wisdom = 0;
    int dexterity = 0;
    int charisma = 0;
    int intelligence = 0;
    //

    QString cmpr = "";
    //make sure there are selections before a result is taken
    if(check.TD != 0 && check.selectedSkill != "" && ui->listWidget2->item(0)->text() != "")
    {
        //get selected player from clicked initiative list
        QString playerName = ui->listWidget2->item(0)->text();

        //pull up playerName skills from vector<struct> p
        for(int i = 0; i < init.p.size(); i++)
        {
            cmpr = init.p[i].name;

            //search init.p for matching name entry
            //load in values from vector<struct>
            for(int j = 0; j < init.p.size(); ++j)
            {
                if(init.p[j].name == cmpr)
                {
                    strength = init.p[j].STR;
                    wisdom = init.p[j].WIS;
                    charisma = init.p[j].CHA;
                    dexterity = init.p[j].DEX;
                    intelligence = init.p[j].INT;
                    index = j;
                }
            }
        }

        //check selected skill and += player's skill #
        if(check.selectedSkill == "STR")
        {
            check.playerSkill_t += init.p[index].STR;
        }
        else if(check.selectedSkill == "WIS")
        {
            check.playerSkill_t += init.p[index].WIS;
        }
        else if(check.selectedSkill == "CHA")
        {
            check.playerSkill_t += init.p[index].CHA;
        }
        else if(check.selectedSkill == "INT")
        {
            check.playerSkill_t += init.p[index].INT;

        }
        else if(check.selectedSkill == "DEX")
        {
            check.playerSkill_t += init.p[index].DEX;

        }

        //+= advantage, += proficiency
        check.playerSkill_t += check.AdvScore;
        check.playerSkill_t += check.profBonus;

        //if no contest
        if(check.contest == false)
        {

            //winning conditions:
            // player skill must be greaterthan or equal to task difficulty
            if(check.playerSkill_t - check.TD >= 0)
            {
                qDebug() << "Passed";
            }
            else
            {
                qDebug() << "Failed";
            }
        }
        else //competitor
        {
            //convert competitor selected to a QString
            QString competitor;
            QModelIndex ind = ui->compList->currentIndex();
            competitor = ind.data(Qt::DisplayRole).toString();

            //load in character; c = competitor
            int c_strength = 0;
            int c_wisdom = 0;
            int c_dexterity = 0;
            int c_charisma = 0;
            int c_intelligence = 0;
            int c_index = 0;

            //pull up playerName skills from vector<struct> p
            for(int i = 0; i < init.p.size(); i++)
            {
                cmpr = init.p[i].name;

                //search init.p for matching name entry
                //load in values from vector<struct>
                for(int j = 0; j < init.p.size(); ++j)
                {
                    if(init.p[j].name == cmpr)
                    {
                        c_strength = init.p[j].STR;
                        c_wisdom = init.p[j].WIS;
                        c_charisma = init.p[j].CHA;
                        c_dexterity = init.p[j].DEX;
                        c_intelligence = init.p[j].INT;
                        c_index = j;
                    }
                }
            }
                //check selected skill and += player's skill #
                if(check.selectedSkill == "STR")
                {
                    check.enemySkill_t += init.p[c_index].STR;
                }
                else if(check.selectedSkill == "WIS")
                {
                    check.enemySkill_t += init.p[c_index].WIS;
                }
                else if(check.selectedSkill == "CHA")
                {
                    check.enemySkill_t += init.p[c_index].CHA;
                }
                else if(check.selectedSkill == "INT")
                {
                    check.enemySkill_t += init.p[c_index].INT;

                }
                else if(check.selectedSkill == "DEX")
                {
                    check.enemySkill_t += init.p[c_index].DEX;

                }

                //+= advantage, += proficiency
                check.enemySkill_t+= check.c_AdvScore;
                check.enemySkill_t+= check.c_profBonus;

                //win condition
                if(check.playerSkill_t > check.enemySkill_t)
                {
                    qDebug() << "Player Wins";
                }
                else if(check.playerSkill_t == check.enemySkill_t)
                {
                    qDebug() << "Situation remains neutral";
                }
                else
                {
                    qDebug() << "Enemy Wins";
                }


        }
   }
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

    if(checked == 1)
    {
        check.contest = 0;
    }
}


void Widget::on_Contest_Duel_toggled(bool checked)
{
    check.contest = 0;
    if(checked == 1)
    {
        check.contest = 1;
    }
}

//Roll for initiative list
//Needs the most work
//***NEEDS PYTHON SCRIPT***//
void Widget::on_initRoll_clicked()
{
    //Clears (but doesn't delete) names from the display list
    while(ui->listWidget->count()>0)
    {
        ui->listWidget->takeItem(0);
    }
    while(ui->compList->count()>0)
    {
        ui->compList->takeItem(0);
    }

    //button executes if the vector<struct> is not empty of players
    if(!init.p.empty())
    {
        //assigns every player initiative via dice roll
        init.AssignInit();

        QString order;
        for(int i = 0; i<init.p.size(); i++)
        {
            order = init.combatOrder[i];
            ui->listWidget->addItem(order);
            ui->compList->addItem(order);
        }

        //Reset Initiative for next button press
        init.resetInit();
    }
}

//Display selected player for skill check
void Widget::on_listWidget_itemClicked(QListWidgetItem *item)
{
    //clear buffer between clicks
    while(ui->listWidget2->count()>0)
    {
        ui->listWidget2->takeItem(0);
    }

    //display item
    ui->listWidget2->addItem(item->text());
}

//clear all choices for a re-roll
void Widget::on_SkillCheck_Clear_clicked()
{
    QButtonGroup* TD = new QButtonGroup;    //Group of buttons for Task Difficulty
    QButtonGroup* CT = new QButtonGroup;    //Group of buttons for Contest (single/duel)
    QButtonGroup* AD = new QButtonGroup;    //Group of buttons for player Advantage-disadvantage
    QButtonGroup* SK = new QButtonGroup;    //Group of buttons for Skill being checked
    QButtonGroup* c_AD = new QButtonGroup;  //Group of buttonsfor player Advantage-disadvantage

    //Task Difficulty
    TD->addButton(ui->TaskDifficulty_Easy);
    TD->addButton(ui->TaskDifficulty_vEasy);
    TD->addButton(ui->TaskDifficulty_Medium);
    TD->addButton(ui->TaskDifficulty_Hard);
    TD->addButton(ui->TaskDifficulty_vHard);
    TD->addButton(ui->TaskDifficulty_Extreme);
    QAbstractButton* checked = TD->checkedButton();
    if(checked)
    {
        TD->setExclusive(false);
        checked->setChecked(false);
        TD->setExclusive(true);
    }

    //Skill Being Checked
    SK->addButton(ui->SkillCheck_CHA);
    SK->addButton(ui->SkillCheck_DEX);
    SK->addButton(ui->SkillCheck_INT);
    SK->addButton(ui->SkillCheck_STR);
    SK->addButton(ui->SkillCheck_WIS);

    QAbstractButton* checked2 = SK->checkedButton();
    if(checked2)
    {
        SK->setExclusive(false);
        checked2->setChecked(false);
        SK->setExclusive(true);
    }

    //Contest
    CT->addButton(ui->Contest_Single);
    CT->addButton(ui->Contest_Duel);
    QAbstractButton* checked3 = CT->checkedButton();
    if(checked3)
    {
        CT->setExclusive(false);
        checked3->setChecked(false);
        CT->setExclusive(true);
    }

    //Player Advantage-Disadvantage
    AD->addButton(ui->Advantage_positive);
    AD->addButton(ui->Advantage_negative);
    AD->addButton(ui->Advantage_neutral);
    QAbstractButton* checked4 = AD->checkedButton();
    if(checked4)
    {
        AD->setExclusive(false);
        checked4->setChecked(false);
        AD->setExclusive(true);
    }

    //Enemy Advantage-Disadvantage
    c_AD->addButton(ui->cAdvantage_positive);
    c_AD->addButton(ui->cAdvantage_negative);
    c_AD->addButton(ui->cAdvantage_neutral);
    QAbstractButton* checked5 = c_AD->checkedButton();
    if(checked5)
    {
        c_AD->setExclusive(false);
        checked5->setChecked(false);
        c_AD->setExclusive(true);
    }

    //Proficiency Bonus
    ui->SkillCheck_ProfBonus->setValue(0);  //set value to 0;
    ui->SkillCheck_cProfBonus->setValue(0);


}

//+proficiency Bonus
void Widget::on_SkillCheck_ProfBonus_valueChanged(int arg1)
{
    //clear 'buffer'
    check.profBonus = 0;
    //apply new value
    check.profBonus += arg1;
}

//Add Player to playerList
void Widget::on_addPlayer_clicked()
{
    QString URL;    //URl entered
    QString str;    //str to hold comparison strings for error check

    //Check for empty submission
    if(ui->playerURL->text() != "")
    {
        URL = ui->playerURL->text();

        //for initial submission
        if(ui->playerList->count() == 0)
        {
            ui->playerList->addItem(URL);
            init.processPlayer(URL);  //add player to vector
            init.num_p++;   //+1 player
        }
        //else check for repeat submission
        else
        {
            int match = 0;
            for(int row = 0; row < ui->playerList->count(); ++row)
            {

                //pull Qstring from row# to str
                str = ui->playerList->item(row)->text();
                if(str == URL)
                {
                    match++;
                }
            }
            if(match == 0)
            {
                //***CALL PYTHON SCRIPT HERE***//
                //get name
                //convert name to QString
                //send QString through below argument

                ui->playerList->addItem(URL);
                init.processPlayer(URL);  //add player to vector
                init.num_p++;   //+1 player
            }
        }
    }

    //clear dialog box after submission
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
    for(auto i = init.p.begin(); i!= init.p.end(); ++i)
    {
        if(i->name == str)
        {
            i = init.p.erase(i);
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

