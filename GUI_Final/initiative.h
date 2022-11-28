#ifndef INITIATIVE_H
#define INITIATIVE_H
#include "dice.h"

#include <QString>
#include <QWidget>
#include <string>
using namespace std;

//Roll for Initiative
class Init
{
public:
    Dice d;

    struct player
    {
      QString name;
      int initiative;
      int STR;
      int WIS;
      int CHA;
      int INT;
      int DEX;
    };

    int num_p = 0;              //number of players
    vector<player> p;           //name of players
    //struct player p[5];
    QString combatOrder[5];

    void processPlayer(QString);       //takes name from add player and does a struct

    int getInit(int);
    void AssignInit();
    void SortOrder();
    void resetInit();

};



#endif // INITIATIVE_H
