// Section 9
// Challenge
/*
    This challenge is about using a collection (list) of integers and allowing the user
    to select options from a menu to perform operations on the list.

    Your program should display a menu options to the user as follows:

    P - Print numbers (Print elements of the list)
    A - Add a number to the list that is asked to the user
    M - Display mean of the numbers
    S - Display the smallest number
    L - Display the largest number
    Q - Quit

    Enter your choice:

The program should only accept valid choices from the user, both upper and lowercase selections should be allowed.
If an illegal choice is made, you should display, "Unknown selection, please try again" and the menu options should be
displayed again.


If the user enters 'P' or 'p', you should display all of the elements (ints) in the list.
If the list is empty you should display "[] - the list is empty"
If the list is not empty then all the list element should be displayed inside square brackets separated by a space.
For example, [ 1 2 3 4 5 ]

If the user enters 'A' or 'a' then you should prompt the user for an integer to add to the list
which you will add to the list and then display it was added. For example, if the user enters 5
You should display, "5 added".
Duplicate list entries are OK

If the user enters 'M' or 'm'  you should calculate the mean or average of the elements in the list and display it.
If the list is empty you should display, "Unable to calculate the mean - no data"

If the user enters 'S' or 's' you should display the smallest element in the list.
For example, if the list contains [2 4 5 1],  you should display, "The smallest number is 1"
If the list is empty you should display, "Unable to determine the smallest number - list is empty"

If the user enters 'L' or 'l' you should display the largest element in the list
For example, if the list contains [2 4 5 1], you should display, "The largest number is 5"
If the list is empty you should display, "Unable to determine the largest number - list is empty"

If the user enters 'Q' or 'q' then you should display 'Goodbye" and the program should terminate.

Hint: Use a vector (as we want this to grow dynamically)

Additional functionality if you wish to extend this program.

- search for a number in the list and if found display the number of times it occurs in the list
- clearing out the list (make it empty again) (Hint: the vector class has a .clear() method)
- don't allow duplicate entries
- come up with your own ideas!

Good luck!

*/
#include <iostream>
#include <vector>
#include <iomanip>
#include <numeric>

int main(){

  char choice {};
  std::vector<int> list{};
  int num{}, smallest_p {}, smallest_num, largest_p {}, largest_num {};
  double mean {};

  std::cout << std::fixed << std::setprecision(2);

  do {
    // Menu
    std::cout << "\nP - Print numbers\n"
              << "A - Add a number\n"
              << "M - Display mean of the numbers\n"
              << "S - Display the smallest number\n"
              << "L - Display the largest number\n"
              << "Q - Quit\n" << std::endl;

    std::cout << "Enter your choice: ";
    std::cin >> choice;

    switch (choice){
      case 'p':
      case 'P':
        if (list.size() != 0){
          std::cout <<"[ ";
          for (auto list_elements: list) // range based for loop
            std::cout << list_elements << " ";
          std::cout << "]" << std::endl;
        }
        else
          std::cout << "[] - the list is empty" << std::endl;
        break;
      case 'a':
      case 'A':
        std::cout << "Enter an integer to add to the list: ";
        std::cin >> num;
        list.push_back(num);
        std::cout << num << " added" << std::endl;
        break;
      case 'm':
      case 'M':
        if (list.size() != 0){
          int sum {};
          for (int element: list)
            sum += element;
          mean = sum /double(list.size()); // accumulate(list.begin(), list.end(), 0)/double(size(list)); - STL
          std::cout << "The mean is : " << mean << std::endl;
        }
        else
          std::cout << "Unable to calculate the mean - no data" << std::endl;
        break;
      case 's':
      case 'S':
        if (list.size() != 0){
          for (int i{}; i < list.size()-1; i++){
            if (list.at(i) < list.at(i+1))
              smallest_p = list.at(i);
            else
              smallest_p = list.at(i+1);
            if (smallest_num > smallest_p)
               smallest_num = smallest_p;
          } // for
          std::cout << "The smallest number is " << smallest_num << std::endl;
        }
        else
          std::cout << "Unable to determine the smallest number - list is empty" << std::endl;
        break;
      case 'l':
      case 'L':
        if (list.size() != 0){
          for (int i{}; i < list.size()-1; i++){
            if (list.at(i) > list.at(i+1))
              largest_p = list.at(i);
            else
              largest_p = list.at(i+1);
            if (largest_num < largest_p)
              largest_num = largest_p;
          }// for
          std::cout << "The largest number is " << largest_num << std::endl;
        }
        else
          std::cout << "Unable to determine the largest number - list is empty";
        break;
      case 'q':
      case 'Q':
        std::cout << "Goodbye" << std::endl;
        break;
      default:
       std::cout << "Unknown selection, please try again." << std::endl;
    }
  } while(choice != 'Q' && choice != 'q');

  return 0;
}
