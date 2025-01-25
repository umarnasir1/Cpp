/*
  Character Functions - C-Style Strings

  C-Style Strings : should end with NULL Character \0 othervise there will be problems as  all c-style string functions 
  expect to find a null character.
  Always initilize c-style strings so they have NULL Character in the end

  C++ is fun have 10 characters but compiler have allocated 11 characters for it.

  0 1 2 3 4 5 6 7 8 9  10
  C + +   i s   f u n NULL

  String Functions
    strcat - concatinate strings
    Strcpy - copy C style String
    strcmp - will compare two strings
    strlen - display lenght of a c-style string

    getline() - input user string 
*/

#include <iostream>
#include <cstring>
#include <cctype>

int main (){

  // Eg. 1
  char my_name [] {"Frank"}; // declaring C style string
  // C++ compiler will allocate 5 characters for this array since it need to terminate the string with NULL character.
  // F r a n k \0
  // 0 1 2 3 4 5

  my_name [5] = 'y'; // Franky - will replace the null character \0 with y
  // F r a n k y
  // 0 1 2 3 4 5
  // since the size of the array is fixed. So if we  wanted to add a y to Frank and create Franky, we couldn't without having some 
  // potential problems since the new string would not be null terminated (drawback of arrays). We will not get a compiler error or 
  // even a warning as, in this case, my_name index 5 is still within the array bounds.

  // my_name [6] = 'x'; // WARNING - since the size of the array is fixed. So if we want to add a x to Franky and create Frankyx, 
  // we couldn't without having some potential problems since the new string would full (drawback of arrays). We will not get a
  // compiler error but just a warning.
  // my_name [7] = 'z'; // WARNING - since the size of the array is fixed. So if we want to add a x to Franky and create Frankyx, 
  // we couldn't without having some potential problems since the new string would full (drawback of arrays). We will not get a 
  // compiler error but just a warning.

  // Eg. 2
  char my_name1 [8] {"Frank"}; // we are explicitly asking the compiler to allocate 8 characters to array so remaining characters 
  // will be NULL. In this case, if we want to change the character at index 5, which is that first null character to a lowercase y, 
  // it would be just fine since the string now contains Franky and is still null terminated.

  // F r a n k \0 \0 \0
  // 0 1 2 3 4 5  6  7

  // Eg. 3
  char my_name2 [8];
  // In this example, we ask the compiler to allocate an array of eight characters, and we don't initialize them. This could be very 
  //  problematic because if you use this array as a string, all C-style string functions expect to find a null character. And here 
  //  there may or may not be one. We really don't know what the data in the array is.

  //------------------------------------
  // String Functions
  // 1. How to copy a c-style string.
  //------------------------------------
  // Well, in this case we start at the first element of the array and we iterate through the array. At every character, we see if 
  //  it's the null character. If it is, we stop since we reach the end of the string. If it's not, we print the character and then 
  //  we move to the next character. In this case, we don't know what's going to happen. We might see a null right away or we might 
  //  not see a null for a very long time. Additionally, Some of the stuff may not even be displayable since some characters are 
  //  control characters.

  //my_name2 = "Frank"; // Compiler Error - we cant initialize c-style stings using the assignment operator. Reason: Array names and 
  // literals evaluate to their location in memory, so we're effectively assigning one location to another which is illegal. Think 
  // of this as saying assign 10 to 12. It doesn't make sense and the compiler won't allow it.

  // Strcpy
    // How to copy string - same as how to display a string and how to calcualte length of C- style string. It will copy one 
    // character at a time till it hit the NULL character.

  strcpy(my_name2, "Frank"); // strcpy function is used to copy c-style literal "Frank" to name array.
  std::cout << my_name2 << std::endl;

  //------------------------------------
  // String Functions
  // 2. How to display lenght of a c-style string using strlen.
  //------------------------------------

  // Let's say we have Frank. Since no length information is stored with the string only the characters in the array, the only way 
  // to determine the length is to start counting at the first array element and then increment the longest until you see the null 
  // character. So in the case of "Frank", we would look at the f, increment one, look at the r, two, the a, three the, n four, the k 
  // five. Then we see a null character, and we stop. Now we know that the length is five. But if there is no NULL character, we 
  // keep going and we keep counting. So the result will very likely be incorrect, even worse if you're copying one string into 
  // another and the string you're copying isn't null terminated, you'll very likely exceed the bounds of the target string and very 
  // likely cause a program crash.

  // strcmp - will compare two strings; if two strings are same (character by character lexically), the strcmp() will return 0 else, 
  // it will return a negative number or a positive number depending on which of the string is larger. It returns <0 if the first 
  // string lexically comes before the second string or return >0 if the first string lexically comes after the second string.

  // so these functions, copy character by character and then put a NULL character in the end.

  // Eg. 4
  // Examples using string functions.
  char str [80];
  strcpy(str, "Hello "); // copy
  strcat (str, "there"); // concatenate
  std::cout << strlen (str) << std::endl;  // 11 (Hello there)
  strcmp (str, "Another");

  // Eg. 5
  // char first_name[20];
  // displaying first name as we havent initilized it.
  // cout << first_name; // Will likely display garbage (what ever characters are at that location, if there are NULL characters at those locations, then nothing will print so best practice is to initilize strings).

  char first_name[20] {};
  char last_name[20] {};
  char full_name[50] {};
  char temp[50] {};

/*
  cout << "Please enter your first name: ";
  cin >> first_name;

  cout << "Please enter your last name: ";
  cin >> last_name;
  cout << "--------------------------------------" << endl;

  cout << "Hello, " << first_name << ", your first name has " << strlen(first_name)
       << " characters and your last name, " << last_name << " has " << strlen(last_name) << " characters."
       << endl;

  strcpy(full_name, first_name); // copy first_name to full_name
  strcat(full_name, " "); // concatenate full_name and a space
  strcat(full_name, last_name); // concatenate last_name to full_name
  cout << "Your full name is " << full_name << endl;

  //behavior of cin extraction operator in string case.
  cout << "-------------------------" << endl;
  cout << "Enter your full name: ";
  cin >> full_name;    // it reads a space and it stops (so nothing after space will be displayed - stops at NULL character)
  cout << "Your full name is " << full_name << endl;
*/

  // so, solution will be using getline fucntion (works with C-style strings.
  std::cout << "\nEnter your full name : ";
  std::cin.getline(full_name, 50); // full_name is c-style string; 50 is limit -how many characters maximum you are going to read. So it will either stop when we press enter or at 50 characters.
  std::cout <<"Your full name is " << full_name << std::endl;

  // Comparision Example
  std::cout << "-----------------------------------" << std::endl;
  strcpy(temp, full_name);
  if (strcmp(temp, full_name) == 0) // they should be the same
    std::cout << temp << " and " << full_name << " are the same." << std::endl; // if same
  else
    std::cout << temp << " and " << full_name << " are different." << std::endl; // if not same

  std::cout <<"-------------------------------------" << std::endl;

  // modify the string and compare it again.
  // converting full_name into upper case
  for (size_t i{0}; i < strlen(full_name); ++i) //using size_t instead of int (as strlen return size_t)
    if(isalpha(full_name[i])) // checking if the character is alphabet
      full_name[i] = toupper(full_name[i]);

  std::cout << "Your full name is " << full_name <<std::endl;

  // comparing again (full_name is full upper case name; temp is name as typed by user)
  std::cout << "---------------------------------------------------" << std::endl;
  if (strcmp(temp, full_name) == 0)
    std::cout << temp << " and " << full_name << " are the same" << std::endl;
  else
    std::cout << temp << " and " << full_name << " are different" << std::endl;

  std::cout << "----------------------------------------------------" << std::endl;
  std::cout << "Result of comparing " << temp << " and " << full_name << ":" << strcmp(temp, full_name) << std::endl;
  std::cout << "Result of comparing " << full_name << " and " << temp << ":" << strcmp(full_name, temp) << std::endl;

  return 0;
}
