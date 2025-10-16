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

  Can use both Initialization List and Delegating Constructor.

  Type::Type (const Type &source);
  class::constructor (single object passed as a reference and const)

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

class Player{
private:
  std::string name;
  int health;
  int xp;
public:
  // getters
  std::string get_name(){return name;}
  int get_health(){return health;}
  int get_xp(){return xp;}
  // Constructor
  Player(std::string name_val="None", int health_val=0, int xp_val=0); // Default Constructor
  // Copy Constructor - Prototype
  Player(const Player &source); // single object in the parameter list
  // Destructor
  ~Player(){ std::cout<<"Destructor called for: " + name << std::endl; }
};

// Constructor
Player::Player(std::string name_val, int health_val, int xp_val)
  : name{name_val}, health{health_val}, xp{xp_val}{
    std::cout << "Three-args constructor for " + name << std::endl;
}

//------ Implementing the Player class Copy constructor
// Notice that we're initializing the newly created object attributes in the initializer list based on the source object's attributes.
Player::Player (const Player &source)
  : name{source.name}, health{source.health}, xp{source.xp} { // Initializer list ot initialize source object
  //: Player {source.name, source.health, source.xp} {// Delegating constructor- delegate the construction of this object to my constructor so the control will transfer to constructor (line 54)
    // any code we write in the constructor body will be executed immediately after the new object is initialized.
    std::cout << "Copy Constructor - made copy of: " << source.name << std::endl;
}

// function display_player displays the values
// One of the used cases where the copy constructor is called
void display_player(Player p){ // expects player object by value
  // p is a COPY of whatever object (empty in this case) that is passed in  (using the copy constructor) - on the stack
  std::cout << "Name: " << p.get_name() << std::endl;
  std::cout << "Health: " << p.get_health() << std::endl;
  std::cout << "XP: " << p.get_xp() << std::endl;
  // Destructor for p will be called (as p is going out of scope as p is local to this function)
}

// // Return Object by value
// Player create_super_enemy(){ // creates and returns a player object
//   // The Player object and enemy is created in the function and then returned from this function. Since we're returning an enemy by value. A copy of the enemy object is made by the copy constructor.
//   Player an_enemy{"Super Enemy", 1000, 1000};
//   return an_enemy; // A COPY of an_enemy is returned
// }

int main(){
  Player empty;
  display_player(empty); // Pass object to function/method by - value;  When we call this function and pass in empty, the function parameter p will be created and it will be created as a copy of empty, using the copy constructor.
  Player frank {"Frank"};
  Player hero {"Hero",100};
  Player villain {"Villain",100,55};

  // // Return Object by value
  // Player enemy;
  // enemy = create_super_enemy();

  // // Construct one object based on another (existing)
  // // We want to create another object called empty1 based on empty1.
  // Player empty1{"XXXXX", 100, 50};
  // Player my_new_object {empty1}; // initializing by empty1 object i.e., creating a copy of empty1 object. Copy constructor will be called again.

  return 0;
}