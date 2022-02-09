/*
 Playing with cin

 Cin extraction uses white space (spaces, tabs, new lines) as terminating the value being extracted. So if you put spaces between the characters that you type in, the spaces will be ignored. Even when the user press enter, that is treated as white space by compiler.

 Characters are read from the keyboard, and they're not read directly by cin, they're stored in a buffer. This is done to make the program more efficient. So if 123 is typed on the keyboard, 123 is stored in buffer and then read from buffer. And the compiler knows that num1 is an integer. So it's going to read those characters (one by one), and it's only going to process what makes sense to be an integer. After reading all characters in buffer, cin will have 123. So 123 gets stored into num1, which will be printed on console.

 Eg.
 Enter an ingeger:    89 76
 You entered 89

 ----
 It's possible that the extraction operator could fail. For example, suppose you want to read an integer and the user enters a name Frank. In this case, the operation fails and the data will have an undetermined value.

 Eg.
 Enter an ingeger: name
 You entered 0

 -----
 In case of two integers, int1 and int 2. if both numbers are entered by the user at the promt when program is asking user to enter one number what will happen?

 The extraction operator realizes that num1 is an integer, so it's going to try to read an integer from this stream and say I got a 1 a 0 and a 0 and then it sees a white space that must mean that my integer is done. So it's going to take 100 and store it right into num1.
 Now it's going to output, enter another integer.
 And it's going to try to read that second integer from the input stream. Well, it's already in there, right. So it's going to start right here, and start reading 2, then 0 and 0, space, aha that's 200. It's not going to wait for me to press enter (for second input as its already there - data is in the buffer). So in this case, the 200 gets put into num2 and this will print out 100 and 200. So your output will be correct but the way that the the prompts are displayed is a little different because it's got data in that buffer already.

 Eg.
 Enter first integer: 100   200
 Enter second integer: You entered 100 and 200

*/
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main(){

  int num1;
  int num2;

//  cout << "Enter an ingeger: ";
//  cin >> num1;
//  cout << " You entered " << num1 << endl;

  cout << "Enter first integer: ";
  cin >> num1;
  cout << "Enter second integer: ";
  cin >> num2;
  cout << "You entered " << num1 << " and "<< num2 << endl;

  return 0;
}
