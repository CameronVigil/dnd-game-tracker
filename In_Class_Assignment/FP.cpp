/*
* Name: Julian Mendoza
* Class: CSCE 3444.003
* Date: Nov. 7th, 2022
*/
#include <iostream>

using namespace std;

int main()
{


    //Step 1
    int ScaleValue = 3;
    int F = 14 * ScaleValue;
    
    //Step 2
    float CAF = (0.65 + (0.01 * F));
    
    //Step 3 
    int AverageFU[] = {4,5,4,10,7};
    int AverageData[] = {50, 40, 35, 6, 4};

    //Var declariations
    int UFP = 0;
    int UFP_Single = 0;
    float FP = 0;

    //Step 3 loop to find UFP
    for(int i = 0; i < 5; i++)
    {
        UFP_Single = AverageFU[i] * AverageData[i];
        UFP += UFP_Single;
    }

    //Step 4
    FP = UFP * CAF;

    cout << FP << endl;


    return 0;
}