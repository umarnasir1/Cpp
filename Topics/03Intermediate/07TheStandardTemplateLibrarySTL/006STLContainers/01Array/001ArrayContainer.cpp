#include <iostream>
#include <array> // header file for the array container

void main(){

    // array declaration & initialization
    std::array <int, 3> testArr1 { 10, 20,30 }; // C++14
    // std::array <int, 3> testArr1 { { 10, 20,30 } }; In c++11, we need to provide double curly braces.

    // If we have more than 5 integers in the initializer list, we'll get an error.
    // If we have fewer than 5, the remaining integers omitted will be set to 0.

    std::array<std::string, 3> stooges { 
        std::string {"Larry"}, // check if round or curley brackets 
        "Moe", // C-style string literals will be convered into std::string
        std::string {"Curly"}
    };

    // methods
    
}