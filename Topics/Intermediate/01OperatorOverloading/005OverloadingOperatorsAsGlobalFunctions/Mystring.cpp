/*
  Mystring.cpp
  Overloading operators as non-member (global) methods

  Often declared as friend functions in the class declaration (we will directly access the private attribute str in that case).
  if declared as a friend of Mystring can access private str attribute 
  Otherwise we must use getter methods. 
  

  operator- (unary negation operator)
  operator== (binary equality operator)


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

// Overloaded Constructor - expects a c-style string; creating object
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

// Move constructor
Mystring::Mystring(Mystring &&source)
  :str{source.str}{ // stealing the pointer - stealing the source objects pointer and moving it to str.
    source.str = nullptr; // nulling out the value of source object pointer. 
    std::cout << "Move constructor used" << std::endl; 
  }

// Destructor
Mystring::~Mystring(){
  if (str == nullptr)
    std::cout << "Calling destructor for Mystring: nullptr" << std::endl; 
  else 
    std::cout << "Calling destructor for Mystring: " << str << std::endl; 
  delete [] str; // de-allocating the memory
}

// Copy assignment 
Mystring &Mystring::operator=(const Mystring &rhs){
  std::cout << "Using copy assignment" << std::endl; 

  if (this == &rhs) 
    return *this; 
  delete [] str; // delete current object
  str = new char[std::strlen(rhs.str)+1]; // allocating space for rhs object in lhs
  std::strcpy(str, rhs.str); // copying rhs to lhs
  return *this; 
}

//Move assignment
// Steps 
// 1. Deallocate current storage
// 2. Steal the pointer
// 3. null out the rhs object
Mystring &Mystring::operator=(Mystring &&rhs){
  std::cout << "Using move assignment" << std::endl; 

  if (this == &rhs)// checking for self assignment.
    return *this; // return current object 
  delete [] str; // dellocate current storage since we are overwriting it and we dont want a memory leak
  str = rhs.str; // steal the pointer from rhs object and assign it to this-> str / copy of a pointer variable. (NO deep copy here)
  rhs.str = nullptr; // null out the rhs object  
  return *this; // returning LHS Object (current object)
}

// overloading unary - to make string lowercase
Mystring operator- (const Mystring &obj){
  char *buff = new char[std::strlen(obj.str)+1]; // allocate storage on the HEAP; char as its c-style string
  std::strcpy(buff, obj.str); // copy object string data
  for (size_t i{0}; i<std::strlen(buff); i++) // loop through and make the copied string all lowercase.
    buff[i] = std::tolower(buff[i]); 
  Mystring temp {buff}; // creating new object using the lowercase string as the initializer
  delete [] buff; // de-allocate the temporary storage
  return temp; // returing created object
}

// overloading binary == equality operator 
bool operator== (const Mystring &lhs, const Mystring &rhs){
  if (std::strcmp(lhs.str, rhs.str) == 0)
    return true; 
  else
    return false; 
}

// Display method - displays the string (cstyle string) & length separated by a :
void Mystring::display() const {
  std::cout << str << " : " << get_length() << std::endl;
}

// length getter - returns the length of the string
int Mystring::get_length() const { return std::strlen(str); } // length of the string is beging determining every time dynamically  as we are asking what the string length is.

// string getter - returns pointer as const
const char *Mystring::get_str() const { return str; }