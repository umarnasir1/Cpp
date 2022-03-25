/*
  Constructors & Destructors
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
  void set_name(std::string name_val){name = name_val;}
  //Overloaded Constructors
  Player(){cout<< "No args constructor is called" << endl;} // called when there is no information provided for initialization - its not going to do any initialization.
  Player(std::string name){cout<< "String arg constructor is called" << endl;} // its not going to do any initialization.
  Player(std::string name, int health, int xp){cout<< "Three arg constructor is called" << endl;} // its not going to do any initialization.
  // Destructor
  ~Player(){cout<< "Destructor called for " << name << endl;} // name - objects (slayer, bjarne, stroustrup)
};

class Account{
private:
  std::string name;
  double balance;
public:
  //Constructors - 4 Overloaded Constructors
  Account(); // no args constructor
  Account(std::string name, double balance);
  Account(std::string name);
  Account(double balance);
  //Destructor
  ~Account();
};

int main (){
  // 4 + 2 Player objects - local objects created on the stack - But then when the block ends, these objects go out of scope and their destructors will be called automatically. So in this case all four destructors will be called. And whatever code we provide in, the destructors will be executed before the objects are destroyed.
  {
    Player slayer; //since no initialization information is provided,the no args constructor is called, i.e.,Player()
    slayer.set_name("Slayer");
  } // end of scope of slayer object so destructor for slayer will be called

  {
    Player frank; // constructor created for frank
    frank.set_name("Frank");
    Player hero("Hero");
    hero.set_name("Hero");
    Player villain("Villain", 100, 12);
    villain.set_name("Villain");
  } // end of scope of frank, hero and villain object so destructor for these 3 objects will be called


  Player *enemy = new Player; // we have a pointer to a player object.


  Player *level_boss = new Player("Level Boss", 1000, 300);
  level_boss -> set_name("Level Boss");

  delete enemy; // destructor called.
  delete level_boss;

  // Player bjarne {"Bjarne", 100, 4}; // the constructor that expects a string and two integers will be called i.e., Player(std::string name, int health, int xp)
  // Player stroustrup {"stroustrup"}; // the constructor that expects a single string object will be called, i.e., Player(std::string name)
  // Player villain {"Villain"}; // the constructor that expects a single string object will be called, i.e., Player(std::string name)
  // Player *enemy = new Player("Enemy", 1000, 0); // we have a pointer to a player object and we use the constructor that expects a string and two integers to initialize it.
  //delete enemy;
}
