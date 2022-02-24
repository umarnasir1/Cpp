/*
  while loop

  while (expression) // if more than one statement then block {}
    statement;

*/

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::cin;
using std::vector;

int main (){

  // ---- Eg. 01
  // pring numbers from 1-5
  int i {1};
  while (i <= 5){
    cout << i << endl;
    ++i;
  }

  // ---- Eg. 02
  // print even numbers between 1 and 10
  int i {1};
  while (i <= 10){
    if (i % 2 == 0)
      cout << i << endl;
    ++i;
  }

  // ---- Eg. 03
  // while loop to iterate over an array
  int scores [] {100, 90, 87};
  int i {0};

  while (i < 3){
    cout << scores[i] << endl;
    ++i;
  }

  // ---- Eg. 04
  // loops are commonly used in programming to provide input validation.
  // In this example, we want the user to enter an integer less than 100, If the dont, we want to ask them again and again  and again until they enter a valid integer.
  int number {};

  cout << "Enter an integer less than 100: ";
  cin >> number;

  while (number >= 100){ // !(number < 100)
    cout << "Enter an integer less than 100: "; // repeated statments, this can be done in a better way also
    cin >> number;
  }

  cout << "Thanks" << endl;

  // ---- Eg. 05
  // Input - validation: ask the user to enter a number between 1 and 5
  int number {};

  cout << "Enter a number between 1 and 5: ";
  cin >> number;

  while (number <= 1 || number >=5){
    cout << "Enter a number between 1 and 5: ";
    cin >> number;
  }

  cout << "Thanks" << endl;

  // ---- Eg. 06
  // input validation - use boolean flag to control while loop
  // boolean flag logic is better than the logic in prvious example as the statements are not repeated /duplicated code.
  bool done {false}; // we are not done. if done is false then the program will go in loop. explicitly set to false.
  int number {0};

  while (!done){
    cout << "Enter an integer between 1 and 5: ";
    cin >> number;
    if (number <= 1 || number >= 5)
      cout << "Out of range, try again" << endl;
    else {
      cout << "Thanks! " << endl;
      done = true;  // loop condition will fail and we will exit the loop - important so to get out of while
    }
  }

  // ---- Eg. 07
  // count down
  int num {};

  cout << "Enter a positive integer to start the countdown : ";
  cin >> num;

  while (num > 0){
    cout << num << endl;
    --num;
  }
  cout << "Blastoff!" << endl;

  // ---- Eg. 08
  // while loop that counts up
  int num {};

  cout << "Enter a positive integer to count up to: ";
  cin >> num;

  int i {1}; // count up starting from 1
  while (num >= i){
    cout << i << endl;
    ++i;
  }

  // ---- Eg. 09
  // Determine how many integers are present before you see the value -99. Its possible -99 is not in the vector. If -99 is not in the vector then the result will be equal to the number of elements in the vector. The final result should be stored in an integer variable named count.

  const vector <int> vec {1, 2, 3, 4, 5, 6, 7, -99, 8};
  int count {};
  size_t index {}; // size_t is the type returned by the size() function of the vector, so we want to be consistent with our index variable.
  // size_t is normally an unsigned int.

  while (index < vec.size() && vec.at(index) != -99){
    ++count;
    ++index;
  }

  cout << "Number of elements : " << count << endl;

  return 0;
}
