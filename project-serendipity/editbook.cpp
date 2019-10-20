#include <iostream>
#include <string>
#include <iomanip>
#include "addbook.hpp"
#include "bookdata.hpp"
#include "searchbook.hpp"
#include "util.hpp"
#include <limits>
#include <ctime>

using namespace std;

 time_t now = time(0);
char *dt = ctime(&now);

void resetTemps(bookType &tBook) {
	tBook.setTitle("EMPTY");
	tBook.setISBN("EMPTY");
	tBook.setAuthor("EMPTY"); 
	tBook.setPublisher("EMPTY"); 
	tBook.setDateAdded(dt);
	tBook.setQty(0);
	tBook.setWholesale(0.0);
	tBook.setRetail(0.0);
}
void editor(bookType *[], int x);

/*
void editBook(bookType *books_[]) {  
	 //bookType** books = bookValueToPointer(books_);

    resultsType results[20]; // new kevin code


     int toEdit;
     bool escape;
     char choice;

     if (books_[0] -> getBookCount() != 0) {
        system("clear"); 
        cout << "\t\t\t\t\t  Serendipity Book Sellers\n";
        cout << "\t\t\t\t\t         Book Edit\n\n";
        cin.ignore();

        toEdit = lookUpBook(books_, results);

        string tempBookTitle = books_[toEdit] -> getBookTitle();
        string tempISBN = books_[toEdit] -> getISBN();
	    string tempAuthor = books_[toEdit] -> getAuthor();
	    string tempPublisher = books_[toEdit] -> getPublisher();
	    string tempDateAdded = books_[toEdit] -> getDateAdded();
	    int tempQtyOnHand = books_[toEdit] -> getQtyAdded();
	    double tempWholeSale = books_[toEdit] -> getWholesale();
	    double tempRetail = books_[toEdit] -> getRetail();
        
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
			     << "\t\t\t\t       Current Database Size: " << books_[0] -> getBookCount()
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
                    
                    books_[toEdit] -> setAll(tempBookTitle,
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
*/


void editBook(bookType *book[]) {
	bool exitEditBook = false;
	bool validInput;
	char selection;
	
	
	
	resultsType results[20]; //create table of results possible of 20 searches
	int amtResults = 0;
	
	
	
	while (exitEditBook != true) {
		system("clear");
		validInput = false;
		cout << "\t\tSerendipity Booksellers\n\t\tInventory Database\n\n\t\t1. Look up a Book\n\t\t2. Add a Book\n\t\t3. Edit a Book's Record\n\t\t4. Delete a Book\n\t\t5. Return to Main Menu\n\n\t\tPlease type in your input: 3\n"; 
		int index = lookUpBook(book, results, amtResults);
		
		if (index >= 0) {
			for (int x = 0; x < amtResults; x++) {
				if (exitEditBook != true) {
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
							
							
							cout << "\n\nWould you like to edit the selected book? \nN = Next Selection\n\n\t(Y/N): ";
							
							
							
							cin >> selection;
							switch (selection) {
								case 'Y':
								case 'y':
									validInput = true;
									editor(book, results[x].index);
									exitEditBook = true;
									break;
								case 'N':
								case 'n':
									validInput = true;
									if (x == amtResults - 1)
										exitEditBook = true;
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
							exitEditBook = true;
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
}

void editor(bookType *book[], int x) {
	bool exitEditor = false;
	bookType tBook;
	tBook.setTitle(book[x]->getBookTitle());
	tBook.setISBN(book[x]->getISBN());
	tBook.setAuthor(book[x]->getAuthor());
	tBook.setPublisher(book[x]->getPublisher());
	tBook.setDateAdded(book[x]->getDateAdded());
	tBook.setQty(book[x]->getQtyAdded());
	tBook.setWholesale(book[x]->getWholesale());
	tBook.setRetail(book[x]->getRetail());
	while (exitEditor != true) {
		system("clea");
		bool validInput;
		char selection;
		string temp;
		int tempInt;
		double tempDouble;
		do {
			cout << fixed;
			cout.precision(2);
			cout << "*************************************************************\n\t\tSerendipity Booksellers\n\t\t\tBook Editor Menu\n\n\tCurrent Database Size: " << book[0]->getBookCount() << "/" << 20 << "\n" << endl;
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

					
					/*
					book[x]->setTitle(tBook.getTitle());
					book[x]->setIsbn(tBook.getIsbn());
					book[x]->setAuthor(tBook.getAuthor());
					book[x]->setPublisher(tBook.getPublisher());
					book[x]->setDateAdded(tBook.getDateAdded());
					book[x]->setQtyOnHand(tBook.getQtyOnHand());
					book[x]->setWholesale(tBook.getWholesale());
					book[x]->setRetail(tBook.getRetail());
					*/
					
					cout << "Edit was successful. Database: (" << book[0]->getBookCount() << "/" << 20 << ")";
					cout << endl;
					resetTemps(tBook);
					system("pause");
					system("clear");
					break;
				case '0':
					validInput = true;
					system("clear");
					resetTemps(tBook);
					exitEditor = true;
					break;
				default:
					validInput = false;
					system("clear");
					cout << "\nPlease enter a valid selection!\n";
					break;
			}	
		} while (validInput == false);
	}
}