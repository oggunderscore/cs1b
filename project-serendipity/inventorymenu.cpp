//--------------------------------------------------------------------------
//  File name: invmenu.cpp
//  Project name: Serendipity
//--------------------------------------------------------------------------
//  Creator's name and email: Felix Murray felix.murray@gmail.com
//  Course Selection: CS1B
//  Creation Date: 8/24/19
//  Date of Last Modification: 8/28/19
//--------------------------------------------------------------------------
//  Purpose: This program will display the inventory database menu and
//           take user input for a menu selection.
//--------------------------------------------------------------------------
//  Algorithm:
//      Step 1: Display Menu Options to the console and prompt user to make
//              a selection.
//      Step 2: Recieve user input for option.
//      Step 3: Switch in user input and either display a temporary message
//              informing the user of the choice they made or return to the
// 				main menu.
//      Step 4: Repeat steps 1 - 3 until user enters '5' to return to the
//              main menu.
//--------------------------------------------------------------------------

#include <iostream>
#include <string>
#include "inventorymenu.hpp"
#include "addbook.hpp"
#include "editbook.hpp"
#include "searchbook.hpp"
#include "bookdata.hpp"
#include "util.hpp"
#include "deletebook.hpp"
#include "menuformatting.hpp"

using namespace std;

void invMenu (bookType books[]) {
	//--------------------------------------------------------------------------
	// DATA DICTIONARY
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

	do
	{
		printHeaderMenu(MENU_INVENTORY);

		cout << "\t\t\t\t       Current Database Size: " << books[0].getBookCount()
			 << " (Max 20)\n" << endl;

		cout << "\t\t\t\t\t1.   Look Up a Book\n";
		cout << "\t\t\t\t\t2.   Add a Book\n";
		cout << "\t\t\t\t\t3.   Edit a Book's Record\n";
		cout << "\t\t\t\t\t4.   Delete a Book\n";
		cout << "\t\t\t\t\t5.   Return to the Main Menu\n\n";

		cout << "\t\t\t\t\t     Enter Your Choice: ";
		cin >> choice;

		switch (choice)
		{
		case '1':
			lookUpBook(books);
			break;
		case '2':
			addBook(books);
			break;
		case '3':
			editBook(books);
			break;
		case '4':
			deleteBook(books);
			break;
		case '5':
			exit = true;
			break;
		default:
			printHeaderMenu(MENU_INVENTORY);
			cout << "\n\t\t\t\t     ERROR: Choice must be a number 1 - 5.\n\n";
			pause();
			break;
		}
	} while (!exit);
	
}