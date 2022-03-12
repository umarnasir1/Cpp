/*
  Const and Pointers
*/
#include<iostream>

int main(){

  // pointers to constant
  int high_score {100}, low_score {65};
  const int *score_ptr {&high_score}; //score_ptris a pointer to an integer constant and is initialized to point to high score.

  // *score_ptr = 86; //ERROR - as constant so value cannot be changed.
  score_ptr = &low_score; // OK - we can assign another address to the pointer and have it point somewhere else.

  // Constant Pointers
  int *const score_ptr1 {&high_score}; // score_ptr1 is  a const pointer to integer.

  *score_ptr1 = 86; // OK
  //score_ptr1 = &low_score; // Error

  // Constant pointers to constants
  const int *const score_ptr2 {&high_score}; // score_ptr2 is a constant pointer to integer constant.

  //*score_ptr2 = 86; // ERROR
  //score_ptr2 = &low_score; // ERROR

  return 0;
}
