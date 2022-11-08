//Jared Edge
//jpe0050
//11/7/2022
//FP Calculator In=Class Assignment 3444

#include <iostream>

using namespace std;

int main()
{
    //Initialize Variables
    int Scale = 3;
    int FUValues[] = {4, 5, 4, 10, 7};
    int UFPTable[] = {50, 40, 35, 6, 4};
    int UFP = 0;
    int UFPPart = 0;
    float FP = 0;

    //Calculate CAF
    int F = 14 * Scale;
    float CAF = (0.65 + (0.01 * F));

    //Calculate UFP
    for(int i = 0; i < 5; i++)
    {
        UFPPart = FUValues[i] * UFPTable[i];
        UFP += UFPPart;
    }

    //Calculate FP
    FP = UFP * CAF;

    //Output
    cout << FP << endl;

    return 0;
}