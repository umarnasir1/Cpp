/*
    Introduction to STL Iterators 

    Example using a vector: so we can see how to initialize iterators

    A container has a beginning and an end. The STL defines the beginning as the first element in the 
    container and the stl defines the end as 1 after the last element in the container.
        vec.begin() - will return an iterator object that is poining 
        
        first element 
        vec.end() - location after last element



*/
#include<iostream>
#include<vector>

int main(){
    std::vector<int> vec {1,2,3}; 

    std::vector<int>::reverse_iterator it = vec.rbegin(); 

    while (it != vec.rend()){
       std::cout<< *it << " ";
       ++it;
    }
    return 0; 
}