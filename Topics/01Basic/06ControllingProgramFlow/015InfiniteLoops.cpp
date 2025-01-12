/*
  Infinite Loops
*/

#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int main () {

  // Eg. 1: infinite for loop
  for (;;) // infinite for loop
    cout << "This will print forever" << endl;

  // Eg. 2: infinite while loop
  while (true) // we can use an expression that is always true also e.g., while (10 < 12)
    cout << "This will print forever" << endl;

  // Eg. 3: infinite do while loop
  do {
    cout << "This will print forever" << endl;
  } while(true);


  // E.g.3: This is an example of an endless loop that might be okay.
  while (true){ // This condition will always be true.
    char again {};
    cout << "Do you want to loop again ? (Y/N) ";
    cin >> again;

    if (again == 'N'|| again == 'n')
      break; // loop termination.
  }
  return 0;
}
