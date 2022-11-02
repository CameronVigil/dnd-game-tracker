#ifndef TOKEN_H
#define TOKEN_H

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

void interpret(vector<string> tokens);
void tokenizer(string line);

#endif TOKEN_H