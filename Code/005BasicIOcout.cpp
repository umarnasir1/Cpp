// Playing with cout and \n

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main(){
  cout << "Hello World" << endl;
  cout << "Hello World\n"; //new line character embeded in string \n doesnt flush the buffer
  cout << "Hello\nOut\nThere\n";

  return 0;
}
