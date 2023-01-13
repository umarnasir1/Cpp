/*
  Overloading Constructors
*/
#include<iostream>
#include<string>

class Player{
private:
  std::string name;
  int health;
  int xp;
  //can also initialize here
  // std::string name {"Name xxx"};
  // int health {123};
  // int xp {20};
public:
  //Overloaded Constructors
  Player(); // no arg construction - base initialization so there are no garbage values.
  Player(std::string name_val); // initialization name to name_val
  Player(std::string name_val, int health_val, int xp_val); // initialization value for all three attributes
};

Player::Player(){
  name = "None";
  health = 0;
  xp = 0;
}

Player::Player(std::string name_val){
  name = name_val;
  health = 0;
  xp = 0;
}

Player::Player(std::string name_val, int health_val, int xp_val){
  name = name_val;
  health = health_val;
  xp = xp_val;
}

int main(){
  // Three ways to create player objects
  Player empty; // None,0,0 - empty obejct will be initialized by the no args constructor - Player().

  Player hero{"Hero"}; // Hero,0,0 - hero object will be initialized by Player(std::string name_val)
  Player villain{"Villain"}; // Villain,0,0 - villain object will be initialized by Player(std::string name_val)

  Player frank{"Frank", 1000, 4}; // Frank,1000,4 - frank object will be intialized by layer(std::string name_val, int health_val, int xp_val)

  Player *enemy = new Player("Enemy",1000,0); // Enemy,1000,0 - enemy object will be created on the heap and will be intialized by layer(std::string name_val, int health_val, int xp_val)
  delete enemy;

  return 0;
}
