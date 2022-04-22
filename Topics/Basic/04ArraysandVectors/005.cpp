/*
  storing a hard-coded board
  write a function to print out the board
  read the board from a file

*/
#include<iostream>
#include<vector>

using std::vector;
using std::cout;
using std::endl;

int main(){

  vector <vector<int>> board{
    {0, 1, 0, 0, 0, 0},
    {0, 1, 0, 0, 0, 0},
    {0, 1, 0, 0, 0, 0},
    {0, 1, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 0}
  };

  cout << board.at(0).at(0) << endl;

  return 0;
}


// In the next exercise, you will write two for loops to print the contents of a 2D vector so you will be able to print the grid in your project!
