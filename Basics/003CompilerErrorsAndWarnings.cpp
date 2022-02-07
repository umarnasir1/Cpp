// Syntax Error
// Semantic Error
// Compiler Warnings: The compiler has recognized an issue with your code, the only warning is because the compiler is still able to generate correct machine code. OBS!! Do not ignore- try to correct it
// Linker Errors

#include <iostream>

int main() { // Syntax Error 1: if { missing
  std::cout << "Hellow World!!" << std::endl; // Syntax Error 2:  is " missing or if enld instead of endl
  // Semantic Error 1: std::cout << ("Hellow World!!" /125) << std::endl;
  return "Joe"; // Semantic Error 2: as we wrote above that the program will return an int but it is returning string - compiler will give an error as it will try to figure out how to convert that Joe to integer.
  // Syntax Error 3: if ; missing after return 0
}

// Eg. of Compiler Warning - The comipler can give warning to be caseful because anything could print here.
// int main(){
//     int favourite_number;
//     std::cout << favourite_number << std::endl;
//}

// Eg. of Compiler Warning - Now we have created a variable and assigned a value to it but we havent used it so compiler will give a warning - that variable favorite number is set but not used. Additionally, if we create a varibale and we not use it, e.g we remove the line favorite_number = 100; then we will get warning: unsed variable (that we created a variable but not used it)
// int main(){
//     int favourite_number;
//     favorite_number = 100;
//     std::cout << "Hello World" << std::endl;
//}
