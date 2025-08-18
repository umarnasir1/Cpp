/* To check if 
 updated 2025-06-24
 
 std::format is new feature of c++20
 if we want to use this format library download and install from reference implimentation

 https://fmt.dev/latest/index.html

 conclusion: std::format is not supported yet
 We will be using format to format strings in this course. 

 format() returns a string.
 */
#include <cstdio>
#include <format> // C++20
#include <iostream>

int main() {

    // Eg. 1
    int i {};
    std::cout << std::format("i is {}\n", i);

    // Eg. 2
    const char* str {"Hello, World!"};
    std::cout << std::format("The str is {}\n", str); // this will give error as std::format is not working

    // Eg. 3
    int x {42};
    auto str = std::format("x is {}\n", x);
    std::cout << str;

    //
    std::cout << std::format("Element {} is {}\n", i, array[i]); 
    std::cout << std::format("Element {} is {}\n", i, string[i]);
    std::cout << std::format("The value of x is {}\n", x);
    std::cout << std::format("The value of y is {}\n", y);
    std::cout << std::format("The value of *ip is {}\n", *ip);
    std::cout << std::format("Value of df is {:.20f}\n", df); // displaying precision of double - // 20 decimal places 
}
