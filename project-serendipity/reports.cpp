//--------------------------------------------------------------------------
//  File name: reports.cpp 
//  Project name: Serendipity
//--------------------------------------------------------------------------
//  Creator's name and email: Felix Murray felix.murray@gmail.com
//  Course Selection: CS1B
//  Creation Date: 8/24/19
//  Date of Last Modification: 8/28/19
//--------------------------------------------------------------------------
//  Purpose: This program will display the reports menu and take user input 
//           for a menu selection. 
//--------------------------------------------------------------------------
//  Algorithm: 
//      Step 1: Display Menu Options to the console and prompt user to make 
//              a selection.
//      Step 2: Recieve user input for option.
//      Step 3: Switch in user input and either display a temporary message
//              informing the user of the choice they made or return to the
// 				main menu.
//      Step 4: Repeat steps 1 - 3 until user enters '7' to return to the 
//              main menu.  
//--------------------------------------------------------------------------

#include <iostream>
#include "reports.hpp"

using namespace std;

void reportsMenu () {
	//--------------------------------------------------------------------------
	// 	DATA DICTIONARY
	//--------------------------------------------------------------------------
	// VARIABLES
	//
	//   NAME              DATA TYPE         VALUE
	//--------------------------------------------------------------------------
	//  choice				char				null
	//  exit                bool               false
	//  reply              string   			null 
	//--------------------------------------------------------------------------
	char choice;
	bool exit = false;
	char reply; 

	do {
		system("clear");
		cout << "\t\t\t\t\t  Serendipity Booksellers\n";
		cout << "\t\t\t\t\t          Reports\n\n";

		cout << "\t\t\t\t\t1. Inventory Listing\n";
		cout << "\t\t\t\t\t2. Inventory Wholesale Value\n";
		cout << "\t\t\t\t\t3. Inventory Retail Value\n";
		cout << "\t\t\t\t\t4. Listing by Quantity\n";
		cout << "\t\t\t\t\t5. Listing by Cost\n";
        cout << "\t\t\t\t\t6. Listing by Age\n";
        cout << "\t\t\t\t\t7. Return to the Main Menu\n\n";

		cout << "\t\t\t\t\t     Enter Your Choice: ";
		cin >> choice;

		switch (choice) {
			case '1': 
				system("clear");
				cout << "You entered choice 1...\n\n";
				cout << "Press any key to continue...";
				cin >> reply;
				if (reply != '\0'){ 
					break;
				}
			case '2':
				system("clear");
				cout << "You entered choice 2...\n\n";
				cout << "Press any key then to continue...";
				cin >> reply;

				if (reply != '\0'){ 
					break;
				}
			case '3': 
				system("clear");
				cout << "You entered choice 3...\n\n";
				cout << "Press any key to continue...";
				cin >> reply;

				if (reply != '\0'){ 
					break;
				}
			case '4': 
				system("clear");
				cout << "You entered choice 4...\n\n";
				cout << "Press any key to continue...";
				cin >> reply;
				if (reply != '\0'){ 
					break;
				}
			case '5': 
				system("clear");
				cout << "You entered choice 5...\n\n";
				cout << "Press any key to continue...";
				cin >> reply;
				if (reply != '\0'){ 
					break;
				} 
            case '6':
                system("clear");
				cout << "You entered choice 6...\n\n";
				cout << "Press any key to continue...";
				cin >> reply;
				if (reply != '\0'){ 
					break;
				}
            case '7':
                exit = true;
				break;
			default: 
				system("clear");
				cout << "ERROR: Choice must be a number 1 - 7.\n\n";
				cout << "Press any key to continue...";
				cin >> reply;
				
				if (reply != '\0'){ 
					break;
				}
		}
	} while (exit != true);
	
}