#include<iostream>

int main(){
    char character{'X'}; 
    int integer{character}; 
    std::cout << character << " " << static_cast<int>(character) << std::endl; // casting char to int
    std::cout << integer << " " << static_cast<char>(integer) << std::endl; // casting int to char

    return 0; 
}