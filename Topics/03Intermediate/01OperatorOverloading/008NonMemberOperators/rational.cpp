/*
    Operator Overloading 
        1. Member Functions as part of a class definition (007MemberFunctions)
            Performs Four Function Arithmetic on Rational numbers as fractions 
        2. Separate Non-member function out side of a class definition

    Temporary objects destroys each time when function ends.
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
    //Rational operator + (const Rational&) const; // + operated overloaded - const qualified, i.e, work with const objects - Moving it outside the class
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

// Non-Member Operator Overloading
Rational operator + (const Rational &lhs, const Rational &rhs) {
    return Rational((lhs.numerator() * rhs.denominator()) + (lhs.denominator() * rhs.numerator()), 
                    lhs.denominator() * rhs.denominator()); // does operation in a constructor for a new rational object and then it returns that rational object
}
// not in the scope of Rational class due to which
// now it take two parameters 
// no longer const qualified as no longer part of the class 
// We are using two rational objects instead of one (lhs and rhs)
// We will use getters to access class members as this function is no longer part of the class.
// This will work for both integer and ratrional 

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

    // Rational object + integer literal 
    std::cout << "b + 14 = " << (b + 14).str() << std::endl; 
    // order of Operation 
    // 1. Rational for 14. (14/1)
    // 2. (b + 14) overloaded + (lhs=b; rhs=14)
    // 3. Rational Result of b+14
    // 4. str()

    // In 007MemberFunctions (if member funcrtion)
    // order of Operation 
    // 1. Rational for 14. (14/1)
    // 2. (b + 14) overloaded + (this=b; rhs=14)
    // 3. Rational Result of b+14
    // 4. str()
    // 1. it works because compiler sees the b as a rational object (14/1)
    // 2. it looks for the + operator in the Rational class (operator overloading),
    //  it takes the integer 14 and use it as a rhs object which is a rational object. Additionally there is a rational constructor, i.e., 
    //  Rational (int numerator =0, int denominator = 1), that will take this as a one parameter constructor for the rational object, i.e., 14 (as a numerator). It 
    //  then uses that rational object as the rhs of the + operator overloading and returns an rational object (as in point 3). 

    // circumstance where Member Functions as part of a class definition doesnt work 
    // literal + rational object
    std::cout << "14 + b = " << (14 + b).str() << std::endl; 
    // order of Operation 
    // 1. Rational for 14. (14/1)
    // 2. (14 + b) overloaded + (lhs=14; rhs=b)
    // 3. Rational Result of 14 +b
    // 4. str()

    // This code will not work inn 007MemberFunctions 
    // In case of Member functions
    // error: invalid operands to binary expression ('int' and 'Rational') 
    // we do the same as for b + 14, but we do it for integer instead of a rational object. 
    // the + operator for the integer (14 + b), looks for integer and b is a rational object & thats why there is an error. 
    // the solution is to move the operator overload (+) outside the class 

    return 0;
}