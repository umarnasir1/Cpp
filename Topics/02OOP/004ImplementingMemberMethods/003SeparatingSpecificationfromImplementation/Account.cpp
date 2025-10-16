/*
Implementing Member Methods
  Separating Specification from Implementation - Account.cpp
*/
#include "Account.h"

// Method definition
void Account::set_balance(double bal){
  balance = bal;
}

double Account::get_balance(){
  return balance;
}

void Account::set_name(std::string n){
  name = n;
}

std::string Account::get_name(){
  return name;
}

bool Account::deposit(double amount){
  //if verify amount
  balance += amount;
  return true;
}

bool Account::withdraw(double amount){
  if (balance-amount >= 0){ // checking if there are sufficient funds.
    balance -= amount;
    return true;
  }
  else
    return false;
}
