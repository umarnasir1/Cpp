/*
    Difference between L-value reference and R-value reference
*/
  
#include<iostream>

int main(){
    int x {100}; // x is a l-value as it is addressable and its got a name
    int &l_ref = x; // l-value reference since x is an l-value ; l_ref is reference to x

    std::cout << x << std::endl; 
    std::cout << l_ref << std::endl; 

    l_ref = 10; // change x to 10

    std::cout << x << std::endl; 
    std::cout << l_ref << std::endl; 
    
    // r-value
    int &&r_ref = 200; // r-value reference since 200 is an R-value ; declared by using && operator
    std::cout << r_ref << std::endl; 

    r_ref = 300; // change r_ref to 300; stores 300 into the R-value of where ref refers to so we can change that temporary variable.
    std::cout << r_ref << std::endl;     

    // int &&x_ref = x; // Compiler error: if we try to assign an L-value to an R-value reference
}
  