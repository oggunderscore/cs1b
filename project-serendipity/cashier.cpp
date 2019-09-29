//--------------------------------------------------------------------------
//  File name: cashier.cpp 
//  Project name: Serendipity
//--------------------------------------------------------------------------
//  Creator's name and email: Felix Murray felix.murray@gmail.com
//  Course Selection: CS1B
//  Creation Date: 8/24/19
//  Date of Last Modification: 8/28/19
//--------------------------------------------------------------------------
//  Purpose: This program will take in user input to enter a book and 
//  		 its information and calculate its cost.
//--------------------------------------------------------------------------
//  Algorithm: 
//      Step 1: Recieve user input for date.
//      Step 2: Recieve user input for Quantity.
//      Step 3: Recieve user input for ISBN.
//      Step 4: Recieve user input for Title.
//      Step 5: Recieve user input for Price.
//      Step 6: Display Reciept based on calculations made using user 
//  		    inputed data.
//		Step 7: Prompt the user to start a new transaction or quit.
//      Step 2: Either return to previous menu or start new transaction
//      	    (repeats Steps 1 - 7)
//--------------------------------------------------------------------------
#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>

#include "cashier.hpp"
#include "searchbook.hpp"
#include "bookdata.hpp"

using namespace std;

#define SALES_TAX 0.06;

