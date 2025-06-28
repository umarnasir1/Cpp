/*
  if statement

  if (control expr) statement1; // good approach
  
  OR 

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

Any thing that is non-zero is considered true 
            only zero is considered false 
            The empty string is non-zero (In C++ it is actually an address)
            Ex. 
              if (1); if ("")

Turnary Conditional Operator - Eg 5

*/

#include <iostream>

int main(){

  // Eg. 01
  // setting boundries
  int num {};
  const int min {10};
  const int max {100};

  std::cout << "Enter a number between 10 and 100: ";
  std::cin >> num;

  // to check if the number is greater than or equal to min
  if (num >= min) {
    std::cout << "\n================= if statement 1 ==============" << std::endl;
    std::cout << num << " is greater than or equal to " << min << std::endl;

    // displaying how far away that is the num from min.
    int diff {num-min}; // declared inside if block so scope will be in this block.
    std::cout << num << " is " << diff << " greater than " << min << std::endl;
  }

  // to check if the number is less than or equal to max
  if (num <= max) {
    std::cout << "\n================== if statement 2 ==================" << std::endl;
    std::cout << num << " is less than or equal to " << max << std::endl;

    int diff {max - num}; // creates a new copy of diff that is only visible to this block.
    std::cout << num << " is " << diff << " less than " << max << std::endl;
  }

  // to check if the number is within the bounds - this statement will only execute if statement 1 and 2 executes as we are in range.
  if (num >= min && num <= max) {
    std::cout << "\n================== if statement 3 ==================" << std::endl;
    std::cout << num << " is between " << min << " and " << max << std::endl;
  }

  // to check wether they are on boundries - we want to know weather its actually equal to 10 or equal to 100. This statement will only execute if all three statements will execute.
  if (num == min || num == max) {
    std::cout << "\n================== if statement 4 ==================" << std::endl;
    std::cout << num << " is right on the boundry " << std::endl;
  }

  // Eg. 02 - if (condition);
  /*
  Enter a temperature: 70
  It's cold!
  It's hot!
  as   if (temperature < 50); so cout will execute and then next if condition will execute. more explanition up.
  */ 
 
  int temperature;
  std::cout << "\nEnter a temperature: ";
  std::cin >> temperature;
  if (temperature < 50); // no statement
  
  if (temperature > 50) std::cout << "It's hot!" << std::endl;
  else std::cout << "Maybe it's raining?" << std::endl;

  // Eg. 03 - if more than one statement then always use {} block otherwise we will see unexpected results. Just first statement will be considered part of if and other two will print if the condition is not meet
  /*
  Enter your favorite number: 20
  That's amazing!
  Great minds think alike!
  */
  int favorite{};
  std::cout << "Enter your favorite number: ";
  std::cin >> favorite;
  if (favorite == 13){
     std::cout << "That my favorite number too!" << std::endl;
     std::cout << "That's amazing!" << std::endl;
     std::cout << "Great minds think alike!" << std::endl;
  }

  // Eg. 04 - The empty string is non-zero (In C++ it is actually an address)
  if ("") std::cout << "Condition is true." << std::endl; // Condition is true 

  // Eg. 05 - Turnary Conditional Operator 
  auto x {50}, y {40};
  auto z = x > y ? "true" : "false";
  std::cout << "Answer: " << z << std::endl; 

  return 0;
}
