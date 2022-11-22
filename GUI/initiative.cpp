#include "initiative.h"

int Init::getInit(string name)
{
    return(d.diceRoll(20));
    //return (d.diceRoll(20)+dex(name) MISSING MISSING MISSING MISSING MISSING
}

//Assigns Initiative to each player
void Init::AssignInit()
{
    for(int i = 0; i < num_p; i++)
    {
        p[i].initiative = getInit(p[i].name);
    }
}

void Init::SortOrder()
{
    for(int i = 0; i < num_p; i++)
    {
        combatOrder[i] = p[i].name;
    }

    for(int i = num_p; i >= 0; i--)
    {
        for(int j = num_p; j > num_p - i; j--)
        {
            if(p[j].initiative > p[j-1].initiative)
            {
                swap(combatOrder[j], combatOrder[j-1]);
            }
        }
    }
}

//reset initiative to 0
void Init::resetInit()
{
    for(int i = 0; i<num_p; i++)
    {
        p[i].initiative = 0;
    }
}
