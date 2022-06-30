/*
  Challenge - Letter Pyramid

  Write a C++ program that displays a Letter Pyramid from a user-provided std::string.

  Prompt the user to enter a std::string and then from that string display a Letter Pyramid as follows:
  It's much easier to understand the Letter Pyramid given examples.
  If the user enters the string "ABC", then your program should display:
    A
   ABA
  ABCBA

  If the user enters the string, "12345", then your program should display:

      1
     121
    12321
   1234321
  123454321

  If the user enters 'ABCDEFG', then your program should display:

        A
       ABA
      ABCBA
     ABCDCBA
    ABCDEDCBA
   ABCDEFEDCBA
  ABCDEFGFEDCBA

  If the user enters 'ABCDEFGHIJKLMNOPQRSTUVWXYZ', then your program should display:
                           A
                          ABA
                         ABCBA
                        ABCDCBA
                       ABCDEDCBA
                      ABCDEFEDCBA
                     ABCDEFGFEDCBA
                    ABCDEFGHGFEDCBA
                   ABCDEFGHIHGFEDCBA
                  ABCDEFGHIJIHGFEDCBA
                 ABCDEFGHIJKJIHGFEDCBA
                ABCDEFGHIJKLKJIHGFEDCBA
               ABCDEFGHIJKLMLKJIHGFEDCBA
              ABCDEFGHIJKLMNMLKJIHGFEDCBA
             ABCDEFGHIJKLMNONMLKJIHGFEDCBA
            ABCDEFGHIJKLMNOPONMLKJIHGFEDCBA
           ABCDEFGHIJKLMNOPQPONMLKJIHGFEDCBA
          ABCDEFGHIJKLMNOPQRQPONMLKJIHGFEDCBA
         ABCDEFGHIJKLMNOPQRSRQPONMLKJIHGFEDCBA
        ABCDEFGHIJKLMNOPQRSTSRQPONMLKJIHGFEDCBA
       ABCDEFGHIJKLMNOPQRSTUTSRQPONMLKJIHGFEDCBA
      ABCDEFGHIJKLMNOPQRSTUVUTSRQPONMLKJIHGFEDCBA
     ABCDEFGHIJKLMNOPQRSTUVWVUTSRQPONMLKJIHGFEDCBA
    ABCDEFGHIJKLMNOPQRSTUVWXWVUTSRQPONMLKJIHGFEDCBA
   ABCDEFGHIJKLMNOPQRSTUVWXYXWVUTSRQPONMLKJIHGFEDCBA
  ABCDEFGHIJKLMNOPQRSTUVWXYZYXWVUTSRQPONMLKJIHGFEDCBA

  If the user enters "C++isFun!", then your program should display:

          C
         C+C
        C+++C
       C++i++C
      C++isi++C
     C++isFsi++C
    C++isFuFsi++C
   C++isFunuFsi++C
  C++isFun!nuFsi++C

  Think about the problem before you begin and break it down into steps.
  This can be a very challenging problem to solve!
  *****  Don't forget to paste your code solution when you submit.******
  *****  Also, submit it so your peers can see it and possibly comment. ******
  Have fun!

  Questions for this assignment
  Which C++ loop(s) did you use and why?
  How did you handle displaying the leading spaces in each row of the pyramid?
  Now that you completed the assignment, how might approach the problem differently if you had to solve it again?
*/

#include <iostream>
#include <string>

int main (){

  std::string user_input;

  std::cout << "Enter a string: ";
  std::cin >> user_input;

  

  return 0;
}
