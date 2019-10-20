#include <iostream>
#include <string>
#include <iomanip>
#include "addbook.hpp"
#include "bookdata.hpp"
#include "searchbook.hpp"
#include "util.hpp"
#include <limits>

using namespace std;

void editBook(bookType books[]) {  
	 int toEdit;
     bool escape;
     char choice;


     if (books[0].getBookCount() != 0) {
        system("clear"); 
        cout << "\t\t\t\t\t  Serendipity Book Sellers\n";
        cout << "\t\t\t\t\t         Book Edit\n\n";
        cin.ignore();

        toEdit = lookUpBookLogic(books, escape);

        string tempBookTitle = books[toEdit].getBookTitle();
        string tempISBN = books[toEdit].getISBN();
	    string tempAuthor = books[toEdit].getAuthor();
	    string tempPublisher = books[toEdit].getPublisher();
	    string tempDateAdded = books[toEdit].getDateAdded();
	    int tempQtyOnHand = books[toEdit].getQtyAdded();
	    double tempWholeSale = books[toEdit].getWholesale();
	    double tempRetail = books[toEdit].getRetail();
        
        while (toEdit == -1 && escape) {
            system("clear");
            cout << "\t\t\t\t\t  Serendipity Book Sellers\n";
            cout << "\t\t\t\t\t         Book Edit\n\n";
            cout << "\t\t\t Book not found. Please search for a book within the inventory.\n";
            pause();
            break;
        }

        while (!escape) {
            system("clear");
			cout << fixed;
			cout.precision(2);
			cout << "\t\t\t\t\t  Serendipity Book Sellers\n"
				 << "\t\t\t\t\t           Edit Book\n"
			     << "\t\t\t\t       Current Database Size: " << books[0].getBookCount()
				 << " (Max 20)\n" << endl;
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

			switch (choice)
			{
                case '1':
                    system("clear");
                    cout << "\n\tInput Book Title: ";
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Clear input buffer from previous text.
                    getline(cin, tempBookTitle);
                    break;
                case '2':
                    system("clear");
                    cout << "\n\tInput ISBN: ";
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Clear input buffer from previous text.
                    getline(cin, tempISBN);
                    break;
                case '3':
                    system("clear");
                    cout << "\n\tInput Author: ";
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Clear input buffer from previous text.
                    getline(cin, tempAuthor);
                    break;
                case '4':
                    system("clear");
                    cout << "\n\tInput Publisher: ";
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Clear input buffer from previous text.
                    getline(cin, tempPublisher);
                    break;
                case '5':
                    system("clear");
                    cout << "\n\tInput Date: ";
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Clear input buffer from previous text.
                    getline(cin, tempDateAdded);
                    break;
                case '6':
                    system("clear");
                    cout << "\n\tInput Quantity on Hand: ";
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Clear input buffer from previous text.
                    cin >> tempQtyOnHand;
                    break;
                case '7':
                    system("clear");
                    cout << "\n\tInput Wholesale Cost: ";
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Clear input buffer from previous text.
                    cin >> tempWholeSale;
                    break;
                case '8':
                    system("clear");
                    cout << "\n\tInput Retail Price: ";
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Clear input buffer from previous text.
                    cin >> tempRetail;
                    break;
                case '9':
                    system("clear");
                    
                    books[toEdit].setAll(tempBookTitle,
                                         tempISBN, 
                                         tempAuthor, 
                                         tempPublisher, 
                                         tempDateAdded,
                                         tempQtyOnHand,
                                         tempWholeSale, 
                                         tempRetail);

                    cout << "\t\t\t\t\t  Serendipity Book Sellers\n"
                        << "\t\t\t\t\t           Edit Book\n\n";
                    cout << "\t\t\t\t             Save was successful.\n\n";
                    pause();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Clear input buffer from previous text.
                    break;
                case '0':
                    escape = true;
                    break;
                default:
                    system("clear");
                    cout << "\t\t\t\t\t  Serendipity Book Sellers\n"
                        << "\t\t\t\t\t           Edit Book\n";
                    cout << "\n\t\t\t\t     ERROR: Choice must be a number 0 - 9.\n\n";
                    pause();
			}
        }
    } else {
        system("clear");
        cout << "\t\t\t\t\t  Serendipity Book Sellers\n";
        cout << "\t\t\t\t\t       Edit Book\n\n";
        cout << "\t\t\t\t    No books currently in the database!\n\n";
	    pause();
    }
}