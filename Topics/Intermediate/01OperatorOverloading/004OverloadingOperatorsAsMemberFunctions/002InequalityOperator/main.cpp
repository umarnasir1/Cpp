#include <iostream>
#include "Money.h"
#include <cstring>

int main (){

    Money one {4, 70};
    Money two {4, 38}; 
    Money three {4, 70}; 
    
    std::cout << std::boolalpha << std::endl; 
    std::cout << (one == two) << std::endl; 
    std::cout << (one == three) << std::endl; 

    std::cout << "\n!=" << std::endl; 
    std::cout << (one != two) << std::endl; 
    std::cout << (one != three) << std::endl; 

    return 0; 
}