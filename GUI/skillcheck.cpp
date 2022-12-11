#include "skillcheck.h"
#include "dice.h"

//recieves two dice rolls, returns highest/lowest based on advantage
int Check::ProcessAd(int ad)
{
    int r1 = diceRoll(20);  //dice roll 1
    int r2 = diceRoll(20);  //dice roll 2

    //advantage/neutral -> take highest of two rolls
    if(ad == 1 || ad == 0)
    {
        if(r1 > r2)
        {
            return r1;
        }
        else
        {
            return r2;
        }
    }
    //disadvantage -> take lowest of two rolls
    else
    {
        if(r1 > r2)
        {
            return r2;
        }
        else
        {
            return r1;
        }
    }
}
