/*
  Classes & Objects

  We're using our own user-defined types (classes), and we're using them intuitively like we've used other c++ types (int, double).

  // Declaring a class in C++
  class Class_Name{         // Best practice to capitalize class names for our user-defined classes.
  // declaration(s);        // define the structure and behavior of class
  };

*/
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::boolalpha;

int main(){
  /* ANALOGY -OBJECTS
  We know that ints and doubles are primitive types in c++. They're not classes, but this analogy will help make a point

  Two integers, high_score and low_score are defined. This tells us what the valid values are for those variables (int), and it also tells us the operations we can perform on those variables, for example, addition, subtraction, multiplication and so forth. Notice that low score and high score are instances of integer. They each have a value, and they each have an identity.

  Again, integers are not classes. But just for a moment, think of int as the class and low score and high score as objects created from the int class.
  */

  int high_score;
  int low_score;

  /*
  Let's assume that we've already written the account class, and it's a true c++ class.
  Notice the syntax and how similar it is to the syntax for the integers above i.e., it's the same way we create primitive types.
  Account is a user-defined type., So Frank account and Jim account are instances of the account class, they are objects.
  Each of these objects has an identity and values associated with them, just like high_score and low_score did.
  */
  Account frank_account;
  Account jim_account;

  /*
  The following lines create a scores object that's an instance of a vector of integers
  and a name object that's an instance of string.
  */
  std::vector <int> scores;
  std::string name;


  // Class - Player

  // Eg1.  a class name to player as we might have in a game application.
  class Player {
    // attributes or instance variables
    std::string name; // class has a string named name
    int health; // players health
    int xp; //

    // methods
    // Since c++ supports encapsulation, that means we can also provide methods or functions in the class body that are specific to the player class. In this case, we have two methods:
    // (1) talk which expects a standard string and (2) is dead which returns a Boolean.
    void talk (std::string text_to_say);
    bool is_dead();
  };

  // Creating Objects - instances of class - same way we create primitive types.
  Player frank;
  Player hero;

  Player *enemy = new Player(); // creating pointer to object - Here, a pointer to a player object - ememy is declared and that object is dynamically created on the heap using new.
  delete enemy; // When I'm finished using enemy object, its storage has to be freed up using delete.

  // *******************************************************************************
  // E.g 2
  class Account {
    // attributes
    std::string name; // name of account
    double balance; // account balance

    // methods
    bool withdraw (double amount); // expects the amount amount to withdraw and returns a boolean indicating success.
    bool deposit (double amount); // expects amount to deposit and returns a Boolean indicating success.
  };

  // Creating Objects - instances of account class
  Account frank_account;
  Account jim_account;

  // Marys account is a pointer to an  account object that has been allocated dynamically on the heap and then freed up when we are done with it.
  Account *mary_account = new Account();
  delete mary_account;

  // Once we have objects, we can use them like any other variable in C++
  Account accounts [] {frank_account, jim_account}; // creating array of account object and initilize it to Frannks account and Jims account.

  std::vector <Account> accounts1 {frank_account}; // creating a standard vector of account objects and initialize it to Frank's account
  accounts1.push_back(jim_account); // pushing back Jims account.

  return 0;
