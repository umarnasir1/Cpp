/*
  STL Algorithm:
    accumulate () - sum of the elements in the vector
    copy ()
      back_inserter
    find ()
      locate the first occurrence of an element in a container or end().
      vector, list, map, set
      TODO: 
        (1) find with user-defined tpes
          find needs to be able to compare two elements in order to see if they're the same. (it uses 
          equality operator to compare). For primitive types (e.g., ints), the compiler knows how to 
          compare primitive types. but for user-defined objects in containers, we must provide the 
          overloaded equality operator.
          Also, we can define what equality means. We might want all player attributes to match or only the name or only the xp.
          We have all the power to decide.
    min (), max () - check later
    sort() - sorting in ascending order.
    reverse() - sorting in descending order.

    TODO:
      (1) Test with providing subset of vector.
            sort the first half of a vector, we could modify the iterator to produce just the first half of the elements.
            min, max föstår inte (https://www.geeksforgeeks.org/c-magicians-stl-algorithms/)
      (2) Make a template function to display container instead of seperate dispalay for vector, list, etc
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <list> 
#include <map>
#include <set>

class Player{
private:
  std::string name {"name"}; 
  int health {0}; 
  int xp {0};
public:
  // constructor for initialization
  // overloaded constructors 
  // Player(){name = "None"; health = 0; xp = 0;}
  Player() : name{"None"}, health{0}, xp{0} {} 
  Player(std::string name_val, int health_val, int xp_val) : name{name_val}, health{health_val}, xp{xp_val} {}
  // Destructor
  ~Player(){std::cout<< "Destructor called for " << name << std::endl;}

  // operator overloading here
  // we must provide the overloaded equality operator for our objects since that's what the algorithm will call.

  // Implimentation of equality operator ==
  // bool operator== (const Player &rhs) const{
  //   return (std::strcmp(name,rhs.name)==0); // strcmp returns Zero if lhs and rhs compare equal.

    // alternate
    // if (std::strcmp(str, rhs.str) == 0) // compares c-style strings and returns 0 if strings are equal
    //   return true; 
    // else
    //   return false; 
  //}

  // operator << 

};

int main (){

  // vector 
  std::vector<int> v {10, 20, 5, 23, 42, 15};
  std::cout << "Vector is: "; 
  for (auto elem: v)
    std::cout << elem << " "; 
  
  // list
  std::list<int> l {10, 20, 30, 40, 50};
  std::list<std::string> l1 {"Larry", "Moe", "Curly"};

  // map
  std::map<std::string, int> burger {
    {"Simple", 150}, // key: value
    {"SingleSausage", 190},
    {"DoubleSausage", 220}
  };

  // set
  std::set<char> name {'U', 'M', 'A', 'R'};

  // ------------------------------------------------------------------------------
  // Accumulate
  // ------------------------------------------------------------------------------
  std::cout << "\nThe accumulation of vector elements is: " << std::accumulate(v.begin(), v.end(), 0) << std::endl; // 0 - running sum will start at; if double then 0.0; typically 0, but we can use any number. If we use 3 then the accumulation will start from 3 onwards.
  
  // ------------------------------------------------------------------------------
  // Copy
  // ------------------------------------------------------------------------------
  std::vector<int> v2 {4, 5, 2, 8, 0, 9, 2}; 
  std::copy(v.begin(), v.end(), std::back_inserter (v2));
  std::cout<< "\nAfter Copy: "; 
  for (auto elem: v2)
    std::cout << elem << " "; // After Copy: 4 5 2 8 0 9 2 10 20 5 23 42 15
  
  // ------------------------------------------------------------------------------
  // find
  // ------------------------------------------------------------------------------
  std::cout << "\n\nfind()" << std::endl; 
  // lots of variations 
  // if the function finds the elements, it returns an iterator that points to the element it just found.
  // If the function does not find the element, it will return an iterator pointing to the end of the container
  // loc = an iterator to a vec of integers. It is a  variable. We are using auto to let the compiler deduce the type of loc. 
  
  // vector
  auto loc = std::find(v.begin(), v.end(), 42); //passing the iterators in std::find; v.begin(), v.end(), element we want to find; 
  if (loc != v.end()) // if loc != v.end() we know loc is pointing (iterators are implimented 'pointer like') to the first occurrence of 42
    std::cout << *loc << std::endl; //42 - pringing where loc is poining (iterators are implimented 'pointer like')

  // list
  auto loc1 = std::find(l.begin(), l.end(), 40); 
  if (loc1 != l.end()) // found it!
    std::cout << *loc1 << std::endl; // 40
  
  auto loc2 = std::find(l1.begin(), l1.end(), "Moe"); 
  if (loc2 != l1.end())  // found it!
    std::cout << *loc2 << std::endl; // Moe

  // map
  auto loc3 = burger.find("Simple");
  if (loc3 != burger.end()) // found it!
    std::cout << loc3->first << " : " << loc3->second << std::endl; 

  // set
  auto loc4 = std::find(name.begin(), name.end(), 'A');
  if (loc4 != name.end()) // found it!
    std::cout << *loc4 << std::endl; // A
  
  // ---------------------------------------
  // find with user defined types
  //  operator== must be provided by class

  Player m1 {"Javed", 100, 12};
  Player m2 {"Sultan", 100, 9};
  Player m3 {"Waqar", 100, 8};

  std::vector<Player> mtr {m1, m2, m3}; // m1, m2, m3 - members
  
  // auto loc5 = std::find(mtr.begin(), mtr.end(), m1); // m1 is player we want to find in the vector
  // difference between primitive types and user-defined types
  // The only difference is that the compiler will compare m1 to the container elements using the 
  // overloaded equality operator that must be provided in the player class.
  

  // if (loc5 != mtr.end()) // found it!
  //   std::cout << *loc5 << std::endl; // operator<< called



  // // ------------------------------------------------------------------------------
  // // max
  // // ------------------------------------------------------------------------------
  // std::cout << "\nMaximum element of vector is:  " << *max_element(v.begin(), v.end()); 

  // // ------------------------------------------------------------------------------
  // // min
  // // ------------------------------------------------------------------------------
  // std::cout << "\nMinimum element of vector is:  " << *min_element(v.begin(), v.end());
  
  // ------------------------------------------------------------------------------
  // sort a vector
  // ------------------------------------------------------------------------------
  std::cout << "\nVector after sorting is: "; 
  std::sort(v.begin(), v.end()); // the entire vector

  for (auto elem: v) // displaying a vector using range based for loop - behind the scenes, range based loop is an iterator.
    std::cout << elem << " ";

  // ------------------------------------------------------------------------------
  // descending order
  std::cout << "\nVector after sorting in Descendign Order: ";
  std::reverse(v.begin(), v.end());
  for (auto elem_r: v)
    std::cout << elem_r << " ";

  std::cout << std::endl; 
  return 0;
}
