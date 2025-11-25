// iostream-formatting.cpp by Bill Weinman [bw.org]
// updated 2022-06-22
#include <iostream>
#include <string>
#include <iomanip>

int main() {
    std::cout << "Hello, World!\n";

    std::string istr {};
    std::cout << "Prompt: ";
    std::cin >> istr;    // one word at a time
    std::cout << "Input: " << istr << '\n';

    char buf[128] {};
    std::cout << "Prompt: ";
    std::cin.getline(buf, sizeof(buf));
    std::cout << "Input: " << buf << '\n';

    // integer formatting
    int i1 {42};
    int i2 {127};
    int i3 {5555};
    std::cout << "default: " << i1 << ' ' << i2 << ' ' << i3 << '\n';
    std::cout << "hex: " << std::hex << i1 << ' ' << i2 << ' ' << i3 << '\n';
    std::cout << "hex with showbase: " << std::showbase << std::hex << i1 << ' ' << i2 << ' ' << i3 << '\n';
    std::cout << "octal with showbase: " << std::oct << i1 << ' ' << i2 << ' ' << i3 << '\n';
    std::cout << "default: " << std::noshowbase << std::dec << i1 << ' ' << i2 << ' ' << i3 << "\n\n";
    
    // floating point formatting options
    double d1 {3.1415926534};
    double d2 {1234.5};
    double d3 {4.2e-10};
    std::cout << "default: " << d1 << ' ' << d2 << ' ' << d3 << ' ' << '\n';
    std::cout << "fixed: " << std::fixed << d1 << ' ' << d2 << ' ' << d3 << ' ' << '\n';
    std::cout << "scientific: " << std::scientific << d1 << ' ' << d2 << ' ' << d3 << ' ' << '\n';
    std::cout << "set precision (3): " << std::setprecision(3) << std::fixed << d1 << ' ' << d2 << ' ' << d3 << ' ' << '\n';
    std::cout << "scientific (7): " << std::setprecision(7) << std::scientific << d1 << ' ' << d2 << ' ' << d3 << ' ' << '\n';
    std::cout.unsetf(std::ios_base::floatfield);
    std::cout << "default: " << d1 << ' ' << d2 << ' ' << d3 << ' ' << std::endl << '\n';
    
    // string formatting options
    std::string s1 {"This is a string."};
    std::string s2 {"This is a much longer string."};
    std::string s3 {"Today's news: Big Light in Sky Slated to Appear in East"};
    
    std::cout << s1 << '\n';
    std::cout << s2 << '\n';
    std::cout << s3 << '\n';
    
    std::cout << std::setw(64) << std::right << s1 << std::endl;
    std::cout << std::setw(64) << std::right << s2 << std::endl;
    std::cout << std::setw(64) << std::right << s3 << std::endl;
    
    std::cout << std::setfill('-') << std::setw(64) << std::right << s1 << std::endl;
    std::cout << std::setfill(' ') << std::setw(64) << std::right << s1 << std::endl;
    std::cout << std::left << s1 << std::endl;
}
