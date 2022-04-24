/*
  Static Class Members

  Player.h - class specification
  Player.cpp - class definition
  020StaticClassMembers.cpp
*/

#include "Player.h"

int Player::num_players {0}; // initialize the static variable num_players

// We need to increment and decrement the number of players whenever we create and destroy objects. If many overloaded constructors, we might need to increment num_playersin more than one place. (where we create an object). We only have one constructor in the player class and we're delegating to it from our copy constructor, so this is the only place we want to increment num players in this example.
Player::Player(std::string name_val, int health_val, int xp_val)
  : name{name_val}, health{health_val}, xp{xp_val}{ //initializer list
    ++num_players;
}

Player::Player(const Player &source)
  :Player{source.name, source.health, source.xp}{ // delegating to Player (three ags constructor)
}

Player::~Player(){
  --num_players; // decement the num_players count when object is destroyed.
}

// implement static method - Since this function is static, it only has access to static data members. It does not have access to non-static class data members.
int Player::get_num_players(){
  return num_players; // static functions have only access to static variables
}
