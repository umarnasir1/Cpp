/*
  Using const with classes
*/
#include<iostream>

// Player class
// get_name function in player class


const Player villian {"Villain", 100, 55}; // villain is const object so its attributes cannot be change/modified.

// What happens when we call member methods on a const object ?
// setter object method which change object

void display_player_name (const Player &p){
  cout << p.get_name() << endl;
}

display_player_name(villain); // ERROR 
