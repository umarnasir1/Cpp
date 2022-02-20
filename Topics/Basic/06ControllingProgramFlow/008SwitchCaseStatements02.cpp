/*
  Switch-Case Statement - with enumeration

  Example: Switch statement with enumaration type.

  We have an enumeration type called color with 3 enumeration constants: red, green and blue. We also have a variable named screen_color, which we initialize to green. (can only be red, green, blue)
  But it can hold any of the 3 enumeration constants.
  Using this enumeration variable in the switch statement is a very common use case and a great way to execute code depending on its value.

  enum Color {
    red, green, blue
  };
  Color screen_color {green};

  switch (screen_color){
    case red: cout << "red"; break;
    case green: cout << "green"; break;
    case blue: cout << "blue"; break;
    default: cout << "shoudl never execute"; //unless add another enumeration constant and forget to include a case for it.
  }
*/

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main(){

  enum Direction {   // we are creating a new type
    left, right, up, down // enumeration constants - variable headings could be any one of these four.
  };

  Direction heading {left}; // create variable of enumeration type and initilizing it to left - one of enum constant defined in enum.

  switch (heading) {
    case left:
      cout << "Going left." << endl;
      break;
    case right:
      cout << "Going right." << endl;
      break;
    // either create case for up and down OR create a default that will handle everything else
    default:
      cout << "OK" << endl;
  }

  return 0;
}
