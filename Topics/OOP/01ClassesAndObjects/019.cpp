/*
  Using const with classes

  What happens when we call member methods on a const object.
    We weill get compiler error when we will pass areference to a const object.
    Solution: We need to tell the compiler that specific methods will not modify the object.
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
  std::string get_name(){return name;}; //  const; // const correctness - We need to tell the compiler that specific methods will not modify the object. Now, the compiler will not only allow this method to be called on const objects, it will also produce a compiler error if you try to modify any of the object attributes in the method.
  // we will get compiler error if we write code in the body of get_namethat modifies the object as get_name is a const member function.
  void set_name(std::string name_val){name=name_val;}
  // Overloaded Constructors
  Player();
  Player(std::string name_val);
  Player(std::string name_val, int health_val, int xp_val);
};

Player::Player()
  :Player {"None", 0, 0}{ // delegating to Player (three ags constructor) i
}

Player::Player(std::string name_val) // delegating to Player (three ags constructor) i
  :Player {name_val, 0, 0}{ // check this
}

Player::Player(std::string name_val, int health_val, int xp_val)
  :name{name_val}, health{health_val}, xp{xp_val}{ // initializer list
}

// What happens when we call member methods on a const object ?
// setter object method which change object
// ERROR - since the object is declared constant. Here we are not modifying the const object. We are simply getting a copy of its name for display. REASON: The compiler assumes that the get name function could potentially change the object,

// void display_player_name (const Player &p){ // expects a reference to a const object.
//   cout << p.get_name() << endl;
// }
//
// display_player_name(villain); // ERROR (if std::string get_name())- get_name could potentially change the object. The compiler is being very careful not to allow a const object to lose its constness.
//
// // const correctness
// villian.set_name("Nice guy"); // Error - as set_name is not a const function
// cout << villian.get_name() << endl // OK


int main(){

  const Player villian {"Villain", 100, 55}; // villain is const object so its attributes cannot be change/modified.
  Player hero {"Hero", 100, 15};

  return 0;
}
