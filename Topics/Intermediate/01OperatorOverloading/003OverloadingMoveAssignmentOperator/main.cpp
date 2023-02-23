/*
  Overloading move constructor and move assignment operator 

  Mystring.h - class specification
  Mystring.cpp - class definition
  main.cpp

  */
#include <iostream>
#include <vector>
#include "Mystring.h"

int main(){

  Mystring a{"Hello"}; //Overloaded constructor
  a = Mystring{"Hejsan"}; // Overloaded constructor then move assignment - Mystring {"Hejsan"} is temporary object (as it have no name) - R value
  a = "Tja"; // Overloaded constructor then move assignment as right hand side value is R-value

  // // objects
  // Mystring empty; // empty Mystring object - no-args constructor
  // Mystring larry {"Larry"}; // overloaded constructor used to initialize to string Larry (C-Style string literal. C++ compiler will treat it as a const char * and what is being passed to the constructor is the address of the first character in the null-terminated string literal.)
  // Mystring stooge {larry}; // copy constructor as we are initializing using larry object

  // // displaying objects
  // empty.display();
  // larry.display();
  // stooge.display();

  return 0;
}
