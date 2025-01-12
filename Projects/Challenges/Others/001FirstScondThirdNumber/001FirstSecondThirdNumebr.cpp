// Write a program in C++ to print the first, second, and third no. in a three digit no. 
#include <iostream>

int main (){

    int num {};

    std::cout << "Enter a three digit number: ";
    std::cin >> num;

    std::cout << "The first digit number is: " << num/100 << std::endl;
    std::cout << "The second digit number is: " << (num%100)/10 << std::endl; // Alternate logic: (num/100)%10
    std::cout << "The last digit number is: " << num%10 << std::endl;

    return 0;
}