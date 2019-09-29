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
#include "bookinfo.hpp"
#include "searchbook.hpp"
#include "bookdata.hpp"

using namespace std; 


// int lookUpLogic() {

// }

void lookUpBook(int &bookNums, bookType books[]) {
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

	char reply;
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

	if (bookNums > 0) {
		cout << "\t\t\t   Enter the title or ISBN of the book to search for:\n";
		cout << "\t\t\t\t\t\t      ";

		getline(cin, searchTitle);

		for (int i = 0; i < searchTitle.length(); i++) {
			searchTitle[i] = tolower(searchTitle[i]);
		}

		for (int index = 0; index < bookNums; index++) {
			temp = "";
			for (int indexInner = 0; indexInner < books[index].bookTitle.length(); indexInner++) {
				temp.append(1, tolower(books[index].bookTitle.at(indexInner)));
			}
			 //uncomment below if temp value seems to be causing issues
			 //cout << temp << " " << "\n" << index << " ";
			if (temp.find(searchTitle) != string::npos){
				found = true;

				while (true) {			
					system("clear"); 
					cout << "\t\t\t\t\t  Serendipity Book Sellers\n";
					cout << "\t\t\t\t\t         Book Search\n\n";
					cout << "\t\t\t\t\t      RESULT>: " << books[index].bookTitle <<  "\n\n";
					cout << "\t\t\t\t\tView this book record? (Y/N): ";
					cin >> selectRecord;
					cin.ignore(600, '\n');
		
					if (selectRecord == 'Y' || selectRecord == 'y') {
						bookInfo(index, books);
						recordViewed = true; 
						break;
					} else if (selectRecord == 'N' || selectRecord == 'n') {
						break;	
					} else {
						system("clear");
						cout << "\t\t\t\t\t  Serendipity Book Sellers\n";
						cout << "\t\t\t\t\t         Book Search\n\n";
						cout << "\t\t\t\t       ERROR: Input must be 'Y' or 'N'\n\n";
						cout << "\t\t\t\t        Press any key to continue...";
						cin >> reply;		
						if (reply != '\0'){ 
							continue;
						}
					}
				}
				if (recordViewed) {
					break;
				}	
			}
			if (index > bookNums - 1) {
				found = false;
			}
		}

		if (!found) {
			system("clear");
			cout << "\t\t\t\t\t  Serendipity Book Sellers\n";
			cout << "\t\t\t\t\t         Book Search\n\n";
			cout << "\t\t\t Book not found. Please search for a book within the inventory.\n";
			cout << "\t\t\t\t        Press any key to continue...";
			cin >> reply;
		}
		//temp = "";
	} else {
		cout << "\t\t\t\t    No books currently in the database!\n\n";
		cout << "\t\t\t\t        Press any key to continue...";
		cin >> reply;
	}
	
}