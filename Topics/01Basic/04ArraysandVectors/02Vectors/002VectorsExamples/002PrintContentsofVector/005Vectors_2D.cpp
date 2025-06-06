/*
  Print the board.
     print the contents of a 2D vector

  storing a hard-coded board
  write a function to print out the board

  declare a variable board as a vector of vectors of ints
  Write a void PrintBoard function. The function should accept the board as an argument. The function should print each row of the board with a newline.
  When you have written your PrintBoard function, call it from within main() to print the board.
*/
#include<iostream>
#include<vector>

int PrintBoard (std::vector <std::vector<int>> board);  // Function Prototype

int main(){

  std::vector <std::vector<int>> board{
    {0, 1, 0, 0, 0, 0},
    {0, 0, 1, 0, 0, 0},
    {0, 1, 0, 0, 0, 0},
    {1, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 0}
  };

  PrintBoard(board);

  return 0;
}

int PrintBoard (std::vector <std::vector<int>> board) { // nested for loops to print the contents of a 2D vector
  for (auto row: board){ // for row in matrix
    for (auto i: row) // for col in row
      std::cout << i;
    std::cout << std::endl;
  }
  return 0;
}
