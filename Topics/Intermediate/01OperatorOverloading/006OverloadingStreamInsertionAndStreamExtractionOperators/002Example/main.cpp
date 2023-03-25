/*
    Operator Overloading the Stream Insertion Operator

    Add the overloaded stream insertion  << operator so that it displays a Money object on a output stream as follows:
    If the Money object models 1 dollar and 70 cents, the output should be:
        Money amount {1, 70};
        std::cout << amount;
    dollars: 1 cents: 70 
    no '\n' or endl should be added. 
*/

#include<iostream>
#include "Money.h"

int main(){
    Money amount {1,70};
    std::cout << amount; 

    return 0; 
}