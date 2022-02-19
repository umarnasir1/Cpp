// Constants - Declared constants- but with additional small room

/*
    Frank's Carpet Cleaning Service
    Charges:
      $25 per small room
      $35 per large room
    Sales tax rate is 6%
    Estimates are valid for 30 days

    Prompt the user for the number of small and large rooms they would like cleaned
    and provide an estimate such as:

Estimate for carpet cleaning service:
Number of small rooms: 3
Number of large rooms: 1
Price per small room: $25
Price per large room: $35
Cost: $110
Tax: $6.6
====================================
Total estimate: $116.6
This estimate is valid for 30 days

*/

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main() {
    cout << "Hello, welcome to Frank's Carpet Cleaning Service" << endl;

    int number_of_small_rooms {0};
    cout << "\nHow many small rooms would you like cleaned? ";
    cin >> number_of_small_rooms;

    int number_of_large_rooms {0};
    cout <<"\nHow many large rooms would you like cleaned? ";
    cin >> number_of_large_rooms;

    // Declared Constants
    const double price_per_small_room {25.0};
    const double price_per_large_room {35.0};
    const double sales_tax {0.06};
    const int estimate_expiry {30}; // days

    // Variables
    double cost = (price_per_small_room * number_of_small_rooms) +
                  (price_per_large_room * number_of_large_rooms);
    double tax = cost * sales_tax;

    cout << "\nEstimate for carpet cleaning service" << endl;
    cout << "Number of small rooms: " << number_of_small_rooms << endl;
    cout << "Number of large rooms: " << number_of_large_rooms << endl;
    cout << "Price per small room: $" << price_per_small_room << endl;
    cout << "Price per large room: $" << price_per_large_room << endl;

    cout << "Cost : $" << cost << endl;

    cout << "Tax: $" << tax << endl;

    cout << "===============================" << endl;
    cout << "Total estimate: $" << cost + tax << endl;

    cout << "This estimate is valid for " << estimate_expiry << " days" << endl;

    cout << endl;
    return 0;
}
