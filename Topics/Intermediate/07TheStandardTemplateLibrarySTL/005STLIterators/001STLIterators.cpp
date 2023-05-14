/*
    Introduction to STL Iterators 

    How can we use operators to work with iterators.
        Using iterator to iterate over the vector and display the contents 
        of the vector.
        (1) iterator
        (2) reverse iterator
        (3) iterate set of characters using iterator 
    
    OBS!! why not just use a range-based for loop or a counter controlled for loop?
    We absolutely could and we often do. We'll see in a bit that a range based for 
    loop is converted to an iterator-based loop behind the scenes by the compiler.
    But the real answer is that in the case of a vector, we could do it a lot of 
    different ways. But other containers don't allow us to randomly access elements 
    like a vector does. So for those containers, iterators are necessary. 

*/
#include<iostream>
#include<vector>
#include<set> // for ordered set
#include<unordered_set> 

int main(){
    std::vector<int> vec {1,2,3}; // declaring and initializing vector

    // 1. iterator 1,2,3
    //declaring and initializing iterator to first element of vec
    std::vector<int>::iterator it = vec.begin(); 
    // or
    // auto it = vec.begin(); // compiler will deduce the type of the iterator to vector of integers based on the result returned by vec.begin(); 

    while (it != vec.end()){ // iterate through the vector
       std::cout<< *it << " "; // display the element the iterator is pointing to by dereferencing the iterator
       ++it; // moving to next element
    }
    
    // // alternative 
    // // for loop - comment 24 as it is initialized there
    // for (auto it = vec.begin() ; it != vec.end(); it++) // compiler will deduce the type of the iterator to vector of integers based on the result returned by vec.begin(); 
    //     std::cout << *it << " ";

    std::cout<< std::endl;

    // ------------------------------------------------------------
    // 2. reverse iterator 3,2,1
    std::vector<int>::reverse_iterator it_r = vec.rbegin(); // Since it's a reverse iterator, it will be pointing to the last element in the list, not the first.

    while(it_r != vec.rend()){
        std::cout<< *it_r << " "; 
        ++it_r; 
    }

    std::cout << std::endl; 

    // ------------------------------------------------------------
    // 3. iterate over a set of characters using iterator 
    
    // std::set<char> suits {'U', 'M', 'A', 'R'};
    std::unordered_set<char> suits {'U','M','A','R'}; // set of characters

    // iterator
    auto it_c = suits.begin(); // compiler will deduce its type based on the result of suits.begin()

    while (it_c != suits.end()){
        std::cout << *it_c << " "; // displaying the character - A M R U as std::set is ordered by default with unordered: R M A U
        ++it_c; 
    }

    return 0; 
}