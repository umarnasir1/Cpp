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

  Loops Used: 
  (1) For loop: used as main loop to construct a pyramid and another for loop is used inside main loop to deal with leading spaces in each row of the pyramid. (for loop selected here as its more efficient then while loop here. The same thing can be done using while loop but it will require few extra lines of code) 
  (2) While loop: used inside the main for loop to display the string elements. The same logic can be implemented using a for loop.

  Leading Spaces in each row of the pyramid are handled in a separate for loop.

  Different approach to problem: A different approach can be to split the pyramid into three parts, till center, center, reverse order and to loop it accordingly to display characters.
*/

/*
  Solution
    The idea when solving this problem is first to break up the problem up into subproblems.
    Get the input from the user and store it in a std::string variable
    Loop for each row
        Determine how many blank spaces must be displayed before the current row and display them
        Determine how many letters must be displayed and display them
        Display the remaining characters in reverse order
        Complete the row with a new line
*/

#include <iostream>
#include <string>

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

/*
  Alternative Solution 1- Course Instructor
  The idea when solving this problem is first to break up the problem up into subproblems.
  Get the input from the user and store it in a std::string variable
  Loop for each letter in the string entered by the user
      Determine how many blank spaces must be displayed before the current row and display them
      Determine how many letters must be displayed before the current character and display them
      Display the current character
      Display the remaining characters in reverse order
      Complete the row with a new line

  There are many, many ways to solve this problem. Solution is considering that the std::string .length() and .at() methods use size_t as the type for the return value and parameter.
  int can be used instead of size_t for this problem, but you will get compiler warnings about int and size_t compatibility issues.
*/
// Letter Pyramid
// Written by Frank J. Mitropoulos

// #include <iostream>
// #include <string>
//
// int main()
// {
//     std::string letters{};
//
//     std::cout << "Enter a string of letters so I can create a Letter Pyramid from it: ";
//     getline(std::cin, letters);
//
//     size_t num_letters = letters.length();
//
//     int position {0};
//
//     // for each letter in the string
//     for (char c: letters) {
//
//         size_t num_spaces = num_letters - position; // Paramid stats with a " " thats y one extra space here
//         while (num_spaces > 0) {
//             std::cout << " ";
//             --num_spaces;
//         }
//
//         // Display in order up to the current character
//         for (size_t j=0; j < position; j++) {
//             std::cout << letters.at(j);
//         }
//
//         // Display the current 'center' character
//         std::cout << c;
//
//         // Display the remaining characters in reverse order
//         for (int j=position-1; j >=0; --j) {
//             // You can use this line to get rid of the size_t vs int warning if you want
//             auto k = static_cast<size_t>(j);
//             std::cout << letters.at(k);
//         }
//
//         std::cout << std::endl; // Don't forget the end line
//         ++position;
//     }
//
//     return 0;
// }

// Alternative Solution 2
// #include <iostream>
// #include <string>
//
// using namespace std;
//
// int main() {
//
//     cout << "Enter a string: ";
//     string aString;
//     getline(cin, aString);
//
//     for (int i {0}; i < aString.length(); i++)
//     {
//
//         for(int j {0}; j < aString.length() - i - 1; j++)
//         {
//             cout << " ";
//         }
//         for(int j {0}; j <= i; j++)
//         {
//             cout << aString[j];
//         }
//         for(int j {i-1}; j > -1; j--)
//         {
//             cout << aString[j];
//         }
//         cout << endl;
//     }
//
//
//
//     return 0;
//
//
// }
