/*
    cin by default get one word at a time, 
    getline() - more than one word 
    
    std::setw()
    std::setfill() E.g., '-';'0';' ',
    std::right std::left
*/

#include <iostream>
#include <string>
#include <iomanip>

int main() {
    std::cout << "Hello, World!\n";

    std::string istr {};
    std::cout << "Prompt: ";
    std::cin >> istr;    // one word at a time - this is a string, will print this only 
    std::cout << "Input: " << istr << '\n';

    char buf[128] {}; // buffer 
    std::cout << "Prompt: ";
    std::cin.getline(buf, sizeof(buf));
    std::cout << "Input: " << buf << '\n';

    return 0; 
}
