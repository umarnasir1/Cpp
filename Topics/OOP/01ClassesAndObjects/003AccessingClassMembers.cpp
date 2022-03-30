/*
Accessing Class Memebers
  . Operator - if we have an object
  -> Operator - if we have pointer to object
*/

#include<iostream>
#include<string>

using std::string;
using std::cout;
using std::endl;

class Player{
public: // By default all of the information in the class is private, i.e., we dont have access to it. Now making it public, i.e., it will be accessable - if private we will get compiler error.
  //attributes
  string name;
  int health;
  int xp;

  //methods
  void talk(string text_to_say) {cout << name << " says " << text_to_say << endl;} // whatever string we pass into the player, the player will talk it right back out.
  bool is_dead();
};

class Account{
public:
  //attributes
  string name;
  double balance;

  //methods
  //These methods should return void since no bool is actually returned in the code. Best practice is to return values from a function that says it will.
  bool deposit(double bal){balance += bal; cout << "Deposited: " << bal <<  endl; } // will return true if successful or false otherwise.
  bool withdraw(double bal){balance -= bal; cout << "Withdrawed: " << bal << endl; } // will return true if successful or false otherwise
};

int main(){

  // Creating Object
  Player bjarne;

  // Setting Attributes
  // dot operator
  bjarne.name = "Bjarne";
  bjarne.health = 100;
  bjarne.xp  = 12;

  // Displaying string attributes
  cout << bjarne.name << endl;

  // Class methos
  bjarne.talk("Hi there"); // Control will be transferred to method talk and it will display the text. So what's neat about this is that since the method - talk is called by the bjarne object, these attributes (name, health, xp) are available. so there is no need to pass the name (it will be used automatically). Scope: the compiler will look for the definition of this variable (name) inside the class first. If it's not there, then it will look for it in global.

  // if pointer to an object
  Player *enemy = new Player;
  // Two ways to do it
  // Alt 1: Dereference the pointer then use the dot operator. () are used as the dot operator has higher precedence then the pointer de-reference operator.
  (*enemy).name = "Enemy";
  (*enemy).health = 100;

  // Alt2: Use the member of pointer operator (->)
  enemy -> xp = 15;

  // method
  enemy -> talk("I will destroy you!");

  delete enemy; // when done delete enemy.

  ////////// Account //////////
  // Creating account object
  Account bjarne_account;

  // Acessing attributes
  bjarne_account.name = "Bjarne's account";
  bjarne_account.balance = 5000.0;

  // method()
  bjarne_account.deposit(1000.0); // deposit 1000 into Bjarnes account - accessing deposit method.
  bjarne_account.withdraw(500.0); // withdraw 500.

  // if pointer to an object; two alternatives
  Account *stroustrup_account = new Account; // stroustrup_account is not an account object, it is a pointer to an account object, which has been dynamically allocated on the heap.
  //
  // Alt1: Dereference the pointer then use the dot operator. () are used as the dot operator has higher precedence then the pointer de-reference operator.
  (*stroustrup_account).balance = 20000.0;
  (*stroustrup_account).deposit(1000.0);
  (*stroustrup_account).withdraw(200.0);

  // Alt2: Use the member of pointer operator (->)
  stroustrup_account->name = "Stroustrup's account";
  stroustrup_account->deposit(2000.0);
  stroustrup_account->withdraw(500.0);

  delete stroustrup_account;

  return 0;
}
