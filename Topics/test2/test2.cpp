#include<iostream>

int main(){
    char character{'X'}; 
    int integer{character}; 
    std::cout << character << " " << static_cast<int>(character) << std::endl;
    std::cout << integer << " " << static_cast<char>(integer) << std::endl; 

    return 0; 
}