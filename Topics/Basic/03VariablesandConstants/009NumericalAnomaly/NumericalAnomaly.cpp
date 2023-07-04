/*
    double store data in 16 bits and float in 8 bits. 
    This is an effect of the fact that numbers stored as floating point data can be different from their real (precise) values.
*/

#include <iostream>

int main(){
    // double a {0.1}, b{0.2}, c{0.3}; // numerical anomaly
    float a {0.1}, b{0.2}, c{0.3}; // but works with floats

    if (a+b != c)
        std::cout << "Your computer is out of order." << std::endl; 
}