#include<iostream>

int main(){

  int rows {};

  std::cout << "Enter number of rows :";
  std::cin >> rows;

  for (int i{1}; i <= rows; i++){ // rows
    for (int j{1}; j<=i; j++) // cols
      std::cout << "* ";
    std::cout << std::endl;
  }

  return 0;
}
