#include <iostream>


int main (){

    int side {};

    std::cout << "Enter the lenght of a side of a square: ";
    std::cin >> side;

    std::cout << "The area of the square is: " << side*side << std::endl;

    return 0;
}