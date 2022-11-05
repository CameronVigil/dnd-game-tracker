#include "roll.h"


#include <stdio.h>      
#include <math.h>
#include <cstdlib>
#include <iostream>     // std::cout
#include <algorithm>    // std::for_each
#include <vector>       // std::vector
#include <string>

using namespace std;


//function for each individual roll
void rollDice(string token) {
    int numOfRolls = 0;             //number of rolls for specific dice
    int DiceRoll = 0;               //type of dice
    int totalDiceRollSum = 0;       // sum of dice rolls
    string currentToken = token;    //current token being parsed

    cout << token << "\n";
    //checks if there is number in front representing multiple dice rolls
    if (isdigit(token.front())) {
        int dPosition = token.find('d');            //finds 'd' character
        string subS = token.substr(0, dPosition);   //substring for number of rolls
        numOfRolls = stoi(subS);                    //sets the number of rolls
        token.erase(0, dPosition + 1);              //remove up to and including 'd' character
    }
    else {
        numOfRolls = 1;     //assumed 1 roll
        token.erase(0,1);   //remove 'd' character
    }
    
    //set token string to number of dice roll
    DiceRoll = stoi(token); 

    for (int i = 0; i < numOfRolls; i++) {
        int result = floor(rand() % DiceRoll) + 1;      //random number in range of dice number
        totalDiceRollSum = totalDiceRollSum + result;   //total sum for dice
    }

    cout << "Total for the dice roll (" << currentToken << "):" << totalDiceRollSum << "\n";

}


//roll function
void roll(vector <string> tokens) {

    for_each(tokens.begin(), tokens.end(), rollDice);   //calls function for each dice roll requested

}

/*
// Random dice rolls on click

// Look at this d4 die, when clicked, do something
$("#dice-roller-d4").on("click", () => {
  let totalDiceRollSum = 0;
  // integer value of the number of rolls selected
  const numOfRolls = parseInt($("#count_1").val());
  console.log(numOfRolls);
  // If more than one die is rolled,
  // roll, and calculate the total of the random results
  for (let i = 0; i < numOfRolls; i++) {
    // Tried Math.round here at first but received decimals
    let result = Math.floor(Math.random() * 4) + 1;
    totalDiceRollSum = totalDiceRollSum + result;
  }
  // Look for a div labeled: "d4-generated-num" and change the HTML
  // to be the resulting integer
  document.getElementById("d4-generated-number").innerHTML = totalDiceRollSum;
});
$("#dice-roller-d6").on("click", () => {
  let totalDiceRollSum = 0;
  const numOfRolls = parseInt($("#count_2").val());
  console.log(numOfRolls);
  for (let i = 0; i < numOfRolls; i++) {
    let result = Math.floor(Math.random() * 6) + 1;
    totalDiceRollSum = totalDiceRollSum + result;
  }
  document.getElementById("d6-generated-number").innerHTML = totalDiceRollSum;
});
$("#dice-roller-d8").on("click", () => {
  let totalDiceRollSum = 0;
  const numOfRolls = parseInt($("#count_3").val());
  console.log(numOfRolls);
  for (let i = 0; i < numOfRolls; i++) {
    let result = Math.floor(Math.random() * 8) + 1;
    totalDiceRollSum = totalDiceRollSum + result;
  }
  document.getElementById("d8-generated-number").innerHTML = totalDiceRollSum;
});
$("#dice-roller-d10").on("click", () => {
  let totalDiceRollSum = 0;
  const numOfRolls = parseInt($("#count_4").val());
  console.log(numOfRolls);
  for (let i = 0; i < numOfRolls; i++) {
    let result = Math.floor(Math.random() * 10) + 1;
    totalDiceRollSum = totalDiceRollSum + result;
  }
  document.getElementById("d10-generated-number").innerHTML = totalDiceRollSum;
});
$("#dice-roller-d12").on("click", () => {
  let totalDiceRollSum = 0;
  const numOfRolls = parseInt($("#count_5").val());
  console.log(numOfRolls);
  for (let i = 0; i < numOfRolls; i++) {
    let result = Math.floor(Math.random() * 12) + 1;
    totalDiceRollSum = totalDiceRollSum + result;
  }
  document.getElementById("d12-generated-number").innerHTML = totalDiceRollSum;
});
$("#dice-roller-d20").on("click", () => {
  let totalDiceRollSum = 0;
  const numOfRolls = parseInt($("#count_6").val());
  console.log(numOfRolls);
  for (let i = 0; i < numOfRolls; i++) {
    let result = Math.floor(Math.random() * 20) + 1;
    totalDiceRollSum = totalDiceRollSum + result;
  }
  document.getElementById("d20-generated-number").innerHTML = totalDiceRollSum;
});

// Plus counter inputs
$("#plus_1").on("click", () => {
  const currentValue = $("#count_1").val();
  // parseInt() function parses a string argument and
  // returns an integer
  $("#count_1").val(parseInt(currentValue) + 1);
});
$("#plus_2").on("click", () => {
  const currentValue = $("#count_2").val();
  $("#count_2").val(parseInt(currentValue) + 1);
});
$("#plus_3").on("click", () => {
  const currentValue = $("#count_3").val();
  $("#count_3").val(parseInt(currentValue) + 1);
});
$("#plus_4").on("click", () => {
  const currentValue = $("#count_4").val();
  $("#count_4").val(parseInt(currentValue) + 1);
});
$("#plus_5").on("click", () => {
  const currentValue = $("#count_5").val();
  $("#count_5").val(parseInt(currentValue) + 1);
});
$("#plus_6").on("click", () => {
  const currentValue = $("#count_6").val();
  $("#count_6").val(parseInt(currentValue) + 1);
});

// Minus counter inputs
$("#minus_1").on("click", () => {
  const currentValue = $("#count_1").val();
  // Cease the decrement count at 1 die
  $("#count_1").val(parseInt(currentValue) - 1);
  // Ternary Operator for the two choices:
  // Condition followed by a ?, separated by a :
  // If the condition is truthy, the first expression is executed
  // otherwise the second.
  
$("#count_1").val(currentValue - 1 < 1 ? 1 : currentValue - 1);
});
$("#minus_2").on("click", () = > {
    const currentValue = $("#count_2").val();
    $("#count_2").val(parseInt(currentValue) - 1);
    $("#count_2").val(currentValue - 1 < 1 ? 1 : currentValue - 1);
});
$("#minus_3").on("click", () = > {
    const currentValue = $("#count_3").val();
    $("#count_3").val(parseInt(currentValue) - 1);
    $("#count_3").val(currentValue - 1 < 1 ? 1 : currentValue - 1);
});
$("#minus_4").on("click", () = > {
    const currentValue = $("#count_4").val();
    $("#count_4").val(parseInt(currentValue) - 1);
    $("#count_4").val(currentValue - 1 < 1 ? 1 : currentValue - 1);
});
$("#minus_5").on("click", () = > {
    const currentValue = $("#count_5").val();
    $("#count_5").val(parseInt(currentValue) - 1);
    $("#count_5").val(currentValue - 1 < 1 ? 1 : currentValue - 1);
});
$("#minus_6").on("click", () = > {
    const currentValue = $("#count_6").val();
    $("#count_6").val(parseInt(currentValue) - 1);
    $("#count_6").val(currentValue - 1 < 1 ? 1 : currentValue - 1);
});




*/