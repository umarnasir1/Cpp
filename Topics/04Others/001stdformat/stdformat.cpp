/* 
 
 std::format is new feature of c++20

 format() returns a string.
 */
#include <format> // C++20
#include <iostream>
#include <string>

int main() {

    // Eg. 1
    int i {};
    std::cout << std::format("i is {}\n", i); //i is 0

    // Eg. 2
    const char* str {"Hello, World!"}; // C-Style string
    std::cout << std::format("The str is {}\n", str); // The str is Hello, World!

    // Eg. 3
    int x {42}, y {50};
    std::cout << std::format("The value of x is {}\n", x); // The value of x is 42
    std::cout << std::format("The value of y is {}\n", y); // The value of y is 50
    
    // define an array 
    //std::cout << std::format("Element {} is {}\n", i, array[i]); 

    // define a string
    //std::cout << std::format("Element {} is {}\n", i, string[i]);
    
    // define a pointer 
    //std::cout << std::format("The value of *ip is {}\n", *ip);

    // e.g. of decimal place
    //std::cout << std::format("Value of df is {:.20f}\n", df); // displaying precision of double - // 20 decimal places 
    
}
