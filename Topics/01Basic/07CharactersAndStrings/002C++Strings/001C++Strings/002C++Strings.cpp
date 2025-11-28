/*
  C++ String

  There are other ways as well to declare and initialize strings, e.g, constructor and assignment syntax but initializer syntax is recommended {}.

  C++ strings are always initialized.

  Contents:
    Declaring
    Initiazing strings.
    Comparision ( ==, !=, >, >=, <, <=)
    Assigning values - using assignment operator =
    Manipulating C++ String
    Concatination (+, append())
    Compound Concatination
    String Methods
      length() - (length and size both do the same thing; Generally string has length and container has size)
      substr() - sub string
      erase() - removing characters from string
      input with C++ strings
        >>
        getline()
          getline with delimiter
      find()- returns the index of substring in a std::string.
        find word in a string returns position of string or str::nopos (no position)
      rfind() - find from right hand side  
      clear()
      compare()
      insert()
      size() - (length and size both do the same thing; Generally string has length and container has size)
      swap()
      erase()
      replace() -005 - stringName.replace(stringName.find("whatToFind"), whatToFind.size(), "whatToReplace")
                        stringName.replace(starting_position, charactersToReplace, "whatToReplace")
*/
#include<iostream>
#include<string>

int main(){

  // Declaring and initializing strings.
  std::string s1;               // Empty - automatically initialize to zero like vectors in modern C++.
  std::string s2 {"Bjarne"};    // Bjarne - c-style literal will be converted into C++ stirng.
  std::string s3 {s2};          // Bjarne - a copy of s2 will be created but in different area of memory.
  std::string s4 {"Bjarne", 3}; // Bja - using first three characters
  std::string s5 {s3, 0, 2};    // Bj - when initializing from another string, the first integer represents starting index, and 
  // the second integer is length of the substring, i.e., 0 to 1
  std::string s6 (3, 'X');      // XXX - initialize string to a specific number of a specific character. This used a constructor 
  // syntax ().

  // std::cout << s1 << std::endl; //automatically initialize to zero (no garbage) like vectors in modern C++ with length 0
  // std::cout << s1.length();

  // Initializing
  std::cout << "\nInitialization" << "\n-----------------------------------------" << std::endl;
  std::cout << "s1 is initialized to: " << s1 << std::endl;
  std::cout << "s2 is initialized to: " << s2 << std::endl;
  std::cout << "s3 is initialized to: " << s3 << std::endl;
  std::cout << "s4 is initialized to: " << s4 << std::endl;
  std::cout << "s5 is initialized to: " << s5 << std::endl;
  std::cout << "s6 is initialized to: " << s6 << std::endl;

  // Comparision ( ==, !=, >, >=, <, <=)
  // TWo string objects are compared character by character & their character values will be compared lexically. (So A is less than Z and A is less than a - That's because the capital letters come before the lowercase letters in the ascii table.)
  // We cant use these operators for two C-style strings but we can use these operators if:
  // two std::string objects
  // std::string object and C-Style string literal
  // std::string object and C-Style variable.

  std::string s11 {"Apple"};
  std::string s12 {"Banana"};
  std::string s13 {"Kiwi"};
  std::string s14 {"apple"};
  std::string s15 {s11}; // Apple

  std::cout << "\nComparision" << "\n---------------------------------------------------------" << std::endl;
  std::cout << std::boolalpha; // true false instead of 1 0

  std::cout << s11 << " == " << s15 << " : " << (s11 == s15) << std::endl;  //true
  std::cout << s11 << " == " << s12 << " : " << (s11 == s12) << std::endl;   //False
  std::cout << s11 << " != " << s12 << " : " << (s11 != s12) << std::endl;  //true
  std::cout << s11 << " < " << s12 << " : " << (s11 < s12) << std::endl;    //true - A comes before a in ASCII
  std::cout << s12 << " > " << s11 << " : " << (s12 > s11) << std::endl;   //true
  std::cout << s14 << " < " << s15 << " : " << (s14 < s15) << std::endl;   //False  - A comes before a in ASCII
  std::cout << s11 << " == " << "Apple" << " : " << (s11 == "Apple") << std::endl; //true - "Apple" is a C-style sting literal and C-style literal is convereted to an object and then we do object to object comparision.
  // ASCII table ye

  // Compare two Strings
  // compare() - returns 0 when strings are same
  std::string s16, s17;
  std::cout << "Enter string 1: ";
  getline(std::cin, s16);

  std::cout << "Enter string 2: ";
  getline(std::cin, s17);

  if (s16.compare(s17) == 0)
    std::cout << "Same!!" << std::endl;
  else 
    std::cout << "Not the Same!" << std::endl;


  // Assigning values - using assignment operator =
  // feels more natural as compared to C-style strings ie using strcpy function.

  std::cout << "\nAssignment" << "\n-----------------------------------------" << std::endl;

  s1 = "C++ Rocks! "; // s1 will grow dynamically as needed.
  std::cout << "s1 is now: " << s1 << std::endl;
  s2 = s1; // s2 is copy of s1, they are not pointing to the same value, they are two copies that are individual. So if s1 is changed 
  // it wont affect s2 and vice versa.
  std::cout << "s2 is now: " << s2 << std::endl;

  s3 = "Bjarne";
  std::cout << "s3 is now: " << s3 << std::endl;

  // Manipulate strings.(subscript operator [] OR  at () method)
  std::cout << "\nManipulating C++ String" << "\n-----------------------------------------" << std::endl;
  std::cout << s3 << std::endl;
  s3[0] = 'C'; //Cjarne
  std::cout << "s3 change first letter to 'C':" << s3 << std::endl;
  s3.at(0) = 'P'; //Pjarne
  std::cout << "s3 change first letter to 'P':" << s3 << std::endl;


  // Concatination of C++ strings
  // We can use + operator to concatinate strings
  // in C-Style strings we used strcat()

  std::cout << "\nConcatination" << "\n-----------------------------------------" << std::endl;

  std::string part1 {"C++"};
  std::string part2 {"is a powerful"};

  std::string sentence;

  sentence = part1 + " " + part2 + " language"; // A combination of c++ strings and c-style strings is okay.

  std::cout << sentence << std::endl;

  s13 = s15 + " and " + s12 + " juice."; // In this case -> s15 + " and " when we are using object and a C-style literal, this is ok, as it will convert
  std::cout << s13 << std::endl;


  // Compiler errors when concatinating two C-style literals
  //  sentence = "C++" + " is powerful"; // illegal - as it have two C-style literals and we cannot concatinate C-style literals. We will get compiler error in this case
  //  s13 = "nice " + " cold " + s15 + "juice"; will get error at this part ->"nice " + " cold " as two C-style literals cannot be concatinated using + operator and we have to use strcat in this case.

  // compund concatenation assignment operator
  std::cout << "\nCompound Concatination" << "\n-----------------------------------------" << std::endl;
  s2 = "Bjarne";
  s2 += " Stroustrup"; // works same way as that compund assignment operators work with integers/doubles etc.
  std::cout << s2 << std::endl; // Bjarne Stroustrup

  // Alternative Concatination method
  std::cout << "\nAlternative Concatination" << "\n-----------------------------------------" << std::endl;
  std::cout << part1.append(part2) << std::endl; // C++is a powerful (without space)

  /************************
   Methods
  **************************/

  // length method -length() - length of strings (number of objects in string )
  std::cout << "\nlength" << "\n-----------------------------------------" << std::endl;
  std::string tests2 {"Bjarne"};
  std::cout << "Length of " << tests2 << " is :" << tests2.length() <<std::endl; // 6

  // size() - alternative method to find the langth of the string 
  std::cout << "\nSize" << "\n-----------------------------------------" << std::endl;
  std::cout << "Length of " << tests2 << " is :" << tests2.size() <<std::endl; // 6

  // for loop / iteration
  std::cout << "\nLooping" << "\n-----------------------------------------" << std::endl;

  std::cout << s2 << std::endl;
  for (size_t i{}; i < s2.length(); ++i)
    std::cout << s2.at(i) << std::endl;  // or s2[i];

  // using range based for loop to display the string characters. (The null character will not be displayed for C++ string objects.)
  std::cout << "\nUsing range based for loop \n";
  for (const auto &c: s2)  // if we change char to int - it will display the integer values (ASCII codes) that represents those characters.
    std::cout << c << std::endl;

  // Substrings - substr() - extracts a substring from a std::string.
  std::cout << "\nSubstring" << "\n-----------------------------------------" << std::endl;
  std::string str1 {"This is a test"};

  std::cout << str1.substr(0,4) << std::endl; // This - from index 0 till next 4 characters, if <4 characters left in the string then the remaining characters are included.
  std::cout << str1.substr(5,2) << std::endl; // is - starting at index 5 and including two characters
  std::cout << str1.substr(10,4) << std::endl; // test - starting at index 10 and includes 4 characters.

  // erase()
  //erase() - removing character, starting index, how many characters to delete

  std::cout << "\nErase" << "\n-----------------------------------------" << std::endl;
  std::cout << str1.erase(0,5) << std::endl; // will erase "This" and return str1 which is now "is a test"
  std::cout << str1.erase(5,4) << std::endl; // will erase "test" for str1 which is now "is a test" and will return "is a"


  // input with C++ strings
  // input >> and getline()
  // C++ string work great with input and output streams e.g with output stream (cout) and extracting c++ string from an input stream 
  // (cin). However,there's one issue that's also true for c-style strings.

  std::string stringone;
  //std::cin >> stringone; // only accepts up to the first space. e.g if "Hello there" is entered, only Hello will be displayed. This is because extraction operator stops when it sees white space.
  // std::cout << stringone << std::endl; // Hello

  std::cout << "\ngetline" << "\n-----------------------------------------" << std::endl;
  // in many cases we need to read entire line of text till user presses enter. getline() is used in such cases
  std::cout << "Enter your full name: ";
  getline(std::cin, stringone); //Read entire line until \n - first element (cin) -input stream - where we want to get the input, second element is name of c++ string where you want the text that the user enters stored.
  std::cout << "Your full name is : " << stringone << std::endl; // Hello there

  // getline with delimiter
  std::cout << "Enter string with ending at delimiter x: ";
  getline(std::cin, stringone, 'x'); // this isx -another variant - has one additional parameter - delimiter - the character that we want getline to stop reading input at. so as long as the user doesnt enter delimiter, everything will be stored in the string variable. delimited is not stored in the variable, its discarded.
  std::cout << stringone << std::endl; // this is


  // Searching - find() - returns the index of substring in a std::string.
  std::cout << "\nfind" << "\n-----------------------------------------" << std::endl;
  str1 = "This is a test";
  std::cout << str1.find("This") << std::endl; // 0 - since This starts at 0
  std::cout << str1.find("is") << std::endl; // 2 - since first is starts at positon 2
  std::cout << str1.find("test") << std::endl; // 10 -index where test starts
  std::cout << str1.find('e') << std::endl; // 11 - first occurance at index 11
  std::cout << str1.find("is",4) << std::endl; // 5 - variant of the method that allows the index where we want to start the search from (starting at index 4 in this eg)
  std::cout << str1.find("XX") << std::endl; // string::npos -18446744073709551615 -(no position information available)- what if the string/character  we want to find isnt there. In this case the method returns end position which means no position information available.
  // string::npos end of the string. 

  // we can check for a word in the string using if statement. The user will enter a word/character in the defined string (str1)
  std::string word {};

  std::cout << "Enter the word to find: ";
  std::cin >> word;

  size_t position = str1.find(word);
  if (position != std::string::npos) // string::npos will search till the end of the string.
    std::cout << "Found " << word << " at positon: " << position << std::endl;
  else
    std::cout << "Sorry, the word - " << word << " - not found" << std::endl;

  // rfind - find from right hand side  
  std::string rfindstr {"This is a string"};
  int pos = rfindstr.rfind("s"); //10
  std::cout << "find last \"s\" in s1 (pos): " << pos << std::endl;  

  // clear() method
  // clear() - removing entire string of characters
  std::cout << "\nclear" << "\n-----------------------------------------" << std::endl;
  std::cout << "Value of str1 is :" << str1 << std::endl;
  str1.clear(); // empties string str1
  std::cout << "Updated value of str1 is : " << str1 << std::endl;

  // insert()
  std::cout << "\ninsert" << "\n-----------------------------------------" << std::endl;
  std::string unformatted_full_name {"BjarneStroustrup"};

  std::string first_name {unformatted_full_name, 0, 6}; // Bjarne
  std::string last_name = unformatted_full_name.substr(6, 10); // Stroustrup

  std::string formatted_full_name = first_name + last_name; // BjarneStroustrup

  formatted_full_name.insert(6, " "); //inset space at index 6

  std::cout << "Formatted string :" << formatted_full_name << std::endl; //Bjarne Stroustrup

  //insert using iterator 
  s1.insert(s1.begin() + 3, 'X');
  std::cout << "s1 after insert: " << s1 << std::endl; //C++X Rocks!

  // swap ()
  std::cout << "\nswap()" << "\n-----------------------------------------" << std::endl;

  // program that will be used in a digital library to format and sort journal entries based on the authors last name. Each entry has room to store only the last name of the author.

  std::string journal_entry_1 {"Isaac Newton"};
  std::string journal_entry_2 {"Leibniz"};

  // swap()
  journal_entry_1.swap(journal_entry_2);
  std::cout << "journal_entry_1: " << journal_entry_1 << std::endl; // Leibniz
  std::cout << "journal_entry_2: " << journal_entry_2 << std::endl; // Isaac Newton

  // erase()
  // removing the first name of Isaac Newton along with white space.
  journal_entry_1 = "Isaac Newton";
  std::cout << "After Erase : " << journal_entry_1.erase(0,6) << std::endl; // Newton

  // erase() using iterator 
  journal_entry_2.erase(journal_entry_2.begin() + 6);
  std::cout << "Erase Using Iterator: " << journal_entry_2 << std::endl; // Isaac ewton 

  // replace
  // stringName.replace(starting_position, charactersToReplace, "whatToReplace")
  std::string st1 {"This is a string"};
  st1.replace(5, 2, "ain't");
  std::cout << "st1 after replace: " << st1 << std::endl; //This ain't a string

  // Alphabetically sorting
  if (journal_entry_2 < journal_entry_1) // 1 - as L is smaller than N in ASCII table lexically.
    journal_entry_2.swap(journal_entry_1); // it will swap strings such that journal_entry_1 will be Leibniz and journal_entry_2 will become Newton.

  std::cout << journal_entry_1 << "\n" << journal_entry_2 << std::endl;

  return 0;
}