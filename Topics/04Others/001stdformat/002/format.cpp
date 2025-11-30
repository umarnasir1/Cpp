/*
    The C++ formatting library does not include a print function. 
    positional arguments
        :.5 to 5 decimal places, e.g., .1234
        1: check later the meaning
    fill character
    allignments 
    format specialization
*/
#include <format>
#include <string>
#include <string_view>
#include <vector>
#include <numbers>

// for the fraction
// template class 
template<typename T>
struct Frac { // structure
    T n;
    T d;
};

// format specialization
template <typename T>
struct std::formatter<Frac<T>> : std::formatter<unsigned> { //inheriting structure from the standard formatter and creating a specilization called formatter with Frac of type T
    template <typename Context>
    auto format(const Frac<T>& f, Context& ctx) const { // type - Frac<T> 
        return std::format_to(ctx.out(), "{}/{}", f.n, f.d); //function: format_to; specification: {}/{} - two values separated by /;  
    }
};

// implimenting format print function
// it works exactly like format function but instead of returning a string like format, this will actually print to the console using fputs. 
// this allows to use print(), without having to use the std::cout function in conjunction with std::format. 
template<typename... Args> // template argument ... (three dots) followed by Args - parameter pack 
constexpr void print(const std::string_view str_fmt, Args&&... args) {
    fputs(std::vformat(str_fmt, std::make_format_args(args...)).c_str(), stdout);
}

int main() {
    const int inta {47};
    const char* human {"earthlings"}; // C-string
    const std::string alien {"vulcans"}; // C++ String
    const double dpi {std::numbers::pi}; // double

    // ints
    print("inta is {}\n", inta); // inta is 47
    
    // string
    print("Hello {}\n", human); // Hello earthlings
    print("Hello {} we are {}\n", human, alien); // Hello earthlings we are vulcans
    print("Hello {1} we are {0}\n", human, alien); // Hello vulcans we are earthlings - using positional arguments to change the order of strings

    // double     
    print("π is {}\n", dpi); // π is 3.141592653589793
    print("π is {:.5}\n", dpi); // π is 3.1416 - constrain to 5 decimal places :.5
    print("inta is {1:}, π is {0:.5}\n", dpi, inta); //inta is 47, π is 3.1416

    // fill characters & allignments
    print("inta is [{:*<10}]\n", inta); // inta is [47********] - fill character *; < left allignment; 10 places (total)
    print("inta is [{:0>10}]\n", inta); // inta is [0000000047] - fill character 0; > right allignment; 10 places 
    print("inta is [{:^10}]\n", inta); // inta is [    47    ] - ^ center alligned; 10 places 
    print("inta is [{:_^10}]\n", inta); // inta is [____47____] - fill character _; ^ center alligned; 10 places 

    // hex, octal & decimal 
    print("{:>8}: [{:04X}]\n", "Hex", inta); // Hex: [002F] - [{:04x}] - to change to lower case f; fill character 0; > right allignment; 8 places;
    print("{:>8}: [{:4o}]\n", "Octal", inta); // Octal: [  57]
    print("{:>8}: [{:4d}]\n", "Decimal", inta); // Decimal: [  47]

    // Fraction
    Frac<long> n{ 3, 5 }; // object = n
    print("Frac: {}\n", n); // Frac: 3/5   

    return 0;
}
