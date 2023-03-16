/*
  Overloading operators as non-member (global) methods

  Mystring.h - class specification
  Mystring.cpp - class definition
  main.cpp
    Test cases for Overloading binary operators as non-member functions
      Equal operator == for comparision 
      + operator for concatination
    Test cases for Overloading unary - operator to make string lower case
  */
#include <iostream>
#include "Mystring.h"

int main(){

  // operator -
  Mystring larry {"Larry"}; 
  larry.display(); // Larry 

  larry = -larry; // operator-(larry)
  larry.display(); // larry 

  // operator ==
  std::cout << std::boolalpha << std::endl;
  Mystring moe{"Moe"};  
  Mystring stooge = larry; 

  std::cout << (larry==moe) << std::endl; // false
  std::cout << (larry==stooge) << std::endl; // true

  // operator + 
  Mystring stooges { " is one of the three stooges"}; 

  Mystring result = larry + stooges;  // operator+(larry, stooges); 
  result.display(); // larry is one of the three stooges

  result = moe + " is also a stooge"; // operator+(moe, " is also a stooge"); 
  result.display(); // Moe is also a stooge 

  result = "Moe" +  stooges; // OK with non-member functions. Either one of both arguments can be of Mystring type.
  result.display(); // Moe is one of the three stooges

  Mystring two_stooges = moe + " " + "Larry";     
  two_stooges.display(); // Moe Larry
  
  Mystring three_stooges = moe + " " + larry + " " +  "Curly";
  three_stooges.display(); // Moe larry Curly  

  // result = "Moe" + "Larry"; // wont work in case of two string literals.  

  return 0;
}
