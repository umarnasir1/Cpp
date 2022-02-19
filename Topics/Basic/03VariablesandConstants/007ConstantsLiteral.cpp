// Constants - E.g., Literal Constants - demetit - if have to change value for e.g., the price per roo, or tax, we have to change every where. for larger programs, this can be issue. 

/*
    Frank's Carpet Cleaning Service
    Charges $30 per room
    Sales tax rate is 6%
    Estimates are valid for 30 days

    Prompt the user for the number of rooms they would like cleaned
    and provide an estimate such as:

Estimate for carpet cleaning service:
Number of rooms: 2
Price per room: $30
Cost: $60
Tax: $3.6
====================================
Total estimate: $63.6
This estimate is valid for 30 days

Pseudocode:
    Prompt the user to enter the number of rooms
    Display number of rooms
    Display price per room

    Display cost:  (number of rooms * price per room)
    Display tax:   number of rooms * price per room * tax rate
    Display total estimate: (number of rooms * price per room) + (number of rooms * price per room * tax rate)
    Display estimate expiration time
*/

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main() {
    cout << "Hello, welcome to Frank's Carpet Cleaning Service" << endl;
    cout << "\nHow many rooms would you like cleaned? ";

    int number_of_rooms {0};
    cin >> number_of_rooms;

    cout << "\nEstimate for carpet cleaning service" << endl;
    cout << "Number of rooms: " << number_of_rooms << endl;
    cout << "Price per room: $" << 30 << endl;
    cout << "Cost : $" << 30 * number_of_rooms << endl;
    cout << "Tax: $" << 30 * number_of_rooms * 0.06 << endl;
    cout << "===============================" << endl;
    cout << "Total estimate: $" << ( 30 * number_of_rooms) + (30 * number_of_rooms * 0.06) << endl;
    cout << "This estimate is valid for " << 30 << " days" << endl;

    cout << endl;
    return 0;
}
