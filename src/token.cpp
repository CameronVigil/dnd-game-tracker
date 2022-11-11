#include "token.h"

#include "webScrape.h"
#include "func.h"
#include "database.h"
#include "roll.h"
#include <stdio.h>      
#include <math.h>
#include <cstdlib>
#include <iostream>     // std::cout
#include <algorithm>    // std::for_each
#include <vector>       // std::vector
#include <sstream>

using namespace std;

//read and execute tokens
void interpret(vector<string> tokens)
{
    //help 
    if (tokens[0] == "/help")
    {
        help();
    }
    else if (tokens[0] == "roll")
    {
        tokens.erase(tokens.begin());
        roll(tokens);

    }
    else if (tokens[0] == "add" && tokens[1] == "player")
    {
        string testURL = "https://www.dndbeyond.com/characters/44851421";
        webScrape(testURL);
    }
    else if (tokens[0] == "del" && tokens[1] == "player")
    {

    }
    else if (tokens[0] == "/exit")
    {
        save();
        cout << "|Closing Program\n";
        exit(0);
    }
    else if (tokens[0] == "Load")
    {
        load();
    }
    else
    {
        cout << "|Invalid cmd. Enter /help for cmds\n";
    }
    //list of commands
    //about 
    //add player 
    //del player

}

//parse cmd line into tokens
void tokenizer(string line)
{
    vector <string> tokens;

    string temp;
    
    stringstream check1(line);
    
    //delimit ' '
    while(getline(check1, temp, ' '))
    {
        //push individual words onto vector
        tokens.push_back(temp);
    }
    //read and execute tokens
    interpret(tokens);
}