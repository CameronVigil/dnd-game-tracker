#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>

class Player

{

    private:
        int initiative = 0;
        int strength = 0;
        int dexterity = 0;
        int constitution = 0;
        int charisma = 0;
        int intelligence = 0;



    public:
        std::string name = "unnamed";

        int getInitiative();
        void assignInitiative(int init);
        void resetInitiative();
        void addPlayer(std::string url, std::vector<Player> *players);
        void removePlayer(std::string name, std::vector<Player> *players);

};


#endif // PLAYER_H
