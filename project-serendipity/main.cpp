#include <iostream>
#include <iomanip>

#include "util.hpp"
#include "cashier.hpp"

using std::cout; 
using std::cin; 
using std::system;

void menu () {
    char option;
    bool shouldLoop = true; 
    while (shouldLoop) {
        system("clear");
        cout
            << "Serendipity Book Sellers\n"
            << "Main Menu\n\n"
            << "1.   Cashier Module\n"
            << "2.   Inventory Database Module\n"
            << "3.   Report Module\n"
            << "4.   Exit\n\n"
            << "Enter Your Choice: ";

        cin >> option;
        
        switch (option) {
            case '1':
                break;
            case '2': 
                break; 
            case '3':
                break;
            case '4':
                shouldLoop = false; 
                break; 
            default: 
                cout << "ERROR: Input Must be an Option from 1 - 4.";
                break; 
        }
    }
}

int main () {

    return 0; 
}