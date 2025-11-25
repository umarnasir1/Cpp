// 08-challenge.cpp by Bill Weinman [bw.org]
// updated 2022-06-01
#include <format>
#include <iostream>

using std::format;
using std::cout;

unsigned long factorial(unsigned long n) {
    auto result = n;
    while (n > 1) {
        result *= --n;
    }
    return result;
}

int main() {
    unsigned long n {5};
    cout << format("Factorial of {} is {}\n", n, factorial(n));
}
