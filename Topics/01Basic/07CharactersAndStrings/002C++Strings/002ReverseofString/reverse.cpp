/* Write a C++ Program to revrse a string */

#include<iostream>
#include<string>

int main (){
    std::string s1;

    std::cout << "Enter a string: ";
    getline(std::cin,s1);

    for (size_t i{s1.size()-1}; i >= 0; --i)  // some problem in the loop 
        std::cout << s1.at(i);

    std::cout << std::endl;

    return 0;
} 