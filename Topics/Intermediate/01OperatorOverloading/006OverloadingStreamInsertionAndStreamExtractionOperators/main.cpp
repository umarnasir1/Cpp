/*
    Overloading stream insertion (<<) and extraction operators (>>)

    Mystring.h - class specification
    Mystring.cpp - class definition
    main.cpp
*/

#include<iostream>
#include "Mystring.h"

int main(){
    Mystring larry {"Larry"};
    Mystring moe {"Moe"}; 
    Mystring curly; // empty string

    std::cout << "Enter the third stooges first name: "; 
    std::cin >> curly; //reaing data from cin into curley - overloading >> operator to work with Mystring object.  

    std::cout << "The three stooges are " << larry << ", " << moe << " and " << curly << std::endl;  

    std::cout << "\nEnter the three stooges name separated by a space: "; 
    std::cin >> larry >> moe >> curly; 

    std::cout << "The three stooges are " << larry << ", " << moe << " and " << curly << std::endl;

    // Player hero {"Hero", 100, 33}; 
    // std::cout << hero << std::endl; // {name: Hero, health: 100, xp: 33}

    // std::cin >> hero; // reading data into hero

    return 0; 
}