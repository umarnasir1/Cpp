/*
  Copy Constructor

  Used Case - When object copy is required - Where copy constructors are used.
    Pass object to function/method by - value
    Return object by value
    Construct one object based on another

  Declaring Copy constructor
  Same name as the class as its a constructor.
  And in the parameter list, we have a single object passed in of the same type. We pass that object in as a reference and a constant.
  Y by reference and constant?
    if we pas by value, then we have to make a copy of it. That's the whole point of the copy constructor. We would defeat the purpose and end up with never ending recursive calls.
    And as a constant because the semantics of copying means that we're copying the source, we're not modifying it. So the const prevents any modification to the source object.

  Type::Type (const Type &source);

  Implementing the Copy constructor
  Shallow copy
  Deep Copy

  Shallow Copy
  Type::Type (const Type &source){
  // code or initialization list to copy the object
  // As we have access to source, so we can reference any attributes we want from source.
  }
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
  // getters
  std::string get_name(){return name};
  int get_health(){return health;}
  int get_xp(){return xp;}
  // Constructor
  Player(std::string name_val="None", int health_val=0, int xp_val=0);
  // Copy Constructor - Prototype
  Player::Player(const Player &source); // single object in the parameter list
  // Destructor
  ~Player(){ cout<<"Destructor called for: " << name << endl; }
};

// Constructor
Player::Player(std::string name_val, int health_val, int xp_val)
  : name{name_val}, health{health_val}, xp{xp_val}{
    cout << "Three-args constructor for " + name << endl;
}

// Copy Constructor 

int main(){
  Player empty;
  Player frank {"Frank"};
  Player hero {"Hero",100};
  Player villain {"Villain",100,55};

  return 0;
}

// Pass object to function/method by - value
Player hero {"Hero", 100, 20};

void display_player(Player p){ // expects player object by value
  // p is a COPY of hero in this example (using the copy constructor)
  // use p
  // Destructor for p will be called (as p is going out of scope)
}

display_player(hero); // When we call this function and pass in hero, the function parameter p will be created and it will be created as a copy of hero, using the copy constructor.

// Return Object by value
Player enemy;

Player create_super_enemy(){ // creates and returns a player object
  // The Player object and enemy is created in the function and then returned from this function. Since we're returning an enemy by value. A copy of the enemy object is made by the copy constructor.
  Player an_enemy{"Super Enemy", 1000, 1000};
  return an_enemy; // A COPY of an_enemy is returned
}

enemy = create_super_enemy();

// Construct one object based on another (existing)
// We want to create another object called another hero based on hero.
Player hero {"Hero", 100, 100};

Player another_hero {hero}; // A copy of hero is made using copy constructor

//----  Declaring Copy constructor

Account::Account(const Account &source);

//------ Implementing the Player class Copy constructor
// Notice that we're initializing the newly created object attributes in the initializer list based on the source object's attributes.
Player::Player (const Player &source)
  : name{source.name},
    health{source.health},
    xp{source.xp} {
      // any code we write in the constructor body will be executed immediately after the new object is initialized.
}

// Implementing the copy constructor for Account class
Account::Account (const Account &source)
  : name{source.name},
    balance {source.balance} {
}
