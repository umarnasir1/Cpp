/* Write a C++ program to check if a given number is a multiple of 3 */

#include<iostream>

int main(){

    int number {};

    std::cout<< "Enter a number: ";
    std::cin>> number;

    if (number%3 == 0)
        std::cout<< "The number " << number << " is a multiple of 3." << std::endl;
    else
        std::cout<< "The number is not a multipe of 3." << std::endl;

    return 0;
}