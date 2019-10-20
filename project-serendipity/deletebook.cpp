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

void deleteBook(bookType books[])
{
	system("clear");
	//Checks to see if there are any books in database
	if (books[0].getBookCount() == 0)
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
			index = lookUpBookLogic(books, exit);

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
				//Quick error checking
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
					//use the uber setter
					books[index] = books[books[index].getBookCount() - 1];
					books[books[index].getBookCount() - 1].setTitle("EMPTY");
					books[books[index].getBookCount() - 1].setISBN("EMPTY");
					books[books[index].getBookCount() - 1].setAuthor("EMPTY");
					books[books[index].getBookCount() - 1].setPublisher("EMPTY");
					books[books[index].getBookCount() - 1].setDateAdded("EMPTY");
					books[books[index].getBookCount() - 1].setQty(0);
					books[books[index].getBookCount() - 1].setWholesale(0);
					books[books[index].getBookCount() - 1].setRetail(0);
					books[index].decBookCount();
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
					if (selection == 'N' || selection == 'n')
					{
						exit = true;
					}
				}
			}
		} while (exit == false);
	}
	return;
}
