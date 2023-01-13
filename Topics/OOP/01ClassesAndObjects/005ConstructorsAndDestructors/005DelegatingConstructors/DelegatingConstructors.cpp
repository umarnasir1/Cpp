/*
  Delegating Constructors
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
  // Overloaded Constructors
  Player();
  Player(std::string name_val);
  Player(std::string name_val, int health_val, int xp_val);
};

Player::Player()
  : Player {"None", 0, 0}{ // delegating to Player (three ags constructor) i.e., calling the three arg constructor (Player) with initialization data we need
  // no arg constructor is delegating constructor since it delegates object initialization to another constructor -  three ags player constructor here.
    cout << "No-args constructor." << endl;
}

Player::Player(std::string name_val)
  : Player {name_val, 0, 0}{ // calling the three arg constructor (Player) with initialization data we need
    cout << "One arg constructor." << endl;
}

Player::Player(std::string name_val, int health_val, int xp_val)
  : name{name_val}, health{health_val}, xp{xp_val}{
    cout << "Three-args constructor." << endl;
}

int main(){

  Player empty; // Player() object - contorl will be shifted to player() and then rathen than initializing here, it will delegate the construction of this object to constructor that expects three args where initialization will occur and control will be shifted back to no arg contructor and back to main. 
  Player frank {"Frank"}; // Player(std::string name_val) object
  Player bjarne {"Bjarne", 100, 55}; // Player::Player(std::string name_val, int health_val, int xp_val) object

  return 0;
}
