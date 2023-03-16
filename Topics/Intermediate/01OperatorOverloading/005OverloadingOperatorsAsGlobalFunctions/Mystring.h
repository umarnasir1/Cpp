/*
  Overloading operators as non-member (global) methods

  Mystring.h - class specification
    Often non-member methods are declared as friend functions in the class declaration (class has to grant friendship) 
    We will directly access the private attribute str in that case, i.e., if declared as a friend of Mystring).
    Otherwise we must use getter methods (Alternate option). 
  Mystring.cpp - class definition
  main.cpp

  Mystring models a string and will implement it behind the scenes using a raw 
  C-style pointer. 
  We are going to add overloaded operators to this basic class.

  Although we have a standard string class, but C-style string used so we can play around 
  with:
    raw pointers a little bit more,
    understand the copy constructor,
    understand the move constructor,
    understand the assignment operators.
      think about copy and move assignment when we overload the assignment operator.
*/ 
#ifndef _MYSTRING_H_
#define _MYSTRING_H_

//---- Mystrng class
// declaration
class Mystring { // models a string and will implement it behind the scenes using a raw c-style pointer.
  // function prototypes - class will grant friendship
  friend bool operator==(const Mystring &lhs, const Mystring &rhs); 
  friend Mystring operator-(const Mystring &obj); 
  friend Mystring operator+(const Mystring &lhs, const Mystring &rhs);
private:
  char *str; // pointer to a char[] that holds a C-style string
public:
  Mystring(); // No-args constructor
  Mystring (const char *s); // Constructor that expects a c-style string (char) - Overloaded constructor
  Mystring (const Mystring &source); // copy constructor
  Mystring (Mystring &&source); // Move constructor
  ~Mystring(); // Destructor

  Mystring &operator=(const Mystring &rhs); // Copy assignmnet 
  Mystring &operator=(Mystring &&rhs); // Move assignment

  void display() const; // displays the contents string (string and its length)
  int get_length() const; // getter - returns current length of the string
  const char *get_str() const; // getter - returns pointer to the string (as a const)
};

#endif // _MYSTRING_H_
