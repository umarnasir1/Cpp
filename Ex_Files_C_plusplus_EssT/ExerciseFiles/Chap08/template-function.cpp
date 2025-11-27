/*
    Template Function that returns the maximum value of two parameters
*/
#include <iostream>

template<typename T>  // templateKeyWord<TemplateArgumentList>
T maxof(T a, T b) {
    return a > b ? a : b;
}

int main() {

    int x {47};
    int y {73};
    auto z = maxof<int>(x, y);
    std::cout << "max is " << z << std::endl;

    return 0;
}
