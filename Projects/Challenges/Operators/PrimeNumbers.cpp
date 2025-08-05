/*
    Write a program to calculate the first 25 prime numbers, which are all the prime numbers under 100.
    (2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71 73 79 83 89 97)

    Prime Number Definition: A prime number is a natural number greater than 1 that cannot be formed by multiplying two smaller natural numbers, 
    i.e., its only factors are one and itself.
*/

#include<iostream>

int main(){

    int factors {0};

    for (int number {2}; number < 100; ++number){ // Checking numbers from 2-99
        for (int divisor {1}; divisor <= number; ++divisor) // Counting the divisors of the number
            if (number % divisor == 0)
                ++factors;

        if (factors == 2) // Only prime if divisible by 1 and the number itself. 
            std::cout << number << " ";
        
        factors = 0; // Resetting factor counter for the next number
    }

    std::cout << std::endl;

    return 0; 
}