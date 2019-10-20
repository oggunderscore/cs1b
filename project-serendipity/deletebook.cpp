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

#include "resultstype.hpp"


void removeBook(bookType *books_[], int index) {
    //bookType** books = bookValueToPointer(books_);

	system("clear");
    int finalBook = index;

    for (int i = index; i < 20 - 1; i++){
      	books_[i] -> setTitle(books_[i + 1] -> getBookTitle());
		books_[i] -> setISBN(books_[i +1 ] -> getISBN());
		books_[i] -> setAuthor(books_[i + 1] -> getAuthor());
		books_[i] -> setPublisher(books_[i + 1] -> getPublisher());
		books_[i] -> setDateAdded(books_[i + 1] -> getDateAdded());
		books_[i] -> setQty(books_[i + 1] -> getQtyAdded());
		books_[i] -> setWholesale(books_[i + 1] -> getWholesale());
		books_[i] -> setRetail(books_[i + 1] -> getRetail());
        finalBook++;
    }
    delete books_[finalBook];
    books_[0] -> decBookCount();
}

void deleteBook(bookType *books_[])
{
	//bookType** books = bookValueToPointer(books_);
	system("clear");

	resultsType results[20]; // new kevin code
	int amtResults  = 0;




	bool exitDeleteBook = false;
	bool validInput = false;
	char selection;
	
	
	while (exitDeleteBook != true) {
		system("clear");
		validInput = false;
		cout << "\t\tSerendipity Booksellers\n\t\tInventory Database\n\n\t\t1. Look up a Book\n\t\t2. Add a Book\n\t\t3. Edit a Book's Record\n\t\t4. Delete a Book\n\t\t5. Return to Main Menu\n\n\t\tPlease type in your input: 4\n"; 
		int index = lookUpBook(books_, results, amtResults);
		
		if (index >= 0) {
			for (int x = 0; x < amtResults; x++) {
				if (exitDeleteBook != true) {
					validInput = false;
					do {
						if (validInput != true) {
							system("clear");
							cout << endl;
							for (int y = 0; y < amtResults; y++) {
								string selected = "   ";
								if (x == y) {
									selected = " > ";
								}
								cout << selected << "\"" << results[y].bookTitle << "\"" << endl;
							}
							cout << "\n\nWould you like to delete the selected book? \nN = Next Selection\n\n\t(Y/N): ";
							cin >> selection;
							switch (selection) {
								case 'Y':
								case 'y':
									validInput = true;
									removeBook(books_, results[x].index);
									cout << "Database: (" << books_[0]->getBookCount() << "/" << 20 << ")" << endl;
									cout << endl;
									pause();
									exitDeleteBook = true;
									break;
								case 'N':
								case 'n':
									validInput = true;
									if (x == amtResults - 1)
										exitDeleteBook = true;
									break;
								default:
									cout << "Please enter a valid response! ";
									validInput = false;
									break;
							}
						} else {
							break;
						}
					} while (validInput != true);
				}
			}
		} else {
			do {
				if (validInput != true) {
					cout << "Error: Could not find Book by Title / ISBN. Try again? (Y/N): ";
					cin >> selection;
					switch (selection) {
						case 'Y':
						case 'y':
							validInput = true;
							break;
						case 'N':
						case 'n':
							validInput = true;
							exitDeleteBook = true;
							break;
						default:
							cout << "Please enter a valid response! ";
							validInput = false;
							break;
					}
				} else {
					break;
				}
			} while (validInput != true);
		}
	}




	/*


	//Checks to see if there are any books in database
	if (books_[0] -> getBookCount() == 0)
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
			index = lookUpBook(books_, results, amtResults);

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
	*/
}
