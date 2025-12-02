/*
  Stream Manipulators - boolean
    default - 1,0 
    boolalpha: true, false
    noboolalpha: 1, 0
  Method version
    setf - Setting back to true/falase
    resetiosflags - reset to default
*/
#include<iostream>
#include<iomanip>

int main(){

  // default behavior of boolean
  std::cout << "noboolalpha - default (10 == 10): " << (10 == 10) << std::endl; // 1
  std::cout << "noboolalpha - default (10 == 20): " << (10 == 20) << std::endl; // 0

  // Formatting Boolean types
  // using string manipulator to switch this into True and False
  std::cout << std::boolalpha; // change to true/false
  std::cout << "boolalpha (10 == 10): " << (10 == 10) << std::endl; // true
  std::cout << "boolalpha (10 == 20): " << (10 == 20) << std::endl; // false

  // Toggle to 0/1
  std::cout << std::noboolalpha; // 1 0
  std::cout << "noboolalpha (10 == 10): " << (10 == 10) << std::endl; // 1
  std::cout << "noboolalpha (10 == 10): " << (10 == 20) << std::endl; // 0

  // Method version
  // Setting back to true/falase using setf method.
  std::cout.setf(std::ios::boolalpha); // setf is the method; std is namespace; ios is the class; boolalpha is the flag that is defined in that class.
  std::cout << "boolalpha (10 == 10): " << (10 == 10) << std::endl; // true
  std::cout << "boolalpha (10 == 20): " << (10 == 20) << std::endl; // false

  // std::cout.setf(std::ios::noboolalpha);

  // Reset to default
  std::cout<< std::resetiosflags(std::ios::boolalpha); // reset to whatever the default is for that flag. - resetiosflag is manipulator that expects what ever flag we want to reset and that flag will be reset to default.
  std::cout << "Default (10 == 10): " << (10 == 10) << std::endl; // 1
  std::cout << "Default (10 == 20): " << (10 == 20) << std::endl; // 0

  return 0;
}
