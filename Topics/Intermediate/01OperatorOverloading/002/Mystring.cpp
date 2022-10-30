/*
  What is Operator Overloading - Mystring.cpp

  Mystring.h - class specification
  Mystring.cpp - class definition
  main.cpp
*/
#include <cstring>
#include <iostream>
#include "Mystring.h" // including as we are implimenting that class methods.

// No-args constructor
// if we create an empty object, we could simply set that pointer to null pointer but here we are setting an 
// empty string to an empty string i.e., a single character with the null terminator in it rather than a null pointer
Mystring::Mystring() // Mystring a;
  :str{nullptr}{ 
  // setting a single character with the null terminator in it rather than a null pointer.
  str = new char[1]; // creating empty string - allocate space for one character on the HEAP. (OBS! object is created on STACK) - assign that address of that created space (for one character) to str so str is pointing to heap as str is a pointer (to empty string/null ptr).
  *str = '\0'; // Then, de-referencing the pointer and putting terminator '\0'
}

// Overloaded Constructor - expects a c-style string
Mystring::Mystring(const char *s) // Mystring a{"Hello"}
  :str{nullptr}{ // setting strs primary value
    if (s==nullptr){ // checking if someone sent a null pointer here (instead of passing "Hello"), i.e., Mystring a{"Hello"};
      str = new char[1]; // creating empty string
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

// Overloading the copy assignment operator (deep copy)
//
// In this case, we only have a single raw pointer.
// If our class has multiple raw pointers, then don't forget to deep copy each
// of them.

// the object on lhs of assignment statement is refered as this pointer
// rhs: the object passed into the method 

// s2 = s1; s2.operator=(s1) // calls in backend.  
// Since we're assigning the right-hand side object to the left-hand 
// side object, we must make a deep copy of the right-hand side object's 
// attributes and copy them over to the left-hand side object.

// Copy assignment
// what does this mean semantically? 
// the lhs object (this object) will be overwritten. so 
// 1. We need to de-allocate anything it refers to on the heap.
// 2. We have to allocate space in the LHS object for the RHS object data. 
// 3. Copy the data over to the LHS from RHS. 
Mystring &Mystring::operator=(const Mystring &rhs){
    std::cout << "Copy assignment" << std::endl;
    // overloading the copy assignment operator - steps for deep copy
    if (this == &rhs) // checking for self assignment p1=p1; 
    // we can check for self assignment by checking the address of the LHS
    // object which is in the pointer this and comparing it to the address of 
    // the right hand object. 
    // this is pointer to current object and pointer holds address.
    // If they're the same, then we really don't want to do anything and we 
    //  just return de-reference this, which is the LHS object.
        return *this; // return current object 
        // if we dont de-reference, then it will be a pointer and as per 
        // function definition, it is expecting address 
    
    // Step 1: De-allocating storage 
    // if we dont have self assignment, then we need to de-allocate storage for
    // this string as 
    // this object is the one that is being copied into, so it may be pointing 
    // to something (that str attribute may be pointing to a string (on Heap))
    // Actually, it is pointing to a string (even if it is just an empty string.
    // We need to de-allocate the storage. 
    // Otherwise when we copy the new data over,
    // we'll orphan this memory and end up with a memory leak.
    delete [] str; // OR delete[] this->str; 
    // Step 2: Allocate storage for deep copy on the HEAP
    // Now the LHS object is ready to be assigned from the data from 
    // the RHS object, but we haven't yet allocated storage on the heap 
    // for the deep copy. So, we need to allocate enough storage on the heap,
    // i.e., the size of the string in the RHS object + 1 (string terminator)
    str = new char [std::strlen(rhs.str) + 1]; // rhs.str as there is str in lhs(this) also
    // Step 3: Perform the copy 
    // We can perform the copy by copying over one character at a time
    // until we see the null character.
    // As we are using C-style string, we will use std::strcpy, which copies
    // from RHS object to LHS object.
    std::strcpy(str, rhs.str); // std::strcpy(this->str, rhs.str);

    // return LHS object to allow chain assignment
    return *this;  // s1 = s2 = s3; 
}

// Display method - displays the string (cstyle string) & length separated by a :
void Mystring::display() const {
  std::cout << str << " : " << get_length() << std::endl;
}

// getters
// length getter - returns the length of the string
int Mystring::get_length() const { return std::strlen(str); } // length of the string is beging determining every time dynamically  as we are asking what the string length is.

// string getter - returns pointer as const
const char *Mystring::get_str() const { return str; }
