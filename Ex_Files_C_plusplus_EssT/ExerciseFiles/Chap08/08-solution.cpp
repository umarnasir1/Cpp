// 08-solution.cpp by Bill Weinman [bw.org]
// updated 2022-06-04
#include <format>
#include <iostream>

using std::format;
using std::cout;

// non-recursive factorial template
template<typename T>
T factorial(T n) {
    auto result = n;
    while(n > 1) {
        result *= --n;
    }
    return result;
}

int main() {
    int i {5};
    cout << format("{}! is {}\n", i, factorial(i));

    long long unsigned int llui {15};
    cout << format("{}! is {}\n", llui, factorial(llui));
    
    long double ld {25};
    cout << format("{}! is {:-4.5}\n", ld, factorial(ld));
}
