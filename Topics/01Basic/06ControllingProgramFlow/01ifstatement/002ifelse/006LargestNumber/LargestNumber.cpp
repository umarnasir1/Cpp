/* Write a C++ program to check the largest number among three given integers.*/

#include<iostream>

int main(){

    int number1 {}, number2 {}, number3 {};

    std::cout<< "Enter a number1: ";
    std::cin>> number1;
    std::cout<< "Enter a number2: ";
    std::cin>> number2;
    std::cout<< "Enter a number1: ";
    std::cin>> number3;

    if (number1 > number2 && number1 > number3)
        std::cout<< "The number " << number1 << " is the largest number." << std::endl;
    else if (number2 > number1 && number2 > number3)
        std::cout<< "The number " << number2 << " is the largest number." << std::endl;
    else if (number3 > number1 && number3 > number2)
        std::cout<< "The number " << number3 << " is the largest number." << std::endl;
    else
        std::cout<< "Some Problem! like the entered number are equal." << std::endl;

    return 0;
}