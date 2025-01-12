/*
  Overflow: its important to keep in mind the limitations when you perform math on variables and then store results in other variables since the results may not fit into the variables you are saving to.

  The error can be corrected if value1 and product are long instead of short.
*/

#include <iostream>

int main (){

  short value1 {30000};
  short value2 {1000};
  short product = value1 * value2;

  std::cout << "The product of " << value1 << " and " << value2 << " is " << product << std::endl; // -15488 as the product dont fit and it overflows

  return 0;
}
