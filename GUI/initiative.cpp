#include "initiative.h"
#include <algorithm>
#include <vector>

void Init::TEMPnames()
{
   p[0].name = "Sam";
   p[1].name = "Tom";
   p[2].name = "Sally";
   p[3].name = "Bill";
   p[4].name = "Robert";

}

int Init::getInit(string name)
{
    return(d.diceRoll(20));
    //return (d.diceRoll(20)+dex(name) MISSING MISSING MISSING MISSING MISSING
}

//Assigns Initiative to each player
void Init::AssignInit()
{
    //each player gets initiative value
    for(int i = 0; i < num_p; i++)
    {
        p[i].initiative = getInit(p[i].name);
    }
    //order is sorted in descending order
    SortOrder();
}

//Sort in descending order
void Init::SortOrder()
{

    //assign Name to order of combat (unsorted)
    for(int i = 0; i < num_p; i++)
    {
        combatOrder[i] = p[i].name;
    }

    int tempArr[num_p];
    //copy p[n].initiative to a temporary array
    for(int i = 0; i<num_p; i++)
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
                string temp1 = combatOrder[i];
                combatOrder[i] = combatOrder[j];
                combatOrder[j] = temp1;
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
