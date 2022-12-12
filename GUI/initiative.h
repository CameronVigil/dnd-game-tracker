#ifndef INITIATIVE_H
#define INITIATIVE_H
#include "player.h"
#include <QWidget>
#include <string>
using namespace std;

//Roll for Initiative


int getInit(string name,std::vector<Player> *players);
void AssignInit(std::vector<Player> *players,std::string *combatOrder);
void SortOrder(std::vector<Player> *players,std::string *combatOrder);
void resetAllInitiatives(std::vector<Player> *players);




#endif // INITIATIVE_H
