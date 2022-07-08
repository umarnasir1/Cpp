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

int main (){
  std::string user_input;
  int count {}, count1 {}, k {};
  // count - count for first half of pyramid (increasing)
  // count1 - count for second halft of pyramid (reverse)
  // k - while loop

  std::cout << "Enter a string: ";
  std::cin >> user_input; // getline(std::cin, user_input)

  for (int i{1}; i <= user_input.length(); ++i){
    for (size_t space{1}; space <= user_input.length()-i; ++space){ // loop for space
      std::cout << "  ";
      ++count;
    }

    while(k != i*2-1){// to print numbers in rows (in paramid) 1,3,5,7,9 ....
      if(count <= user_input.length()-1){ // left half of parymid (increasing order)
        // user_input.length()-1 in condition because count will be 0 to 4 for the first half and space 0 to 4 incase of length() = 5
        std::cout << user_input[k] << " ";
        ++count;
      }
      else { // right half of paramid - reverse order
        ++count1;
        std::cout << user_input[k-2*count1] << " ";
      }
      ++k;
    }
    count1 = count = k = 0;
    std::cout << std::endl;
  }
  return 0;
}