void cashier (int &bookNums, bookType books[]) {
	//--------------------------------------------------------------------------
	// DATA DICTIONARY
	//--------------------------------------------------------------------------
	// VARIABLES
	//
	//   NAME              DATA TYPE         VALUE
	//--------------------------------------------------------------------------
	//  repeat                 bool             true
	//  inputRecieved 		   bool             false        
	//  date                  string   			null 
	//  isbn                  string   			null 
	//  title                 string   			null
	//  continueTransaction    char 			null
	//  quantity			    int				null
	//  price 				   double           null
	//  subtotal			   double			null
	//  tax					   double			null
	//  total 			       double   		null
	//--------------------------------------------------------------------------
	bool repeat = true;
	bool buying = true;
		
	char continueTransaction;
	int quantity;
	double subtotal;
	double tax;
	double total;
	bool inputRecieved = false;

	char reply;
	char selectRecord;
	bool purchaseMade = false; 
	bool found = false;
	bool repeatTransaction = false;
	// int index = 0;
	string temp;
	string searchTitle; 

	newTransaction:
	system("clear");
	cout << "\t\t\t\t\t  Serendipity Book Sellers\n";
	cout << "\t\t\t\t\t       Cashier Module\n\n";

	cin.ignore();

	if (bookNums > 0) {
		cout << "\t\t\t   Enter the title or ISBN of the book to search for:\n";
		cout << "\t\t\t\t\t\t      ";

		getline(cin, searchTitle);

		for (int i = 0; i < searchTitle.length(); i++) {
			searchTitle[i] = tolower(searchTitle[i]);
		}

		for (int index = 0; index < bookNums; index++) {
			if (repeatTransaction) {
				index = 0;
				repeatTransaction = false;
				double subtotal = 0;
				double tax = 0;
				double total = 0;
				bool inputRecieved = false;
			}

			temp = "";
			for (int indexInner = 0; indexInner < books[index].bookTitle.length(); indexInner++) {
				temp.append(1, tolower(books[index].bookTitle.at(indexInner)));
			}
			//uncomment below if temp value seems to be causing issues
			//cout << temp << " " << "\n" << index << " ";
			if (temp.find(searchTitle) != string::npos){
				found = true;

				while (true) {			
					copyError:
					system("clear"); 
					cout << "\t\t\t\t\t  Serendipity Book Sellers\n";
					cout << "\t\t\t\t\t       Cashier Module\n\n";
					cout << "\t\t\t\t\t      RESULT>: " << books[index].bookTitle <<  "\n\n";
					cout << "\t\t\t\t\t    Buy this book? (Y/N): ";
					cin >> selectRecord;
					cin.ignore(600, '\n');
		
					if (selectRecord == 'Y' || selectRecord == 'y') {
						purchaseMade = true;
						cout << "\t\t\t\t\t    How Many Copies? (Current Qty: " 
								<< books[index].qtyOnHand << " ): ";
						cin >> quantity;
						if (quantity > books[index].qtyOnHand || quantity <= 0) {
							system("clear");
							cout << "\t\t\t\t\t  Serendipity Book Sellers\n";
							cout << "\t\t\t\t\t       Cashier Module\n\n";
							cout << "\t\t\t\t       ERROR: Quantity Not Valid\n\n";
							cout << "\t\t\t\t        Press any key to continue...";
							cin >> reply;		
							if (reply != '\0'){ 
								goto copyError;
							}
						}
						cin.ignore(600, '\n');

						subtotal = quantity * books[index].retail;
						tax = subtotal * SALES_TAX;
						total = subtotal + tax;
						books[index].qtyOnHand = books[index].qtyOnHand - quantity; 

						system("clear");
						
						//System Time for Current Date
						time_t now = time(0);
   						char* dt = ctime(&now);

						cout << "Date: " << dt << " \n\n";

						cout << "Qty\tISBN\t\tTitle\t\t\t\tPrice\t\tTotal\n";
						cout << "_______________________________________________________________________________";
						cout << "\n\n\n";

						//inline information
						cout << quantity << "\t"; //display quantity
						cout << left << setw(14) << books[index].isbn << "\t"; //display ISBN
						cout << left << setw(26) << books[index].bookTitle << "\t$ "; //displays title
						cout << fixed << showpoint << right << setprecision(2); //set up number formatting
						cout << setw(6) << books[index].retail << "\t$ "; //display price
						cout << setw(6) << subtotal << "\n\n\n"; //display subtotal in line

						//calculated totals
						cout << "\t\tSubtotal\t\t\t\t\t\t$ ";
						cout << setw(6) << subtotal << "\n";
						cout << "\t\tTax\t\t\t\t\t\t\t$ ";
						cout << setw(6) << tax << "\n";
						cout << "\t\tTotal\t\t\t\t\t\t\t$ ";
						cout << setw(6) << total << "\n\n";
						cout << "_______________________________________________________________________________";
						cout << "\n\nThank you for shopping at Serendipity!\n"; 
						break;
					} else if (selectRecord == 'N' || selectRecord == 'n') {
						break;	
					} else {
						system("clear");
						cout << "\t\t\t\t\t  Serendipity Book Sellers\n";
						cout << "\t\t\t\t\t       Cashier Module\n\n";
						cout << "\t\t\t\t       ERROR: Input must be 'Y' or 'N'\n\n";
						cout << "\t\t\t\t        Press any key to continue...";
						cin >> reply;		
						if (reply != '\0'){ 
							continue;
						}
					}
				}
				if (purchaseMade) {
					while (!inputRecieved) {
						cout << "\n\nWould you like to make another transaction? (Y/N): ";
						cin >> continueTransaction;
						if (continueTransaction == 'n' || continueTransaction == 'N'){
							inputRecieved = true;
							break;
						} else if (continueTransaction == 'y' || continueTransaction == 'Y') {
							inputRecieved = true;
							repeatTransaction = true;
							goto newTransaction;
						} else {
							system("clear");
							cout << "ERROR: Choice must be either y or n.";
							continue;
						} 
					}
				}
			}
			if (index > bookNums - 1) {
				found = false;
			}
		}

		if (!found) {
			system("clear");
			cout << "\t\t\t\t\t  Serendipity Book Sellers\n";
			cout << "\t\t\t\t\t       Cashier Module\n\n";
			cout << "\t\t\t Book not found. Please search for a book within the inventory.\n";
			cout << "\t\t\t\t        Press any key to continue...";
			cin >> reply;
		}
		//temp = "";
	} else {
		cout << "\t\t\t\t    No books currently in the database!\n\n";
		cout << "\t\t\t\t        Press any key to continue...";
		cin >> reply;
	}
		 
}