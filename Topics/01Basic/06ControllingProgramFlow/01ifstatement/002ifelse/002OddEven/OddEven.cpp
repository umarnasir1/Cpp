/*
    Write a program in C++ that take a number as input & check whether number is Odd or Even.
*/
#include <iostream>

int main (){
    int number {};
    std::cout << "Enter a number :";
    std::cin >> number;

    if (number%2 == 0)
        std::cout << "The number is Even." << std::endl;
    else 
        std::cout << "The number is Odd." << std::endl;
    return 0;
}