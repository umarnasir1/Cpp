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

using std::cout;
using std::cin;
using std::endl;

int main(){

  int num {};
  const int target {10};

  cout << "Enter a number to be compared to " << target << ": ";
  cin >> num;

  if (num >= target ) {
    cout << "==========================================================" << endl;
    cout << num << " is greater than or equal to " << target << endl;
    int diff {num - target};
    cout << "The difference between " << num << " and " << target << " is " << diff << endl;
  }
  else {
    cout << "==========================================================" << endl;
    cout << num << " is less than " << target << endl;
    int diff {target - num};
    cout << "The difference between " << num << " and " << target << " is " << diff << endl;
  }

  return 0;
}
