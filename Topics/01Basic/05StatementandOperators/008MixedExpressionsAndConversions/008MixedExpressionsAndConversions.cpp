/*
  Mixed Expression and Conversion
*/

#include <iostream>

int main(){

  // E.g. 1: the lower operand is promoted to higher
  2 * 5.2; // In order to perform the multiplication, the compiler will convert the lower type (int) to the higher type (float) and then perform the multiplication. So int 2 will be converted to double 2.0 and then perform multiplication.

  // Eg. 2:
  int num {0};
  num = 100.2; // we're assigning a value from a higher type to a lower type. In this case, the compiler demotes the higher type to the lower type, potentially losing information. Many compilers will warn you about the possible loss of precision but not all do.

  // Eg. 3: Explicit Type Casting - static_cast
  // The c++ compiler will try to do automatic coercion when it can. However, as programmers, we can explicitly tell the compiler to cast to a specific type if we wish.

  int total_amount {100};
  int total_number {8};
  double average {0.0};

  average = total_amount / total_number;
  std::cout << average << std::endl; // 12 - since both of these numbers are integers, the compiler will do integer division

  // We could change the type of total amount to double, but we're modeling a running total of integers. So an integer type is more appropriate.
  // The solution is for us to tell the compiler to cast or perform a coercion of total amount from integer to double. Now one of the operands is a double so the compiler will automatically convert the total number to a double and do double division.

  average = static_cast <double> (total_amount) / total_number; // Moder C++
  // average = (double)total_amount/count; Old C++
  std::cout << average << std::endl;


  // E.g 4: Ask the user to enter 3 integers.
  //        Calculate the sum of the integers then calculate the average of three integers.
  //       Display the 3 integers entered the the sum of the 3 integers and the average of the 3 integers.

  std::cout << "\nExample 4" << std::endl;

  int total {}; // we have to add 3 integers so its make sence to keep this variable as int.
  // int num1, num2, num3 {0}; // num3 will be 0 and num1 and num2 will not be initilized
  int num1 {}, num2 {}, num3 {};
  const int count {3};
  double average1 {0.0};

  std::cout << "Enter 3 integers separated by spaces: ";
  std::cin >> num1 >> num2 >> num3;

  total = num1 + num2 + num3;
  average = static_cast <double> (total) / count;

  std::cout << "The 3 numbers were: " << num1 << ", " << num2 << ", " << num3 << "." << std::endl;
  std::cout << "Sum : " << total << std::endl;
  std::cout << "Average:  " << average << std::endl;

  return 0;
}
