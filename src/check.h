#ifndef CHECK_H
#define CHECK_H
using namespace std;

//don't make advantage a bool, can be present or be neutral 

class roll
{
    public:
    //member functions 
    int abilityCheck(bool, bool, int, string, int);
    int ProcessAd(bool);
    int diceRoll(int);    //---->placeholder
};

//---->placeholder function 
int roll::diceRoll(int diceType)
{
    return 15;
}

//|----Ability Check----|
int roll::abilityCheck(bool p_ad, bool e_ad, bool single, int player, int skill, int TD)
{
    int p_skill_total = 0;  //player skill total
    int p_pick = ProcessAd(p_ad);    //highest/lowest of two dice rolls based on advantage

    if(single == false) //player competing with another entity (ie. player fights ork)
    {
        //initialize enemy's rolls and skill
        int e_skill_total = 0;      //enemy skill total 
        int e_pick2 = ProcessAd(e_ad);//ditto 
        
        //---->NEED skill accumulation algo 
        //Left off here
    }
    else  //player doing task (ie. climbing a wall)
    {
        //compare to task difficulty 
        if(skill_total - TD > 0)
        {
            return 1;    //task passed 
        }
        else if(skill_total - TD =< 0)
        {
            return 0;   //task failed
        }
    }   
}

//|----Process Advantage----|
//recieves two dice rolls and advantage/disadvantage, returns highest/lowest as needed 
int roll::ProcessAd(int ad)
{
    int r1 = diceRoll(20);  //dice roll 1
    int r2 = diceRoll(20);  //dice roll 2
    
    //advantage -> take highest of r1 and r2
    if(ad == 1 || ad == -1)
    {
        if(r1 > r2)
        {
            return r1;
        }
        else
        {
            return r2;
        }
    }
    //disadvantage -> take lowest of r1 and r2
    else
    {
        if(r1 > r2)
        {
            return r2;
        }
        else
        {
            return r2;
        }
    }
}

#endif
