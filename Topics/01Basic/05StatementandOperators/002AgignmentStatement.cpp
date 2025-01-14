/*
  Agignment Statement
  Simple assignment statement
  Chain assignment statement
*/

#include <iostream>

int main(){

  int num1 {10};
  int num2 {20};

  // num1 = 100; // Assignment statement
  num1 = num2 = 1000; // chaining
  // First, the compiler will process num2 = 1000; and this will return 1000; Then compiler will process num1 = 1000

  std::cout << "num1 is " << num1 << std::endl;
  std::cout << "num2 is " << num2 << std::endl;

  return 0;
}
