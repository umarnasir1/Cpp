/*
  Situation1: Instead of entering int, user enters a float. the program will read an integer from the buffer. So it's going to see that the 1 and then 0 and it's going to say yep that's an integer. When it sees the decimal point, it knows it can't be an integer anymore. So it's just going to take the 10 and store it in num1.
  The program is going to ask me to enter the double, but it's not going to wait for me to press enter because it's already got data in the buffer.
  Then for remaining stream there is .5 left in buffer. so it's going to start at the decimal point, and it's going to read 0.5. 0.5 is a double so it's going to store 0.5 in num2. So your output is going to be 10 and 0.5.

  Eg.
  Enter an integer: 10.5
  Enter a double: The integer is: 10
  And the double is 0.5

  Situation2: Enter a name instead of int
  When it tried to read the integer, it got the N in Name and it's lost. So the input failed, and it goes into a fail state. From that point on, everything that's happening is unreliable. You can see that the integer got 0. It got basically initialized to 0 there. But everything else
  after that point is completely unreliable,
  
  Enter an integer: Name
  Enter a double: The integer is: 0
  And the double is 6.95313e-310
*/

#include <iostream>

int main() {

  int num1;
  double num2;

  std::cout << "Enter an integer: ";
  std::cin >> num1;

  std::cout << "Enter a double: ";
  std::cin >> num2;

  std::cout << "The integer is: " << num1 << std::endl;
  std::cout << "And the double is " << num2 << std::endl;

  return 0;
}
