/*
  Write a program that asks the user to enter the following:
  An integer representing the number of comments

  You may assume that the number of cents entered is greater than or equal to zero

  The program should then display how to provide that change to the user.

  In the US:
    1 dollar is 100 cents
    1 quarter is 25 cents
    1 dime is 10 cents
    1 nickel is 5 cents, and
    1 penny is 1 cent
*/

#include <iostream>

int main(){

  const int dollar_value {100}; // 100 cents
  const int quarter_value {25};
  const int dime_value {10};
  const int nickel_value {5};

  int cents {};

  std::cout << "Enter an amount in cents : ";
  std::cin >> cents;

  int dollar {}, quarter {}, dime {}, nickel {}, penny {};

  dollar = cents / dollar_value ;
  quarter = cents % 100 / quarter_value;
  dime = cents % 100 % 25 / dime_value ;
  nickel = cents % 100 % 25 % 10 / nickel_value;
  penny = cents % 100 % 25 % 10 % 5;

  std::cout << "\nYou can provide this change as follows : \n"
      << "dollars : " << dollar << endl
      << "quarters : " << quarter << endl
      << "dimes : " << dime << endl
      << "nickel : " << nickel << endl
      << "pennies : " << penny << endl;

  return 0;
}
