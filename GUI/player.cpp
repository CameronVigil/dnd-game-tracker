#include "player.h"
#include "webScrape.h"
#include "skillcheck.h"
#include <string>
#include <vector>

//reset initiative to zero for player object
void Player::resetInitiative(){
    initiative = 0;
}
//get initiative from player object
int Player::getInitiative(){
    return initiative;
}
//assign initiative to player object
void Player::assignInitiative(int init){
    initiative = init;
}

//add player to vector of players
void addPlayer(std::string url, std::vector<Player> *players){
   Player player;

   cout << "performing web scrape" << endl;


   player.name = webScrapeName(url);
   player.strength = webScrapeStrength(url);
   player.dexterity = webScrapeDexterity(url);
   player.constitution = webScrapeIntelligence(url);
   player.intelligence = webScrapeIntelligence(url);
   player.wisdom = webScrapeWisdom(url);
   player.url = url;


   players->push_back(player);
   cout << player.name << endl;
}
//remove player from vector of players
void removePlayer(std::string name, std::vector<Player> *players){
    for(auto it = players->begin(); it != players->end(); ++it){
        if(it->name == name){
            players->erase(it); //remove player object from vector of players
            break;
        }
    }

}
