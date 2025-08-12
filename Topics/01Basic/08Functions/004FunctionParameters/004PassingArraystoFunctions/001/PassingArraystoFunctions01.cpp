/*
  Passing Arrays To Functions

  void print_arry (int numbers [], size_of_array);

  //void print_arry (int numbers []); The idea is that this function iterates through the array and displays the array values but it will not work as the arrays in C++ are different.
  When we pass array to the function, we need to pass in the size of array also. This is because when we pass array, the array name evaluates to the location of first element of the array.

  // Eg02
  Since we are passing the location of the array, the function can modify the actual array.

  // Eg03
  The scenario in eg 2 (modifying of array values), can be avoided by making the function parameters const (read-only) - within the function body).
  In this case any attempt to modify the array will result in compiler error.
*/

#include <iostream>

// Function prototype
void print_array(int arr[], size_t size);
void zero_array(int arr[], size_t size);
void set_array(int arr[], size_t size, int value);
// void print_array1(const int numbers [], size_t size);

int main (){

  // Eg. 01 - Displaying elements of Array
  std::cout << "------------ Eg. 01 ------------------------------" << std::endl;
  int my_scores[] {100, 98, 90, 86, 84};
  print_array(my_scores, 5);

  // Eg. 02 -Since we are passing the location of the array, the function can modify the actual array.
  std::cout << "\n------------ Eg. 02 ------------------------------" << std::endl;
  zero_array(my_scores, 5); // my_numbers is now zeros!
  print_array(my_scores, 5); // 0 0 0 0 0
  set_array(my_scores, 5, 100);
  print_array(my_scores, 5); // 100 100 100 100 100

//  std::cout << "\n------------ Eg. 03 ------------------------------" << std::endl;
//  int my_numbers1 [] {6,7,8,9,10};
//  print_array1(my_numbers1, 5); // Compiler error as function parameter is const (read-only)

  std::cout << std::endl;
  return 0;
}

// Function Definition
void print_array(int arr[], size_t size){// int arr [] will work too but const is just added to insure that array does not get modified (intentionally or unintentionally). if it trys to modify unitentionally, compiler error - check pring_array1 function. (print_array1 function.)
  for (size_t i{0}; i<size; ++i)
    std::cout << arr[i] << " ";
  std::cout << std::endl;
  // arr[0] = 50000; // just to test this will update the arr[] ... print_array1 written for this puprose
}

void zero_array(int arr[], size_t size){ // yahan pe const hona chiye
  for (size_t i{0}; i<size; ++i)
    arr[i] = 0;
}

// set each array element to a value
void set_array(int arr[], size_t size, int value){
  for (size_t i{0}; i < size; ++i)
    arr[i] = value;
}

// void print_array1(const int numbers [], size_t size){
//   for (size_t i{0}; i < size; ++i)
//     std::cout << numbers[i] << std::endl;
//   numbers[2] = 50000; // compiler error
// }
