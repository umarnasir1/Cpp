/*
    Introduction to STL Iterators 

    How can we use operators to work with iterators.
        Using iterator to iterate over the vector and display the contents 
        of the vector.

*/
#include<iostream>
#include<vector>

int main(){
    std::vector<int> vec {1,2,3}; // declaring and initializing vector

    // iterator 1,2,3
    //declaring and initializing iterator to first element of vec
    std::vector<int>::iterator it = vec.begin(); 
    // or
    // auto it = vec.begin(); // compiler will deduce the type of the iterator to vector of integers based on the result returned by vec.begin(); 

    while (it != vec.end()){ // iterate through the vector
       std::cout<< *it << " "; // display the element the iterator is pointing to by dereferencing the iterator
       ++it;
    }

    // std::set<char> suits{'C','H','S','D'};

    return 0; 
}