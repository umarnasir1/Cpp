// Write a C++ program to delete all the vowels from the string. 

#include<iostream>
#include<string>

int main (){
    std::string s1;

    std::cout << "Enter a string: ";
    getline(std::cin,s1);

    for (size_t i{}; i<s1.size(); ++i)
        if (s1.at(i) == 'a' || s1.at(i) == 'e' || s1.at(i) == 'i' || s1.at(i) == 'o'|| s1.at(i) == 'u' )
            s1.at(i) = ' '; 
    
    std::cout << s1 << std::endl;

    return 0;
} 
