// Write a C++ program to replace a with $ 

#include<iostream>
#include<string>

int main (){
    std::string s1;

    std::cout << "Enter a string: ";
    getline(std::cin,s1);

    for (size_t i{}; i<s1.size(); ++i)
        if (s1.at(i) == 'a')
            s1.at(i) = '$'; 

    // replace all occurances of 'a' except the first occurance
    /*int count {};
    for (size_t i{}; i<s1.size(); ++i){
        if (s1.at(i) == 'a' && count == 0)
            count++;
        else if (s1.at(i) == 'a' && count != 0)
            s1.at(i) = '$'; 
        else 
            std::cout << "a is not found." << cout::endl;
    } */   
    
    std::cout << s1 << std::endl;

    return 0;
} 
