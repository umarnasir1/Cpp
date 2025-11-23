#include <iostream>

class C1 { // default data memebers are private 
        int num1 {}; 
        int num2 {}; 
        int num3 {};    
    public:
        C1 (int a, int b, int c) : num1{a}, num2{b}, num3{c} {} // Constructor Initialization List
        // setters 
        void setnum1 (int a) { num1 = a; } 
        void setnum2 (int b) { num2 = b; }
        void setnum3 (int c) { num3 = c; }
        // getters 
        int getnum1 () {return num1; }
        int getnum2 () {return num2; }
        int getnum3 () {return num3; }
};

int main (){
    C1 o1 {47, 37, 85}; // creating object and initializing via objects (constuctor initialization list)
    // std::cout << o1.num1 << " " << o1.num2 << " " << o1.num3 << std::endl; // error as num1, num2, num3 are private
    std::cout << o1.getnum1() << " " << o1.getnum2() << " " << o1.getnum3() << std::endl;
    o1.setnum1(55); // setting num1 
    o1.setnum2(80);
    o1.setnum3(99);
    std::cout << o1.getnum1() << " " << o1.getnum2() << " " << o1.getnum3() << std::endl;
    return 0; 
}