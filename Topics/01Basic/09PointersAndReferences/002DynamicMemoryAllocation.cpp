/*
  Dynamic Memory Allocation/Dealloccation

  Single int, double, strings, vectors, ...   - new, delete
  Array (of int, ... ) - new[], delete[]
*/

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main (){

  // Using new to allocate storage
  int *int_ptr {nullptr}; // this is on stack (in main() function) point to the . this pointer will hold address of integers and now its pointing to nowhhere (as initialized to nullptr)

  int_ptr = new int;  // allocating int at runtime on the heap and allocating storage for an int on the heap and stores address in int_ptr. We are pointing to storage from int_ptr

  cout << int_ptr << endl; // 0x7fe17f4057e0 -  memory location where that integer is on the heap. address that is stored in int_ptr and int_ptr is pointing to it. address of newly created integer.

  cout << *int_ptr << endl; // 41188048 - dereferencing pointer to check value of integer. garbage -  Thats because the integer that was allocated hasent been initialized.

  *int_ptr = 100; // assigning value to that integer on the heap

  cout << *int_ptr << endl; // 100

  // Using delete to deallocate storage
  delete int_ptr; // frees the allocaated storage

  // --------------------------------
  // Array
  // --------------------------------

  // Using new[] to allocate storage for an array dynamically (at run time)

  double *array_ptr {nullptr}; // on stack
  size_t size {0};

  cout << "How big do you want the array? ";
  cin >> size;

  // what happens if our call to allocate the size fails.
  //while (true) // endless loop
  //  array_ptr = new double[size]; // keep allocating - and creating memory leaks leaks all over the place.  Eventually, we will run out of memory and heap

  array_ptr = new double[size]; // allocate array on the heap contiguously in the memory and stores the address of first one in array_ptr and the address of the first element is stored in array_ptr

  cout << array_ptr << endl; // 0x7f82ac504080- address of first double

  // Memory Leak e.g.,
  // array_ptr = nullptr; We nulled out array_ptr. We lost our only way to gt to array_ptr storage

  delete [] array_ptr; // using delete[] to deallocate storage for an array

  // We had that array_ptr the stack. We allocated, let's say, 100 doubles on the heap. array_ptr is pointing to the first one (on the heap).

  return 0;
}
