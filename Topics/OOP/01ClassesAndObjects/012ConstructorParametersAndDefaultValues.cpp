/*
  Constructor Parameters & Default Values
  Ambigous Constructor - If we implement a no args constructor, we'd get a compiler error because the compiler wouldn't know which one to call.
*/
#include<iostream>
#include<string>

using std::cout;
using std::endl;

class Player{
private:
  std::string name;
  int health;
  int xp;
public:
  // Constructor with default parameter values
  Player (std::string name_val = "None", // this constructor can replace 3 overloaded constructors in the previous eg.
          int health_val = 0,
          int xp_val = 0);
};

// Initilization List
Player::Player (std::string name_val, int health_val, int xp_val)
  : name {name_val}, health{health_val}, xp{xp_val} {
    cout <<"Three-args constructor." << endl;
}

int main(){

  Player empty; // None, 0, 0 - all three default parameters will be substituted.
  Player frank {"Frank"}; // Frank,0,0
  Player hero {"Hero", 100}; // Hero, 100, 0
  Player bjarne {"Bjarne", 100, 55}; // Bjarne, 100, 55

  return 0;
}
