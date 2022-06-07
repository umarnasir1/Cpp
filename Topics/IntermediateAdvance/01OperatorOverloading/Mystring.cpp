/*
  What is Operator Overloading - Mystring.cpp
*/
#include <cstring>
#include <iostream>
#include "Mystring.h" // including as we are implimenting that class methods.

// No-args constructor
Mystring::Mystring()
  :str{nullptr}{ // setting a single character with the null terminator in it rather than a null pointer.
  str = new char[1]; // creating empty string -  (on HEAP) allocate space for one character.
  *str = '\0'; // assign that address to str so str is pointing to heap (to empty string created in previous line). Then, de-referencing the pointer and putting terminator '\0'
}

// Overloaded Constructor - expects a c-style string
Mystring::Mystring(const char *s) // Mystring a{"Hello"}
  :str{nullptr}{
    if (s==nullptr){ // checking if someone sent a null pointer here, i.e., Mystring a{"Hello"};
      str = new char[1]; // creating empty string
      *str = '\0';
    }
    else {
      str = new char[std::strlen(s)+1]; // allocate strlen(source.str)+1 characters on the HEAP; +1 - we need extra character for terminator; strlen()  defined in cstring
      std::strcpy(str, s); // copying s to str i.e., from object to HEAP - going to copy hellow (to HEAP) and point from str to HEAP
    }
}

// Copy Constructor
Mystring::Mystring(const Mystring &source) // Mystring stooge {larry};
  :str{nullptr}{ //this ptr
    str= new char[std::strlen(source.str)+1]; // allocate space on HEAP - length of source object str (source.str which will be 'Hello'); +1 for null character
    std::strcpy(str, source.str); // copty source.str to str. copying 'larry' on heap and this is pointing to heap
}
// this refers to the object that is being created.
// source is larry here

// Destructor
Mystring::~Mystring(){
  delete[] str; // de-allocating the memory
}

// Display method - displays the string (cstyle string)
void Mystring::display() const {
  std::cout << str << " : " << get_length() << std::endl;
}

// length getter - returns the length of the string
int Mystring::get_length() const { return std::strlen(str); }

// string getter - returns pointer
const char *Mystring::get_str() const { return str; }
