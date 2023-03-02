/*
   Overloading operators as non-member (global) methods

  Mystring.h - class specification
  Mystring.cpp - class definition
  main.cpp

  */
#include <iostream>
#include <vector>
#include "Mystring.h"

int main(){

  Mystring a{"Hello"}; //Overloaded constructor
  a = Mystring{"Hejsan"}; // Overloaded constructor (construct a temporary object-rhs) then move assignment, destructor for destroying temporary object. Mystring {"Hejsan"} is temporary object (as it have no name) - R value; this is assignment not initialization as a already exists. 
  a = "Tja"; // Overloaded constructor then move assignment as right hand side value is R-value and then destructor for destroying temporary object, destructor for a

  // objects
  Mystring empty; // empty Mystring object - no-args constructor
  Mystring larry {"Larry"}; // overloaded constructor used to initialize to string Larry (C-Style string literal. C++ compiler will treat it as a const char * and what is being passed to the constructor is the address of the first character in the null-terminated string literal.)
  Mystring stooge {larry}; // copy constructor as we are initializing using larry object
  Mystring stooges; // no-args constructor 

  empty = stooge; // copy assignment operator 
                  // stooge is an L-value 
  
  empty = "Funny"; // overloaded constructor (construct temporary object), move assignment operator, destuctor for destroying temporary object 
                   // "Funny" is an R-value 

  // displaying objects
  empty.display();
  larry.display();
  stooge.display();
  empty.display(); 

  stooges = "Larry, Moe, and Curly"; // overloaded constructor (construct temporary object), move assignment operator, destuctor for destroying temporary object 
                                     // "Larry, Moe, and Curly" is an R-value 
  stooges.display(); 

  std::vector <Mystring> stooges_vec; 
  stooges_vec.push_back("Larry"); // Overloaded constructor to create 'Larry'; Move constructor to move; destructor to destroy Larry
  stooges_vec.push_back("Moe"); // Overloaded constructor to create 'Moe'; Move constructor to move; destructor to destroy Moe
  stooges_vec.push_back("Curly"); // Overloaded constructor to create 'Curly'; Move constructor to move; destructor to destroy Curly

  std::cout << "=== Loop 1 =============================" << std::endl; 
  for (const Mystring &s: stooges_vec)
    s.display(); 
  
  std::cout << "=== Loop 2 =============================" << std::endl; 
  for (Mystring &s: stooges_vec)
    s = "Changed"; // move assignment 
  
  std::cout << "=== Loop 3 =============================" << std::endl; 
  for (const Mystring &s: stooges_vec)
    s.display();

  return 0;
}
