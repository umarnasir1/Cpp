// Playing with cout and \n

#include <iostream>

int main(){
  std::cout << "Hello World" <<std::endl;
  std::cout << "Hello World\n"; //new line character embeded in string \n doesnt flush the buffer
  std::cout << "Hello\nOut\nThere\n";

  return 0;
}
