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
#include "limits"


void removeBook(bookType books_[], int index) {
    bookType** books = bookValueToPointer(books_);

	system("clear");
    int finalBook = index;

    for (int i = index; i < 20 - 1; i++){
      	books[i] -> setTitle(books[i + 1] -> getBookTitle());
		books[i] -> setISBN(books[i +1 ] -> getISBN());
		books[i] -> setAuthor(books[i + 1] -> getAuthor());
		books[i] -> setPublisher(books[i + 1] -> getPublisher());
		books[i] -> setDateAdded(books[i + 1] -> getDateAdded());
		books[i] -> setQty(books[i + 1] -> getQtyAdded());
		books[i] -> setWholesale(books[i + 1] -> getWholesale());
		books[i] -> setRetail(books[i + 1] -> getRetail());
        finalBook++;
    }
    delete books[finalBook];
    books[0] -> decBookCount();
}

void deleteBook(bookType books_[])
{
	bookType** books = bookValueToPointer(books_);
	system("clear");
	//Checks to see if there are any books in database
	if (books[0] -> getBookCount() == 0)
	{
		system("clear");
        cout << "\t\t\t\t\t  Serendipity Book Sellers\n";
        cout << "\t\t\t\t\t       Delete Book\n\n";
        cout << "\t\t\t\t    No books currently in the database!\n\n";
		pause();
	}
	//Goes into this loop if there are books in database.
	else
	{
		bool exit = false;
		char selection;
		int index;
		
		do
		{
			system("clear");
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			index = lookUpBookLogic(books_, exit);

			//Checks to see if the book is in the database.
			if (index == -1)
			{
				system("clear");
				cout << "\t\t\t\t\t  Serendipity Book Sellers\n";
            	cout << "\t\t\t\t\t         Delete Book\n\n";
            	cout << "\t\t\t Book not found. Please search for a book within the inventory.\n";
				pause();
			}

			//If book was found goes in here
			else
			{
				cout << "\t\t\t        Are you sure you want to delete this book? (Y/N): ";
				cin >> selection;
				
				while (selection != 'Y' && selection != 'y' &&
					   selection != 'N' && selection != 'n')
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "\nERROR: Enter a valid option of (Y/N): ";
					cin >> selection;
				}

				if (selection == 'Y' || selection == 'y')
				{
					removeBook(books_, index);

					cout << "\t\t\t Book Deleted. Would you like to delete another book? (Y/N): ";
					cin >> selection;
					while (selection != 'Y' && selection != 'y' &&
						   selection != 'N' && selection != 'n')
					{
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "\nERROR: Enter a valid option of (Y/N): ";
						cin >> selection;
					}
					if (selection == 'Y' || selection == 'y') 
					{
						//something
					}
					if (selection == 'N' || selection == 'n')
					{
						exit = true;
					}
				}
				else
				{
					cout << "\t\t\t      Would you like to delete another book? (Y/N): ";
					cin >> selection;
					while (selection != 'Y' && selection != 'y' &&
						   selection != 'N' && selection != 'n')
					{
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "\nEnter a valid option of (Y/N): ";
						cin >> selection;
					}
					if (selection == 'Y' || selection == 'y') 
					{ 
						//something!
					} else if (selection == 'N' || selection == 'n')
					{
						exit = true;
					}
				}
			}
		} while (exit == false);
	}
	return;
}
