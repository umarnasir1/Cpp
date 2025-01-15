#include<iostream>
#include<vector>

int main(){

    std::vector <int> test {10, 10, 20, 40, 20};
    int sum {};

    for (auto i: test)
        sum += i;

    std::cout << "The sum of the vector is: " << sum << std::endl;

    return 0;
}