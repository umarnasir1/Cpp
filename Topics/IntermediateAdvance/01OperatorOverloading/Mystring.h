/*
  What is Operator Overloading - Mystring.h

  c-style string used so we can play around with
    raw pointers a little bit more,
    understand the copy constructor,
    understand the move constructor,
    understand the assignment operators.
*/
#ifndef _MYSTRING_H_
#define _MYSTRING_H_

//---- Mystrng class
// declaration
class Mystring { // models a string and will implement it behind the scenes using a raw c-style pointer.
private:
  char *str; // pointer to a char[] that holds a C-style string
public:
  Mystring(); // no-args constructor
  Mystring (const char *s); // constructor that expects a c-style string - Overloaded constructor
  Mystring (const Mystring &source); // copy constructor
  ~Mystring(); // destructor
  void display() const; // displays the contents string (string and its length)
  int get_length() const; // getter - returns current length of the string
  const char *get_str() const; // getter - returns pointer to the string
};

#endif // _MYSTRING_H_

// When is a copy constructor get called ?
// (1)copy an existing object and construct a new object from it.
// (2)gets called if you pass an object by value to a function
