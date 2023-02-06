/*
    R-value reference parameters
    R-value references in the context of function parameters.
*/

#include<iostream>

int main (){
    
    int x {100}; // x is an L-value
  
    void func(int &&num); // fucntion prototype- exects an R-value reference as its denoted by &&;
  
    func(200); // ok since 200 is an r-value and as num is a reference to r-value
    // func(x); // Error since x is l-value

    return 0; 
}

