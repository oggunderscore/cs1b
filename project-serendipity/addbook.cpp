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

using namespace std; 

void addBook(string title[], string isbn[], string author[], string publisher[],
	string date[], int qty[], double wholesale[], double retail[], const int SIZE, int &bookNums) {
	bool empty = false;
	bool exit = false;
	int index = 0;
	char reply;
	char choice;
	string tempBookTitle = "EMPTY";
	string tempISBN = "EMPTY";
	string tempAuthor = "EMPTY";
	string tempPublisher = "EMPTY";
	string tempDateAdded = "EMPTY";
	int tempQtyOnHand = 0;
	double tempWholeSale;
	double tempRetail;

	if (bookNums < SIZE - 1) {
		while (!exit) {
			system("clear");
			cout << fixed;
			cout.precision(2);
			cout << "\t\t\t\t\t  Serendipity Book Sellers\n"
				 << "\t\t\t\t\t           Add Book\n"
			     << "\t\t\t\t       Current Database Size: " << bookNums
				 << " (Max " << SIZE << ")\n" << endl;
			cout << "\t\t\t\t\t\t\t\t     + Pending Values +" << endl;
			cout << "\t\t\t\t(1) Enter Book Title\t\t\t >   --" << tempBookTitle << endl;
			cout << "\t\t\t\t(2) Enter ISBN\t\t\t\t >   --" << tempISBN << endl;
			cout << "\t\t\t\t(3) Enter Author\t\t\t >   --" << tempAuthor << endl;
			cout << "\t\t\t\t(4) Enter Publisher\t\t\t >   --" << tempPublisher << endl;
			cout << "\t\t\t\t(5) Enter Date Added\t\t\t >   --" << tempDateAdded << endl;
			cout << "\t\t\t\t(6) Enter Quantity on Hand\t\t >   --" << tempQtyOnHand << endl;
			cout << "\t\t\t\t(7) Enter Wholesale Cost\t\t >   --$" << tempWholeSale << endl;
			cout << "\t\t\t\t(8) Enter Retail Price\t\t\t >   --$" << tempRetail << endl;
			cout << "\t\t\t\t(9) Save Book to Database\t" << endl;
			cout << "\t\t\t\t(0) Return to Inventory Menu" << endl;
			cout << "\t\t\t\t\t\tChoice (0-9): ";
			cin >> choice;

			switch(choice) {
				case '1':
					system("clear");
					cout << "\n\tInput Book Title: ";
					cin.ignore(numeric_limits<streamsize>::max(),'\n'); //Clear input buffer from previous text.
					getline(cin, tempBookTitle);
					break;
				case '2':
					system("clear");
					cout << "\n\tInput ISBN: ";
					cin.ignore(numeric_limits<streamsize>::max(),'\n'); //Clear input buffer from previous text.
					getline(cin, tempISBN);
					break;
				case '3':
					system("clear");
					cout << "\n\tInput Author: ";
					cin.ignore(numeric_limits<streamsize>::max(),'\n'); //Clear input buffer from previous text.
					getline(cin, tempAuthor);
					break;
				case '4':
					system("clear");
					cout << "\n\tInput Publisher: ";
					cin.ignore(numeric_limits<streamsize>::max(),'\n'); //Clear input buffer from previous text.
					getline(cin, tempPublisher);
					break;
				case '5':
					system("clear");
					cout << "\n\tInput Date: ";
					cin.ignore(numeric_limits<streamsize>::max(),'\n'); //Clear input buffer from previous text.
					getline(cin, tempDateAdded);
					break;
				case '6':
					system("clear");
					cout << "\n\tInput Quantity on Hand: ";
					cin.ignore(numeric_limits<streamsize>::max(),'\n'); //Clear input buffer from previous text.
					cin >> tempQtyOnHand;
					break;
				case '7':
					system("clear");
					cout << "\n\tInput Wholesale Cost: ";
					cin.ignore(numeric_limits<streamsize>::max(),'\n'); //Clear input buffer from previous text.
					cin >> tempWholeSale;
					break;
				case '8':
					system("clear");
					cout << "\n\tInput Retail Price: ";
					cin.ignore(numeric_limits<streamsize>::max(),'\n'); //Clear input buffer from previous text.
					cin >> tempRetail;
					break;
				case '9':
					if (bookNums == SIZE) {
						system("clear");
						cout << "\t\t\t\t\t  Serendipity Book Sellers\n"
				             << "\t\t\t\t\t           Add Book\n\n";
						cout << "\t\t\t\t\t    ERROR: Database Full.\n\n";
						cout << "\t\t\t\t        Press any key to continue...";
						cin >> reply; 
						break;
					}
					system("clear");
					title[bookNums] = tempBookTitle;
					isbn[bookNums] = tempISBN;
					author[bookNums] = tempAuthor;
					publisher[bookNums] = tempPublisher;
					date[bookNums] = tempDateAdded;
					qty[bookNums] = tempQtyOnHand;
					wholesale[bookNums] = tempWholeSale;
					retail[bookNums] = tempRetail;
					bookNums++;

					tempBookTitle = "EMPTY";
					tempISBN = "EMPTY";
					tempAuthor = "EMPTY";
					tempPublisher = "EMPTY";
					tempDateAdded = "EMPTY";
					tempQtyOnHand = 0;
					tempWholeSale = 0;
					tempRetail = 0;
					
					cout << "\t\t\t\t\t  Serendipity Book Sellers\n"
				         << "\t\t\t\t\t           Add Book\n\n";
					cout << "\t\t\t\t             Save was successful.\n\n";
					cout << "\t\t\t\t        Press any key to continue...";
					cin >> reply; 
					cin.ignore(numeric_limits<streamsize>::max(),'\n'); //Clear input buffer from previous text.
					break;
				case '0':
					exit = true;
					break;
				default:
					system("clear");
					cout << "\t\t\t\t\t  Serendipity Book Sellers\n"
				         << "\t\t\t\t\t           Add Book\n";
					cout << "\n\t\t\t\t     ERROR: Choice must be a number 0 - 9.\n\n";
					cout << "\t\t\t\t        Press any key to continue...";
					cin >> reply; 
			}
		}
	} else {
		system("clear");
		cout << "\t\t\t\t\t  Serendipity Book Sellers\n"
			 << "\t\t\t\t\t           Add Book\n\n";
		cout << "\t\t\t\t\t     ERROR: Database Full.\n\n";
		cout << "\t\t\t\t        Press any key to continue...";
		cin >> reply; 
	}		
}
