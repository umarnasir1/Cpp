/*
  Implementing Member Methods
    Inside the class declaration
    Outside the class declaration
    Separating Specification from Implementation (in next file)
*/
#include<iostream>
#include<string>

using std::string;
using std::cout;
using std::endl;

// Inside the class declaration
//    These public methods set_balance & get_balance are necessary to access the balance since the balance is private.
class Account{
private:
  string name;
  double balance{0.0};
public:
  void set_balance(double bal){ balance = bal;}  // sets the balance to the value passed in by the user.
  double get_balance(){ return balance;} // returns a copy of the account balance
};

// Outside Class declaration
class Account1{
private:
  string name;
  double balance1{0.0};
public: // Method prototype/Declaration
  // As attributes are private, if we try to display or change values, we will get compiler error. So, we will use these public member methods as they will have access to private information.
  void set_balance1 (double bal); // sets balance
  double get_balance1 (); // display the balance
  void set_name1(string n); // sets name
  string get_name1(); // returns copy of name
  bool deposit1(double amount); // account deposit
  bool withdraw1(double amount); // account withdraw
};

// Method definition
void Account1::set_balance1 (double bal){
  balance1 = bal;
}

double Account1::get_balance1(){
  return balance1;
}

void Account1::set_name1(string n){
  name = n;
}

string Account1::get_name1(){
  return name;
}

bool Account1::deposit1(double amount){
  //if verify amount
  balance1 += amount;
  return true;
}

bool Account1::withdraw1(double amount){
  if (balance1-amount >= 0){ // checking if there are sufficient funds.
    balance1 -= amount;
    return true;
  }
  else
    return false;
}

int main(){

  Account1 bjarne_account;

  bjarne_account.set_name1("Bjarne's Account");  // bjarne_account.name = "Bjarne's account"; // compiler error as name is private
  bjarne_account.set_balance1(1000.0); // bjarne_account.balance = 1000.0; // compiler error as balance is private

  if (bjarne_account.deposit1(200.0)) // if Account1::deposit1 function returns true
    cout << "Deposit OK" << endl;
  else
    cout << "Deposit Not allowed" << endl; // for whatever reason

  if (bjarne_account.withdraw1(500.0)) // checking if greater than thre required withdraw amount is in account.
    cout << "Withdraw OK" << endl;
  else
    cout << "Not sufficient funds" << endl;

  if (bjarne_account.withdraw1(1500.0))
    cout << "Withdraw OK" << endl;
  else
    cout << "Not sufficient funds" << endl;

  return 0;
}
