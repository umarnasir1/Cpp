/*
  Arithmetic Operators 02
*/

#include <iostream>

int main(){

  int number {5};
  int original_number {number};

  std::cout << "original_number: " << original_number << std::endl;
  std::cout << "number: " << number <<std::endl;

  // Method 1:
  //-- Multiply number by 2 and assign the result back to number
  number = number * 2;

  //-- Add 9 to number and assign the result back to number
  number = number + 9;

  //-- Subtract 3 from number and assign the result back to number
  number = number - 3;

  //-- Divide number by 2 and assign the result back to number
  number = number / 2;

  //-- Subtract the variable original_number from number and assign the result back to number
  number = number - original_number;

  //-- Take the modulus 3 (%) of number and assign it back to number
  number = number % 3;

  std::cout << "Value of number: " << number << std::endl;

  // Method 2:
  //The following is also a valid solution
  // number = ((number * 2 + 9 - 3) / 2 - number) % 3; OR
  // number = ((number * 2 + 9 - 3) / 2 - original_number) % 3;  // number or original_number should work since they will be the same since int original_number {number};

  return 0;
}
