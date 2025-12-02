/*
  StreamManipulators-Integers
    std::dec - default
    std::oct  
    std::hex

    std::showbase; std::noshowbase 
      0x - hex 
      0 - oct 

    std::uppercase; std::nouppercase
    std::showpos; std::noshowpos
        +,-

    setf - an alternate way
    Setting/resetting integer types
    set using setf
      std::cout.setf(std::ios::showbase);
      std::cout.setf(std::ios::uppercase);
      std::cout.setf(std::ios::showpos);

    Reset to defaults
      std::cout << std::resetiosflags(std::ios::basefield); // back to base 10
      std::cout << std::resetiosflags(std::ios::showbase); // not to show base
      std::cout << std::resetiosflags(std::ios::showpos); // not to show +
      std::cout << std::resetiosflags(std::ios::uppercase); // lower case
*/
#include<iostream>
#include<iomanip>

int main(){

  int num {255}, num2 {-255};

  // displaying num in different bases
  std::cout << std::dec << num << std::endl; // 255 - no need to std::dec as it is default.
  std::cout << std::hex << num << std::endl; // ff
  std::cout << std::oct << num << std::endl; // 377

  // Displaying showing the base prefix for hex and oct
  std::cout << std::showbase; // std::noshowbase - to toggle back
  std::cout << std::dec << num << std::endl; // 255
  std::cout << std::hex << num << std::endl; // 0xff 0x prefix for hexadecimal
  std::cout << std::oct << num << std::endl; // 0377 0 prefix for octal

  // to display hexadecimal digits in uppercase although default is lower case.
  // std::showbase will presist
  std::cout << std::uppercase; // std::nouppercase
  std::cout << std::hex << num << std::endl; // 0XFF

  // showpos - display '+' sign in front of positive base 10 numbers.
  // std::dec so to change from std::hex to std::dec
  std::cout << std::dec << num << std::endl; // 255
  std::cout << std::dec << num2 << std::endl; // -255

  std::cout << std::showpos; // std::noshowpos - to toggle back

  std::cout << num << std::endl; // +255
  std::cout << num2 << std::endl; // -255
  std::cout << std::hex << num << std::endl; // 0XFF - showpos have no effect on hex
  std::cout << std::oct << num << std::endl; // 0377  - showpos have no effect on oct

  // restoring defaults using setf
  std::cout << std::resetiosflags(std::ios::basefield); // back to base 10
  std::cout << std::resetiosflags(std::ios::showbase); // not to show base
  std::cout << std::resetiosflags(std::ios::showpos); // not to show +
  std::cout << std::resetiosflags(std::ios::uppercase); // lower case

  std::cout << "\n\nExample ............." << std::endl;
  std::cout << "Enter an integer: ";
  std::cin >> num;

  std::cout << "Decimal default : " << num << std::endl;

  std::cout << "Hexadecimal : " << std::hex << num << std::endl;
  std::cout << "Hexadecimal : " << std::uppercase << num << std::endl; // std::hex will presist
  std::cout << "Hexadecimal : " << num << std::endl; // hex and uppercase will presist
  std::cout << "Hexadecimal : " << std::nouppercase << num << std::endl;

  std::cout << "Octal : " << std::oct << num << std::endl;
  std::cout << "Hexadecimal : " << std::hex << std::showbase << num << std::endl;
  std::cout << "Octal : " << std::oct << num << std::endl; // showbase will presist.
  
  return 0;
}
