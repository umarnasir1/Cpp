/*
  Stream Manipulators - Floating Point
    setprecision
    fixing - right of decimal
    scientific
    showpos; noshowpos

*/
#include<iostream>
#include<iomanip>

int main(){

  double num {1234.5678};
  double num1 {123456789.987654321};

  std::cout << num << std::endl; // 1234.57 as precision is 6 and rounding
  std::cout << num1 << std::endl; // 1.23457e+08 as precision is 6

  // changing to precision 9
  std::cout << std::setprecision(9);
  std::cout << num1 << std::endl; // 123456790 - rounding occurs; no trailing zeros

  // fixing digits to the right of decimal (also 9 as it took that from setprecision; if set presion was not defined then it would be 6 (default))
  std::cout << std::fixed;
  std::cout << num1 << std::endl; // 123456789.987654328

  // setting precison to 3 and also using fixed manipulator - will display precision 3 from the decimal
  std::cout << std::setprecision(3) << std::fixed;
  std::cout << num1 << std::endl; // 123456789.988

  // scientific - set precision to 3 and also use scientific notation
  std::cout << std::setprecision(3) << std::scientific;
  std::cout << num1 << std::endl; // 1.235e+08 will display precion 3 from the decimal as fixed is proceding if there was no fix then it would be 1.23e+008 (1.23 -> 3)

  // scientific uppercase
  std::cout << std::setprecision(3) << std::scientific << std::uppercase;
  std::cout << num1 << std::endl; // 1.235E+08 - precision 3 after decimal and capital E

  // showpos manipulator - displaying the possitive sign
  std::cout << std::setprecision(3) << std::fixed << std::showpos;
  std::cout << num1 << std::endl; // +123456789.988 precision is 3 after decimal point (fixed) and leaving '+'

  std::cout << std::setprecision(6) << std::fixed;
  std::cout << num << std::endl; // +1234.567800

  // setting to default
  std::cout << std::noshowpos;
  // how to removed fixed ?
  double num2 {12.34};
  std::cout << num2 << std::endl;

  // trailing zeros
  // std::cout << num << std::endl;

  return 0;
}
