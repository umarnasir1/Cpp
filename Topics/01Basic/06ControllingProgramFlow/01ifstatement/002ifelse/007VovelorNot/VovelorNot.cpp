/* Write a C++ program to check the character entered is vowel or not. */

#include<iostream>

int main(){

    char c;

    std::cout<< "Enter a Character:";
    std::cin>> c;

    if ((c == 'a' || c == 'A') || (c == 'e'|| c == 'E') || (c == 'i' || c == 'I') || (c == 'o' || c == 'O')|| (c == 'u' || c == 'U'))
        std::cout<< "The entered character " << c << " is a vovel." << std::endl;
    else
        std::cout<< "The entered character " << c << " is not a vovel." << std::endl;

    return 0;
}