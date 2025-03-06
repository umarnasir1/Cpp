/*
  Arrays
  These are C++ Raw Arrays 

  Since C++11 the STL has std::array which is a template-based array class.
    Usage: When we know exactly what we have e.g., we know that we have 10 integers, or 20 integers or 5 strings. 
      (In this case, the vector might be overkill, and it could be a little less efficient. In a case like that, we really want to 
      use std::array. E.g., 12 months in a year, that will not change so in this case we will use std::array).
    OBS!! In modern C++, it is recommended to to use std::array instead of raw arrays.
    supports algorithms, iterators
*/

#include <iostream>
#include <string>

int main(){

  // Array Declaration & Initialization

  int test_scores [] {100, 95, 99, 87, 88};

  int high_score_per_level [10] {3, 5}; // initialize first two elements to 3,5 and remaining to 0 (if we put less initilizers)

  const int days_in_year {365};
  double hi_tempratures [days_in_year] {0}; // initilize all to zero

  int test_scores1 [5] {}; // initilize all to zero

  int another_arry [] {1,2,3,4,5}; // size automatically calculated by compiler based on the # of elements in the initializer list.
  
  // objects
  // std::string accounts []{frank_account, jim_account}; //in case of objects


  // Illegal declaration
  // int numbers [0]; // is not legal since it declares an array with no size
  // double 5numbers[5]; is not legal since the array name is not a legal identifier (identifiers cannot start with a digit)

  //test_scores[0]; also called array subscripting.

  /************************************************************
  Accessing arrays elements
  *************************************************************/

  // Example:1

  // Always initialize arrays - or they will contain unknown values
  // if not initilized there can be junk values. e.g output

  // First score at index 0: 0
  // Second score at index 0: 0
  // Third score at index 0: 0
  // Fourth score at index 0: 0
  // Fifth score at index 0: -402196424

  // after initialization
  std::cout << "First score at index 0: " << test_scores[0] << std::endl;
  std::cout << "Second score at index 1: " << test_scores[1] << std::endl;
  std::cout << "Third score at index 2: " << test_scores[2] << std::endl;
  std::cout << "Fourth score at index 3: " << test_scores[3] << std::endl;
  std::cout << "Fifth score at index 4: " << test_scores[4] << std::endl;

  std::cout << "\nEnter 5 test scores: ";
  std::cin >> test_scores[0];
  std::cin >> test_scores[1];
  std::cin >> test_scores[2];
  std::cin >> test_scores[3];
  std::cin >> test_scores[4];

  std::cout << "First score at index 1: " << test_scores[0] << std::endl;
  std::cout << "Second score at index 2: " << test_scores[1] << std::endl;
  std::cout << "Third score at index 3: " << test_scores[2] << std::endl;
  std::cout << "Fourth score at index 4: " << test_scores[3] << std::endl;
  std::cout << "Fifth score at index 5: " << test_scores[4] << std::endl;  // test_scores[-1] will give warning.


  /************************************************************
  Storing Values & Changing the contents of array elements
  **************************************************************/

  // Example:2
  double hi_temps [] {90.1, 89.8, 77.5, 81.6};

  std::cout << "The first high temprature is now : " << hi_temps[0] << std::endl;

  hi_temps[0] = 100.7; // set the first element in hi_temps to 100.7

  std::cout << "The first high temprature is now : " <<hi_temps[0] << std::endl;

  std::cout << hi_temps[5] << std::endl; // Garbage value - when using array [] indexing the compiler does not do bounds checking, that is one of the advantages of vectors. There will be warning but no error.

  // Example: 3
  // char
  // C++ treats arrays of characters and char *  as strings. So when we display an array of characters or a char *  pointer name, C++ will assume it is a string and display every character until it sees the NULL character.
  // This behavior is because C++ is backward compatible with C and that's how C works.
  char array[4] {'a', 'b', 'c'};
  std::cout << array << std::endl; // abc
  std::cout << *array << std::endl; // a

  // address of character array
  std::cout << &array << std::endl;// 0x7ff7ba6f0988 - address of the 4-character array, which is the same address as the first character of the array.

  int intarray[3] {1,2,3};
  std::cout << intarray << std::endl; // 0x7ff7ba6f0994- address of first element
  std::cout << *intarray << std::endl; // 1

  return 0;
}
