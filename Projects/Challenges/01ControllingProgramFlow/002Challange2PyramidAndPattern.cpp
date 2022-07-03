// Example 1:
// Program to print half pyramid using *

// #include <iostream>
//
// int main(){
//
//   int rows {};
//
//   std::cout << "Enter number of rows: ";
//   std::cin >> rows;
//
//   for (int i{1}; i <= rows; i++){ // rows
//     for (int j{1}; j <= i; j++) // cols
//       std::cout << "* ";
//     std::cout << std::endl;
//   }
//
//   return 0;
// }

// Example 2:
// Program to print pyramid using numbers
// #include <iostream>
//
// int main(){
//
//   int rows {};
//
//   std::cout << "Enter number of rows: ";
//   std::cin >> rows;
//
//   for (int i{1}; i <= rows; i++){ // rows
//     for (int j{1}; j <= i; j++) // cols
//       std::cout << j << " ";
//     std::cout << std::endl;
//   }
//
//   return 0;
// }

// Example 3:
// Program to print half pyramid using alphabets
// #include <iostream>
//
// int main(){
//
//   char alphabet = 'A', user_input;
//
//   std::cout << "Enter the uppercase character to be printed in the last row: ";
//   std::cin >> user_input;
//
//   for (int i{1}; i <= (user_input-'A'+1); i++){ // rows - https://en.cppreference.com/w/cpp/language/ascii, iterations -user_input-'A'+1
//     for (int j{1}; j <= i; j++) // cols
//       std::cout << alphabet << " ";
//     ++alphabet;
//     std::cout << std::endl;
//   }
//
//   return 0;
// }

// Example 4:
// Inverted half pyramid using *
// #include <iostream>
//
// int main (){
//
//   int rows {};
//
//   std::cout << "Enter the number of rows: ";
//   std::cin >> rows;
//
//   for (int i{rows}; i >= 1; i--){
//     for (int j{1}; j <= i; j++)
//       std::cout << "* ";
//     std::cout << std::endl;
//   }
//
//   return 0;
// }

// Example 5:
// Inverted half pyramid using numbers
# include <iostream>

int main (){

  int rows;

  std::cout << "Enter number of rows: ";
  std::cin >> rows;

  for (int i{5}; i>=1; --i){
    for (int j{1}; j<=i; ++j)
      std::cout << j << " ";
    std::cout << std::endl;
  }
  return 0;
}
