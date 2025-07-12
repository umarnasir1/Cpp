/*
    storage duration static
        it will no longer disards that variable and rainitializes it each time the function is called.
        initializes it once and uses that same static memory space every time it is called. 
*/
#include <iostream>

int func() {
    static int x {7}; // static - just initialize it once,
    return ++x;
}

int main() {
    int i {42};
    // cont int i {42}; will make the value of i to be constant (immutable), and read only. 
    std::cout << "The integer is " << i << std::endl;
    std::cout << "Function reutns " << func() << std::endl; // 8 if int x {7}; 8 if static int {7}
    std::cout << "Function reutns " << func() << std::endl; //8 (if int x {7}); 9 if static int {7} 
    std::cout << "Function reutns " << func() << std::endl; //8 (if int x {7}); 10 if static int {7}
    return 0; 
}


