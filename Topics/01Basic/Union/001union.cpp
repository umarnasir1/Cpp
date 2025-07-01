#include<iostream>

union x {
    int a; // int a{}; when we initilize, it gives error .. check later y 
    float b; // float b{}; 
    char c[25];
};

int main () {
    return 0; 
}