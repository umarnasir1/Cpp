/*
    Example: 
    Operator Overloading as Non-member Functions

    Overloaded + operator will add two Money objects together and return a Money object representing
    their sum. This overloaded operator function should not modify the objects in any way.
*/

#include "Money.h"
#include <iostream>

int main(){
    Money one {4, 70};
    Money two {6, 38}; 
    Money three {50, 45}; 

    Money total = one + two; //  Total Dollars: 11, Total Cents: 8
    std::cout << "Total Dollars: " << total.get_dollars() << ", "
              << "Total Cents: " << total.get_cents() << std::endl;

    // total = one + three; // Total Dollars: 55, Total Cents: 15
    // total = two + three; // Total Dollars: 56, Total Cents: 83

    return 0; 
}