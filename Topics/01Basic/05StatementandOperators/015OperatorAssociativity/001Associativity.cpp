#include<iostream>

int main(){

    int var1 {10}, var2 {20}, var3{30};
    float total {0};

    // Ex1
    //total = var2 - var3 + var1; // 0;  - amd + have same presidence. so associativity is left to right 
    
    // Ex2
    total = ++var2 - --var3 + var1; // 2  
    // Uniary operators have higher presidence so will perform ++ and -- first
    // ++ and -- have same presidence, so associativity is right to left so -- will be performed first and then  ++  ( 21 - 29 + 10)
    //- amd + have same presidence. so associativity is left to right (-8 + 10 )

    std::cout << total << std::endl;

    return 0;
}