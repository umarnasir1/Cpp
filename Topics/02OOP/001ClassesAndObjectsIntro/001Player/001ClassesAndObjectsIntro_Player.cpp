/*
  Declaring a Class and Creating Objects

  We're using our own user-defined types (classes), and we're using them intuitively like we've used other c++ types (int, double).

  // Declaring a class in C++
  class Class_Name{         // Best practice to capitalize class names for our user-defined classes.
  // declaration(s);        // define the structure and behavior of class
  };

  Where do we create the class?
  If a class is created right inside main(), then its scope will be inside of main(), which means that only main will have access to that class.
  If we would like the entire application to have access of the class, we would declare the class above main().
  OBS!! Better way: Use separate files to declare classes.
*/
#include <iostream>
#include <string>
#include <vector>

// Class - Player
// Eg1.  a class name to player as we might have in a game application.
class Player {
  // attributes or instance variables
  std::string name {"Player"}; // class has a string named name - we can initialize values in class declaration from C++11 onwards, but we can initialize the values of attributes using constructors/initializer lists.
  int health {100}; // players health
  int xp {3}; //experience

  // methods
  // Since c++ supports encapsulation, that means we can also provide methods or functions in the class body that are specific to the player class. In this case, we have two methods:
  // (1) talk which expects a standard string and (2) is dead which returns a Boolean.
  void talk (std::string text_to_say);
  bool is_dead();
};

int main(){
  /* ANALOGY -OBJECTS
  We know that ints and doubles are primitive types in c++. They're not classes, but this analogy will help make a point
  Two integers, high_score and low_score are defined. This tells us what the valid values are for those variables (int), and it also tells us the operations we can perform on those variables, for example, addition, subtraction, multiplication and so forth. Notice that low score and high score are instances of integer. They each have a value, and they each have an identity.
  Again, integers are not classes. But just for a moment, think of int as the class and low score and high score as objects created from the int class.
  
  int high_score;
  int low_score;

  Player frank; // frank is instance of player class
  Player hero; // hero is instance of player class

  // The following lines create a scores object that's an instance of a vector of integers
  // and a name object that's an instance of string.

  // std::vector <int> scores;
  // std::string name;
  */

  // Creating Objects - instances of class - same way we create primitive types.
  Player frank;
  Player hero;

  Player *enemy = new Player(); // creating pointer to object - Here, a pointer to a player object - ememy is declared and that object is dynamically created on the heap using new.
  delete enemy; // When I'm finished using enemy object, its storage has to be freed up using delete.

  // Once we have objects, we can use them like any other variable in C++
  Player players[] {frank, hero}; 

  std::vector <Player> player_vec {frank}; // collection of player object. 
  player_vec.push_back(hero); // pushing back hero

  return 0;
  }