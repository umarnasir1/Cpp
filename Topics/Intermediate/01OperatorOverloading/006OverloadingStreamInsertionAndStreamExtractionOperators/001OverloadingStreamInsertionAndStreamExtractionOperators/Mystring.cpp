/*
  Overloading stream insertion (<<) and extraction operators (>>)
  
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

// Display method - displays the string (cstyle string) & length separated by a :
void Mystring::display() const {
  std::cout << str << " : " << get_length() << std::endl;
}

// length getter - returns the length of the string
int Mystring::get_length() const { return std::strlen(str); } // length of the string is beging determining every time dynamically  as we are asking what the string length is.

// string getter - returns pointer as const
const char *Mystring::get_str() const { return str; }

// Overloading stream insertion operator (<<)
std::ostream &operator<<(std::ostream &os, const Mystring &rhs){
    os << rhs.str; // if friend function (we will havve access to all private data members.) -  inserting data in output stream
    // os << obj.get_str(); // if not friend function - using getters to access private members
    return os; // returning output stream reference.
}

// Overloading stream extraction operator (>>)
// depending on the data we want to read, we can get the data from the input stream and either store 
// it locally or store it directly in the object.
std::istream &operator>>(std::istream &in, Mystring &rhs){
    char *buff = new char[1000]; // allocating array of characters dynamically on the HEAP to store string from the input stream
    in >> buff; // getting/extracting whatever is in the input stream and store it in buffer.
    rhs = Mystring{buff}; 
    // assigning a temporary Mystring object, which is initialized with our buff variable, assign it back to the object that was passed in. If we have copy or move assignment - in case of both, it will use move assignment. 
    delete [] buff; // deleting temporary storage
    return in; // return a reference to the istream so we can  keep inserting (chain assign)
}

// Example .......
// For Example, We create a test object;
//  Mystring test;
// Then we ask the user for a name:
//  std::cout << "Enter a name: ";
// Now with our overloaded extraction operator >> we can now do this:
// std::cin >> test; // test is a Mystring rhs.
// Lets say the user enters: "Testing" and Presses Enter.
// Once this line executes and our user presses Enter, control gets shifted to the overloaded extraction operator>>() function.
// We enter the function:
// We have:
//  in = "";
//  rhs.str = "";
// Now we execute:
//  char *buff = new char[1000];
// Now we have :
//  in = "";
//  rhs.str = "";
//  *buff = uninitialized pointer of 1000 characters;
// Then we execute this line:
//  in >> buff; 
// Now our extraction operator>> gets the input from earlier "Testing" and places it into buff which now gives us:
//  in = "Testing";
//  rhs.str = "";
//  *buff = "Testing";
// Then we assign a temporary Mystring rhs initialized with the value of buff to our passed in test obj:
//  rhs = Mystring{buff};
// Now since we are done with buff and its dynamically allocated we must delete it using:
//  delete [] buff; 
// Now we have:
//  in = "Testing";
//  rhs.str = "Testing";
// And finally we return our std::istream object(in) by reference if any more >> extractions are to take place. If we have chained any extractions.
//  return in;

// End - Example

// // regular functions - not member functions 
// // overloading binary == equality operator 
// bool operator==(const Mystring &lhs, const Mystring &rhs){
//   return (std::strcmp(lhs.str, rhs.str) == 0); 
//   // if (std::strcmp(lhs.str, rhs.str) == 0) // comparing both strings 
//   //   return true; 
//   // else
//   //   return false; 
// }

// // overloading unary - to make string lowercase
// Mystring operator-(const Mystring &obj){
//   char *buff = new char[std::strlen(obj.str)+1]; // allocate storage (array of characters) on the HEAP; char as its c-style string
//   std::strcpy(buff, obj.str); // copy object string data - copies one character a time till it reaches null terminator. 
//   for (size_t i{0}; i<std::strlen(buff); i++) // loop through and make the copied string all lowercase.
//     buff[i] = std::tolower(buff[i]); 
//   Mystring temp {buff}; // creating new object using the lowercase string as the initializer
//   delete [] buff; // de-allocate the temporary storage
//   return temp; // returing created object
// }

// // overloading binary + operator for concatenation of two Mystirng objects. 
// Mystring operator+(const Mystring &lhs, const Mystring &rhs) { // returns Mystring object by value; expects two Mystring objects (rhs and lhs - both constants references as we dont want to modify them) 
//   size_t buff_size = std::strlen(lhs.str) + std::strlen(rhs.str) +1; 
//   char *buff = new char[buff_size]; // c-style string allocation on heap
//   std::strcpy(buff, lhs.str); 
//   std::strcat(buff, rhs.str); 
//   Mystring temp {buff}; // creating new object using the concated string as the initializer
//   delete [] buff; // de-allocating the temporary storage
//   return temp; 
// }