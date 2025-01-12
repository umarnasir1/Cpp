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

int main(){

  int scores [] {100, 95, 98};
  std::cout << scores << std::endl; // 0x7ffee2a1377c - The value of an array name is the address of the first element in the array
  std::cout << *scores << std::endl; // 100 -  scores is an array, how can we dereference that? Scores is the address of the first array element. So if we go to that address, which is what dereferencing is, we get the element at that location.

  int *score_ptr {scores}; // value of score point is same as scores.
  std::cout << score_ptr << std::endl; // 0x7ffee2a1377c
  std::cout << *score_ptr << std::endl; // 100

  std::cout << "\nArray Subscript Notation ......................................\n";
  std::cout << scores[0] << std::endl; // 100 - subscript 0 i.e., 0 integer away from starting location
  std::cout << scores[1] << std::endl; // 95 - subscript 1 i.e., 1 integer away from starting location
  std::cout << scores[2] << std::endl; // 98

  // We can use an array name and a pointer name interchangeably and we can use array subscripting on a pointer.
  // C++ doesn't really have true arrays, and that arrays are just the address of the first element in a chunk of memory.
  std::cout << "\nPointer Subscript Notation .....................................\n";
  std::cout << score_ptr[0] << std::endl; // 100 - subscript 0 i.e., 0 integer away from starting location
  std::cout << score_ptr[1] << std::endl; // 95
  std::cout << score_ptr[2] << std::endl; // 98
  std::cout << std::endl;

  // we can addd offset to the pointer variable and we can point to any array element.
  std::cout << (score_ptr + 1) << std::endl; // 0x7ffeeebbb780 - value of score_ptr have incresed by 4 (bytes) - this is because we are adding the size of 1 integer to the pointer value. (as the pointer holds addresses of integers.)
  std::cout << (score_ptr + 2) << std::endl; // 0x7ffeeebbb784 - increment score_ptr by 8 as it is 2 integers away

  std::cout << "\nPointer Offset Notation .....................................\n";
  // dereference the pointer to get to integer
  std::cout << *score_ptr << std::endl; // 100
  std::cout << *(score_ptr + 1) << std::endl; // 95 - score_ptr+1 - what score_ptr is pointing to +1 (int)
  std::cout << *(score_ptr + 2) << std::endl; // 98
  //
  std::cout << "\nArray Offset Notation .....................................\n";
  std::cout << *scores << std::endl; // 100  - scores - array name. i.e., addres of the first element in the array - derefferenced
  std::cout << *(scores + 1) << std::endl; // *(socres+1) - int - *(scores+4bytes)
  std::cout << *(scores + 2) << std::endl;

  return 0;
}
