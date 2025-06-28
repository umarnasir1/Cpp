/*
  while loop - executes only if the condition is true

  while (expression) // if more than one statement then block {}
    statement;

  if block {} is not added and more than one statments then only first statement will be considered part of loop

  Ex 12 & Ex 13 break & continue
*/

#include <iostream>
#include <vector>

int main (){

  // ---- Eg. 01
  // pring numbers from 1-5
  int i {1};
  while (i <= 5){
    std::cout << i << std::endl;
    ++i;
  }

  // ---- Eg. 02
  // print even numbers between 1 and 10
  i = 1;
  while (i <= 10){
    if (i % 2 == 0)
      std::cout << i << std::endl;
    ++i;
  }

  // ---- Eg. 03
  // while loop to iterate over an array
  int scores [] {100, 90, 87};
  i = 0;

  while (i < 3){
    std::cout << scores[i] << std::endl;
    ++i;
  }

  // ---- Eg. 04
  // loops are commonly used in programming to provide input validation.
  // In this example, we want the user to enter an integer less than 100, If the user dont, we want to ask them 
  // again and again  and again until they enter a valid integer.
  int number {};

  std::cout << "Enter an integer less than 100: ";
  std::cin >> number;

  while (number >= 100){ // !(number < 100)
    std::cout << "Enter an integer less than 100: "; // repeated statments, this can be done in a better way also
    std::cin >> number;
  }

  std::cout << "Thanks" << std::endl;

  // ---- Eg. 05
  // Input - validation: ask the user to enter a number between 1 and 5
  number = 0;

  std::cout << "Enter a number between 1 and 5: ";
  std::cin >> number;

  while (number <= 1 ||number >=5){
    std::cout << "Enter a number between 1 and 5: ";
    std::cin >> number;
  }

  std::cout << "Thanks" << std::endl;

  // ---- Eg. 06
  // input validation - use boolean flag to control while loop
  // boolean flag logic is better than the logic in prvious examples as the statements are not repeated /duplicated code.
  bool done {false}; // we are not done. if done is false then the program will go in loop. explicitly set to false.
  number = 0;

  while (!done){
    std::cout << "Enter an integer between 1 and 5: ";
    std::cin >> number;
    if (number <= 1 ||number >= 5)
      std::cout << "Out of range, try again" << std::endl;
    else {
      std::cout << "Thanks! " << std::endl;
      done = true;  // loop condition will fail and we will exit the loop - important so to get out of while
    }
  }

  // ---- Eg. 07
  // count down
  int num {};

  std::cout << "Enter a positive integer to start the countdown : ";
  std::cin >> num;

  while (num > 0){
    std::cout << num << std::endl;
    --num;
  }
  std::cout << "Blastoff!" << std::endl;

  // ---- Eg. 08
  // while loop that counts up till the number provided by the user.
  num = 0;

  std::cout << "Enter a positive integer to count up to: ";
  std::cin >> num;

  i = 1; // count up starting from 1
  while (num >= i){
    std::cout << i << std::endl;
    ++i;
  }

  // ---- Eg. 09
  // Determine how many integers are present before you see the value -99. Its possible -99 is not in the vector. If -99 is not in the vector then the result will be equal to the number of elements in the vector. The final result should be stored in an integer variable named count.

  const std::vector <int> vec {1, 2, 3, 4, 5, 6, 7, -99, 8};
  int count {};
  size_t index {}; // size_t is the type returned by the size() function of the vector, so we want to be consistent with our index variable.
  // size_t is normally an unsigned int.

  while (index < vec.size() && vec.at(index) != -99){
    ++count;
    ++index;
  }

  std::cout << "Number of elements : " << count << std::endl;

  // ---- Eg. 10
  // while loop with using {}
  // this will be infite loop and the decement will be considered outside the loop and the loop will get stick in infinite loop. 
  
  num = 10;
  while (num >= 1)
     std::cout << num << " ";
     num--;
  
  // ---- Eg. 11
  // Write a program in C++ to find the sum of first 10 natural numbers.    
  int sum {}, nNum{1};
  while ( nNum <= 10){
    sum += nNum;
    nNum ++;
  }
  
  std::cout << "The sum of first 10 natural numbers is: " << sum << std::endl;

  // ---- Eg. 12
  // break
  int z {0};
  while (z <= 5){
    if (z==3) break; 
    std::cout << z << std::endl; // 0 1 2 
    ++z;
  }

  // --- Eg. 13
  // continue
  int y {0}; 
  while (y <= 5){
    if (y==2){
      ++y;
      continue; 
    }
    std::cout << y << std::endl; // 0 1 3 4 5
    ++y;
  }

  return 0;
}
