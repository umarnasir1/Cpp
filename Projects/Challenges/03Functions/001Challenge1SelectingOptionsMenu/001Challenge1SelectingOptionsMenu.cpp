// Functions -Challenge 
/*
     Recall the challenge from Section 9 below.
    Your challenge for section 11 is to modularize your solution to the Section 9
    challenge by refactoring your solution so that it uses uses functions.
    
    You decide how to modularize the program.
    you can use my solution which is included in this file, or modularize your solution.
    
    Here are a few hints:
        - Create functions for each major function
        - Keep the functions small
        - Remember the Boss/Worker analogy
        - Keep the vector declaration in the main function and pass the vector object
          to any function that requires it

        DO NOT move the vector object outside main and make it a global variable.
    
        - You can start by defining a function that displays the menu
        - You can then define a function that reads the selection from the user and returns it in uppercase
        - Create functions for each menu option
        - Create functions that display the list of numbers, calculates the mean and so forth
        
    Take it one function at a time and take your time.
    If you get frustrated, take a break -- this isn't as easy as it looks the first time you do it!
    
    Finally,  don't forget to use function prototypes!
    
    Good luck -- I know you can do it!
*/
/*    
    This challenge is about using a collection (list) of integers and allowing the user
    to select options from a menu to perform operations on the list.
    
    Your program should display a menu options to the user as follows:
    
    P - Print numbers
    A - Add a number
    M - Display mean of the numbers
    S - Display the smallest number
    L - Display the largest number
    Q - Quit

    Enter your choice:
    
The program should only accept valid choices from the user, both upper and lowercase selections should be allowed.
If an illegal choice is made, you should display, "Unknown selection, please try again" and the menu options should be
displayed again.


If the user enters 'P' or 'p', you should display all of the elements (ints) in the list.
If the list is empty you should display "[] - the list is empty"
If the list is not empty then all the list element should be displayed inside square brackets separated by a space. 
For example, [ 1 2 3 4 5 ]
      
If the user enters 'A' or 'a' then you should prompt the user for an integer to add to the list 
which you will add to the list and then display it was added. For example, if the user enters 5
You should display, "5 added".
Duplicate list entries are OK

If the user enters 'M' or 'm'  you should calculate the mean or average of the elements in the list and display it.
If the list is empty you should display, "Unable to calculate the mean - no data"

If the user enters 'S' or 's' you should display the smallest element in the list.
For example, if the list contains [2 4 5 1],  you should display, "The smallest number is 1"
If the list is empty you should display, "Unable to determine the smallest number - list is empty"

If the user enters 'L' or 'l' you should display the largest element in the list
For example, if the list contains [2 4 5 1], you should display, "The largest number is 5"
If the list is empty you should display, "Unable to determine the largest number - list is empty"

If the user enters 'Q' or 'q' then you should display 'Goodbye" and the program should terminate.

Before you begin. Write out the steps you need to take and decide in what order they should be done.
Think about what loops you should use as well as what you will use for your selection logic.

This exercise can be challenging! It may likely take a few attempts before you complete it -- that's OK!

Finally, be sure to test your program as you go and at the end.

Hint: Use a vector!

Additional functionality if you wish to extend this program.

- search for a number in the list and if found display the number of times it occurs in the list
- clearing out the list (make it empty again) (Hint: the vector class has a .clear() method)
- don't allow duplicate entries
- come up with your own ideas!

Good luck!
*/
#include <iostream>
#include <vector>
#include <cctype> // for to upper

// Function Prototypes
// for displaying menu and getting user selection 
void display_menu();
char get_selection(); 

// Menu Handling function prototypes 
void handle_display(const std::vector<int> &v); 
void handle_add(std::vector<int> &v);
void handle_mean(const std::vector<int> &v);
void handle_smallest(const std::vector<int> &v);
void handle_largest(const std::vector<int> &v);
void handle_find(const std::vector<int> &v);
void handle_quit(); 
void handle_unknown(); 

