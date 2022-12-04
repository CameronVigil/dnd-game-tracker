#ifndef WIDGET_H
#define WIDGET_H
#include "skillcheck.h"
#include "player.h"


#include <QWidget>
#include <QListWidgetItem>
#include <QButtonGroup>
#include <string>
#include <QModelIndex>

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE




class Widget : public QWidget
{
    Q_OBJECT

public:
    Check check;
    std::vector<Player> players;
    std::string combatOrder [10];

    Widget(QWidget *parent = nullptr);

    ~Widget();

private slots:
    void on_AbilityCheck_Result_clicked();

    void on_TaskDifficulty_vEasy_toggled(bool checked);

    void on_TaskDifficulty_Easy_toggled(bool checked);

    void on_TaskDifficulty_Medium_toggled(bool checked);

    void on_TaskDifficulty_Hard_toggled(bool checked);

    void on_TaskDifficulty_vHard_toggled(bool checked);

    void on_TaskDifficulty_Extreme_toggled(bool checked);

    void on_Advantage_positive_toggled(bool checked);

    void on_Advantage_neutral_toggled(bool checked);

    void on_Advantage_negative_toggled(bool checked);

    void on_Contest_Single_toggled(bool checked);

    //void on_initRoll_clicked();

    //void on_listWidget_itemClicked(QListWidgetItem *item);

    //void on_SkillCheck_Clear_clicked();

    //void on_SkillCheck_ProfBonus_valueChanged(int arg1);



    //void on_addPlayerButton_clicked(bool checked);


    void on_delPlayer_clicked();

    void on_SkillCheck_STR_toggled(bool checked);

    void on_SkillCheck_DEX_toggled(bool checked);

    void on_SkillCheck_INT_toggled(bool checked);

    void on_SkillCheck_WIS_toggled(bool checked);

    void on_SkillCheck_CHA_toggled(bool checked);

    //void on_Contest_Duel_toggled(bool checked);

    void on_cAdvantage_positive_toggled(bool checked);

    void on_cAdvantage_neutral_toggled(bool checked);

    void on_cAdvantage_negative_toggled(bool checked);

    void on_SkillCheck_cProfBonus_valueChanged(int arg1);


    void on_addPlayer_clicked();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
