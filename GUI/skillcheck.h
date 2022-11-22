#ifndef SKILLCHECK_H
#define SKILLCHECK_H

#include <QWidget>
#include "dice.h"

//Ability Check
class Check
{
public:
    Dice dice;
    int TD = 0;         //Task Difficulty
    int Advantage = 0;  //1 = advantage, 0 = neutral, -1 = disadvantage
    int AdvScore = 0;   //Player's advantage score, added to a total later
    int ProcessAd(int); //process Advantage
    int playerSkill_t=0;//total player skill, is used for comparison
    int enemySkill_t =0;//total enemy skill (if duel), is used for comparison
    bool contest = 0;   //1 = enemy contest, 0 = single player (ie. climbing a ledge vs racing someone)
};

#endif // SKILLCHECK_H
