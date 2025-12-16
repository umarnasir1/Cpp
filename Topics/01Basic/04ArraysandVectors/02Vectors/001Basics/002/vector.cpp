/*
vector initializer list E.g., {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
    size()
    front() front element in a container
    back() back element in a container
iterators works like pointers
    begin()
    end()
    insert() - insert an element 
    erase() - erase an element 
    push_back() - adding a value to the back (last value) of a container

vector type provides iterators 
iterators works just like pointers 

.at() method checks range checking and [] does not 
*/

#include <iostream>
#include <string>
#include <vector>

int main() {
    std::cout << "vector from initializer list:\n";
    std::vector<int> vi1 {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; //vi1[0] = 1 ...vi1[9] = 10

    std::cout << "size: " << vi1.size() << std::endl; //10
    std::cout << "front: " << vi1.front() << std::endl; //1 -front element
    std::cout << "back: " << vi1.back() << std::endl; //10 -back element  
    std::cout << std::endl;
    
    // iterator
    std::cout << "iterator: " << std::endl;
    //auto itbegin = vi1.begin(); // beginning iterator - 1
    //auto itend = vi1.end(); // end iterator - 0
    //std::cout << *(vi1.begin()) << std::endl; // - de-refererencing it as iterators works like pointers

    for (auto it = vi1.begin(); it < vi1.end(); ++it) //- more common 
        std::cout << *it << std::endl; // 1 2 3 4 5 6 7 8 9 10 - de-refererencing it as iterators works like pointers
    std::cout << std::endl;

    // vector indexing    
    std::cout << "element 5: " << vi1[5] << std::endl; //6 - square bracket operator 
    std::cout << "element 5: " << vi1.at(5) << std::endl; //6 - at() method

    std::cout << std::endl;
    std::cout << "range-based for loop: " << std::endl;
    for (const auto &i : vi1) 
        std::cout << i << std::endl; // 1 2 3 4 5 6 7 8 9 10

    std::cout << std::endl << std::endl;

    std::cout << "insert 42 at begin + 5:\n"; 
    vi1.insert(vi1.begin() + 5, 42); // just like a pointer, the addition operator operates on the iterator based on the size of the elements. 
    std::cout << "size: " << vi1.size() << std::endl; //11
    std::cout << "element 5: " << vi1.at(5) << std::endl; //42
    std::cout << std::endl;
    
    std::cout << "erase at begin + 5:\n";
    vi1.erase(vi1.begin() + 5);
    std::cout << "size: " << vi1.size() << std::endl; //10
    std::cout << "element 5: " << vi1.at(5) << std::endl; //6
    std::cout << std::endl;
    
    std::cout << "push_back 47:" << std::endl;
    vi1.push_back(47);
    std::cout << "size: " << vi1.size() << std::endl; //11
    std::cout << "vi1.back(): " << vi1.back() << std::endl; //47
    std::cout << std::endl;

    // Initialize a vector from C-array (to vector)
    const size_t size {10};
    int ia[size] {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::cout << "vector from C-array: " << std::endl;
    std::cout << ia << std::endl; // 0x16fdfec38
    std::cout << ia + size <<std::endl; // 0x16fdfec60

    std::vector<int> vi2(ia, ia + size); // two pointers ia - beginning of the array; ia + size - end of the array (array + its size)
    for (const auto &i : vi2) {
        std::cout << i << " "; //1 2 3 4 5 6 7 8 9 10
    }
    std::cout << std::endl << std::endl;
 
    // vector of strings
    std::cout << "vector of strings:" << std::endl;
    std::vector<std::string> vs {"one", "two", "three", "four", "five"};
    for (const auto& v : vs) {
        std::cout << v << std::endl; // one two three four five
    } 

    return 0;       
}
