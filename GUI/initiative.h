#ifndef INITIATIVE_H
#define INITIATIVE_H
#include "dice.h"

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
      string name;
      int initiative = 0;
    };
    static const int num_p = 5;  //---->Placeholder
    struct player p[num_p];
    string combatOrder[5];

    //placeholder
    void TEMPnames();//---->placeholder

    int getInit(string);
    void AssignInit();
    void SortOrder();
    void resetInit();

};



#endif // INITIATIVE_H
