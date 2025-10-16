// l-value reference parameters
// L-value references in the context of function parameters.

#include<iostream>

int main (){
    
    int x {100}; // x in an L-value

    void func(int &num); // function prototype-func expects an L-value reference (as denoted by &)

    func(x); // okay since x is an L-value and num will be the reference to an L-value
    // func(200); // Error as 200 is R-value

    return 0; 
}

