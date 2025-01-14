/*
  Multi-dimensional arrays
  Modeling real world data - movie ratings 0-5
  rows - reviewers (for each revieer)
  cols - movies (for each movie)

  Either We could declaring three arrays of four integers each or use Multi-dimensional array.
  Multi-Dimentional array - similar to layout of a spread sheet.

  With 2D vector, we can allow each vector within the vector 2D to be of different size. E.g., 
  vector <vector <int>> vector_2d {
    {1, 2, 3},
    {10, 20, 30, 40},
    {100, 200, 300, 400, 500}
  };
*/

#include <iostream>

int main(){

  // Declaration
  // const int rows {3};
  // const int cols {4};
  // int movie_rating [rows][cols]; // size of array = 12 integers.

  // Initializing multi-dimensional arrays
  int movie_rating [3][4]{
    { 0, 4, 3, 5},
    { 2, 3, 3, 5},
    { 1, 4, 4, 5}
  };

  // Accessing array elements in multi-dimensional arrays
  std::cout << "Enter rating for Reviewer 0; Movie 0: ";
  std::cin >> movie_rating [0][0];
  std::cout << "====================================" << std::endl;
  std::cout << "Revier 0 reviewd movie 0 as as : " << movie_rating [0][0] << std::endl;
  std::cout << "Revier 0 reviewd movie 1 as as : " << movie_rating [0][1] << std::endl;
  std::cout << "Revier 0 reviewd movie 2 as as : " << movie_rating [0][2] << std::endl;
  std::cout << "Revier 0 reviewd movie 3 as as : " << movie_rating [0][3] << std::endl;
  std::cout << "Revier 1 reviewd movie 0 as as : " << movie_rating [1][0] << std::endl;
  std::cout << "Revier 1 reviewd movie 1 as as : " << movie_rating [1][1] << std::endl;
  std::cout << "Revier 1 reviewd movie 2 as as : " << movie_rating [1][2] << std::endl;
  std::cout << "Revier 1 reviewd movie 3 as as : " << movie_rating [1][3] << std::endl;
  std::cout << "Revier 2 reviewd movie 0 as as : " << movie_rating [2][0] << std::endl;
  std::cout << "Revier 2 reviewd movie 1 as as : " << movie_rating [2][1] << std::endl;
  std::cout << "Revier 2 reviewd movie 2 as as : " << movie_rating [2][2] << std::endl;
  std::cout << "Revier 2 reviewd movie 3 as as : " << movie_rating [2][3] << std::endl;
  return 0;
}
