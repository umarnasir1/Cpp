/*
  do-while loop

  do {
    statements;
  } while (expression);

*/

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::cin;
using std::vector;

int main (){

  // ---- Eg.1
  // input validation - ask the user to enter a number between 1 and 5. If the user enter out of range number, promt user to re-enter the number till user enters the number in the range.

  int number {};

  do {
    cout << "Enter an integer between 1 and 5: ";
    cin >> number;
  } while(number <= 1 || number >= 5);

  cout << "Thanks" << endl;

  // ---- Eg.2
  // area calculation
  char selection {};

  do {
    double width {}, height {};
    cout << "Enter width and height separated by a space: ";
    cin >> width >> height;

    double area {width * height};
    cout << "The area is " << area << endl;

    cout << "Calculate another ? (Y/N) : ";
    cin >> selection;

  } while(selection == 'Y' || selection == 'y'); // if the selection is any other character, the loop terminates.

  cout << "Thanks!" << endl;

  // ---- Eg.3
  // Simple Menu
  // do display the Menu
  // while a user doesnt quit
  char selection {};

  do {
    // Menu
    cout << "\n------------------------------- \n"
         << "1. Task 1\n"
         << "2. Task 2\n"
         << "3. Task 3\n"
         << "Q. Quit" << endl;

    cout << "\nEnter your selection: ";
    cin >> selection;

    switch (selection) {  // can also work with if - else if - else if - else if -else (check do-while video v.86)
      case '1':
        cout << "Operations for Task 1" << endl;
        break;
      case '2':
        cout << "Operations for Task 2" << endl;
        break;
      case '3':
        cout << "Operations for Task 3" << endl;
        break;
      case 'q':
      case 'Q':
        cout << "Thank you!" << endl;
        break; 
      default:
        cout << "Invalid Entry. Please try again" << endl;
    }

  } while(selection != 'Q' && selection != 'q');

  return 0;
}
