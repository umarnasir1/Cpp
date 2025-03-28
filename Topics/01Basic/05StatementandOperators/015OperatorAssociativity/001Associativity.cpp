#include<iostream>

int main(){

    int var1 {10}, var2 {20}, var3{30};
    float total {0};

    // Ex1
    //total = var2 - var3 + var1; // 0;  - amd + have same presidence. so associativity is left to right 
    
    // Ex2
    // total = ++var2 - --var3 + var1; // 2  
    // Uniary operators have higher presidence so will perform ++ and -- first
    // ++ and -- have same presidence, so associativity is right to left so -- will be performed first and then  ++  ( 21 - 29 + 10)
    // - amd + have same presidence. so associativity is left to right (-8 + 10 )

    // Ex3
    // total = var2++ - var3-- + var1; // 0 
    // Uniary operators have higher presidence so will perform ++ and -- first. 
    // ++ and -- have same presidence, so associativity is right to left so -- will be performed first and then  ++, but as it is post 
    //   increment/decrement, the value of var3 and var2 will be decremented/incremented later (after evaluation of the statement).  ( 20 - 30 + 10)
    // - amd + have same presidence. so associativity is left to right (-10 + 10 )

    // Ex4
    // total = var2++ - (var3+ var1); // -20
    // Brackets will have higher precision 
    // After it the post increment operator will be solved but the value will be increment after the expression is completely evaluated
    //   (20++ - 40) -> (20 - 40)

    // Ex5
    total = var1 + var3 - 2*var2; // 0
    // First will multiple 
    // Precedence is same of + and -, but associativity says solve it from L to R

    std::cout << total << std::endl;

    return 0;
}