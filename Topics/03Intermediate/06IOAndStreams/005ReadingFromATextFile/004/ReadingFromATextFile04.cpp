/*
    using the STL 
        Read a text file (that represents items in an inventory)
        Decode it 
        Store its data in a structure 
        Print the results 

    inventory
    Delimiter: tab 
    each line has two tabs separating its three fields 
    1. sku - stock keeping unit number, 2. name of the item 3. description 
*/

#include <format>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

const size_t maxstring {1024};  // size of line buffer
const char *file_name {"/Users/umar/Library/CloudStorage/GoogleDrive-umar021@gmail.com/My Drive/Kurser/C++/Cpp/Topics/03Intermediate/06IOAndStreams/005ReadingFromATextFile/004/items.txt"}; //path to the file
const char delimiter {'\t'};

class Item {
    int item_sku {};
    std::string item_name {};
    std::string item_desc {};
public:
    Item(){ reset(); } // constructor
    Item(int sku, std::string &name, std::string &desc) : item_sku(sku), item_name(name), item_desc(desc) {} // constructor
    Item(const Item &rhs); // constructor
    Item & operator = (const Item &rhs); //copy operator
    ~Item() { reset(); } // destructor
    void reset() { item_sku = 0; item_name = item_desc = "unk"; }
    void sku(int sku) { item_sku = sku; }
    int sku() const { return item_sku; } // getter
    void name(const std::string &name) { item_name = name; }
    std::string name() const { return item_name; } // getter
    void desc(const std::string &desc) { item_desc = desc; }
    std::string desc() const { return item_desc; } // getter
};

Item::Item(const Item &rhs) { //copy constructor
    item_sku = rhs.item_sku;
    item_name = rhs.item_name;
    item_desc = rhs.item_desc;
}

Item & Item::operator = (const Item &rhs) { // copy operator
    if(this != &rhs) {
        item_sku = rhs.item_sku;
        item_name = rhs.item_name;
        item_desc = rhs.item_desc;
    }
    return *this;
}

// split a string on tabs
std::vector<std::string> strsplit(const std::string &s) {
    std::vector<std::string> strs_v;    // vector for results
    size_t start_loc {};
    size_t sep_loc {}; // seperation location
    while (true) {
        sep_loc = s.find(delimiter, start_loc); // finding the \t
        strs_v.push_back(s.substr(start_loc, sep_loc - start_loc)); // pushback a substring onto a vector; from start_loc till next sep_loc - start_loc characters
        // substr() is a member function of the std::string class, used to extract a portion of a string and return it as a new std::string object.
        if (sep_loc == std::string::npos) break; //largest possible value for an element of type size_t; if cursor reaches to last character
        start_loc = sep_loc +1; //moving cursor to next character
    }
    return strs_v; // return the vector
}

int main()
{
    char buf[maxstring] {};    // buffer for reading lines in file

    // open the file
    std::ifstream infile(file_name);

    // read the file
    while (infile.good()) { // The good() function returns true if none of the stream's error flags are set. 
        // get the line
        infile.getline(buf, sizeof(buf)); // get line
        if(!*buf) break; // break if buffer is empty 

        // split the string into 3 strins 
        std::vector<std::string> split_v {strsplit(buf)};
        if(split_v.size() < 3) continue; // item_sku, item_name, item_desc 

        // construct the object with split_v values
        Item current_item {std::stoi(split_v[0]), split_v[1], split_v[2]}; // std::stoi is a C++ standard library function used to convert a string representation of an integer into an actual integer value (int). 
        std::cout << std::format("sku: {}, name: {}, desc: {}\n",
                       current_item.sku(), current_item.name(), current_item.desc()); // printing the object
        
    }
    infile.close(); // close the file
}
