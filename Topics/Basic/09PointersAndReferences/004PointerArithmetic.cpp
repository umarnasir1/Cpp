/*
  Pointer Arithmetic
*/
#include<iostream>
#include<string>

using std::string;
using std::cout;
using std::endl;
using std::boolalpha;

int main (){

  int scores [] {100, 95, 89, 68, -1};
  int *score_ptr {scores}; // score_ptr is pointing to address of first element of array

  // loop through an array using a pointer and a sentinal value (-1)/terminator
  while (*score_ptr != -1){ // exit loop when value is -1
    cout << *score_ptr << endl; // Dereferencing
    score_ptr++; // increment
  }

  // Another way to do this
  cout << "\n---------------------------------" << endl;
  score_ptr = scores;
  while (*score_ptr != -1)
    cout << *score_ptr++ << endl; // dereference score_ptr and increment it  - *score_ptr++ has 2 operators, * (dereference operator) and ++ (postfix increment operator). Since we have 2 operators with different precedence (precedence of the postfix increment operator is greater than that of the dereference operator), this becomes equivalent to: *(score_ptr++). This means that we are dereferencing score_ptr, but we also know that we are incrementing score_ptr. Since the increment is a post-increment, then the effect of is: 1. *score_ptr 2. increment score_ptr
    // OBS!!
    // int result {0}, value {1000};
    // result = (value++); This will assign 1000 to result then increment - the () doesnt matter
    // cout << result << endl; // 1000


  // Comparing two pointers
  cout << "\n---------------------------------" << endl;
  string s1 {"Bjarne"};
  string s2 {"Bjarne"};
  string s3 {"Stroustrup"};

  string *p1 {&s1};
  string *p2 {&s2};
  string *p3 {&s1};

  cout << boolalpha;
  cout << p1 << " == " << p2 << ": " << (p1 == p2) << endl; // false
  cout << p1 << " == " << p3 << ": " << (p1 == p3) << endl; // true - as same memory location

  // Comparing the data pointers are pointing to
  cout << *p1 << " == " << *p2 << ": " << (*p1 == *p2) << endl; // True
  cout << *p1 << " == " << *p3 << ": " <<  (*p1 == *p3) << endl; // True

  p3 = &s3; // point to Straustrup
  cout << *p1 << " == " << *p3 << ": " << (*p1 == *p3) << endl; // False

  // Eg. using - (substracting two pointers - there are xx characters in between)
  cout << "\n---------------------------------" << endl;
  char name [] {"Bjarne"}; // array of characters B j a r n e \0

  char *char_ptr1 {nullptr};
  char *char_ptr2 {nullptr};

  char_ptr1 = &name[0]; // address of F - &name would be same
  char_ptr2 = &name[3]; // address of r

  cout << "In the string " << name << ", " << *char_ptr2 << " is " << (char_ptr2 - char_ptr1) << " characters away from " << *char_ptr1 << endl;

  // increment
  int_ptr += n;
  int_ptr -= n;

  return 0;
}
