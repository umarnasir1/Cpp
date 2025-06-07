/*
  Relational Operators
*/

#include <iostream>

int main(){

  // Example 1
  int num1 {}, num2 {};

  std::cout << std::boolalpha; // to display true and false instead of 1 and 0.
  std::cout << "Enter 2 integers separated by a space: ";
  std::cin >> num1 >> num2;

  std::cout << num1 << " > " << num2 << " : " << (num1 > num2) << std::endl;
  std::cout << num1 << " >= " << num2 << " : " << (num1 >= num2) << std::endl;
  std::cout << num1 << " < " << num2 << " : " << (num1 < num2) << std::endl;
  std::cout << num1 << " <= " << num2 << " : " << (num1 <= num2) << std::endl;
  std::cout << num1 << " <=> " << num2 << " : " << (num1 <= num2) << std::endl; // -std=c++20 in C++ Compiler Options
  // <=> three-way comparision C++20 - This operator compares two expressions and evaluates to: 
  //  zero if they're equal, 
  //  less than zero if the left-hand side is greater than the right-hand side and 
  //  greater than zero if the right-hand side is greater than the left-hand side

  // Example 2
  const int lower {10};
  const int upper {20};

  std::cout << "\nEnter an integer that is greater than " << lower << " : ";
  std::cin >> num1;
  std::cout << num1 << " > " << lower << " is " << (num1 > lower) << std::endl;

  std::cout << "\nEnter an integer that is less than or equal to " << upper << " : ";
  std::cin >> num1;
  std::cout << num1 << " <= " << upper << " is " << (num1 <= upper) << std::endl;

  return 0;
}
