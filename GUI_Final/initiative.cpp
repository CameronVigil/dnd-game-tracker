#include "initiative.h"
#include <algorithm>
#include <vector>
#include <QString>


void Init::processPlayer(QString name)
{
   p.push_back({name, 0, 0, 0, 0, 0, 0});
}

//get initiative
int Init::getInit(int i)
{
    return(d.diceRoll(20));
    //NEED return (d.diceRoll(20) + player's dex + initiative bonus)
}

//Assigns Initiative to each player
void Init::AssignInit()
{
    for(int i = 0; i< p.size(); i++)
    {
        p[i].initiative = getInit(i);
    }
    //order is sorted in descending order
    SortOrder();
}

//Sort in descending order; includes a tie breaker dice roll if p[n].initiative == p[n+1].initiative
void Init::SortOrder()
{
    int tb1 = 0;    //tie-breaker1 roll
    int tb2 = 0;    //tie-breaker2 roll

    //assign Name to order of combat (unsorted)
    for(int i = 0; i < p.size(); i++)
    {
        combatOrder[i] = p[i].name;
    }

    int tempArr[num_p];
    //copy p[n].initiative to a temporary array
    for(int i = 0; i<p.size(); i++)
    {
        tempArr[i] = p[i].initiative;
    }

    //Sort tempArr
    for(int i = 0; i<num_p; i++)
    {
        for(int j = i+1; j < num_p; j++)
        {
            if( tempArr[i] < tempArr[j])
            {
                //sort temporary array
                int temp = tempArr[i];
                tempArr[i] = tempArr[j];
                tempArr[j] = temp;
                //reflect this in combat order
                QString temp1 = combatOrder[i];
                combatOrder[i] = combatOrder[j];
                combatOrder[j] = temp1;
            }
            //tie breaker
            else if(tempArr[i] == tempArr[j])
            {
                //roll for tie breaker
                while(tb1 == tb2)
                {
                    tb1 = d.diceRoll(20);
                    tb2 = d.diceRoll(20);
                }
                if(tb1 < tb2)
                {
                    int t = tempArr[i];
                    tempArr[i] = tempArr[j];
                    tempArr[j] = t;

                    QString t1 = combatOrder[i];
                    combatOrder[i] = combatOrder[j];
                    combatOrder[j] = t1;
                }
                //reset to 0
                tb1 = 0;
                tb2 = 0;
            }
        }
    }
}

//reset initiative to 0
void Init::resetInit()
{
    for(int i = 0; i< p.size(); i++)
    {
        p[i].initiative = 0;
    }
}
