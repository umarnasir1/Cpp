// Ask the user to enter favourite number from 1-100 and then desplay it.

#include <iostream> // input, output libraries

int main(){
  int favorite_number; // variable declaration
  std::cout << "Enter your favorite number between 1 to 100: ";
  std::cin >> favorite_number;
  std::cout << "Amazing!! " <<favorite_number<<" is my favorite number too" << std::endl; //endl will flush the buffers and will move the cursor to the next line
  return 0;
}
