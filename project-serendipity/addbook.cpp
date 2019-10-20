//--------------------------------------------------------------------------
//  File name: addbook.cpp
//  Project name: Serendipity
//--------------------------------------------------------------------------
//  Creator's name and email: Felix Murray felix.murray@gmail.com
//  Course Selection: CS1B
//  Creation Date: 8/30/19
//  Date of Last Modification: 9/8/19
//--------------------------------------------------------------------------
//  Purpose: This program will allow the user to add books to the database.
//--------------------------------------------------------------------------
//  Algorithm:
//      Step 1: Display Menu Options to the console and prompt user to make
//              a selection.
//      Step 2: Recieve user input for option.
//      Step 3: Switch in user input and switchs to the relevent screen
//              to allow for user input for the selected data point.
//      Step 4: Repeat steps 1 - 3 until user enters '0' to return to the
//              main menu.
//--------------------------------------------------------------------------
#include <iostream>
#include <string>
#include <iomanip>
#include "addbook.hpp"
#include "bookdata.hpp"
#include "editbook.hpp"
#include "util.hpp"
#include "menuformatting.hpp"

using namespace std;

time_t now2 = time(0);
char *dt2 = ctime(&now2);

void addBook(bookType *book[]) {
	bookType tBook;
	resetTemps(tBook);
	bool exitAddBook = false;
	while (exitAddBook != true) {
		system("clear");
		
		if (book[0]->getBookCount() >= 20) {
			cout << "Database is full! Please delete some books to proceed! (" << book[0]->getBookCount() << "/" << 20 << ")\n";
			pause();
			system("clear");
			exitAddBook = true;
		} else {
			bool validInput;
			char selection;
			string temp;
			int tempInt;
			double tempDouble;
			do {
				cout << fixed;
				cout.precision(2);
				cout << "*************************************************************\n\t\tSerendipity Booksellers\n\t\t\tAdd Book Menu\n\n\tCurrent Database Size: " << book[0]->getBookCount() << "/" << 20 << "\n" << endl;
				cout << "\t\t\t\t\t+ Pending Values +" << endl;
				cout << "(1) Enter Book Title\t\t\t >   --" << tBook.getBookTitle() << endl;
				cout << "(2) Enter ISBN\t\t\t\t >   --" << tBook.getISBN() << endl;
				cout << "(3) Enter Author\t\t\t >   --" << tBook.getAuthor() << endl;
				cout << "(4) Enter Publisher\t\t\t >   --" << tBook.getPublisher() << endl;
				cout << "(5) Enter Date Added\t\t\t >   --" << tBook.getDateAdded() << endl;
				cout << "(6) Enter Quantity on Hand\t\t >   --" << tBook.getQtyAdded() << endl;
				cout << "(7) Enter Wholesale Cost\t\t >   --$" << tBook.getWholesale() << endl;
				cout << "(8) Enter Retail Price\t\t\t >   --$" << tBook.getRetail() << endl;
				cout << "(9) Save Book to Database\t" << endl;
				cout << "(0) Return to Inventory Menu" << endl;
				cout << "\n*************************************************************\n\tChoice (0-9): ";
				cin >> selection;
				validInput = true;
				switch(selection) {
					case '1':
						validInput = true;
						system("clear");
						cout << "*************************************************************\n\tInput Book Title: ";
						cin.ignore(numeric_limits<streamsize>::max(),'\n'); //Clear input buffer from previous text.
						getline(cin, temp);
						tBook.setTitle(temp);
						break;
					case '2':
						validInput = true;
						system("clear");
						cout << "*************************************************************\n\tInput ISBN: ";
						cin.ignore(numeric_limits<streamsize>::max(),'\n'); //Clear input buffer from previous text.
						getline(cin, temp);
						tBook.setISBN(temp);
						break;
					case '3':
						validInput = true;
						system("clear");
						cout << "*************************************************************\n\tInput Author: ";
						cin.ignore(numeric_limits<streamsize>::max(),'\n'); //Clear input buffer from previous text.
						getline(cin, temp);
						tBook.setAuthor(temp);
						break;
					case '4':
						validInput = true;
						system("clear");
						cout << "*************************************************************\n\tInput Publisher: ";
						cin.ignore(numeric_limits<streamsize>::max(),'\n'); //Clear input buffer from previous text.
						getline(cin, temp);
						tBook.setPublisher(temp);
						break;
					case '5':
						validInput = true;
						system("clear");
						cout << "*************************************************************\n\tInput Date: ";
						cin.ignore(numeric_limits<streamsize>::max(),'\n'); //Clear input buffer from previous text.
						getline(cin, temp);
						tBook.setDateAdded(temp);
						break;
					case '6':
						validInput = true;
						system("clear");
						cout << "*************************************************************\n\tInput Quantity on Hand: ";
						cin.ignore(numeric_limits<streamsize>::max(),'\n'); //Clear input buffer from previous text.
						cin >> tempInt;
						tBook.setQty(tempInt);
						break;
					case '7':
						validInput = true;
						system("clear");
						cout << "*************************************************************\n\tInput Wholesale Cost: ";
						cin.ignore(numeric_limits<streamsize>::max(),'\n'); //Clear input buffer from previous text.
						cin >> tempDouble;
						tBook.setWholesale(tempDouble);
						break;
					case '8':
						validInput = true;
						system("clear");
						cout << "*************************************************************\n\tInput Retail Price: ";
						cin.ignore(numeric_limits<streamsize>::max(),'\n'); //Clear input buffer from previous text.
						cin >> tempDouble;
						tBook.setRetail(tempDouble);
						break;
					case '9':
						validInput = true;
						system("clear");
						
						//SAVING CODE
						
						book[book[0]->getBookCount()] = new bookType();
						book[book[0]->getBookCount()]->setAll(tBook.getBookTitle(), tBook.getISBN(), tBook.getAuthor(), tBook.getPublisher(), tBook.getDateAdded(), tBook.getQtyAdded(), tBook.getWholesale(), tBook.getRetail());
						
						book[0]->incBookCount();
						cout << "Save was successful. Database: (" << book[0]->getBookCount() << "/" << 20 << ")";
						cout << endl;
						resetTemps(tBook);
						system("clear");
						cin.ignore(numeric_limits<streamsize>::max(),'\n'); //Clear input buffer from previous text.
						break;
					case '0':
						validInput = true;
						system("clear");
						resetTemps(tBook);
						exitAddBook = true;
						break;
					default:
						validInput = false;
						system("clear");
						cout << "\nPlease enter a valid selection!\n";
						break;
				}	
			} while (validInput == false);
		}
		system("clear");
	}
}