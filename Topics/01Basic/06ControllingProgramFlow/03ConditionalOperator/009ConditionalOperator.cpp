/*
  Conditional Operator ?:

  (cond_expr) ? expr1 : expr2
    conditional expression is evaluated first to a boolean expression
      if cond_expr is true then the value of expr1 is returned
      if cond_expr is false then the value of expr2 is returned
*/

#include <iostream>

int main (){

  int a {10}, b {20};
  int score {92};
  int result {};

  result = (a > b) ? a : b;
  std::cout << "1: " << result << std::endl;

  result = (a < b) ? (b-a) : (a-b);
  std::cout << "2: " << result << std::endl;

  result = (b != 0) ? (a / b) : 0;  // using conditional operator to avoid divide by zero error.
  std::cout << "3: " << result << std::endl;

  std::cout << ((score > 90) ? "Excellent" : "Good") << std::endl;

  std::cout << a << " is " << (( a > b) ? "Greater than " : "Lesser than ") << b << std::endl;

  //-----
  // to know if the entered number is even or odd
  int num {};

  std::cout << "Enter an integer: ";
  std::cin >> num;

  std::cout <<  num << " is "  << ((num % 2 == 0) ? "Even" : "Odd" ) << std::endl;

  // Eg - Compare two integers
  int num1 {}, num2 {};
  std::cout << "Enter two integers separated by a space: ";
  std::cin >> num1 >> num2;

  if (num1 != num2){
    std::cout << "Largest: " << ((num1 > num2) ? num1 : num2 ) << std::endl;
    std::cout << "Smallest: " << ((num1 < num2) ? num1 : num2) << std::endl;
  }
  else
    std::cout << "Both the numbers are same." << std::endl;

  return 0;
}
