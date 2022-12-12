#include "widget.h"
#include "skillcheck.h"
#include "initiative.h"
#include "player.h"
#include "./ui_widget.h"
#include <QDebug>
#include <QString>
#include <string>
#include <QMessageBox>

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
    check.playerSkill_t = 0;    //clear 'buffer' betweenclicks
    check.enemySkill_t = 0;

    int index = 0;
    int strength = 0;
    int wisdom = 0;
    int dexterity = 0;
    int charisma = 0;
    int intelligence = 0;

    string cmpr = "";

    //make sure there are selections before a result is computed
    if(check.TD != 0 && check.selectedSkill != "" && ui->listWidget2->item(0)->text() != "")
    {
        //get selected player from clicked initiative list
        QString Name = ui->listWidget2->item(0)->text();
        string playerName = Name.toLocal8Bit().constData();
        //pull up player's skills from vector
        for(int i = 0; i < players.size(); i++)
        {

            cmpr = playerName;

            for(int j = 0; j < players.size(); ++j)
            {
                //search for matching player name among existing players
                if(players[i].name == cmpr)
                {
                    strength = players[j].strength;
                    wisdom = players[j].wisdom;
                    charisma = players[j].charisma;
                    dexterity = players[j].dexterity;
                    intelligence = players[j].intelligence;
                    //index is where the selected player is among players
                    index = j;
                }
            }
        }

        //check selected skill and += player's skill #
        if(check.selectedSkill == "STR")
        {
            check.playerSkill_t += players[index].strength;
        }
        else if(check.selectedSkill == "WIS")
        {
            check.playerSkill_t += players[index].wisdom;
        }
        else if(check.selectedSkill == "CHA")
        {
            check.playerSkill_t += players[index].charisma;
        }
        else if(check.selectedSkill == "INT")
        {
            check.playerSkill_t += players[index].intelligence;

        }
        else if(check.selectedSkill == "DEX")
        {
            check.playerSkill_t += players[index].dexterity;
        }

        //+= advantage, += proficiency
       check.playerSkill_t += check.AdvScore;
       check.playerSkill_t += check.profBonus;

       //if no contest
       if(check.contest == false)
       {

           //winning conditions:
           // player skill must be greater than or equal to task difficulty
           if(check.playerSkill_t - check.TD >= 0)
           {
               QMessageBox::information(this,"Message","Success",QMessageBox::Ok);
           }
           else
           {
               QMessageBox::information(this,"Message","Failure",QMessageBox::Ok);
           }
       }
       else //competitor
       {
           //convert competitor to Qstring
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

           //pull up player skills from database
           for(int i = 0; i<players.size(); i++)
           {
               cmpr = players[i].name;

               //search init.p for matching name entry
               //load in values from vector<struct>
               for(int j = 0; j < players.size(); ++j)
               {
                   if(players[j].name == cmpr)
                   {
                       c_strength = players[j].strength;
                       c_wisdom = players[j].wisdom;
                       c_charisma = players[j].charisma;
                       c_dexterity = players[j].dexterity;
                       c_intelligence = players[j].intelligence;
                       c_index = j;
                   }
               }
           }

           //check selected skill and += player's skill #
          if(check.selectedSkill == "STR")
          {
              check.enemySkill_t += players[c_index].strength;
          }
          else if(check.selectedSkill == "WIS")
          {
              check.enemySkill_t += players[c_index].wisdom;
          }
          else if(check.selectedSkill == "CHA")
          {
              check.enemySkill_t += players[c_index].charisma;
          }
          else if(check.selectedSkill == "INT")
          {
              check.enemySkill_t += players[c_index].intelligence;

          }
          else if(check.selectedSkill == "DEX")
          {
              check.enemySkill_t += players[c_index].dexterity;

          }
       }

       //+= advantage, += proficiency
      check.enemySkill_t+= check.c_AdvScore;
      check.enemySkill_t+= check.c_profBonus;

      //win condition
      if(check.playerSkill_t > check.enemySkill_t)
      {
          QMessageBox::information(this,"Message","Player Wins",QMessageBox::Ok);
      }
      else if(check.playerSkill_t == check.enemySkill_t)
      {
          QMessageBox::information(this,"Message","The Situation Remains Neutral",QMessageBox::Ok);
      }
      else
      {
          QMessageBox::information(this,"Message","Competitor Wins",QMessageBox::Ok);
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

    if(checked == true)
    {
        check.contest = true;
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
void Widget::on_initRoll_clicked()
{
    //Clears (but doesn't delete) names from the display list
    /*while(ui->playerList->count()>0)
    {
        ui->playerList->takeItem(0);//handle the item if you don't
        ui->playerList->                      //have a pointer to it elsewhere
    }
    while(ui->compList->count()>0)
    {
        ui->compList = ui->playerList;
        ui->compList->clear();
    }*/
    ui->listWidget->clear();
    ui->compList->clear();
    //Assign Initiative
    AssignInit(&players, combatOrder);
    //sort order by initiative
    for(int i = 0; i < combatOrder->size() ; ++i)
    {
        if(combatOrder[i] == ""){ break;}
            //convert std string to QString to then be sent to the widget
            string order = combatOrder[i];
            QString str = QString::fromLocal8Bit(order.c_str());
            //Add the QString to widget's display

            ui->listWidget->addItem(QString::fromStdString(combatOrder[i]));
            ui->compList->addItem(QString::fromStdString(combatOrder[i]));
    }

    //Reset Initiative for next button press
    resetAllInitiatives(&players);
}


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
    //clear enter box for player URL
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



//+proficiency Bonus
void Widget::on_SkillCheck_ProfBonus_valueChanged(int arg1)
{
    //clear 'buffer'
    check.profBonus = 0;
    //apply new value
    check.profBonus += arg1;
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

