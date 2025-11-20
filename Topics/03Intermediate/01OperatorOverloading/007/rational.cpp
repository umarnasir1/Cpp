/*

*/
#include <format>
#include <iostream>
#include <string>

using std::format;

const std::string nanstr {"[NAN]"};

class Rational {
    int n {0};
    int d {1};
public:
    Rational(int numerator = 0, int denominator = 1) : n(numerator), d(denominator) {}
    Rational(const Rational & rhs) : n(rhs.n), d(rhs.d) {}    // copy constructor
    ~Rational();
    int numerator() const { return n; };
    int denominator() const { return d; };
    Rational reduce() const;    // reduce fraction
    std::string str() const;         // return a formatted STL string
    std::string raw_str() const;     // return a non-reduced STL string
    Rational& operator = (const Rational&);  // assignment
    Rational operator + (const Rational&) const;
    Rational operator - (const Rational&) const;
    Rational operator * (const Rational&) const;
    Rational operator / (const Rational&) const;
};

Rational Rational::reduce() const {
    if(n == 0 || d <= 3) return *this;
    for(auto div = d - 1; div; --div) {
        if(n % div == 0 && d % div == 0) {
            return Rational(n / div, d / div );
        }
    }
    return *this;
}

std::string Rational::str() const {
    if(d == 0) return nanstr;
    if(d == 1 || n == 0) return std::to_string(n);

    auto abs_n = abs(n);     // absolute value
    if(abs_n > d) {
        auto whole = n / d;
        auto remainder = abs_n % d;
        if(remainder) return std::to_string(whole) + " " + Rational(remainder, d).str();
        else return std::to_string(whole);
    } else {
        return reduce().raw_str();
    }
}

std::string Rational::raw_str() const {
    return std::to_string(n) + "/" + std::to_string(d);
}

Rational& Rational::operator = (const Rational& rhs) {
    if (this != &rhs) {
        n = rhs.numerator();
        d = rhs.denominator();
    }
    return *this;
}

Rational Rational::operator + (const Rational& rhs) const {
    return Rational((n * rhs.d) + (d * rhs.n), d * rhs.d);
}

Rational Rational::operator - (const Rational& rhs) const {
    return Rational((n * rhs.d) - (d * rhs.n), d * rhs.d);
}

Rational Rational::operator * (const Rational& rhs) const {
    return Rational(n * rhs.n, d * rhs.d);
}

Rational Rational::operator / (const Rational& rhs) const {
    return Rational(n * rhs.d, d * rhs.n);
}

Rational::~Rational() {
    n = 0; d = 1;
}

int main() {
    
    Rational a {7};         // 7/1
    std::cout << "a is: " << a.raw_str() << " = " << a.str() << std::endl;

    Rational b(25, 15);     // 5/3
    std::cout << "b is: " << b.raw_str() << " = " << b.str() << std::endl;

    auto c = b;     // copy constructor
    std::cout << "c is: " << c.raw_str() << " = " << c.str() << std::endl;

    Rational d;     // default constructor
    std::cout << "d is: " << d.raw_str() << " = " << d.str() << std::endl;

    d = c;          // assignment operator
    std::cout << "d is: " << d.raw_str() << " = " << d.str() << std::endl;

    auto& e = d;    // reference
    d = e;          // assignment to self!
    std::cout << "e is: " << e.raw_str() << " = " << e.str() << std::endl;
    std::cout << "d is: " << d.raw_str() << " = " << d.str() << std::endl;

    std::cout << std::endl;
    std::cout << "a + b = " << (a + b).str() << std::endl;
    std::cout << "a - b = " << (a - b).str() << std::endl;
    std::cout << "a * b = " << (a * b).str() << std::endl;
    std::cout << "a / b = " << (a / b).str() << std::endl;

    return 0;
}
