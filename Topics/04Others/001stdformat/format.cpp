/* To check if 
 updated 2025-06-24
 
 std::format is new feature of c++20
 if we want to use this format library download and install from reference implimentation

 https://fmt.dev/latest/index.html

 conclusion: std::format is not supported yet
 We will be using format to format strings in this course. 
 */
#include <cstdio>
#include <format> // C++20
#include <iostream>

int main() {

    // Eg. 1
    const char* str {"Hello, World!"};
    std::cout << std::format("The str is {}\n", str); // this will give error as std::format is not working

    // Eg. 2
    int x {42};
    auto str = std::format("x is {}\n", x);
    std::cout << str;

    // Eg. 3
}
