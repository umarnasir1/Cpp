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

    std::cout << "Enter the third stoogeäs first name: "; 
    std::cin >> curly; //reaing data into curley

    std::cout << "The three stooges are " << larry << ", " << moe << " and " << curly << std::endl;  

    std::cout << "\nEnter the three stooges name separated by a space: "; 
    std::cin >> larry >> moe >> curly; 

    std::cout << "The three stooges are " << larrry << ", " << moe << " and " << curly << std::endl;

    // Player hero {"Hero", 100, 33}; 
    // std::cout << hero << std::endl; // {name: Hero, health: 100, xp: 33}

    // std::cin >> hero; // reading data into hero

    return 0; 
}


// Overloading stream insertion operator (<<)
std::ostream &operator<<(std::ostream &os, const Mystring &obj){
    os << obj.str; // if friend function (we will havve access to all private data members.)
    // os << obj.get_str(); // if not friend function - using getters to access private members
    return os; // returning output stream reference.
}

// Overloading stream extraction operator (>>)
// depending on the data we want to read, we can get the data from the input stream and either store 
// it locally or store it directly in the object.
std::istream &operator>>(std::istream &is, Mystring &obj){
    char *buff = new char[100]; // allocating array of characters to hold data we want to construct a Mystring object
    is >> buff; 
    obj = Mystring{buff}; // If we have copy or move assignment - creating a temporary Mystring object and assign it back to the object that was passed in. 
    delete [] buff; 
    return is; // return a reference to the istream so we can chain assign
}