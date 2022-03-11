/*
  The Relationship Between Arrays and Pointers

  int array_name [] {1,2,3,4,5};
  int *pointer_name {array_name};

  Array Subscript Notation
  Pointer Subscript Notation
  Pointer Offset Notation
  Array Offset Notation

*/
#include<iostream>

using std::cout;
using std::endl;

int main(){

  int scores [] {100, 95, 98};
  cout << scores << endl; // 0x7ffee2a1377c - address of first element of array
  cout << *scores << endl; // 100 -  scores is an array, how can we dereference that? Scores is the address of the first array element. So if we go to that address, which is what dereferencing is, we get the element at that location.

  int *score_ptr {scores}; // value of score point is same as scores.
  cout << score_ptr << endl; // 0x7ffee2a1377c
  cout << *score_ptr << endl; // 100

  cout << "\nArray Subscript Notation ......................................\n";
  cout << scores[0] << endl; // 100 - subscript 0 i.e., 0 integer away from starting location
  cout << scores[1] << endl; // 95 - subscript 1 i.e., 1 integer away from starting location
  cout << scores[2] << endl; // 98

  // We can use an array name and a pointer name interchangeably and we can use array subscripting on a pointer.
  cout << "\nPointer Subscript Notation .....................................\n";
  cout << score_ptr[0] << endl; // 100 - subscript 0 i.e., 0 integer away from starting location
  cout << score_ptr[1] << endl; // 95
  cout << score_ptr[2] << endl; // 98
  cout << endl; 

  // we can addd offset to the pointer variable and we can point to any array element.
  cout << (score_ptr + 1) << endl; // 0x7ffeeebbb780 - value of score_ptr have incresed by 4 (bytes) - this is because we are adding the size of 1 integer to the pointer value. (as the pointer holds addresses of integers.)
  cout << (score_ptr + 2) << endl; // 0x7ffeeebbb784 - increment score_ptr by 8 as it is 2 integers away

  cout << "\nPointer Offset Notation .....................................\n";
  // dereference the pointer to get to integer
  cout << *score_ptr << endl; // 100
  cout << *(score_ptr + 1) << endl; // 95 - score_ptr+1 - what score_ptr is pointing to +1 (int)
  cout << *(score_ptr + 2) << endl; // 98

  cout << "\nArray Offset Notation .....................................\n";
  cout << *scores << endl; // 100  - scores - array name. i.e., addres of the first element in the array - derefferenced
  cout << *(scores + 1) << endl; // *(socres+1) - int - *(scores+4bytes)
  cout << *(scores + 2) << endl;

  return 0;
}
