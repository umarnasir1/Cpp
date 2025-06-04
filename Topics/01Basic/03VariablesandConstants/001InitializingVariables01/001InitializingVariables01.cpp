/*
  Never use variables before initializing them
  if variable is not initialized and used then:
  Age is : 218230821

  When variable is not initialize, the compiler will give a warning

  Explanition:
  If the variable is not iniialized, then it will display the values that is at its memory location at which the variable is associated to.
  for eg. if the variable age is associated to memory location 2000, then it will display what ever value is already stored at memory location 2000. (it will be series of 1s and 0s)

  Best practice int age {21};

  */

#include <iostream>

int main(){
  int age; // variable is not initialize - Best practice int age {21};
  std::cout << "Age is : " << age << std::endl;
  return 0;
}
