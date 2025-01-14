/*
  Testing for Equality - Equality Operators
*/

#include <iostream>

int main(){

/*
  expr1 == expr2; //evaluate to true if the value of expression 1 is equal to the value of expression2.
  expr1 != expr2; //evaluate to true if the value of expression 1 is not equal to the value of expression2.
  100 == 200; //will always evaluate to False as 100 will never be equal to 200.
  num1 != num2; //evaluates to true if num1 is not equal to num2.

  // Eg. compare num1 and num2, if not equal we store true in result else false.
  bool result {false};

  result = (100 == 50 + 50);

  result = (num1 != num2);

  cout << (num1 == num2) << endl;
  cout << std::boolalpha; // boolean expessions in output statements - to display true or false instead of 1 and 0. using boolalpha stream manipulator. Boolaplha and noboolalpha are located in the standard namespace.
  cout << (num1 == num2) << endl;
  cout << std::noboolalpha; // 0, 1 (if want to go back to the default)
*/

  bool equal_result {false};
  bool not_equal_result {false};


  // comparing integers
  int num1 {}, num2 {};

  std::cout << std::boolalpha; // bool alpha stream operator - to display true or false instead of 1 and 0.

  std::cout << "Enter two integers separated by a space: ";
  std::cin >> num1 >> num2;
  equal_result = (num1 == num2);
  not_equal_result = (num1 != num2);
  std::cout << "Comparision result (equals): " << equal_result << std::endl;
  std::cout << "Comparision result (not equals): " << not_equal_result << std::endl;

  // Comparing characters
  char char1 {}, char2 {};
  std::cout << "\nEnter two characters separated by a space: ";
  std::cin >> char1 >> char2;
  equal_result = (char1 == char2);
  not_equal_result = (char1 != char2);
  std::cout << "Comparision result (equals): " << equal_result << std::endl;
  std::cout << "Comparision result (not equals): " << not_equal_result << std::endl;

  // Comparing doubles
  double double1 {}, double2 {};
  std::cout << "\nEnter two doubles separated by a space: ";
  std::cin >> double1 >> double2;
  equal_result = (double1 == double2);
  not_equal_result = (double1 != double2);
  std::cout << "Comparision result (equals): " << equal_result << std::endl;
  std::cout << "Comparision result (not equals): " << not_equal_result << std::endl;

  /*
    Enter two doubles separated by a space: 12.0 11.999999999999999999999999
    Comparision result (equals): true
    Comparision result (not equals): false

    Explanition: they are not same numbers. But, as far as the computer is concerned, those numbers are equal because the representationthat it is using to store the numbers behind the scenes is equal (as the computer stores floating point numbers as approximations.)

    So, if you're dealing with applications that need this kind of precision, you know scientific application, medical applications, many many safety critical type applications you, would not use these built-in doubles. We would use specific specialized libraries that really help us deal with this.

  */

  // Comparing integer and double - mix mode comparision

  /*
    It's using an operator to compare two different types. It doesn't want to do that. Those types have to be the same. So the 10 will be promoted to a 10.0. And then the comparison happens.

    If we compare 10 and 9.999999999999999999999999, what's going to happen again is the 10 will be promoted to 10.0. 10.0 and 9.999999999999999999999999 as far as the internal representation is concerned are equal.
  */

  std::cout << "\nEnter an integer and a double separated by a space: ";
  std::cin >> num1 >> double1;
  equal_result = ( num1 == double1);
  not_equal_result = ( num1 != double1);
  std::cout << "Comparision result (equals): " << equal_result << std::endl;
  std::cout << "Comparision result (not equals): " << not_equal_result << std::endl;

  return 0;
}
