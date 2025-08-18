/*
    Objective: Create a non-recursive function to calculate factorials, avoiding the issues of stack overflow that can occur 
    with recursive functions.

    Challenge Goal: Write a function that takes a value and returns its factorial without using recursion.
*/

#include <iostream>

unsigned long long factorial (unsigned long long n); 

int main (){
    unsigned long long num{0};
    std::cout << "Enter the number: "; 
    std::cin >> num; 
    std::cout << "The factorial of " << num << " is " << factorial(num) << std::endl;
    return 0; 
}

unsigned long long factorial (unsigned long long n){
    auto fac{n};

    do{
        fac *= --n; 
    }while(n>1);

    return fac;
}

// Alternative with while 
/*
    while (n>1){
        fac *= --n; 
    }
*/