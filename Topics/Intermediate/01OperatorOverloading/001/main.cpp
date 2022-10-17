/*
  Mystring.h - class specification
  Mystring.cpp - class definition
  main.cpp

  What is Operator Overloading
  Implementation of Mystring class. (we will extend it later)
    We already have a std::string class but we are doing it ourselves so we can learn 
    how to implement these things.

  In this section, we're going to create our own version of a string class named 
  Mysting and, we want to be able to overload some operators to concatenate mystrings 
  compare them, assign them and so forth.

  We're going to add overloaded operators to this basic class called mystring.

  // ---- Using overloaded operators ------------------
  // Let's see what our calculation would look like if we overloaded the addition, multiplication and division operators.

  // Suppose we have a Number class that models any number. Our user-defined number class now looks and feels and behaves like the built in c++ types.
  Number result = (a+b)*(c/d); // Behind the scenes, we're still calling methods or functions.
*/
#include <iostream>
#include "Mystring.h"

int main(){
  // objects
  Mystring empty; // empty Mystring object - no-args constructor
  Mystring larry {"Larry"}; // overloaded constructor used to initialize to string Larry (C-Style string literal)
  Mystring stooge {larry}; // copy constructor as we are initializing using larry object

  // displaying objects
  empty.display();
  larry.display();
  stooge.display();

  return 0;
}
