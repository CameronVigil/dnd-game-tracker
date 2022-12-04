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
void AssignInit(std::vector<Player> *players)
{
    //each player gets initiative value
    for(auto it = players->begin(); it != players->end(); ++it){
        it->assignInitiative(getInit(it->name, players));
    }
    //order is sorted in descending order
    SortOrder(players);
}

//Sort in descending order
void SortOrder(std::vector<Player> *players)
{
    //copy p[n].initiative to a temporary array
    int tempArr[players->size()];
    string combatOrder[players->size()];
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
        }
    }
}

void resetAllInitiatives(std::vector<Player> *players)
{
    for(auto it = players->begin(); it != players->end(); ++it){
        it->resetInitiative();
    }
}
