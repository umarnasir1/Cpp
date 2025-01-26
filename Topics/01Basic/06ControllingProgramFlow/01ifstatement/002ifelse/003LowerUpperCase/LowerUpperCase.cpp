/*
    Write a program to check whether a entered character is lowercase ( a to z ) or uppercase ( A to Z ).
*/

#include <iostream>

int main (){

    char character {};

    std::cout << "Enter a character for a/A to z/Z :";
    std::cin >> character;

    if (
        character >= 65 && character <= 90)
        std::cout << "The character is upper case." << std::endl;
    else 
        std::cout << "The character is lower case." << std::endl;

    return 0;
}