/*
  Arithmetic Operators
  + Addition
  - Substraction
  * Multiplication
  / Division - integer division
  % Modulo or remainder (works only with integers)

  +, -, *, / operators are overloaded to work with multiple types such as int, double, etc.
  % only work with int types.

  The precedence is same as in math (PEMDAS - Paranthesis Exponent Multiplication Division Multiplication Addition Substraction)
*/

#include <iostream>

int main(){

  int num1 {200};
  int num2 {100};

  //cout << num1 << " + " << num2 << " = " << num1 + num2 << endl;

  int result {0};

  // +
  result = num1 + num2;
  std::cout << num1 << " + " << num2 << " = " << result << std::endl;

  // -
  result = num1 - num2;
  std::cout << num1 << " - " << num2 << " = " << result << std::endl;

  // *
  result = num1 * num2;
  std::cout << num1 << " * " << num2 << " = " << result << std::endl;

  // /
  result = num1 / num2;
  std::cout << num1 << " / " << num2 << " = " << result << std::endl;

  result = num2 / num1;
  std::cout << num2 << " / " << num1 << " = " << result << std::endl; // if we were working with doubles then it would be 0,5 but as we are working with int the result will be 0. E.g. below

  // *
  result = num1 % num2;
  std::cout << num1 << " % " << num2 << " = " << result << std::endl;

  num1 = 10;
  num2 = 3;

  result = num1 % num2;
  std::cout << num1 << " % " << num2 << " = " << result << std::endl;

  // operator precedence
  result = num1 * 10 + num2;

  // E.g with float divisition
  std::cout << 5 / 10 << std::endl;

  std::cout << 5.0 / 10.0 << std::endl;

  return 0;
}
