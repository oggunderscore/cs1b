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
#include "limits"

#include "resultstype.hpp"

using namespace std;

#define SALES_TAX 0.06;

int cashierSearch(bookType *book[]) {
    string search, temp, tempInt;    
    bool foundNeg = true;
    int amount;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    do {
        cout << "\nPurchase Request (exact title/isbn): ";
        //cin.ignore(numeric_limits<streamsize>::max(),'\n');
        getline(cin, temp);
        tempInt = temp.substr(0, 3);
        if (tempInt.find("-") != string::npos) {    
            cout << "ERROR: Cannot enter negative numbers!" << endl;
            foundNeg = true;
        } else {
            foundNeg = false;
            amount = stoi(tempInt);
            search = temp.substr(4, temp.length()); //50 x Title
        }
    } while (foundNeg == true);
    
    if (amount != 0) {
        for (int x = 0; x < 20; x++) {
            size_t found = findCaseInsensitive(book[x]->getBookTitle(), search);
            if (found != string::npos) {
                if (book[x]->getQtyAdded() < amount) {
                    return (-2);
                } else {
                    return x;
                }
            } else { 
                for (int x = 0; x < 20; x++) {
                    found = book[x]->getISBN().find(search);
                    if (found != string::npos) {
                        if (book[x]->getQtyAdded() < amount) {
                            return (-2);
                        } else {
                            return x;
                        }
                    }
                }
            }
        }
    } else {
        return (-3);
    }
    return (-1);
}

void cashier(bookType *books_[])
{
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
    bool final = false;
    bool escape = false;
    bool exit = false;

    double subtotal, total, tax, tempTotal;

    int tempBooks[20] = {0};

    resultsType results[20]; // kevins new code

    if (books_[0]->getBookCount() != 0)
    {
        while (!exit)
        {
            system("clear");
            cout << "\t\t\t\t\t  Serendipity Book Sellers\n";
            cout << "\t\t\t\t\t       Cashier Module\n\n";
            cin.ignore();

            toBuy = cashierSearch(books_);

            //supposed to check if the books is out of stocks
            while (books_[toBuy]->getQtyAdded() <= 0)
            {
                system("clear");
                cout << "\t\t\t\t\t  Serendipity Book Sellers\n";
                cout << "\t\t\t\t\t       Cashier Module\n\n";
                cout << "\t\t\t Book is no longer in stock. Please search for a book in stock.\n";
                pause();

                system("clear");
                cout << "\t\t\t\t\t  Serendipity Book Sellers\n";
                cout << "\t\t\t\t\t       Cashier Module\n\n";
                toBuy = cashierSearch(books_);
            }
            //supposed to be the check for if lookUp returns -1
            while (toBuy == -1)
            {
                system("clear");
                cout << "\t\t\t\t\t  Serendipity Book Sellers\n";
                cout << "\t\t\t\t\t       Cashier Module\n\n";
                cout << "\t\t\t Book not found. Please search for a book within the inventory.\n";
                pause();

                exit = true;
                break;
            }

            while (!escape)
            {
                cout << "\t\t\t\t\n    How Many Copies? (Current Qty: "
                     << books_[toBuy]->getQtyAdded() << " ): ";
                cin >> qty;
                if (qty > books_[toBuy]->getQtyAdded() || qty <= 0)
                {
                    system("clear");
                    cout << "\t\t\t\t\t  Serendipity Book Sellers\n";
                    cout << "\t\t\t\t\t       Cashier Module\n\n";
                    cout << "\t\t\t\t       ERROR: Quantity Not Valid\n\n";
                    pause();
                    continue;
                }
                else
                {
                    tempBooks[toBuy] = qty;
                    cout << "\n\t\t\t\t     Added to cart. Buy another? (Y/N) ";
                    cin >> choice;

                    if (choice == 'y' || choice == 'Y')
                    {
                        books_[toBuy]->setQty(books_[toBuy]->getQtyAdded() - qty);
                        subtotal += qty * books_[toBuy]->getRetail();
                        break;
                    }
                    else if (choice == 'n' || choice == 'N')
                    {
                        books_[toBuy]->setQty(books_[toBuy]->getQtyAdded() - qty);
                        subtotal += qty * books_[toBuy]->getRetail();

                        final = true;
                    }

                    if (final)
                    {
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

                  
                        for (int j = 0; j < books_[j]->getBookCount(); j++)
                        {
                            if (tempBooks[j] > 0)
                            {
                                cout << tempBooks[j] << "\t";                                                   //display quantity
                                cout << left << setw(14) << books_[j]->getISBN() << "\t";                         //display ISBN
                                cout << left << setw(26) << books_[j]->getBookTitle() << "\t$ ";                  //displays title
                                cout << fixed << showpoint << right << setprecision(2) << books_[j]->getRetail(); //set up number formatting
                                cout << setw(14) << books_[j]->getRetail() * tempBooks[j] << "\t\n\n";            //display price
                            }
                        }

                        cout << "\t\tSubtotal\t\t\t\t\t\t$ ";
                        cout << setw(6) << subtotal << "\n";
                        cout << "\t\tTax\t\t\t\t\t\t\t$ ";
                        cout << setw(6) << tax << "\n";
                        cout << "\t\tTotal\t\t\t\t\t\t\t$ ";
                        cout << setw(6) << total << "\n\n";
                        cout << "_______________________________________________________________________________";
                        cout << "\n\nThank you for shopping at Serendipity!\n\n";
                        //PRINT RECIEPT END
                        cout << "Would you like to make another transaction? (Y/N): ";
                        cin >> choice;
                        while (choice != 'Y' && choice != 'y' &&
                               choice != 'N' && choice != 'n')
                        {
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cout << "\nEnter a valid option of (Y/N): ";
                            cin >> choice;
                        }
                        if (choice == 'N' || choice == 'n')
                        {
                            exit = true;
                            break;
                        }
                        else if (choice == 'Y' || choice == 'y')
                        {
                            total = 0;
                            subtotal = 0;
                            tax = 0;
                            break;
                        }
                    }
                }
            } 
        }    
    }
    else
    {
        system("clear");
        cout << "\t\t\t\t\t  Serendipity Book Sellers\n";
        cout << "\t\t\t\t\t       Cashier Module\n\n";
        cout << "\t\t\t\t    No books currently in the database!\n\n";
        pause();
    }
}