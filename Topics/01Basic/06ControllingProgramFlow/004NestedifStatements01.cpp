/*
  Nested if statement

  if (expr1)
    if (expr2)
      statement1;
    else
      statement2;

    In above example, if expr1 is falase, everything is skipped.
    if expr1 is true, then we test expr2. if it's true, we execute statement1. else, we execute statement2.
    We can continue by including if or if else statements as we need.
    ------
    dangling else problem - if we have two ifs and only one else. (PROBLEM - which if does that else belong to)
    In C++, an else belongs to the closest if.
    -------
    if (score > 90)
      if (score > 95)
        cout << "A+";
      else
        cout << "A";

    else
      cout << "Sorry, No A";
    -------
    // checking if Franks score is not equal to bills score.
    if (score_frank != score_bill){
      if (score_frank > score_bill){
        cout <<"Frank Wins" << endl;
      }
      else {
        cout << "Bill Wins" << endl;
      }
    }
    else {
      cout << "Looks like its a tie!" << endl;
    }
    ------------

    The following program will ask the user for the score on an exam between 0 and 100 and will display Grade (ABCDF).
    If F, student have to repeat the class.
    Also, validate to make sure that a value between 0 - 100 is entered.
*/

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main(){

    int score {};
    char letter_grade {};

    cout << "Enter your score in exam (between 0 - 100): ";
    cin >> score;

    if (score >= 0 && score <= 100){
      // grades ABCDEF
      if (score >= 90)
        letter_grade = 'A';
      else if (score >= 80)
        letter_grade = 'B';
      else if (score >= 70)
        letter_grade = 'C';
      else if (score >= 60)
        letter_grade = 'D';
      else
        letter_grade = 'F';

      cout << "Your grade is: " << letter_grade << endl;
      if (letter_grade == 'F')
        cout << "Sorry, you must repeat the class" << endl;
      else
        cout << "Congrats !!! " << endl;

    }
    else {
      cout << "Sorry, " << score << " is not in range." << endl;
    }

  return 0;
}