// Prototypes of functions working with the vector
void display_numbers(const std::vector<int> &v);
double calculate_mean(const std::vector<int> &v);
int smallest_number(const std::vector<int> &v);
int largest_number(const std::vector<int> &v);
bool find(const std::vector<int> &v, int target); // bool as it will return true or false; target- the number we are

int main() {

    std::vector<int> numbers;
    char selection {};
    
    do {
        // Display menu
        display_menu(); 
        selection = get_selection(); 

        if (selection == 'P') {
            handle_display(numbers);
        } else if (selection == 'A') {
            handle_add(numbers);
        } else if (selection == 'M') {
            handle_mean(numbers);
        } else if (selection == 'S') {
            handle_smallest(numbers); 
        } else if (selection == 'L') {
            handle_largest(numbers);
        } else if (selection == 'F'){
            handle_find(numbers);
        } else if (selection == 'Q') {
            handle_quit(); 
        } else {
            handle_unknown(); 
        }
    } while (selection != 'Q');

    // // if option of both lower and upper case characters 
    // do {
    //     // Display menu
    //     display_menu(); 
    //     selection = get_selection(); 

    //     if (selection == 'P' || selection == 'p') {
    //         print_numbers(numbers);
    //     } else if (selection == 'A' || selection == 'a') {
    //         int num_to_add {};
    //         std::cout << "Enter an integer to add to the list: ";
    //         std::cin >> num_to_add;
    //         add_numbers (numbers, num_to_add);
    //     } else if (selection == 'M' || selection == 'm') {
    //         arithematic_mean (numbers);
    //     } else if (selection == 'S' || selection == 's') {
    //         smallest_number(numbers);
    //     } else if (selection == 'L' || selection == 'l') {
    //         largest_number(numbers);
    //     } else if (selection == 'Q' || selection == 'q') {
    //         std::cout << "Goodbye" << std::endl;
    //     } else {
    //         std::cout << "Unknown selection, please try again" << std::endl;
    //     }
    // } while (selection != 'q' && selection != 'Q');

    // switch case solution 
    // do {
    //     display_menu();
    //     selection = get_selection();
    //     switch (selection) {
    //         case 'P': 
    //             handle_display(numbers); 
    //             break;
    //         case 'A': 
    //             handle_add(numbers);
    //             break;
    //         case 'M':
    //             handle_mean(numbers);
    //             break;
    //         case 'S':
    //             handle_smallest(numbers);
    //             break;
    //         case 'L':
    //             handle_largest(numbers);
    //             break;
    //         case 'F':
    //             handle_find(numbers);
    //             break;
    //         case 'Q':
    //             handle_quit();
    //             break;
    //         default:
    //             handle_unknown();
    //     }
    // } while (selection != 'Q');


    std::cout << std::endl;
    return 0;
}

/****************************************************************
Function Definition
****************************************************************/



// This function displays the menu to the console.
void display_menu (){
    std::cout << "\nP - Print numbers" << std::endl;
    std::cout << "A - Add a number" << std::endl;
    std::cout << "M - Display mean of the numbers" << std::endl;
    std::cout << "S - Display the smallest number" << std::endl;
    std::cout << "L - Display the largest number" << std::endl;
    std::cout << "F - Find a number" << std::endl; 
    std::cout << "Q - Quit" << std::endl;
    std::cout << "\nEnter your choice: ";
}

// This function simply reads a character selection from std::cin and returns it as upper case.
char get_selection(){
    char c {}; // local to get_selection()
    std::cin >> c;
    return toupper(c);  
}

// This function is called when the user selects the display list option from the main menu.
void handle_display (const std::vector<int> &v){ // const as we dont want the function to change the vector; & (no copy)
    if (v.size() == 0)
        std::cout << "[] - the list is empty" << std::endl;
    else 
        display_numbers(v); // making another fucntion for displaying the numbers
    return; 
}

