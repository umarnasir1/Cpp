/*
    L-value and R-value reference parameters
    we can overload these functions and have both of them in our code at the same time since they have unique signatures. 
    Compiler will call the correct function depending on whether the parameter is an L-value or and R-value.
*/

#include<iostream>

int main (){

    int x {100};

    void func(int &num);
    void func(int &&num);

    func(x); // l -value
    func(200); // r-value
    
    return 0; 
}


