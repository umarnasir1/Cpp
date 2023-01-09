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

// Class - Accocunt
class Account {
  // attributes
  std::string name; // name of account
  double balance; // account balance

  // methods
  bool withdraw (double amount); // expects the amount amount to withdraw and returns a boolean indicating success.
  bool deposit (double amount); // expects amount to deposit and returns a Boolean indicating success.
};

int main(){
  /* ANALOGY -OBJECTS
  We know that ints and doubles are primitive types in c++. They're not classes, but this analogy will help make a point

  Two integers, high_score and low_score are defined. This tells us what the valid values are for those variables (int), and it also tells us the operations we can perform on those variables, for example, addition, subtraction, multiplication and so forth. Notice that low score and high score are instances of integer. They each have a value, and they each have an identity.

  Again, integers are not classes. But just for a moment, think of int as the class and low score and high score as objects created from the int class.
  
  int high_score;
  int low_score;
  */

  // // Account Class *******************************************************************************
  /*
  Let's assume that we've already written the account class, and it's a true c++ class.
  Notice the syntax and how similar it is to the syntax for the integers above i.e., it's the same way we create primitive types.
  Account is a user-defined type., So Frank account and Jim account are instances of the account class, they are objects.
  Each of these objects has an identity and values associated with them, just like high_score and low_score did.
  */
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
  }