//--------------------------------------------------------------------------
//  File name: searchbook.cpp
//  Project name: Serendipity
//--------------------------------------------------------------------------
//  Creator's name and email: Felix Murray felix.murray@gmail.com
//  Course Selection: CS1B
//  Creation Date: 8/24/19
//  Date of Last Modification: 9/2/19
//--------------------------------------------------------------------------
//  Purpose: This program allows the user to search the database for a
//           certain book title and view the book information for it (latter
// 			 occurs when bookinfo function is called).
//
//--------------------------------------------------------------------------
//  Algorithm:
//      Step 1: Display Menu Options to the console and prompt user to make
//              a selection.
// 		Step 2: Take in search title
//      Step 3: Either retun titles that were found and allow the user to
//              view desired book info or prompt that no books were found.
//--------------------------------------------------------------------------
#include <iostream>
#include <string>
#include <limits>
#include "bookinfo.hpp"
#include "searchbook.hpp"
#include "bookdata.hpp"
#include "util.hpp"
#include "menuformatting.hpp"
#include "resultstype.hpp"

using namespace std;

extern const int DBSIZE = 20;

void executeFind(bookType *books_[]) {
	bool exitExecuteFind = false;
	bool validInput;
	char selection;

	int amtResults = 0;
	
	resultsType results[DBSIZE];//create table of results possible of 20 searches
	
	while (exitExecuteFind != true) {
		system("clear");
		validInput = false;
		cout << "\t\tSerendipity Booksellers\n\t\tInventory Database\n\n\t\t1. Look up a Book\n\t\t2. Add a Book\n\t\t3. Edit a Book's Record\n\t\t4. Delete a Book\n\t\t5. Return to Main Menu\n\n\t\tPlease type in your input: 1\n";
		int index = lookUpBook(books_, results, amtResults);

		system("clear");
		pause();
		cout << "INDEX = " << index << "\n";
		cout << "exitExecuteFind = " << exitExecuteFind;

		if (index >= 0) {
			for (int x = 0; x < amtResults; x++) {
				if (exitExecuteFind != true) {
					validInput = false;
					do {
						if (validInput != true) {
							pause();
							system("clear");
							cout << endl;
							for (int y = 0; y < amtResults; y++) {
								string selected = "   ";
								if (x == y) {
									selected = " > ";
								}
								cout << selected << "\"" << results[y].bookTitle << "\"" << endl;
							}
							
							cout << "\n\nWould you like to view the selected book? \nN = Next Selection\n\n\t(Y/N): ";
							
							cin >> selection;
							switch (selection) {
								case 'Y':
								case 'y':
									validInput = true;
									system("clear");
									bookInfo(results[x].index, books_);
									exitExecuteFind = true;
									break;
								case 'N':
								case 'n':
									validInput = true;
									if (x == amtResults - 1)
										exitExecuteFind = true;
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
							system("clear");
							break;
						case 'N':
						case 'n':
							validInput = true;
							exitExecuteFind = true;
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

int lookUpBook(bookType *book[], resultsType results[], int amtResults) { 
	amtResults = 0;
	string search;
	cout << "\nSearch: ";
	cin.ignore(numeric_limits<streamsize>::max(),'\n'); //Clear input buffer from previous text.
	getline(cin, search);
	
	for (int x = 0; x < book[0] -> getBookCount(); x++) {
		size_t found = findCaseInsensitive(book[x] -> getBookTitle(), search);
		if (found != string::npos) {
			string title = book[x] -> getBookTitle();
			results[amtResults].bookTitle = title; // CRASH
			results[amtResults].index = x;
			amtResults += 1;
			cout << "FOUND " << title << endl;
		} else { 
			for (int x = 0; x < book[0] -> getBookCount(); x++) {
				found = book[x] -> getISBN().find(search);
				if (found != string::npos) {
					results[amtResults].bookTitle = book[x] -> getBookTitle();
					results[amtResults].index = x;
					amtResults += 1;
				}
			}
		}
	}
	if (amtResults == 0) {
		return (-1);
	} else {
		return 0;
	}
}
	