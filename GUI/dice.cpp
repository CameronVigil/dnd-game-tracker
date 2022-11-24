#include "dice.h"

int diceRoll(int max)
{
    int min = 1;

    int roll =rand() % (max - min+1) + min;
    return roll;
}
