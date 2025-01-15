// Write a program, to return largest number in array.

#include <iostream>
#include <vector>

int main (){

    std::vector <int> test {34, 44, 99, 55, 78};

    int largestNumber {test.at(0)};

    for (auto i: test)
        if (i > largestNumber)
            largestNumber = i;

    std::cout << "Largest Number: " << largestNumber << std::endl;

    return 0;
}