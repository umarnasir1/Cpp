#include <iostream>


int main (){

    /*
    int side {};

    std::cout << "Enter the lenght of a side of a square: ";
    std::cin >> side;

    std::cout << "The area of the square is: " << side*side << std::endl;

    */
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