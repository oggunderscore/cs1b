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

using namespace std;

int lookUpBookLogic(bookType books[], bool &wantExit)
{
   	string search;
	string temp;
	char selection;
    cout << "\nSearch: ";
    //cin.ignore(numeric_limits<streamsize>::max(),'\n'); //Clear input buffer from previous text.
    getline(cin, search);
	
    for (int index = 0; index < books[0].getBookCount(); index++) {
        size_t found = findCaseInsensitive(books[index].getBookTitle(), search);

        if (found != string::npos) {
            while (true) 
			{
				system("clear");
				cout << "\t\t\t\t\t  Serendipity Book Sellers\n";
        		cout << "\t\t\t\t\t       Cashier Module\n\n";
				cout << "\t\t\t\t\t      RESULT>: " << books[index].getBookTitle() << "\n\n";
				cout << "\t\t\t\t    Is this the book you wanted? (Y/N): ";
				cin >> selection;

				if (selection == 'Y' || selection == 'y')
				{
					wantExit = false;
					return index;
				}
				else if (selection == 'N' || selection == 'n')
				{
					wantExit = true;
					break;
					
				}
				else
				{
					system("clear");
					cout << "\t\t\t\t\t  Serendipity Book Sellers\n";
					cout << "\t\t\t\t\t         Book Search\n\n";
					cout << "\t\t\t\t       ERROR: Input must be 'Y' or 'N'\n\n";
					pause();
					continue;
				}
			}	
        } 
    }
    return -1; 
}

void lookUpBook(bookType books[]) {
	//--------------------------------------------------------------------------
	// DATA DICTIONARY
	//--------------------------------------------------------------------------
	// VARIABLES
	//
	//   NAME              DATA TYPE         VALUE
	//--------------------------------------------------------------------------
	//  selectRecord	    char				null
	//  exit                bool               false
	//  found               bool               false
	//  loopEnd             bool               false
	//  recoredViewed       bool               false
	//  reply               char   			    null
	//  temp               string               null
	//  searchTitle        string               null
	//--------------------------------------------------------------------------

	char selectRecord;
	bool recordViewed = false;
	bool found = false;
	int index = 0;
	string temp;
	string searchTitle;

	system("clear");

	cout << "\t\t\t\t\t  Serendipity Book Sellers\n";
	cout << "\t\t\t\t\t         Book Search\n\n";

	cin.ignore();

	if (books[0].getBookCount() > 0)
	{
		cout << "\t\t\t   Enter the title or ISBN of the book to search for:\n";
		cout << "\t\t\t\t\t\t      ";

		getline(cin, searchTitle);

		for (int i = 0; i < searchTitle.length(); i++)
		{
			searchTitle[i] = tolower(searchTitle[i]);
		}

		for (int index = 0; index < books[0].getBookCount(); index++)
		{
			temp = "";
			for (int indexInner = 0; indexInner < books[index].getBookTitle().length(); indexInner++)
			{
				temp.append(1, tolower(books[index].getBookTitle().at(indexInner)));
			}
			//uncomment below if temp value seems to be causing issues
			//cout << temp << " " << "\n" << index << " ";
			if (temp.find(searchTitle) != string::npos)
			{
				found = true;

				while (true)
				{
					system("clear");
					cout << "\t\t\t\t\t  Serendipity Book Sellers\n";
					cout << "\t\t\t\t\t         Book Search\n\n";
					cout << "\t\t\t\t\t      RESULT>: " << books[index].getBookTitle() << "\n\n";
					cout << "\t\t\t\t\tView this book record? (Y/N): ";
					cin >> selectRecord;
					cin.ignore(600, '\n');

					if (selectRecord == 'Y' || selectRecord == 'y')
					{
						bookInfo(index, books);
						recordViewed = true;
						break;
					}
					else if (selectRecord == 'N' || selectRecord == 'n')
					{
						break;
					}
					else
					{
						system("clear");
						cout << "\t\t\t\t\t  Serendipity Book Sellers\n";
						cout << "\t\t\t\t\t         Book Search\n\n";
						cout << "\t\t\t\t       ERROR: Input must be 'Y' or 'N'\n\n";
						pause();
						continue;
					}
				}
				if (recordViewed)
				{
					break;
				}
			}
			if (index > books[0].getBookCount() - 1)
			{
				found = false;
			}
		}

		if (!found)
		{
			system("clear");
			cout << "\t\t\t\t\t  Serendipity Book Sellers\n";
			cout << "\t\t\t\t\t         Book Search\n\n";
			cout << "\t\t\t Book not found. Please search for a book within the inventory.\n";
			pause();
		}
		//temp = "";
	}
	else
	{
		cout << "\t\t\t\t    No books currently in the database!\n\n";
		pause();
	}
}