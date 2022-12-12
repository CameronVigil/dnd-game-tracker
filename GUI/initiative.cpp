#include "initiative.h"
#include "player.h"
#include "dice.h"

#include <algorithm>
#include <vector>


int getInit(string name, std::vector<Player> *players)
{
    for(auto it = players->begin(); it != players->end(); ++it){
        if(it->name == name){
            return (diceRoll(20)+ it->getInitiative());
        }
    }
    return 0;
}

//Assigns Initiative to each player
void AssignInit(std::vector<Player> *players,std::string *combatOrder)
{
    //each player gets initiative value
    for(auto it = players->begin(); it != players->end(); ++it){
        it->assignInitiative(getInit(it->name, players));
    }
    //order is sorted in descending order
    SortOrder(players, combatOrder);
}

//Sort in descending order
void SortOrder(std::vector<Player> *players,std::string *combatOrder)
{
    //tie breaker rolls in case two players have same init
    int tb1 = 0;    //tie-breaker1 roll
    int tb2 = 0;    //tie-breaker2 roll

    //copy p[n].initiative to a temporary array
    int tempArr[players->size()];
    combatOrder[players->size()];
    int i = 0;
    //assign Name to order of combat (unsorted)

    for(auto it = players->begin(); it != players->end(); ++it){
        combatOrder[i] = it->name;
        tempArr[i] = it->getInitiative();
        i++;
    }

    //Sort tempArr
    for(int i = 0; i<players->size(); i++)
    {
        for(int j = i+1; j < players->size(); j++)
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
            //tie breaker
            else if(tempArr[i] == tempArr[j])
            {
                //roll for tie breaker
                while(tb1 == tb2)
                {
                    tb1 = diceRoll(20);
                    tb2 = diceRoll(20);
                }
                if(tb1 < tb2)
                {
                    int t = tempArr[i];
                    tempArr[i] = tempArr[j];
                    tempArr[j] = t;

                    //QString t1 = combatOrder[i];
                    //combatOrder[i] = combatOrder[j];
                    //combatOrder[j] = t1;
                }
                tb1 = 0;
                tb2 = 0;
            }
        }
    }
}

//reset initiative to 0 for next click
void resetAllInitiatives(std::vector<Player> *players)
{
    for(auto it = players->begin(); it != players->end(); ++it){
        it->resetInitiative();
    }
}
