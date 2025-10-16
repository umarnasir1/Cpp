/*
  Implementing Member Methods
    Separating Specification from Implementation - main.cpp
    (140.Implemnting Member Methods 14.45)

  ImplementingMemberMethods.cpp -- the main program driver which includes “Account.h”
  Account.cpp -- the Account implementation which also includes “Account.h”
  Account.h -- the Account specification (Interface)
*/
#include<iostream>
#include "Account.h"

int main(){

  Account bjarne_account;

  bjarne_account.set_name("Bjarne's Account");  // bjarne_account.name = "Bjarne's account"; // compiler error as name is private
  bjarne_account.set_balance(1000.0); // bjarne_account.balance = 1000.0; // compiler error as balance is private

  if (bjarne_account.deposit(200.0)) // if Account1::deposit1 function returns true
    std::cout << "Deposit OK" << std::endl;
  else
    std::cout << "Deposit Not allowed" << std::endl; // for whatever reason

  if (bjarne_account.withdraw(500.0)) // checking if greater than thre required withdraw amount is in account.
    std::cout << "Withdraw OK" << std::endl;
  else
    std::cout << "Not sufficient funds" << std::endl;

  if (bjarne_account.withdraw(1500.0))
    std::cout << "Withdraw OK" << std::endl;
  else
    std::cout << "Not sufficient funds" << std::endl;

  return 0;
}
