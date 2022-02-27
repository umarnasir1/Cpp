/*
  Character Functions - C-Style Strings

  0 1 2 3 4 5 6 7 8 9  10
  C + +   i s   f u n NULL
*/

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main (){

  char my_name [] {"Frank"}; // declaring C style string
  // C++ compiler will allocate 6 characters for this array since it need to terminate the string with NULL character.

  my_name [5] = 'y'; // error, since the size of the array is fixed. So if we  wanted to add a y to Frank and create Franky, we couldn't without having some potential problems since the new string would not be null terminated. We will not get a compiler error or even a warning as, in this case, my_name index 5 is still within the array bounds.

  // F r a n k \0
  // 0 1 2 3 4 5

  char my_name1 [8] {"Frank"}; // we are explicitly asking the compiler to allocate 8 characters to array so remaining characters will be NULL. In this case, if we want to change the character at index 5, which is that first null character to a lowercase y, it would be just fine since the string now contains Franky and is still null terminated.

  // F r a n k \0 \0 \0
  // 0 1 2 3 4 5  6  7

/*
  In this example, we ask the compiler to allocate an array of eight characters, and we don't initialize them. This could be very problematic because if you use this array as a string, all c-style string functions expect to find a null character. And here there may or may not be one. We really don't know what the data in the array is.

  Well, in this case we start at the first element of the array and we iterate through the array. At every character, we see if it's the null character. If it is, we stop since we reach the end of the string. If it's not, we print the character and then we move to the next character.
*/
  char my_name2 [8];

  cout << my_name2 << endl;

  return 0;
}
