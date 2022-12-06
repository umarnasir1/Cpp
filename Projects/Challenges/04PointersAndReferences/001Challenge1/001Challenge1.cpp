// Pointers&References Challenge

/* Write a C++ function named apply_all that expects two arrays of integers and their sizes and
  dynamically allocates a new array of integers whose size is the product of the 2 array sizes
  
  The function should loop through the second array and multiplies each element across each element of array 1 and store the
  product in the newly created array.
  
  The function should return a pointer to the newly allocated array.
  
  You can also write a print function that expects a pointer to an array of integers and its size and display the
  elements in the array.
    
  For example,
  
  Below is the output from the following code which would be in main:
  
    int array1[] {1,2,3,4,5};
    int array2[] {10,20,30};
    
    cout << "Array 1: " ;
    print(array1,5);
    
    cout << "Array 2: " ;
    print(array2,3);
    
    int *results = apply_all(array1, 5, array2, 3);
    cout << "Result: " ;
    print(results,15);
   
   Output
   ---------------------
   Array 1: [ 1 2 3 4 5 ]
   Array 2: [ 10 20 30 ]
   Result: [ 10 20 30 40 50 20 40 60 80 100 30 60 90 120 150 ]
*/
  
#include <iostream>

// Function Prototypes
void print(const int array[], size_t array_size);
int *apply_all(const int arrayofinteger1 [], size_t size1, const int arrayofinteger2[], size_t size2); 


int main() {
    const size_t array1_size {5};
    const size_t array2_size {3};
    
    int array1[] {1,2,3,4,5};
    int array2[] {10,20,30};
    
    std::cout << "Array 1: ";
    print(array1,array1_size); // array1- address of first integer (in C++)
    
    std::cout << "Array 2: ";
    print(array2,array2_size);

    int *results = apply_all(array1, array1_size, array2, array2_size);
    constexpr size_t results_size {array1_size * array2_size}; // constant expression

    std::cout << "Result: ";
    print(results, results_size);

    delete [] results; // free up the storage on the HEAP
    std::cout << std::endl;

    return 0;
}

// Function Definition

/*******************************************************************
    The function loops through arr and displays all the integers
    in the array
********************************************************************/

//void print(const int *const arr, size_t array_size) // alternative 
// This function expects:
// arr - constant pointer pointing to constant int
// so we cant change the pointer and what it is pointing to 
//  *const arr and const int arr[] are same as in C++, when array[] is passed in function, its the
// address of first element, and in case of *const int arr, pointer stores and address. 
void print(const int array[], size_t array_size){ // const so that function doesnt modify the array
  std::cout << "[ "; 
  for (size_t i{}; i < array_size; ++i) 
    std::cout << array[i] << " "; // using array subscript notation 
    // pointer offset notation *(arr + i)
  std::cout << "]" << std::endl; 
  return; 
}

/***********************************************************************************
    The function dynamically allocates a new array that is of size = size1 * size2
    Then it loops through each element of arr2 and multiples it across all the
    elements of arr1 and each product is stored in the newly created array
************************************************************************************/

// int *apply_all(const int *const arrayofinteger1, size_t size1, const int *const arrayofinteger2, size_t size2) // alternative 
/*
  This function expects:
      arrayofinteger1 - a pointer to an array of integers
      size1 - the number of integers in arr1
      arrayofinteger2 - a pointer to another array of integers
      size2 - the number of integers in arr2
*/
int *apply_all(const int arrayofinteger1[], size_t size1, const int  arrayofinteger2[], size_t size2){
  // dynamic memory allocation 
  int *array_ptr {nullptr}; 
  array_ptr = new int[size1 * size2]; // allocating size1*size2 integers on the HEAP

  size_t index {}; 
  for (size_t i{}; i < size2; ++i)
    for (size_t j{}; j < size1; ++j){
      array_ptr[index] = *(arrayofinteger2 + i) * *(arrayofinteger1 + j); // pointer offset notation
      // array_ptr[index] = arrayofinteger2[i] * arrayofinteger1[j]; // array subscript notation
      ++index;
    }
  
  return array_ptr; // return address of first element of newly allocated space on the HEAP (so returing a pointer)
} 
