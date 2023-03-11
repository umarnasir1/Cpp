/*
  Implimenting three overloaded operators as member methods 

  Overload three operators as member methods 
    equality operator == 
      to compare two objects 
    - operator
      lower case 
    + operator 
      concatinate

  Mystring.h - class specification
  Mystring.cpp - class definition
  main.cpp

  */
#include <iostream>
#include <vector>
#include "Mystring.h"

int main(){

  Mystring larry{"Larry"}; 
  Mystring moe{"Moe"}; 

  Mystring stooge {larry}; 
  larry.display(); //Larry
  moe.display(); //Moe

  // == 
  std::cout << std::boolalpha << std::endl; 
  std::cout << (larry == moe) << std::endl; // larry.operator== (moe)
  std::cout << (larry == stooge) << std::endl; 

  // -
  Mystring larry1 {"LARRY"}; 
  Mystring larry2 {-larry1}; //larry1.operator-() 

  larry1.display(); // LARRY 
  larry2.display(); // larry

  // + 
  Mystring stooges {" is one of the three stooges"}; 

  Mystring result {larry + stooges}; // larry.operator+ (stooges)
  result = moe + " is also a stooge"; // moe.operator+ (" is also a stooge") - We can use c-style string on the rhs. This is because we have a mystring constructor that can construct mystring objects from a c-style string (is also a stooge in this case).
  
  // limitation: The object on the left-hand side must be an object of the class (that we are using)
  // result = "Moe" + stooges; // "Moe".operator+ (stooges) // Compiler Error - since the lhs operand is not a Mystring object.

  Mystring two_stooges {moe + " " + "Larry"};
  two_stooges.display(); // Moe Larry      
                                                  
  Mystring three_stooges {moe + " " + larry + " " +  "Curly"};
  three_stooges.display(); //  Moe Larry Curly

  return 0;
}
