/* Write a C++ Program to revrse a string 

#include<iostream>
#include<string>

int main (){
    std::string s1;

    std::cout << "Enter a string: ";
    getline(std::cin,s1);

    for (size_t i{s1.size()-1}; i >= 0; --i)  // some problem in the loop, instead of i going to -1 instead of 0, its going to  18446744073709551615
        std::cout << s1.at(i); // if do it as a code, then why error if using at code.

    std::cout << std::endl;

    return 0;
} */


//3. Write a C++ program to reverse a string 
#include <iostream>
#include <string>

int main()
{
    std::string var1;

    std::cout << "enter a string :";
    getline(std::cin, var1);

    std::cout << std::endl;

    for (int i=var1.size(); i >= 0; i--)
        std::cout << var1[i];

    std::cout << std::endl;
    return 0;
}
