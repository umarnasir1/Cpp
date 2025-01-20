/*
  Nested Loops
*/

#include <iostream>
#include <vector>

int main (){

  // Eg 1: basic eg.
  for (int outer_val {1}; outer_val <= 2; ++outer_val)
    for (int inner_val {1}; inner_val <= 3; ++inner_val)
      std::cout << outer_val << " , " << inner_val << std::endl;

  // Eg 2: Multiplication Table from 1 to 10 (10x each)
  for (int num1 {1}; num1 <= 10; ++num1){
    for (int num2 {1}; num2 <= 10; ++num2)
      std::cout << num1 << " x " << num2 << " = " << num1*num2 << std::endl;
    std::cout << "---------------------------" << std::endl;
  }

  // Eg 3: Nested Loop using 2D array
  int grid[5][3] {};

  for (int row {0}; row < 5; ++row){
    for (int col {0}; col < 3; ++col){
      grid[row][col] = 1000; // setting all elements to 1000
      std::cout << grid[row][col] << " "; // displaying
    }
    std::cout << std::endl;
  }

  // Eg. 4: Nested loop with vectors
  std::vector <std::vector <int>> vector_2d {
    {1, 2, 3},
    {10, 20, 30, 40},
    {100, 200, 300, 400, 500}
  };

  for (auto vec: vector_2d){
    for (auto val: vec)
      std::cout << val << " ";

    std::cout << std::endl;
    }


  // Eg. 5: Histogram
  // grab some user input, put them in a vector and display a histogram based on those numbers.

  int num_items {};

  std::cout << "How many data items do you have ? ";
  std::cin >> num_items;

  // using vector to store user data since we dont know how big to make it as we dont know what number user is going to type in so array whould not be a good idea because we dont know how big to make it.
  std::vector <int> data;

  for (int i {1}; i <= num_items; ++i){
    int data_item {};
    std::cout << "Enter data item # " << i << ": "; // asking user for data
    std::cin >> data_item;
    data.push_back(data_item); //putting collected data in a vector
  }

  // displaying data just to test
  //for (auto value: data) //
  //  cout << value << endl;

  std::cout << "\nDisplaying Histogram" << std::endl;
  for (auto val: data){
    for (int i {1}; i <= val; ++i){ // to display dashes instead of value and every 5th * instead of -
      if (i % 5 != 0)
        std::cout << "-";
      else
        std::cout << "*";
    }
    std::cout << std::endl;
  }

  return 0;
}
