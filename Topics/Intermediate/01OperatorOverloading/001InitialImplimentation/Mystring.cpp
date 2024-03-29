/*
  What is Operator Overloading - Mystring.cpp

  Mystring.h - class specification
  Mystring.cpp - class definition
  main.cpp
*/
#include <cstring> // C-style strings
#include <iostream> // output
#include "Mystring.h" // including as we are implimenting that class methods.

// No-args constructor
// if we create an empty object, we could simply set that pointer to null pointer but here we are setting an 
// empty string to an empty string i.e., a single character with the null terminator in it rather than a null pointer
Mystring::Mystring() // Mystring a;
  :str{nullptr}{ // initializing 
  // setting a single character with the null terminator in it rather than just a null pointer.
  str = new char[1]; // creating empty string - allocate space for one character on the HEAP. (OBS! object is created on STACK) - assign that address of that created space (for one character) to str so str is pointing to heap as str is a pointer (to empty string/null ptr).
  *str = '\0'; // Then, de-referencing the pointer and putting terminator '\0'
}

// Overloaded Constructor - expects a c-style string
Mystring::Mystring(const char *s) // Mystring a{"Hello"}
  :str{nullptr}{ // setting strs primary value
    if (s==nullptr){ // checking if someone sent a null pointer here (instead of passing "Hello"), i.e., Mystring a{"Hello"};
      str = new char[1]; // creating empty string on HEAP
      *str = '\0';
    }
    else {
      str = new char[std::strlen(s)+1]; // allocate strlen(source.str)+1 characters on the HEAP; +1 - we need extra character for terminator; strlen()  defined in cstring
      std::strcpy(str, s); // copying s to str i.e., str is pointing to HEAP (Hello\0) as str is pointer (Hello\0 is copied on heap)
    }
}

// Copy Constructor - deep copy
Mystring::Mystring(const Mystring &source) // Mystring a {"Hello"}; Mystring b{b}; this -> refers to object that is being created; source is a object in this e.g.,
  :str{nullptr}{ // new object created ... no name yet (so this pointer is pointing to the new object); we want to copy 'Hello' in this eg in str
    str = new char[std::strlen(source.str)+1]; // allocate space on HEAP - length of source object's str (source.str which will be 'Hello' in this e.g., ); +1 for null character
    std::strcpy(str, source.str); // copy source.str to str. copying 'hello' on heap and str is poining to the heap (as str is pointer)
}

// Destructor
Mystring::~Mystring(){
  delete [] str; // de-allocating the memory
}

// Display method - displays the string (cstyle string) & length separated by a :
void Mystring::display() const {
  std::cout << str << " : " << get_length() << std::endl;
}

// length getter - returns the length of the string
int Mystring::get_length() const { return std::strlen(str); } // length of the string is beging determining every time dynamically  as we are asking what the string length is.

// string getter - returns pointer as const
const char *Mystring::get_str() const { return str; }
