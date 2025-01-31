#include<iostream>
#include<string>

int main(){

    std::string s1, s2;
    
    std::cout<< "Enter string 1: ";
    getline(std::cin, s1);

    std::cout<< "Enter string 2: ";
    getline(std::cin, s2);

    if (s1.length() == s2.length())
        std::cout<< "Strings are Equal." << std::endl;
    else 
        std::cout<< "Strings are not Equal." << std::endl;

    return 0;
}