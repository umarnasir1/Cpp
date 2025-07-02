/*
    double store data in 16 bits and float in 8 bits. 
    This is an effect of the fact that numbers stored as floating point data can be different from their real (precise) values.
    We get rounding errors when using floating point numbers. 
    With double type a little bit less precision.

    #include <iostream>
    #include <format>

    int main(){
        float f {};

        f = 0.1 + 0.1 + 0.1; 
        std::cout << format("value of f is {}\n", f);

        if (f == 0.3) std::cout << "true\n"; 
        else std::cout << "false\n"; // this case will be true as f is not exactly equal to 0.3

        return 0;
    }
    
    The same example can be run with double instdead of float. 
    This will display double value to be 0.300000000000000004
    to get more precision of rounding error we can use:
    std::cout << format("value of f is {:.20f}\n", f); // 20 decimal places 
*/

#include <iostream>

int main(){
    //double a {0.1}, b{0.2}, c{0.3}; // numerical anomaly - Your computer is out of order.
    float a {0.1}, b{0.2}, c{0.3}; // but works with floats

    std::cout << "Value of a+b is : " << a+b << std::endl; 

    if (a+b != c)
        std::cout << "Your computer is out of order." << std::endl; 
    else 
        std::cout << "Working." << std::endl; 
}