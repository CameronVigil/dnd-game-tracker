#ifndef INIT_H
#define INIT_H
using namespace std;

struct player
{
    string name;
    int initiative = 0;
};

//---->!Needs to be worked in rather than declared 
const int num_p = 3;
class Init
{
    public: 
        struct player p[num_p];
        string combatOrder[num_p];
    
    //member functions
    int getInit(string);
    void AssignInit();
    void SortOrder();
    void resetInit();
};

//---->!needs to be integrated with dice roll for full functionality
int Init::getInit(string name)
{
    int result = 0; //---->!placeholder 
    return result; 
    //return diceRoll()+dexterity(name)
}

//Roll for Initiative; assign value to player.initiative 
void Init::AssignInit()
{
    for(int i = 0; i < num_p; i++)
    {
        p[i].initiative = getInit(p[i].name);
    }
}

//Sort Initiative in descending order
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


#endif
