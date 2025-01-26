// Write a program in C++ to find the sum of first 10 natural numbers.   

#include <iostream>

int main() {
    int sum {}, nNum{1};
    do{
        sum += nNum;
        nNum ++;
    }while ( nNum <= 10);
    
    std::cout << "The sum of first 10 natural numbers is: " << sum << std::endl;

    return 0;
} 