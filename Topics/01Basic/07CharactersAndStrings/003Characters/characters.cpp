#include<iostream>

int main(){
    char character1 = 'A';
    character1 += 32; 
    std::cout << "Character1: " << character1 << std::endl; // a

    std::cout << 'A' + ' ' << std::endl; //97
    std::cout << 65 + ' ' << std::endl; // 
    std::cout << 97 - ' ' << std::endl; //  
    std::cout << 'a' - 32 << std::endl; // 
    std::cout << 'a' - ' ' << std::endl; //

    return 0; 
}