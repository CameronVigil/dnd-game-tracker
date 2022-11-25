#ifndef WEBSCRAPE_H
#define WEBSCRAPE_H



#include <stdio.h>      
#include <math.h>
#include <cstdlib>
#include <iostream>     // std::cout
#include <algorithm>    // std::for_each
#include <vector>       // std::vector

using namespace std;

int webScrapeStrength(string importedURL);
int webScrapeDexterity(string importedURL);
int webScrapeConstitution(string importedURL);
int webScrapeIntelligence(string importedURL);
int webScrapeWisdom(string importedURL);
int webScrapeCharisma(string importedURL);

std::string webScrapeName(string importedURL);

#endif // WEBSCRAPE_H
