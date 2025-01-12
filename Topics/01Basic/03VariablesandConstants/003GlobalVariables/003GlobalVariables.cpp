/*
  loclal and global variables

  First, the compiler looks locally to see if there is a declaration of age.
  if not, then it looks globally to see if age has been declared at the global level.

  If there is a local and global variable,
  first compliler will look locally and will use that so in this case
  Age is : 16
*/
#include <iostream>

int age {18}; // Global Variable

int main (){
  int age = {16}; // Local Variable
  std::cout << "Age is : " << age << std::endl;
  return 0;
}
