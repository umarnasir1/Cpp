/*
  Access Modifiers - Public, Private & Protected.
*/
#include<iostream>
#include<string>

class Player {
private: // only accessable from other members of this class and from friends of this class.
  // attributes
  std::string name {"Bjarne"};
  int health;
  int xp;

public:
  void talk(std::string text_to_say) {std::cout << name << " says: " << text_to_say << std::endl;}
  bool is_dead();
};

class Account {
  //attributes
private:
  std::string name;
  double balance {20000.0};

  // methods
public: //Since these methods are member methods, they have access to the balance and can update its value.
  bool deposit (double amount){balance += amount; std::cout << "Total Balance: " << balance << std::endl;}
  bool withdraw (double amount){balance -= amount; std::cout << " Total Balance: " << balance << std::endl;}
};

int main (){

  // Eg. 01
  Player bjarne;

  // What happend if we try to access a private class member
  // bjarne.name = "Frank"; // Compiler error - name is private and is not accessable from outside the class
  // bjarne.health = 1000; // Compiler error - name is private and is not accessable from outside the class
  // std::cout << bjarne.health << endl; // Compiler error - as we are trying to use the variable from outside the class.
  bjarne.talk("Ready to battle !!");

  // Player *p1  = new int;        // p1 points to an uninitialized integer
  // Player *p2  = new int();      // p2 points to an integer initialized to 0
  Player *enemy = new Player(); // () means initilized to zero here
  // enemy->xp = 100; // Compiler error - xp is private and is not accessable from outside the class
  enemy->talk("C++ - Object Oriented Programming" ); // OK
  delete enemy; 

  // Eg. 02
  Account bjarne_account;

  // bjarne_account.balance = 10000000.0; // compiler error - balance is private
  bjarne_account.deposit(10000.0); // OK
  // bjarne_account.name = "Bjarne's Account"; // compiler error - name is private

  Account *stroustrup_account = new Account(); // () means initilized to zero
  // stroustrup_account -> balance = 10000.0; // Compiler Error - balance is private
  stroustrup_account -> withdraw(10000.0); // OK

  delete stroustrup_account;

  return 0;
}
