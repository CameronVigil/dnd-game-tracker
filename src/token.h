#ifndef TOKEN_H
#define TOKEN_H

#include <cstdlib>
#include <iostream>     // std::cout
#include <algorithm>    // std::for_each
#include <vector>       // std::vector
#include <sstream>
#include <string>


using namespace std;

void interpret(vector<string> tokens);
void tokenizer(string line);

#endif TOKEN_H