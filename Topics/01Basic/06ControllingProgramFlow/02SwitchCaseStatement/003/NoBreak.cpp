/*
    Program without break
    As no break statement, the output will be all cases
    AbcdefGhijklMnopqrstUvwxyz. 
*/

#include <iostream>

int main(){

    int a = 1;

    switch(a){
    case 1: std::cout<< "Abcdef";
    case 2: std::cout<<"Ghijkl";
    case 3: std::cout<<"Mnopqrst";
    default: std::cout<<"Uvwxyz";
    }

    return 0;
}