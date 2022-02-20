/*
  Nested if Statements - Can you Drive?

  Any one 16 or older can legally drive, but they must also own a car to drive.
  If the person is not 16 or older then you should display, "Sorry, come back in  n years and be sure you own a car when you come back.", where n is how many years until the person turns 16 years old.

  If the person is 16 or older but they do NOT own a car, then the program should display, "Sorry, you need to buy a car before you can drive!"

  If the person is 16 or older and they DO own a car, then the program should display, "Yes - you can drive!"
*/

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main(){

  int age;
  const int driving_age {16};
  bool has_car {1}; // has a car

  cout << "Enter age : ";
  cin >> age;

  if (age >= driving_age)
      if (has_car)
          cout << "Yes - you can drive!" << endl;
      else
          cout << "Sorry, you need to buy a car before you can drive!" << endl;
  else
      cout << "Sorry, come back in " << driving_age - age << " years and be sure you own a car when you come back." << endl;

  return 0;
}
