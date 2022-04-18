/*
  Using const with classes
  const correctness

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
  std::string get_name() const {return name;}; // const correctness - We need to tell the compiler that specific methods will not modify the object. Now, the compiler will not only allow this method to be called on const objects, it will also produce a compiler error if you try to modify any of the object attributes in the method.
  // we will get compiler error if we write code in the body of get_name that modifies the object as get_name is a const member function.
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

// not a member function, its a regular function thats y not declared in class
void display_player_name (const Player &p){ // expects a reference to a const object.
  cout << p.get_name() << endl;
}

int main(){

  const Player villian {"Villain", 100, 55}; // villain is const object so its attributes cannot be change/modified.
  // villian.xp = 1000; // checking the aove statement by making xp public. It should  because xp is public (made private again after checking this), but it won't because villain is constant.

  //cout << villian.get_name() << endl; // Error
  // REASON: The compiler assumes that the get name function could potentially change the object. The compiler cant guarantee so its going to throw an error.

  // What happens when we call member methods on a const object ?
  // villian.set_name("Super guy"); // Error - villian is const; this will never work even when const correct as we don't want to set anything in villain.

  // display_player_name(villain); // ERROR (if std::string get_name())- p.get_name could potentially change the object. The compiler is being very careful not to allow a const object to lose its constness.

  // const correctness
  cout << villian.get_name() << endl;
  display_player_name(villian);

  // Hero Object
  Player hero {"Hero", 100, 15};
  cout << hero.get_name() << endl; // OK
  // display_player_name(hero); // ERROR - hero is not a const; we are passing hero into display_player_namep as a const (const Player &p) that means this function can't change it. Thats the problem. p.get_name could potentially change the object. The compiler is being very careful not to allow a const object to lose its constness.
  // Solution: const correctness
  display_player_name(hero);

  return 0;
}
