/*
  Relational Operators
*/

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main(){

  // Example 1
  int num1 {}, num2 {};

  cout << std::boolalpha; // to display true and false instead of 1 and 0.
  cout << "Enter 2 integers separated by a space: ";
  cin >> num1 >> num2;

  cout << num1 << " > " << num2 << " : " << (num1 > num2) << endl;
  cout << num1 << " >= " << num2 << " : " << (num1 >= num2) << endl;
  cout << num1 << " < " << num2 << " : " << (num1 < num2) << endl;
  cout << num1 << " <= " << num2 << " : " << (num1 <= num2) << endl;

  // Example 2
  const int lower {10};
  const int upper {20};

  cout << "\nEnter an integer that is greater than " << lower << " : ";
  cin >> num1;
  cout << num1 << " > " << lower << " is " << (num1 > lower) << endl;

  cout << "\nEnter an integer that is less than or equal to " << upper << " : ";
  cin >> num1;
  cout << num1 << " <= " << upper << " is " << (num1 <= upper) << endl;

  return 0;
}
