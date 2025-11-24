/*
    Performs Four Function Arithmetic on Rational numbers as fractions 
    temporary objects destroys each time when function ends.
*/
#include <iostream>
#include <string>

const std::string nanstr {"[NAN]"}; // In static memory space bec they are outside of any function

class Rational {
    int n {0}; // Numerator
    int d {1}; // Denominator 
public:
    Rational(int numerator = 0, int denominator = 1) : n(numerator), d(denominator) {} // if no values provided then default constructor (bec it has default values of numerator and denominator), otherwise, initializer list for when used as multiple args constructor. 
    // can be called with 0,1 or 2 parametrs 
    // 0 parameter = default (0/1); 1 parameter = x/1; 2 parameters = x/x  
    Rational(const Rational &rhs) : n(rhs.n), d(rhs.d) {} // copy constructor - constructor initializer list
    ~Rational(); // destructor
    int numerator() const { return n; }; // getter
    int denominator() const { return d; }; // getter 
    Rational reduce() const; // reduce fraction.
    std::string str() const; // return a formatted STL string
    std::string raw_str() const; // return a non-reduced STL string; num / den as a string
    Rational& operator = (const Rational&);  // assignment operated overloaded 
    Rational operator + (const Rational&) const; // + operated overloaded - const qualified, i.e, work with const objects 
    Rational operator - (const Rational&) const; // - operated overloaded - const qualified
    Rational operator * (const Rational&) const; // * operated overloaded - const qualified
    Rational operator / (const Rational&) const; // / operated overloaded - const qualified
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
    if(d == 0) return nanstr; //infinity case
    if(d == 1 || n == 0) return std::to_string(n);

    auto abs_n = abs(n); // absolute value - why taking abs value ?
    if(abs_n > d) {
        auto whole = n / d;
        auto remainder = abs_n % d;
        if(remainder) return std::to_string(whole) + " " + Rational(remainder, d).str(); //recursion - Rational(remainder, d).str()
        else return std::to_string(whole);
    } else {
        return reduce().raw_str();
    }
}

std::string Rational::raw_str() const {
    return std::to_string(n) + "/" + std::to_string(d);
}

// can return a reference as its an assignment and it modifies the value in the object 
Rational& Rational::operator = (const Rational &rhs) {
    if (this != &rhs) { // a check for if "this" and rhs are different objects
        n = rhs.numerator(); // rhs.n - no need to use getter here 
        d = rhs.denominator(); // rhs.d
    }
    return *this;
}

// const qualified functions dont modify the object, instead they return a new object which is a result of the arithematic operation.
Rational Rational::operator + (const Rational &rhs) const {
    return Rational((n * rhs.d) + (d * rhs.n), d * rhs.d); // does operation in a constructor for a new rational object and then it returns that rational object
}

Rational Rational::operator - (const Rational &rhs) const {
    return Rational((n * rhs.d) - (d * rhs.n), d * rhs.d);
}

Rational Rational::operator * (const Rational &rhs) const {
    return Rational(n * rhs.n, d * rhs.d);
}

Rational Rational::operator / (const Rational &rhs) const {
    return Rational(n * rhs.d, d * rhs.n);
}

Rational::~Rational() {
    n = 0; d = 1; //resetting to default
}

int main() {
    
    Rational a {7}; // 7/1
    std::cout << "a is: " << a.raw_str() << " = " << a.str() << std::endl;

    Rational b(25, 15); // 25/15 = 5/3 = 1 2/3
    std::cout << "b is: " << b.raw_str() << " = " << b.str() << std::endl;

    auto c {b}; // copy constructor 1 2/3
    std::cout << "c is: " << c.raw_str() << " = " << c.str() << std::endl;

    Rational d; // default constructor 0/1 = 0
    std::cout << "d is: " << d.raw_str() << " = " << d.str() << std::endl;

    d = c; // assignment operator (operator overloading) 1 2/3
    std::cout << "d is: " << d.raw_str() << " = " << d.str() << std::endl;

    auto &e {d}; // e is a reference 
    d = e; // assignment to itself! as it is assigning from the reference - as is already initialized so here operatator overloading
    std::cout << "e is: " << e.raw_str() << " = " << e.str() << std::endl;
    std::cout << "d is: " << d.raw_str() << " = " << d.str() << std::endl;

    // Operator Overloads 
    std::cout << std::endl;
    std::cout << "a + b = " << (a + b).str() << std::endl; // (a + b) returns a temporary object and .str() method is used on that tempory object
    std::cout << "a - b = " << (a - b).str() << std::endl;
    std::cout << "a * b = " << (a * b).str() << std::endl;
    std::cout << "a / b = " << (a / b).str() << std::endl;

    return 0;
}