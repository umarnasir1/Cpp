/* Write a C++ program to replace a word from the string 
    replace() -005 - stringName.replace(stringName.find("whatToFind"), whatToFind.size(), "whatToReplace")
    for e.g., if we have to find why the code will be:

    while (s1.find("why") != std::string::npos) // searching the string till the end of the string is encountered
        s1.replace(s1.find("why"), 3, "what"); 
*/

#include<iostream>
#include<string>

int main (){
    std::string s1, s2, s3;

    std::cout << "Enter a string: ";
    getline(std::cin,s1);

    std::cout << "Enter the word to find in the string: ";
    getline(std::cin,s2);

    std::cout << "Enter the string to be replaced with: ";
    getline(std::cin,s3);

    while (s1.find(s2) != std::string::npos) // searching the string till the end of the string is encountered
        s1.replace(s1.find(s2), s2.size(), s3);
    
    std::cout << s1 << std::endl;

    return 0;
} 
