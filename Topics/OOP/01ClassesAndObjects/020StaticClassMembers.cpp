/*
  Static Class Members

  Player.h - class specification
  Player.cpp - class definition
  020StaticClassMembers.cpp

  know how many plaers are active at any time - We can't add that to objects because then each object would have their own copy. So we want to use static variable at the class level so that we now have a variable that applies to the entire class.
*/
#include <iostream>
#include "Player.h"

using std::cout;
using std::endl;

void display_active_players();

int main(){

  display_active_players(); // 0 -  we're calling player and asking the player class to give us the number of players.

  Player obj1 {"Bjarne"};
  display_active_players(); // 1 - Bjarne

  {
    Player frank {"Frank"};
    display_active_players();  // 2
  }

  display_active_players(); // 1 as frank object will be destroyed

  Player *enemy = new Player("Enemy", 100, 100); // enemy is pointer to player created on HEAP
  display_active_players(); // 2 enemy is created on HEAP
  delete enemy;

  display_active_players(); // 1

  return 0;
}

void display_active_players(){
  cout << "Active players: " << Player::get_num_players() << endl; // return the ingeter that represents the static data member that we had in the class.
}
