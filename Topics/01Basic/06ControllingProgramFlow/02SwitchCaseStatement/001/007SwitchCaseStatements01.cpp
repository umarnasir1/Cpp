/*
  Switch-Case Statement

  switch (integer_control_expr) {  // This control expression must evaluate to an integral type (e.g. char, int, enumeration type.
    case expr1: statement1; break; // When the value of the control expression matches the case expression, then the code after : is executed till break stateemnt.
    case expr2: statement2; break;
    case expr3: statement3; break;
    ...
    case expr_n: statement_n; break;
    default: statement_default; // this case will execute when none of the cases is true. (break statement is not needed in default case)
  }

  Example1:
  We can write if else if statements to execute code depending on the character entered. But in this case, we can use a switch statement since the control expression is an integral type and the case statement contains character literals to match.

  switch (selection) { // selection is a character type. (user have entered at the keyboard and that is assigned to selection.)
    case '1': cout << "1 selected";
              break;
    case '2': cout << "2 selected";
              break;
    case '3':                             // same behavior on both case 3 and 4
    case '4': cout << "3 or 4 selected";
              break;
    default: cout << "1,2,3,4 NOT selected";
  }

  -----------------
  Example2: (fall through behavior without break - in case 1,2,3)
  Suppose the user enters the character 1, and it was assigned to selection.
  We check the first case statement and it matches. So we execute the code following the colon.
  In this case, we display "1 selected"
  Now we continue executing code going straight down the switch statement
  until we hit a break statement.
  So in this case, we also display "2 selected" and "3 selected" and "4 selected".
  Finally, we hit a break statement.

  if break is not used, once a match is made, all the code in the switch cases, including and following that match, will be executed until we hit a break statement.

  If you need logic that falls through, please document the code and be very clear in the documentation that the fall through behavior is what you intended. If another programmer sees the code and needs to modify it, they'll understand this and be very careful when adding or removing new conditions or statements.

  switch (selection) {
    case '1': cout << "1 selected";
    case '2': cout << "2 selected";
    case '3': cout << "3 selected";
    case '4': cout << "4 selected";
              break;
    default: cout << "1,2,3,4 NOT selected";
  }

  ----------------

  Example below:
  Ask the user what grade they expect on an exam and tell them what they need to score to get it.
*/


#include <iostream>

int main (){

  char grade {};

  std::cout << "Enter the grade that you expect on the exam: ";
  std::cin >> grade;

  switch (grade){
    // same behavior on both upper case and lower case characters.
    case 'a':
    case 'A':
      std::cout << "You need 90 or above, study hard! " << std::endl;
      break;
    case 'b':
    case 'B':
      std::cout << "You need 80-89 for a B, go study!" << std::endl;
      break;
    case 'c':
    case 'C':
      std::cout << "You need 70-79 for an average grade." << std::endl;
      break;
    case 'd':
    case 'D':
      std::cout << "Hmm, you should strive for a better grade. All you need is 60-69." << std::endl;
      break;
    case 'f':
    case 'F':
      {  // declaring a variable so we need a block {} as we would confirm if a student is really entering F, f
        char confirm {};
        std::cout << "Are you sure (Y/N)?";
        std::cin >> confirm;
        if (confirm == 'Y' ||confirm == 'y')
          std::cout << "OK, I guess you dont want to study.." << std::endl;
        else if (confirm == 'N' || confirm == 'n')
          std::cout << "Good!, go study!" << std::endl;
        else
          std::cout << "Illegal choice." << std::endl;
        break;
      }
    default:
      std::cout << "Sorry, not a valid grade." << std::endl;
  }

  return 0;
}