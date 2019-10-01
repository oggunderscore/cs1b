//--------------------------------------------------------------------------
//  File name: mainmenu.cpp
//  Project name: Serendipity
//--------------------------------------------------------------------------
//  Creator's name and email: Felix Murray felix.murray@gmail.com
//  Course Selection: CS1B
//  Creation Date: 8/24/19
//  Date of Last Modification: 8/28/19
//--------------------------------------------------------------------------
//  Purpose: This program will display the main menu of the store and take
//           user input to determine which store module function to call
//           and move the user to.
//--------------------------------------------------------------------------
//  Algorithm:
//      Step 1: Display Menu Options to the console and prompt user to make
//              a selection.
//      Step 2: Recieve user input for option.
//      Step 3: Switch in user input and either call function for the module
//               corresponding with the given option or display error
//               message if input is not '1', '2', '3', or '4'.
//      Step 4: Repeat steps 1 - 3 until user enters '4' to quit.
//--------------------------------------------------------------------------

#include <iostream>
#include <iomanip>
#include <string>
#include "cashier.hpp"
#include "inventorymenu.hpp"
#include "reports.hpp"
#include "bookinfo.hpp"
#include "searchbook.hpp"
#include "bookdata.hpp"
#include "util.hpp"

using namespace std;

void mainMenu (int &bookNum, bookType books[]) {
    //--------------------------------------------------------------------------
	// DATA DICTIONARY
	//--------------------------------------------------------------------------
	// VARIABLES
	//
	//   NAME              DATA TYPE         VALUE
	//--------------------------------------------------------------------------
	//  choice				char				null
	//  reply              string   			null
    //  shouldLoop          bool                true 
	//--------------------------------------------------------------------------
    char choice;
    bool shouldLoop = true;

    do
    {
        system("clear");
        cout
            << "\t\t\t\t\t  Serendipity Book Sellers\n"
            << "\t\t\t\t\t          Main Menu\n\n"
            << "\t\t\t\t\t1.   Cashier Module\n"
            << "\t\t\t\t\t2.   Inventory Database Module\n"
            << "\t\t\t\t\t3.   Report Module\n"
            << "\t\t\t\t\t4.   Exit\n\n"
            << "\t\t\t\t\t     Enter Your Choice: ";

        cin >> choice;

        switch (choice)
        {
        case '1':
            cashier(bookNum, books);
            break;
        case '2':
            invMenu(bookNum, books);
            break;
        case '3':
            reportsMenu();
            break;
        case '4':
            shouldLoop = false;
            system("clear");
            break;
        default:
            system("clear");
            cout << "ERROR: Choice must be a number 1 - 4.\n\n";
            pause();
            break;
        }
    } while (shouldLoop);
}