//Jeremy Groce
//Software Engineering
//11/7/22

#include <iostream>

using namespace std;

void fp(int rates[][3], int scale)
{
    int UFP = 0;
    
    //table from slides
    //Low|Average|High
    int table[5][3] = {
        {3,4,6},
        {4,5,7},
        {3,4,6},
        {7,10,15},
        {5,7,10},
    };
    
    //calculte UFP
    //traverse 2d array
    for(int i = 0; i<5;i++)
    {
        for(int j = 0; j <3; j++)
        {
            int f = rates[i][j];
            UFP += f * table[i][j];
        }
    }
    
    int sum = 0;
    for(int i = 0; i<14; i++)
    {
        int rate = scale;
        sum += rate;
    }
    
    //calculate CFP
    double CAF = 0.65 + 0.01 * sum;
    //calculate FP
    double FP = UFP * CAF;

    //display calculated output 
    cout << "UFP:\t" << UFP << endl;
    cout << "CAF:\t" << CAF << endl;
    cout << "FP:\t" << FP << endl;
    
}
int main()
{
    int rates[5][3] = {
        {0,50,0},
        {0,40,0},
        {0,35,0},
        {0,6,0},
        {0,4,0}
    };
    
    int scale = 3;
    fp(rates, scale);

    return 0;
}
