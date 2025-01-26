/*
  do-while loop - execute the loop atleast one time

  do {
    statements;
  } while (expression);

*/

#include <iostream>
#include <vector>

int main (){

  // ---- Eg.1
  // input validation - ask the user to enter a number between 1 and 5. If the user enter out of range number, promt user to re-enter the number till user enters the number in the range.

  int number {};

  do {
    std::cout << "Enter an integer between 1 and 5: ";
    std::cin >> number;
  } while(number <= 1 ||number >= 5);

  std::cout << "Thanks" << std::endl;

  // ---- Eg.2
  // area calculation
  char selection {};

  do {
    double width {}, height {};
    std::cout << "\nEnter width and height separated by a space: ";
    std::cin >> width >> height;

    double area {width * height};
    std::cout << "The area is " << area << std::endl;

    std::cout << "Calculate another ? (Y/N) : ";
    std::cin >> selection;

  } while(selection == 'Y' || selection == 'y'); // if the selection is any other character, the loop terminates.

  std::cout << "Thanks!" << std::endl;

  // ---- Eg.3
  // Simple Menu
  // do display the Menu
  // while a user doesnt quit
  selection = 0;

  do {
    // Menu
    std::cout << "\n------------------------------- \n"
         << "1. Task 1\n"
         << "2. Task 2\n"
         << "3. Task 3\n"
         << "Q. Quit" << std::endl;

    std::cout << "\nEnter your selection: ";
    std::cin >> selection;

    switch (selection) {  // can also work with if - else if - else if - else if -else (check do-while video v.86)
      case '1':
        std::cout << "Operations for Task 1" << std::endl;
        break;
      case '2':
        std::cout << "Operations for Task 2" << std::endl;
        break;
      case '3':
        std::cout << "Operations for Task 3" << std::endl;
        break;
      case 'q':
      case 'Q':
        std::cout << "Thank you!" << std::endl;
        break; 
      default:
        std::cout << "Invalid Entry. Please try again" << std::endl;
    }

  } while(selection != 'Q' && selection != 'q');

  return 0;
}