// This function is called when the user selects add a number to the list from the main menu
void handle_add (std::vector<int> &v){ // no const as we will change the list, i.e., add a value in the list. 
    int num_to_add {};
    std::cout << "Enter an integer to add to the list: ";
    std::cin >> num_to_add;
    v.push_back(num_to_add);
    std::cout << num_to_add << " added" << std::endl;
    return; 
}

// This function is called when the user selects calculate the mean from the main menu
void handle_mean (const std::vector<int> &v){ // const as we dont want this function to modify the vector
    if (v.size() == 0) // checking if list is empty
        std::cout << "Unable to calculate mean - no data" << std::endl;
    else 
        std::cout << "The mean is : " << calculate_mean(v) << std::endl;   
    return; 
}

// This function is called when the user selects the smallest  option from the main menu
void handle_smallest(const std::vector<int> &v){ // the parameter is a const reference parameter this function should NOT modify the list of numbers
    if (v.size() == 0) 
        std::cout << "Unable to determine the smallest - list is empty" << std::endl;
    else 
        std::cout << "The smallest number is: " << smallest_number(v) << std::endl;
    return; 
}

// This function is called when the user selects the largest  option from the main menu
void handle_largest (const std::vector<int> &v){ // the parameter is a const reference parameter this function should NOT modify the list of numbers
    if (v.size() == 0)
        std::cout << "Unable to determine largest - list is empty"<< std::endl;   
    else 
        std::cout << "The largest number is: " << largest_number(v) << std::endl;
    return; 
}

// This function is called when the user selects the find option from the main menu
void handle_find(const std::vector<int> &v){ // the parameter is a const reference parameter this function should NOT modify the list of numbers
    if (v.size() == 0)
        std::cout << "The list is empty" << std::endl; 
    else {
        int target {}; 
        std::cout << "Enter the number to find: "; 
        std::cin >> target;  
        if (find(v, target))
            std::cout << target << " was found." << std::endl;
        else 
            std::cout << target << " wasn't found." << std::endl;
    }
    return; 
}

// This function is called when the user selects the quit  option from the main menu
void handle_quit(){
    std::cout << "Goodbye" << std::endl;
    return; 
}

// This function is called whenever the user enters a selection and we don't know how to handle it, i.e., 
// It is not one of the valid options in the main menu
void handle_unknown(){
    std::cout << "Unknown selection, please try again" << std::endl;
    return; 
}

// This function expects a list of integers as a vector and displays all the integers in the list in square brackets
void display_numbers (const std::vector<int> &v){ // the parameter is a const reference parameter this function should NOT modify the list of numbers
    std::cout << "[ ";
    for (auto num: v)
        std::cout << num << " ";
    std::cout << "]" << std::endl; 
    return; 
}

// This function expects a list of integers as a vector and returns the calculated mean
double calculate_mean (const std::vector<int> &v){ // the parameter is a const reference parameter this function should NOT modify the list of numbers
    int total {};
    for (auto num: v)
        total += num;
    return static_cast<double>(total)/v.size(); // casting into double
}

// This function expects a list of integers as a vector and returns the smallest integer in the list
int smallest_number (const std::vector<int> &v){ // the parameter is a const reference parameter this function should NOT modify the list of numbers
    int smallest = v.at(0);
    for (auto num: v)
        if (num < smallest)
            smallest = num;
    return smallest; 
}

// This function expects a list of integers as a vector and returns the largest integer in the list
int largest_number (const std::vector<int> &v){ // the parameter is a const reference parameter; this function should NOT modify the list of numbers
    int largest = v.at(0);
    for (auto num: v)
        if (num > largest)
            largest = num;
    return largest; 
}

// This function searches the list of integers as a vector for the given integer target
bool find (const std::vector<int> &v, int target){ // the parameter is a const reference parameter; this function should NOT modify the list of numbers
    for (auto num: v)
        if (num == target) // target found
            return 1; // return true
    return 0; // return false - target not found
}