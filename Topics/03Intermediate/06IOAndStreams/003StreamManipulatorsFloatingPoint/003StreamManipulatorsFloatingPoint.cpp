/*
  Stream Manipulators - Floating Point
    std::setprecision(2) - setprecision
    std::fixed - fixing - right of decimal
    std::scientific - scientific
    std::showpos; std::noshowpos
    std::showpoint - trailing zeros; noshowpoint
    std::uppercase

  Reset flags: (use no flags where necessary)
    unsetf
      std::cout << unsetf(std::ios::scientific | std::ios::fixed); binary or  scientific and fixed back to default - setting to general notation
    or
      std::cout << std::resetiosflags(std::ios::showpos); // showpos to default
      std::cout << std::resetiosflags(std::ios::showpoint);
*/
#include<iostream>
#include<iomanip>

int main(){

  double num {1234.5678};
  double num1 {123456789.987654321};
  double num2 {12.34};
  double num3 {1234.0};

  // Default - 6 digits of  precision; no +; no trailing 0s; no uppercase letters in scientific notations
  std::cout << "Defaults ................................\n";
  std::cout << num << std::endl; // 1234.57 as precision is 6 and rounding
  std::cout << num1 << std::endl; // 1.23457e+08 as precision is 6
  std::cout << num2 << std::endl; // 12.34
  std::cout << num3 << std::endl; // 1234

  // 2 significant digits
  std::cout << "Precision - 2 ............................\n";
  std::cout << std::setprecision(2);
  std::cout << num << std::endl; // 1.2e+03
  std::cout << num1 << std::endl; // 1.2e+08
  std::cout << num2 << std::endl; // 12 (rounding off)
  std::cout << num3 << std::endl; // 1.2e+03

  // 5 significant digits
  std::cout << "Precision - 5 ............................\n";
  std::cout << std::setprecision(5);
  std::cout << num << std::endl; // 1234.6
  std::cout << num1 << std::endl; // 1.2346e+08
  std::cout << num2 << std::endl; // 12.34
  std::cout << num3 << std::endl; // 1234

  // changing to precision 9
  std::cout << "Precision - 9 ............................\n";
  std::cout << std::setprecision(9);
  std::cout << num << std::endl; // 1234.5678
  std::cout << num1 << std::endl; // 123456790
  std::cout << num2 << std::endl; // 12.340
  std::cout << num3 << std::endl; // 1234

  // fixing and how fixing is chaging precision.
  // fixing digits to the right of decimal (also 9 as it took that from setprecision; if set presion was not defined then it would be 6 (default))
  std::cout << std::fixed;
  std::cout << num1 << std::endl; // 123456789.987654328

  // setting precison to 3 and also using fixed manipulator - note precision is after the decimal point
  std::cout << std::setprecision(3) << std::fixed;
  std::cout << "Precision - 3 - fixed ............................\n";
  std::cout << num << std::endl; // 1234.568
  std::cout << num1 << std::endl; // 123456789.988
  std::cout << num2 << std::endl; // 12.34
  std::cout << num3 << std::endl; // 1234.000

  // Using precision 3, fixed and scientific notation

  // std::cout << num1 << std::endl; // 1.235e+08 will display precion 3 from the decimal as fixed is proceding if there was no fix then it would be 1.23e+008 (1.23 -> 3)

  std::cout << std::setprecision(3) << std::scientific;
  std::cout << "Precision - 3 - scientific ............................\n";
  std::cout << num << std::endl; // 1.235e+03
  std::cout << num1 << std::endl; // 1.235e+08
  std::cout << num2 << std::endl; // 1.234e+01
  std::cout << num3 << std::endl; // 1.234e+03

  // scientific uppercase
  std::cout << std::setprecision(3) << std::scientific << std::uppercase;
  std::cout << "Precision - 3 - scientific - uppercase ............................\n";
  std::cout << num << std::endl; // 1.235E+03
  std::cout << num1 << std::endl; // 1.235E+08
  std::cout << num2 << std::endl; // 1.234E+01
  std::cout << num3 << std::endl; // 1.234E+03


  // showpos manipulator - displaying the possitive sign
  std::cout << std::setprecision(3) << std::fixed << std::showpos;
  std::cout << "Precision - 3 - fixed - showpos ............................\n";
  std::cout << num << std::endl; // +1234.568
  std::cout << num1 << std::endl; // +123456789.988 precision is 3 after decimal point (fixed) and leaving '+'
  std::cout << num2 << std::endl; // +12.340
  std::cout << num3 << std::endl; // +1234.000

  std::cout << std::setprecision(6) << std::fixed;
  std::cout << num << std::endl; // +1234.567800

  // setting back to defaults
  std::cout.unsetf(std::ios::scientific | std::ios::fixed);
  std::cout << std::resetiosflags(std::ios::showpos);

  // showpoint - trailing zeros
  std::cout << num2 << std::endl; // 12.34 - No trailing zeros (default)
  std::cout << std::showpoint; // trailing 0s based on the level of presion used.
  std::cout << num2 << std::endl; // 12.3400 -  trailing zeros up to presision - 6 default

  std::cout << std::resetiosflags(std::ios::fixed);
  std::cout << std::setprecision(10);
  std::cout << "Precision - 10 - showpoint ............................\n";
  std::cout << num << std::endl; // 1234.567800
  std::cout << num1 << std::endl; // 123456790.0
  std::cout << num2 << std::endl; // 12.34000000
  std::cout << num3 << std::endl; // 1234.000000

  return 0;
}
