/*
  Declaring a Class and Creating Objects
  Accessing Class memebers
    . Operator
    -> Operator

  Where do we create the class?
  If a class is created right inside main(), then its scope will be inside of main(), which means that only main will have access to that class.
  If we would like the entire application to have access of the class, we would declare the class above main().
  OBS!! Better way: Use separate files to declare classes.
*/
#include<iostream>
#include<string>
#include<vector>

using std::string;

// modeling a player depending on the problem we have.
// Class Player will be a blueprint to create player obejcts from & every player object is going to have a string that represent their name, two integers; one representing their health and one their xp.
// it is very powerful, as we are creating our own user-defined types, which are what players are and then we use it just like we can use any other variables.
class Player {
  // attributes - data
  string name {"Player"}; // (This can be initilized using constructors also )
  int health {100}; // 0-100; 0=dead (This can be initilized using constructors also )
  int xp {3}; // Experience (This can be initilized using constructors also )

  // methods - operations or functions - now they are prototypes and they are not defined yet - functions will be implimented them in later. We will get linker error, if we try to call them (without defining them)
  void talk (string); // whatever string we pass into the player, the player will talk it right back out.
  bool is_dead(); // This is a method that returns true or false based on whether the player is dead. And the player might be dead if their health is 0 or whatever other criteria we have for that.
};

class Account {
  // attributes
  string name {"Account"}; //name of the account initilized to account (This can be initilized using constructors also )
  double balance {0.0}; //(This can be initilized using constructors also )

  // Methods
  bool deposit {double}; // method declaration - deposit some amount and return true/false weather it was successful or not.
  bool withdraw {double}; // method declaration - withdraw some amount and return true/false depending on wheather it was successful.
};

int main(){

  // creating player objects - each of player object will have player attribues (name, health, xp) and each can call defined methods in player class.
  Player frank;
  Player hero;

  // array
  // once we have created objects we can treat them like any variables. (like int and double.)
  Player players [] {frank, hero}; // player is an array of player objects (initilized to frank and hero).

  // vector of player
  vector <Player> playe_vec {frank}; // collection of player objects - initialized with frank
  player_vec.push_back{hero}; // adding hero to that vector.

  // create objects on the HEAP
  Player *enemy {nullptr}; // enemy is a pointer to a player initialized to null pointer.
  enemy = new Player; // creating enemy object on the heap (the enemy object which is a player) and storing the address of that object in enemy, which is a pointer.

  delete enemy; // when done delete enemy.

  /////////////////////
  Account bjarne_account;
  Account jim_account;

  /////////
  // Accessing Class memebers
  // dot operator
  bjarne_account.balance; // accessing the balance attribute
  bjarne_account.deposit(1000.00); // deposit 1000 into Frank account - accessing deposit method.

  // if pointer to an object; two alternatives
  Account *bjarne_account = new Account(); // bjarne_account is not an account object, it is a pointer to an account object, which has been dynamically allocated on the heap.

  // Alt1: Dereference the pointer then use the dot operator. () are used as the dot operator has higher precedence then the pointer de-reference operator.
  (*bjarne_account).balance;
  (*bjarne_account).deposit(1000.00);

  // Alt2: Use the member of pointer operator (->)
  bjarne_account->balance;
  bjarne_account->deposit(1000.00);


  return 0;
}
