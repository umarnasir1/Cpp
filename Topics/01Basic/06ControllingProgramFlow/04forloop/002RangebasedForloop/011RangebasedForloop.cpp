/*
  range-based for Loop

  for (var_type element: container) // 
    statement; //if more than 1 statement then blocks {}

  var_name will be bound to each element of the collection so it should be of the same type as the collection elements.
  sequence - collection or collection name.
  When we will access the var_name in the body of the loop, it will have a specific elemnt in the collection.
  auto keyword- dont have to expliciitly provide the type of the variable. This tells the compiler to deduce the type itself i.e., C++ compiler will figure out the type based on the declarations.
*/

#include <iostream>
#include <vector>

int main (){

  std::cout << "Example 1: Simple Example of range based for loop \n";
  int scores [] {100, 90, 97};

  for (int score : scores) // score is element; scores is container
    std::cout << score << std::endl;

  // Using auto keyword - So in this case, the compiler figures out the type. The compiler sees that collection scores is an array of integers, so it uses an integer for the score variable.
  std::cout << "\nExample 2: auto keyword\n";
  int scores1 [] {100, 90, 97, 55, 67};

  for (auto score : scores1)
    std::cout << score << std::endl;

  //------------
  std::cout << "\nExample 3: Iterate over an Array \n";
  for (auto score : {100, 90, 97, 55, 67})   // initilizer list array, ex 5 similar eg
    std::cout << score << std::endl;

  // Calculate the average temperature from a vector that contains doubles that represent temperatures.
  std::cout << "\nExample 4: Vector containing doubles\n";
  std::vector <double> temps {87.2, 77.1, 80.0, 72.5};

  double average_temp {};
  double running_sum {};

  for (auto temp : temps)
    running_sum += temp;

  // just to make sure that .size() is not zero because we dont want divide by 0 error.
  if (temps.size() != 0)
    average_temp = running_sum/temps.size();

  std::cout << "Average Temprature : " << average_temp << std::endl;

  // The range-based for loop can also use an initializer list as a collection. This is handy when the elements of collection are known ahead of time and they wont change. Downside: size of vector need to be calculated and we cannot use .size method as no vector definition.
  // This example also calculates the average before temperatures.
  std::cout << "\nExample 5: Use as an initializer list as a collection. \n";
  double average_temp1 {};
  double running_sum1 {};
  int size {};

  for (auto temp1 : {87.2, 77.1, 80.0, 72.5}){ // explicitly providing the collection right in the loop.
    running_sum1 += temp1;
    ++size; // size++ will have same results
  }
  average_temp1 = running_sum1/size;
  std::cout << "Average Temprature : " << average_temp1 << std::endl;

  // Range based loop to iterate over a string. (C++ Syle String)
  std::cout << "\nExample 6: String - Iterating a string.\n";
  for (auto c : "Programming")
    std::cout << c << std::endl;

  //-----
  // skip the spaces in a string - getting rid of the spaces in string.
  std::cout << "\nExample 7: Strings - Removing the spaces in a string.\n";
  for (auto c: "This is a string")
    if (c != ' ')
      std::cout << c;

  //-----
  // Replace space with tab in a string.
  std::cout << "\nExample 8: Strings - Replace space with a tab.\n";

  for (auto c: "This is a string"){
    if (c != ' ')
      std::cout << c;
    else
      std::cout << "\t";
  }

  // loop through a given vector of integers and determine how many elements in the vector are evenly divisible by either 3 or 5.
  std::cout << "\nExample 9\n";
  int count {};

  for (auto num: {1,3,5,15,16,17,18,19,20,21,25,26,27,30,50,55,56,58,100,200,300,400,500,600,700})
    if (num % 3 == 0 || num % 5 == 0)
      ++count;

  std::cout << "# of Elements evenly divisible by either 3 or 5: " << count << std::endl;

  // Reference example
  std::cout << "\nExample 10\n";
  int array[] {1, 2, 3, 4, 5};

  for (const auto &ele : array) 
    std::cout << "Element is " << ele << std::endl; 
  
  // auto - automatically detects the type of the element
  // const &ele
  // refernce to the actual element (ele) i.e we dont make a copy of ele
  // if we didnt had the const, we could actually change it
  // Because we are using reference, thats why we are using const.

  // C String example
  std::cout << "\nExample 11\n";
  const char string[] {"Testing"};

  for (const auto &ele : string) // prints each of the individual characters plus a blank one, i.e., null terminator \0. 
    std::cout << "Element is " << ele << std::endl; 

  // if want to ommit the printing of null terminator 
  // for (const auto &ele : string) // prints each of the individual characters plus a blank one, i.e., null terminator. 
  //  if (ele) std::cout << "Element is " << ele << std::endl; // checking if ele is true or false so in case of null terminator, it will not print it

  return 0;
}
