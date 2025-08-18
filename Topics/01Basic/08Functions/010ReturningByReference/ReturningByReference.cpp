/*
    How to avoid stack overflow?
    Returning large values?
    Solution: Return it as a reference. 
*/

#include <iostream>
#include <string>

const std::string& func(); //returning std:string& 

int main (){
    std::cout << "main()" << std::endl; 
    const auto &x = func(); // as the func is returning a reference so x is reference too and const to avoid side effects
    std::cout << x << std::endl; 
    // return is in the fucntion
}

const std::string& func(){ // const as we are returning through reference to avoid side effects. 
    static std::string s {"Here we go again!"};// not stored on the stack as static as this example is for larger values which can overflow stack; 
    std::cout << "func()" << std::endl; 
    return s; // returning std:string& ; We are returning s through a reference, it will return reference to x (line 14) 
}