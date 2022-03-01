/*
  C++ String

  There are other ways as well to declare and initialize strings, e.g, constructor and assignment syntax but initializer syntax is recommended {}.

  C++ strings are always initialized.
*/
#include<iostream>
#include<string>

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::boolalpha;

int main(){

  // Declaring and initializing strings.
  string s1;               // Empty - automatically initialize to zero like vectors in modern C++.
  string s2 {"Bjarne"};    // Bjarne - c-style literal will be converted into C++ stirng.
  string s3 {s2};          // Bjarne - a copy of s2 will be created but in different area of memory.
  string s4 {"Bjarne", 3}; // Bja - using first three characters
  string s5 {s3, 0, 2};    // Bj - when initializing from another string, the first integer represents starting index, and second integer is length of the substring, i.e., 0 to 1
  string s6 (3, 'X');      // XXX - initialize string to a specific number of a specific character. This used a constructor syntax ().

  // cout << s1 << endl; //automatically initialize to zero (no garbage) like vectors in modern C++ with length 0
  // cout << s1.length();

  // Initializing
  cout << "\nInitialization" << "\n-----------------------------------------" << endl;
  cout << "s1 is initialized to: " << s1 << endl;
  cout << "s2 is initialized to: " << s2 << endl;
  cout << "s3 is initialized to: " << s3 << endl;
  cout << "s4 is initialized to: " << s4 << endl;
  cout << "s5 is initialized to: " << s5 << endl;
  cout << "s6 is initialized to: " << s6 << endl;

  // Comparision ( ==, !=, >, >=, <, <=)
  // TWo string objects are compared character by character & their character values will be compared lexically. (So A is less than Z and A is less than a - That's because the capital letters come before the lowercase letters in the ascii table.)
  // We cant use these operators for two C-style strings but we can use these operators if:
  // two std::string objects
  // std::string object and C-Style string literal
  // std::string object and C-Style variable.

  string s11 {"Apple"};
  string s12 {"Banana"};
  string s13 {"Kiwi"};
  string s14 {"apple"};
  string s15 {s11}; // Apple

  cout << "\nComparision" << "\n---------------------------------------------------------" << endl;
  cout << boolalpha; // true false instead of 1 0

  cout << s11 << " == " << s15 << " : " << (s11 == s15) << endl;  //true
  cout << s11 << " == " << s12 << " : " << (s11 == s12) << endl;   //False
  cout << s11 << " != " << s12 << " : " << (s11 != s12) << endl;  //true
  cout << s11 << " < " << s12 << " : " << (s11 < s12) << endl;    //true - A comes before a in ASCII
  cout << s12 << " > " << s11 << " : " << (s12 > s11) << endl;   //true
  cout << s14 << " < " << s15 << " : " << (s14 < s15) << endl;   //False  - A comes before a in ASCII
  cout << s11 << " == " << "Apple" << " : " << (s11 == "Apple") << endl; //true - "Apple" is a C-style sting literal and C-style literal is convereted to an object and then we do object to object comparision.


  // Assigning values - using assignment operator =
  // feels more natural as compared to C-style strings ie using strcpy function.

  cout << "\nAssignment" << "\n-----------------------------------------" << endl;

  s1 = "C++ Rocks! "; // s1 will grow dynamically as needed.
  cout << "s1 is now: " << s1 << endl;
  s2 = s1; // s2 is copy of s1, they are not pointing to the same watermelon, they are two copies that are individual. So if s1 is changed it wont affect s2 and vice versa.
  cout << "s2 is now: " << s2 << endl;

  s3 = "Bjarne";
  cout << "s3 is now: " << s3 << endl;

  // Manipulate strings.(subscript operator [] OR  at () method)
  cout << "\nManipulating C++ String" << "\n-----------------------------------------" << endl;
  cout << s3 << endl;
  s3[0] = 'C'; //Cjarne
  cout << "s3 change first letter to 'C':" << s3 << endl;
  s3.at(0) = 'P'; //Pjarne
  cout << "s3 change first letter to 'P':" << s3 << endl;


  // Concatination of C++ strings
  // We can use + operator to concatinate strings
  // in C-Style strings we used strcat()

  cout << "\nConcatination" << "\n-----------------------------------------" << endl;

  string part1 {"C++"};
  string part2 {"is a powerful"};

  string sentence;

  sentence = part1 + " " + part2 + " language"; // A combination of c++ strings and c-style strings is okay.

  cout << sentence << endl;

  s13 = s15 + " and " + s12 + " juice."; // In this case -> s15 + " and " when we are using object and a C-style literal, this is ok, as it will convert
  cout << s13 << endl;


  // Compiler errors when concatinating two C-style literals
  //  sentence = "C++" + " is powerful"; // illegal - as it have two C-style literals and we cannot concatinate C-style literals. We will get compiler error in this case
  //  s13 = "nice " + " cold " + s15 + "juice"; will get error at this part ->"nice " + " cold " as two C-style literals cannot be concatinated using + operator and we have to use strcat in this case.

  // compund concatenation assignment operator
  cout << "\nCompound Concatination" << "\n-----------------------------------------" << endl;
  s2 = "Bjarne";
  s2 += " Stroustrup"; // works same way as that compund assignment operators work with integers/doubles etc.
  cout << s2 << endl; // Bjarne Stroustrup

  /************************
   Methods
  **************************/

  // length method -length() - length of strings (number of objects in string )
  cout << "\nlength" << "\n-----------------------------------------" << endl;
  string tests2 {"Bjarne"};
  cout << "Length of " << tests2 << " is :" << tests2.length() << endl; // 6

  // for loop
  cout << "\nLooping" << "\n-----------------------------------------" << endl;

  cout << s2 << endl;
  for (size_t i{}; i < s2.length(); ++i)
    cout << s2.at(i) << endl;  // or s2[i];

  // using range based for loop to display the string characters. (The null character will not be displayed for C++ string objects.)
  cout << "\nusing range based for loop \n";
  for (char c: s2)  // if we change char to int - it will display the integer values (ASCII codes) that represents those characters.
    cout << c << endl;


  // Substrings - substr() - extracts a substring from a std::string.
  cout << "\nSubstring" << "\n-----------------------------------------" << endl;
  string str1 {"This is a test"};

  cout << str1.substr(0,4) << endl; // This - from index 0 till next 4 characters, if <4 characters left in the string then the remaining characters are included.
  cout << str1.substr(5,2) << endl; // is - starting at index 5 and including two characters
  cout << str1.substr(10,4) << endl; // test - starting at index 10 and includes 4 characters.

  // erase()
  //erase() - removing character, starting index, how many characters to delete

  cout << "\nErase" << "\n-----------------------------------------" << endl;
  cout << str1.erase(0,5) << endl; // will erase "This" and return str1 which is now "is a test"
  cout << str1.erase(5,4) << endl; // will erase "test" for str1 which is now "is a test" and will return "is a"


  // input with C++ strings
  // input >> and getline()
  // C++ string work great with input and output streams e.g with output stream (cout) and extracting c++ string from an input stream (cin). However, there's one issue that's also true for c-style strings.

  string stringone;
  //cin >> stringone; // only accepts up to the first space. e.g if "Hello there" is entered, only Hello will be displayed. This is because extraction operator stops when it sees white space.
  // cout << stringone << endl; // Hello

  cout << "\ngetline" << "\n-----------------------------------------" << endl;
  // in many cases we need to read entire line of text till user presses enter. getline() is used in such cases
  cout << "Enter your full name: ";
  getline(cin, stringone); //Read entire line until \n - first element (cin) -input stream - where we want to get the input, second element is name of c++ string where you want the text that the user enters stored.
  cout << "Your full name is : " << stringone << endl; // Hello there

  // getline with delimiter
  cout << "Enter string with ending at delimiter x: ";
  getline(cin, stringone, 'x'); // this isx -another variant - has one additional parameter - delimiter - the character that we want getline to stop reading input at. so as long as the user doesnt enter delimiter, everything will be stored in the string variable. delimited is not stored in the variable, its discarded.
  cout << stringone << endl; // this is


  // Searching - find() - returns the index of substring in a std::string.
  cout << "\nfind" << "\n-----------------------------------------" << endl;
  str1 = "This is a test";
  cout << str1.find("This") << endl; // 0 - since This starts at 0
  cout << str1.find("is") << endl; // 2 - since first is starts at positon 2
  cout << str1.find("test") << endl; // 10 -index where test starts
  cout << str1.find('e') << endl; // 11 - first occurance at index 11
  cout << str1.find("is",4) << endl; // 5 - variant of the method that allows the index where we want to start the search from (starting at index 4 in this eg)
  cout << str1.find("XX") << endl; // string::npos -18446744073709551615 -(no position information available)- what if the string/character  we want to find isnt there. In this case the method returns end position which means no position information available.

  // we can check for a word in the string using if statement. The user will enter a word/character in the defined string (str1)
  string word {};

  cout << "Enter the word to find: ";
  cin >> word;

  size_t position = str1.find(word);
  if (position != string::npos)
    cout << "Found " << word << " at positon: " << position << endl;
  else
    cout << "Sorry, " << word << " not found" << endl;


  // clear() method
  // clear() - removing entire string of characters
  cout << "\nclear" << "\n-----------------------------------------" << endl;
  cout << "Value of str1 is :" << str1 << endl;
  str1.clear(); // empties string str1
  cout << "Updated value of str1 is : " << str1 << endl;

  // insert()
  cout << "\ninsert" << "\n-----------------------------------------" << endl;
  string unformatted_full_name {"BjarneStroustrup"};

  string first_name {unformatted_full_name, 0, 6}; // Bjarne
  string last_name = unformatted_full_name.substr(6, 10); // Stroustrup

  string formatted_full_name = first_name + last_name; // BjarneStroustrup

  formatted_full_name.insert(6, " "); //inset space at index 6

  cout << "Formatted string :" << formatted_full_name << endl; 

  return 0;
}
