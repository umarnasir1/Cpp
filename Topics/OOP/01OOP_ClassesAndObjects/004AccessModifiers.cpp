/*
  Access Modifiers - Public, Private & Protected.
*/
#include<iostream>
#include<string>

using std::string;
using std::cout;
using std::endl;

class Player {
private: // only accessable from other members of this class and from friends of this class.
  // attributes
  string name {"Bjarne"};
  int health;
  int xp;

public:
  void talk(string text_to_say) {cout << name << " says: " << text_to_say << endl;}
  bool is_dead();
};

int main (){

  // Eg. 01 
  Player bjarne;

  // What happend if we try to access a private class member
  // bjarne.name = "Bjarne"; // Compiler error - name is private and is not accessable from outside the class
  // bjarne.health = 1000; // Compiler error - name is private and is not accessable from outside the class
  bjarne.talk("Ready to battle !!");

  // Player *p1  = new int        // p1 points to an uninitialized integer
  // Player *p2  = new int()      // p2 points to an integer initialized to 0
  Player *enemy = new Player(); // () means initilized to zero here
  // enemy->xp = 100; // Compiler error - xp is private and is not accessable from outside the class
  enemy->talk("C++ - Object Oriented Programming" ); // OK

  return 0;
}
