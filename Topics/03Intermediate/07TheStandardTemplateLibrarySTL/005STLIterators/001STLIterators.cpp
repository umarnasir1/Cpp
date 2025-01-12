/*
    Introduction to STL Iterators 

    Egs. of how to use iterators
        Using iterator to iterate over the vector and display the contents 
        of the vector.
        (1) iterate over a vector (to display elements)
        (2) iterator (to display values; to change elements to 0)
        (3) const iterator
        (4) reverse iterator (containers: vector, list, map)
        (5) iterate over a subset of a container
        (6) iterate over a set of characters using iterator  (ordered and unordered)
    
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
#include<map>
#include<list>

// display any vector of integers using range-based for loop
void display (const std::vector<int> &vec){
    std::cout << "[";
    for (auto const &i: vec)
        std::cout<< i << " "; 
    std::cout << "]"; 
    return; 
}

void test1(){
    std::cout<< "\n=============================================================" << std::endl;
    std::vector<int> nums1 {1,2,3,4,5};

    // creating iterator
    auto it = nums1.begin(); // it will point to 1 (its not a real pointer, this is an object, we are saying pointing so we can understand it as the syntax and the way it feels is very pointer like - iterators feel just like pointers); 
    // compiler will deduce the type of the iterator;
    
    std::cout << *it << std::endl; // 1; de-reference the iterator to display value

    it++; // moving the iterator by incrementing it; iterator it will be pointing to 2; 
    std::cout<< *it << std::endl;

    it += 2; // incrementing the iterator by 2; iterator will point to 4
    std::cout<< *it << std::endl;

    it -= 2; // point to 2
    std::cout<< *it << std::endl;

    it = nums1.end() - 1; // iterator pointing to one element back from end; iterator will point to 5
    std::cout<< *it << std::endl; 
}

void test2(){
    std::cout<< "\n=============================================================" << std::endl;
    // display all vector elements using an iterator

    std::vector<int> nums1 {1,2,3,4,5}; // declaring and initializing vector

    // 1. iterator 1,2,3,4,5 
    //declaring and initializing iterator to first element of nums1
    std::vector<int>::iterator it = nums1.begin(); 
    // or
    // auto it = nums1.begin(); // compiler will deduce the type of the iterator to vector of integers based on the result returned by vec.begin(); 

    while (it != nums1.end()){ // iterate through the vector
       std::cout<< *it << " "; // display the element the iterator is pointing to by dereferencing the iterator
       ++it; // increment - moving to next element
    }

    // // alternative 
    // // for loop - comment the initialization of iterator it.
    // for (auto it = vec.begin() ; it != vec.end(); it++) // compiler will deduce the type of the iterator to vector of integers based on the result returned by vec.begin(); 
    //     std::cout << *it << " ";

    std::cout << std::endl;

    // change all vector elements to 0
    it = nums1.begin(); // it is pointing to nums1.end() after execution of while loop so reseting the iterator to point to the beginning
    while (it != nums1.end()){
        *it = 0; // storing 0 whereever the iterator is pointing to 
        it++; 
    }
    display(nums1); // [0 0 0 0 0]
}

void test3(){
    // using const iterator
    std::cout<< "\n=============================================================" << std::endl;
    std::vector<int> nums1 {1,2,3,4,5};

    std::vector<int>::const_iterator it1 = nums1.begin(); // creating a constant iterator pointing to first element.
    // auto it1 = nums1.begin(); // will give regular iterator
    // auto it1 = nums1.cbegin(); // will give constant iterator 

    while (it1 != nums1.end()){
        std::cout << *it1 << " "; 
        it1 ++; 
    }

    // compiler error when we try to change element
    it1 = nums1.begin(); 
    while (it1 != nums1.end()){
    //    *it1 = 0; // compiler error - read only 
        it1++; 
    }
}

void test4(){
    // more iterators
    // using reverse iterator 5,4,3,2,1
    std::cout<< "\n=============================================================" << std::endl;
    std::vector<int> nums1 {1,2,3,4,5};
    // std::vector<int>::reverse_iterator it1 = nums1.rbegin(); // Since it's a reverse iterator, it will be pointing to the last element in the list, not the first.
    auto it1 = nums1.rbegin(); // reverse iterator over vector of ints starts at 5 ( r.end 1 2 3 4 5); r.begin is 5 as its reverse iterator
    while (it1 !=  nums1.rend()){
        std::cout << *it1 << " "; 
        it1++; // as we are using reverse iterator, so incrementing here means decrementing here.
    }
    std::cout << std::endl; 
    

    // const reverse iterator over a list
    std::list<std::string> names {"Larry", "Moe", "Curly"}; // a list of strings; Larry <=> Moe <=> Curly 
    auto it2 = names.crbegin(); // iterator over list of strings point to Curly as it is constant reverse iterator
    std::cout<< *it2 << std::endl; // Curly
    it2++; // point to Moe; incrementing means moving revese in reverse iterator
    std::cout << *it2 << std::endl; // Moe
    std::cout << std::endl;

    // iterator over a map
    std::map<std::string, std::string> favorites { // favorites is a map of string, string pairs
        {"Frank", "C++"}, // key, value: creating association between two strings 
        {"Bill", "Java"},
        {"James", "Haskell"}
    };
    auto it3 = favorites.begin(); //iterator over map of string, string pairs; it goes to the first item in that map.
    while (it3 != favorites.end()){
        std::cout<< it3->first << " : " << it3->second << std::endl; // arrow operator as iterators are implimented as "pointer like"
        it3++;
    }
}

void test5(){
    // iterate over a subset of a container
    std::cout<< "\n=============================================================" << std::endl;
    std::vector<int> nums1 {1,2,3,4,5,6,7,8,9,10};
    // iterators: start and finish
    auto start = nums1.begin() + 2; // 3
    auto finish = nums1.end() - 3;  // 8 

    while (start != finish){
        std::cout << *start << std::endl; // 3 4 5 6 7
        start++;
    }
}

void test6(){
    // iterate over a set of characters using iterator 
    // ordered A M R U as std::set is ordered by default (alphabetic order)
    // unordered R M A U  

    std::cout << "\n------------------------------------------------------------" << std::endl; 

    // std::set<char> suits {'U', 'M', 'A', 'R'};
    std::unordered_set<char> suits {'U','M','A','R'}; // set of characters

    // iterator
    auto it_c = suits.begin(); // compiler will deduce its type based on the result of suits.begin()

    while (it_c != suits.end()){
        std::cout << *it_c << " "; // displaying the character
        ++it_c; // it_c++ same
    }
     
}

int main(){
    // test1(); 
    // test2(); 
    // test3();
    // test4(); 
    // test5();
    test6(); 

    return 0; 
}