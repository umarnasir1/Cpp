/*
  Conditional Operator ?:

  (cond_expr) ? expr1 : expr2
    conditional expression is evaluated first to a boolean expression
      if cond_expr is true then the value of expr1 is returned
      if cond_expr is false then the value of expr2 is returned

*/

#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int main (){

  int a {10}, b {20};
  int score {92};
  int result {};

  result = (a > b) ? a : b;
  cout << "1: " << result << endl;

  result = (a < b) ? (b-a) : (a-b);
  cout << "2: " << result << endl;

  result = (b != 0) ? (a / b) : 0;  // using conditional operator to avoid divide by zero error.
  cout << "3: " << result << endl;

  cout << ((score > 90) ? "Excellent" : "Good") << endl;

  cout << a << " is " << (( a > b) ? "Greater than " : "Lesser than ") << b << endl;

  //-----
  // to know if the entered number is even or odd
  int num {};

  cout << "Enter an integer: ";
  cin >> num;

  cout <<  num << " is "  << ((num % 2 == 0) ? "Even" : "Odd" ) << endl;

  // Eg - Compare two integers
  int num1 {}, num2 {};
  cout << "Enter two integers separated by a space: ";
  cin >> num1 >> num2;

  if (num1 != num2){
    cout << "Largest: " << ((num1 > num2) ? num1 : num2 ) << endl;
    cout << "Smallest: " << ((num1 < num2) ? num1 : num2) << endl;
  }
  else
    cout << "Both the numbers are same." << endl;

  return 0;
}
