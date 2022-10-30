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

  Add the copy assignment operator 
  We will overload it and add it to the class. 

*/
#include <iostream>
#include "Mystring.h"

int main(){
  // objects
  Mystring a {"Hello"}; // overloaded constructor 
    // a object will have a str attribute, which is a pointer. 
    // Hello will be allocated on the heap. 
    // str attribute will be poining to it. 

  Mystring b; // no-args constructor 
    // b object will have a str attribute, which is a pointer. 
    // null character \0 or empty string will be allocated on the heap
    // str attribute will be pointing to it. 

  b = a;  // copy assignment 
          // b.operator=(a); will be called in backend
          // This is assignment as b already exists and is initialized. 
          // 1. Check self assignment (a=a, b=b)
          // 2. Deep copy (on the Heap)
          //      De-allocate what str in b is poining to 
          //      allocate space for strlen(a)+1 on heap
          //      copy a on that space on heap (str of b will be pointing to it)
          // After deep copy, a and b are two different areas in memory. 

  b = "This is a test"; // b.operator=("This is a test"); in backend
                        // Assignment (b already exists)
                        // a little different than previous case as we dont have
                        //  an operator = that expects a character pointer/
                        //  C-style string. So, 
                        //  we need to construct a temporary object using the 
                        //  overloaded constructor and then assign the temporary
                        //  object to b. (temporary object will then be destroyed
                        //  along with constructors for other objects (a and b in this
                        //  case.) order of destructor: temporary object, b, a)

  // Mystring empty; // empty Mystring object - no-args constructor
  // Mystring larry {"Larry"}; // overloaded constructor used to initialize to string Larry (C-Style string literal. C++ compiler will treat it as a const char * and what is being passed to the constructor is the address of the first character in the null-terminated string literal.)
  // Mystring stooge {larry}; // copy constructor as we are initializing using larry object

  // // displaying objects
  // empty.display();
  // larry.display();
  // stooge.display();

  return 0;
}
