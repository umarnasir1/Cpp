/*
  if statement

  if (control expr) //must evaluate to a boolean value; if the value of expr is true, the statement is executed otherwise skipped
    statement1;

  if (control expr){ // if more than one statement then block; if {} not used and more than one statemenets then only first statement would be considered as part of if and the other will not.  (eg. 3)
    statement 1;
    statement 2;
  }
  -------------
  The ; at the end of the if statement means that there is an empty statement in the body of the if. E.g.,
  if (condition) ;
  is the same as
  if (condition)
      ;
  Which means that if the condition is true, do nothing.
  This is shown in eg. 2
  -----

  // Block statement - if more than one statement - block statement (A block statement is a sequence of statements inside a block which is made up of opening and closing curly brackets.). E.g.,
  if (num > 10) {
  ++num;
  cout << "this too";

  Block statments introduce a new level of scope.
  we can declare variables in any block, even in a block that's inside an if statement. (score - block)
  This lets us modularize our code so we have better control of who sees what, which makes writing and debugging our code easier.

  testing independent if statements (statement 1-4)
  checking scrop rules - diff variable
}

*/

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main(){

  int num {};

  // Eg. 01
  // setting boundries
  const int min {10};
  const int max {100};

  cout << "Enter a number between 10 and 100: ";
  cin >> num;

  // to check if the number is greater than or equal to min
  if (num >= min) {
    cout << "\n================= if statement 1 ==============" << endl;
    cout << num << " is greater than or equal to " << min << endl;

    // displaying how far away that is the num from min.
    int diff {num-min}; // declared inside if block so scope will be in this block.
    cout << num << " is " << diff << " greater than " << min << endl;
  }

  // to check if the number is less than or equal to max
  if (num <= max) {
    cout << "\n================== if statement 2 ==================" << endl;
    cout << num << " is less than or equal to " << max << endl;

    int diff {max - num}; // creates a new copy of diff that is only visible to this block.
    cout << num << " is " << diff << " less than " << max << endl;
  }

  // to check if the number is within the bounds - this statement will only execute if statement 1 and 2 executes as we are in range.
  if (num >= min && num <= max) {
    cout << "\n================== if statement 3 ==================" << endl;
    cout << num << " is between " << min << " and " << max << endl;
  }

  // to check wether they are on boundries - we want to know weather its actually equal to 10 or equal to 100. This statement will only execute if all three statements will execute.
  if (num == min || num == max) {
    cout << "\n================== if statement 4 ==================" << endl;
    cout << num << " is right on the boundry " << endl;
  }

  // Eg. 02 - if (condition);
  /*
  Enter a temperature: 70
  It's cold!
  It's hot!
  as   if (temperature < 50); so cout will execute and then next if condition will execute. more explanition up.
  */
  int temperature;
  cout << "Enter a temperature: ";
  cin >> temperature;
  if (temperature < 50);
     cout << "It's cold!" << endl;
  if (temperature > 50)
     cout << "It's hot!" << endl;
  else
     cout << "Maybe it's raining?";

  // Eg. 03 - if more than one statement then always use {} block otherwise we will see unexpected results. Just first statement will be considered part of if and other two will print if the condition is not meet
  /*
  Enter your favorite number: 20
  That's amazing!
  Great minds think alike!
  */
  int favorite;
  cout << "Enter your favorite number: ";
  cin >> favorite;
  if (favorite == 13)
     cout << "That my favorite number too!" << endl;
     cout << "That's amazing!" << endl;
     cout << "Great minds think alike!" << endl;

  return 0;
}
