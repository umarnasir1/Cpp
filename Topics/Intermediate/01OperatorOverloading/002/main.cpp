/*
  Mystring.h - class specification
  Mystring.cpp - class definition
  main.cpp

  TODO: check test cases and their numbers later

  Extending Mystring class.
    Overloading the Assignment Operator (copy)

  // ---- Using overloaded operators ------------------
  // Let's see what our calculation would look like if we overloaded the addition, multiplication and division operators.

  // Suppose we have a Number class that models any number. Our user-defined number class now looks and feels and behaves like the built in c++ types.
  Number result = (a+b)*(c/d); // Behind the scenes, we're still calling methods or functions.

  Add the copy assignment operator 
  We will overload it and add it to the class. 

*/
#include <iostream>
#include <vector>
#include "Mystring.h"

int main(){
  // Test Cases 
  // #01 
  Mystring a {"Hello"}; // overloaded constructor 
    // a object will have a str attribute, which is a pointer. 
    // Hello will be allocated on the heap. 
    // str attribute will be poining to it. 

  // #02
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

  // #03
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
  
  // #04
  Mystring empty; // empty Mystring object - no-args constructor
  Mystring larry {"Larry"}; // overloaded constructor used to initialize to string Larry (C-Style string literal. C++ compiler will treat it as a const char * and what is being passed to the constructor is the address of the first character in the null-terminated string literal.)
  Mystring stooge {larry}; // copy constructor as we are initializing using larry object
  Mystring stooges; // no-args constructor 

  empty = stooge; // copy assignment operator

  empty.display(); // Larry : 5
  larry.display(); // Larry : 5
  stooge.display(); // Larry : 5
  empty.display(); // Larry : 5 

  stooges = "Larry, Moe, and Curly"; 
  stooges.display(); // Larry, Moe, and Curly: 21 

  std::vector <Mystring> stooges_vec; 
  stooges_vec.push_back("Larry"); 
  stooges_vec.push_back("Moe"); 
  stooges_vec.push_back("Curly"); 

  std::cout << "=== Loop 1 ==============================="  << std::endl;
  for (const Mystring &s: stooges_vec)
    s.display(); // Larry
                 // Moe
                 // Curly  
  
  std::cout << "=== Loop 2 ==============================="  << std::endl;
  for (Mystring &s: stooges_vec)
    s = "Changed"; // copy assignment 
  
  std::cout << "=== Loop 3 ==============================="  << std::endl;
  for (const Mystring &s: stooges_vec)
    s.display(); // Changed
                 // Changed 
                 // Changed

  return 0;
}
