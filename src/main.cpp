#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

#include "token.h"          //parse and read cmd
#include "func.h"           //functionalities
#include "database.h"       //SQL database
#include "roll.h"           //roll dice
#include "func.h"
#include "webScrape.h"      //web scraper

void header();

int main()
{
    header();
    string input; 
    
    while(1)
    {
        getline(cin, input);
        tokenizer(input);
        /*while(1)
        {
            loop combat cycle when entered 
        }
        */
    }
    
    return 0;
}

void header()
{
    cout << "||CSCE 3444.003\n";
    cout << "||DnD Combat Helper\n";
    cout << "...\n";
    cout << "Commands:\n";
    cout << "-roll\n";
    cout << "-add player\n";
}