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
#include "util.hpp"

using namespace std;

#define SALES_TAX 0.06;

void cashier (bookType books[]) {
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

    int index = 0;
    int toBuy, qty;
    char choice;
    bool final;
    bool escape;
    
    double subtotal, total, tax, tempTotal;

    string bookToBuy[20];
    string isbnToBuy[20];
    double retailToBuy[20];
    int qtyToBuy[20];

    if (books[0].getBookCount() != 0) {
        flag:
        system("clear"); 
        cout << "\t\t\t\t\t  Serendipity Book Sellers\n";
        cout << "\t\t\t\t\t       Cashier Module\n\n";
        cin.ignore();

        toBuy = lookUpBookLogic(books, escape);

        while (books[toBuy].getQtyAdded() <= 0) {
            system("clear");
            cout << "\t\t\t\t\t  Serendipity Book Sellers\n";
            cout << "\t\t\t\t\t       Cashier Module\n\n";
            cout << "\t\t\t Book is no longer in stock. Please search for a book in stock.\n";
            pause();

            system("clear");
            cout << "\t\t\t\t\t  Serendipity Book Sellers\n";
            cout << "\t\t\t\t\t       Cashier Module\n\n";
            toBuy = lookUpBookLogic(books, escape);
        }
        
        while (toBuy == -1 && escape) {
            system("clear");
            cout << "\t\t\t\t\t  Serendipity Book Sellers\n";
            cout << "\t\t\t\t\t       Cashier Module\n\n";
            cout << "\t\t\t Book not found. Please search for a book within the inventory.\n";
            pause();

            system("clear");
            cout << "\t\t\t\t\t  Serendipity Book Sellers\n";
            cout << "\t\t\t\t\t         Book Search\n\n";
            toBuy = lookUpBookLogic(books, escape);
        }

        while (!escape) {
            cout << "\t\t\t\t    How Many Copies? (Current Qty: "
                    << books[toBuy].getQtyAdded() << " ): ";
            cin >> qty;
            if (qty > books[toBuy].getQtyAdded() || qty <= 0) {
                system("clear");
                cout << "\t\t\t\t\t  Serendipity Book Sellers\n";
                cout << "\t\t\t\t\t       Cashier Module\n\n";
                cout << "\t\t\t\t       ERROR: Quantity Not Valid\n\n";
                pause();
                continue;
            } else {
                    cout << "\n\t\t\t\t     Added to cart. Buy another? (Y/N) ";
                    cin >> choice;

                    if (choice == 'y' || choice == 'Y') {
                        books[toBuy].setQty(books[toBuy].getQtyAdded() - qty);
                        subtotal += qty * books[toBuy].getRetail();

                        bookToBuy[index] = books[toBuy].getBookTitle();
                        isbnToBuy[index] = books[toBuy].getISBN();
                        retailToBuy[index] = books[toBuy].getRetail();
                        qtyToBuy[index] = qty;

                        index++;
                        goto flag;
                    } else if (choice == 'n' || choice == 'N') {
                        books[toBuy].setQty(books[toBuy].getQtyAdded() - qty);
                        subtotal += qty * books[toBuy].getRetail();

                        bookToBuy[index] = books[toBuy].getBookTitle();
                        isbnToBuy[index] = books[toBuy].getISBN();
                        retailToBuy[index] = books[toBuy].getRetail();
                        qtyToBuy[index] = qty;

                        index++;
                        final = true;
                    }
                    
                    if (final) {
                        tax = subtotal * SALES_TAX;
                        total = subtotal + tax;

                        //PRINT RECIEPT START
                        time_t now = time(0);
                        char *dt = ctime(&now);

                        system("clear");
                        cout << "Date: " << dt << " \n\n";

                        cout << "Qty\tISBN\t\tTitle\t\t\t\tPrice\t\tTotal\n";
                        cout << "_______________________________________________________________________________";
                        cout << "\n\n\n";

                        //doesn't work?
                        for (int j = 0; j < index; j++) {
                            //inline information
                            cout << qtyToBuy[index] << "\t";						       //display quantity
                            cout << left << setw(14) << isbnToBuy[index] << "\t";		  //display ISBN
                            cout << left << setw(26) << bookToBuy[index] << "\t$ ";       //displays title
                            cout << fixed << showpoint << right << setprecision(2);		  //set up number formatting
                            cout << setw(6) << retailToBuy[index] << "\t\n\n";			  //display price
                        }

                        cout << "\t\tSubtotal\t\t\t\t\t\t$ ";
                        cout << setw(6) << subtotal << "\n";
                        cout << "\t\tTax\t\t\t\t\t\t\t$ ";
                        cout << setw(6) << tax << "\n";
                        cout << "\t\tTotal\t\t\t\t\t\t\t$ ";
                        cout << setw(6) << total << "\n\n";
                        cout << "_______________________________________________________________________________";
                        cout << "\n\nThank you for shopping at Serendipity!\n\n";
                        pause();
                        break;
                        //PRINT RECIEPT END
                    }
            }
        }
    } else {
        system("clear");
        cout << "\t\t\t\t\t  Serendipity Book Sellers\n";
        cout << "\t\t\t\t\t       Cashier Module\n\n";
        cout << "\t\t\t\t    No books currently in the database!\n\n";
	    pause();
    } 
}