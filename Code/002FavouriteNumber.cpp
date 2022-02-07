/*
  Create a C++ program that asks the user for their favourite number between 1and 100.
  Then read this number from the console

  Suppose the user enters 24.

  Then display the following to the console:
  Amazing!! That's my favorite number too!
  No really!!, 24 is my favorite number!
*/

#include <iostream>

int main(){
  int favorite_number; // variable declaration
  std::cout << "Enter your favorite number between 1 to 100: ";
  std::cin >> favorite_number;
  std::cout << "Amazing!! " <<favorite_number<<" is my favorite number too" << std::endl; 
  return 0;
}
