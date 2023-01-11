/*
Implementing Member Methods
  Separating Specification from Implementation - Account.h
  include guard
  #pragma once
*/

#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_
#include<string>

class Account{
private:
  // attributes
  std::string name;
  double balance{0.0};
public:
  // methods
  void set_balance(double bal);
  double get_balance();
  void set_name(std::string n);
  std::string get_name();
  bool deposit(double amount);
  bool withdraw(double amount);
};

#endif


// #pragma once
//
// class Account2{
// private:
//   double balance;
// public:
//   void set_balance2(double bal);
//   double get_balance2();
// };
