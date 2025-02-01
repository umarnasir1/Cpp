/* Write a C++ program to check a number is in the range 100 to 200.*/

#include<iostream>

int main(){

    int number {};

    std::cout<< "Enter a number: ";
    std::cin>> number;

    if (number >=100 && number <=200)
        std::cout<< "The number " << number << " is in the range 100-200." << std::endl;
    else
        std::cout<< "The number is not in the range." << std::endl;

    return 0;
}