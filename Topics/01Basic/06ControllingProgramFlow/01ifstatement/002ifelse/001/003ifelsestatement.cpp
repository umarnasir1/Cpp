/*
  if else Statement

  if (expr)
    statement1; // will execute if the statement is true
  else
    statement2; // will execute if the statement is false

  if (num > 10)
    cout << "num is greater than 10";
  else
    cout << "num is NOT greater than 10";

  ===================================================================
  Block statements are used if more than one statement. Eg. below

  ==================================================================
  if else if statement

  if (score >= 90)
    cout << "A";
  else if (score > 80)
    cout << "B";
  else if (score > 70)
    cout << "C";
  else if (score > 60)
    cout << "D";
  else                  // all others must be F
    cout << "F";

  cout << "Done";
*/

#include <iostream>

int main(){

  int num {};
  const int target {10};

  std::cout << "Enter a number to be compared to " << target << ": ";
  std::cin >> num;

  if (num >= target ) {
    std::cout << "==========================================================" << std::endl;
    std::cout << num << " is greater than or equal to " << target << std::endl;
    int diff {num - target};
    std::cout << "The difference between " << num << " and " << target << " is " << diff << std::endl;
  }
  else {
    std::cout << "==========================================================" << std::endl;
    std::cout << num << " is less than " << target << std::endl;
    int diff {target - num};
    std::cout << "The difference between " << num << " and " << target << " is " << diff << std::endl;
  }

  return 0;
}
