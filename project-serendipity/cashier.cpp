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

#include "cashier.hpp"

using namespace std;

#define SALES_TAX 0.06;

void cashier () {
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
	
	do {
		system("clear");	
    	string date;
		string isbn;
		string title;
		char continueTransaction;
		int quantity;
		double price;
		double subtotal;
		double tax;
		double total;
		
		bool inputRecieved = false; 

		cout << "\t\t\t\t\t  Serendipity Booksellers\n";
		cout << "\t\t\t\t\t       Cashier Module\n\n";

		cin.ignore();

		cout << "Enter Date: ";
		getline(cin, date);

		cout << "Quantity of the Book: ";
		cin >> quantity;

		cin.ignore(); 

		cout << "ISBN: ";
		getline(cin, isbn);

		cout << "Title: ";
		getline(cin, title);

		cout << "Price: ";
		cin >> price;

		//calcualtions
		subtotal = quantity * price;
		tax = subtotal * SALES_TAX;
		total = subtotal + tax;

		system("clear");
		cout << "Date: " << date << " \n\n";

		cout << "Qty\tISBN\t\tTitle\t\t\t\tPrice\t\tTotal\n";
		cout << "_______________________________________________________________________________";
		cout << "\n\n\n";

		//inline information
		cout << quantity << "\t"; //display quantity
		cout << left << setw(14) << isbn << "\t"; //display ISBN
		cout << left << setw(26) << title << "\t$ "; //displays title
		cout << fixed << showpoint << right << setprecision(2); //set up number formatting
		cout << setw(6) << price << "\t$ "; //display price
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
	

		while (!inputRecieved){
			inputRecieved = false;
			cout << "\n\nWould you like to make another transaction? (Y/N): ";
			cin >> continueTransaction;

			if (continueTransaction == 'n' || continueTransaction == 'N'){
				repeat = false;
				inputRecieved = true; 
			} else if (continueTransaction == 'y' || continueTransaction == 'Y') {
				break;
			} else {
				system("clear");
				cout << "ERROR: Choice must be either y or n.";
			} 
		}

		if (continueTransaction == 'n' || continueTransaction == 'N'){
			repeat = false;
		} 
		

    } while (repeat); 
}