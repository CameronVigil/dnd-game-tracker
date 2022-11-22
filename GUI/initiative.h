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
    const int num_p = 3;  //---->Placeholder
    struct player p[3];
    string combatOrder[3];

    int getInit(string);
    void AssignInit();
    void SortOrder();
    void resetInit();

};



#endif // INITIATIVE_H
