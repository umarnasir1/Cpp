/* 
 
 std::format is new feature of c++20

 format() returns a string.
 */
#include <format> // C++20
#include <iostream>
#include <string>
#include <numbers>

int main() {

    // Int
    int i {}, x {42};
    std::cout << std::format("The value of i is {} and x is {}\n", i, x); // The value of i is 0 and x is 42

    // Strings
    const char* strc {"C-Style String"}; // C-Style string
    std::cout << std::format("The string is {}\n", strc); // The str is C-Style String
    
    std::string strcpp {"C++ String"};
    std::cout << std::format("The string is {}\n", strcpp); // The str is C++ String
    // position arguments
    std::cout << std::format("Hello: {}, {}\n", strc, strcpp); // Hello: C-Style String, C++ String
    std::cout << std::format("Hello: {1}, {0}\n", strc, strcpp); // Hello: C++ String, C-Style String

    //std::cout << std::format(" {} is {}\n", hello, string[i]);

    // array 
    int test_scores [5] {100, 95, 99, 87, 88};
    for (int i{1}; i<=5; ++i)
        std::cout << std::format("Score {}: {}\n", i, test_scores[i]); // Score 1: 95 .... Score 5: 2

    //vector

    // define a pointer 
    //std::cout << std::format("The value of *ip is {}\n", *ip);

    // double and e.g. of decimal place
    const double pi {std::numbers::pi}; 
    std::cout << std::format("Value of pi is {}\n", pi); // Value of pi is 3.141592653589793
    std::cout << std::format("Value of pi is {:.15}\n", pi); // displaying precision of double - Value of pi is 3.14159265358979
    
}
