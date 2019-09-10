#include <iostream> 
#include <string> 
#include "bookinfo.hpp"
#include "searchbook.hpp"


using namespace std; 

void lookUpBook(string title[], string isbn[], string author[], string publisher[],
	string date[], int qty[], double wholesale[], double retail[], const int SIZE, int &bookNums) {
	char reply;
	char selectRecord;
	bool found = false;
	bool inputSuccess = false;
	bool recordViewed = false; 
	int index = 0;
	string temp;
	string searchTitle;

	system("clear");

	cout << "\t\t\t\t\t  Serendipity Booksellers\n";
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
			for (int indexInner = 0; indexInner < title[index].length(); indexInner++) {
				temp.append(1, tolower(title[index].at(indexInner)));
			}
				if (temp.find(searchTitle) != string::npos || searchTitle == isbn[index] && !recordViewed){
					while (true) {
						system("clear"); 
						cout << "\t\t\t\t\t  Serendipity Booksellers\n";
						cout << "\t\t\t\t\t         Book Search\n\n";
						cout << "\t\t\t\t\t      RESULT>: " << title[index] <<  "\n\n";
						cout << "\t\t\t\t\tView this book record? (Y/N): ";
						cin >> selectRecord;
						cin.ignore(600, '\n');
			
						if (selectRecord == 'Y' || selectRecord == 'y') {
							bookInfo(title, isbn, author, publisher, date,
								 	 qty, wholesale, retail, SIZE, index);
							recordViewed = true; 
							break;
						} else if (selectRecord == 'N' || selectRecord == 'n') {
							break;	
						} else {
							system("clear");
							cout << "\t\t\t\t\t  Serendipity Booksellers\n";
							cout << "\t\t\t\t\t         Book Search\n\n";
							cout << "\t\t\t\t       ERROR: Input must be 'Y' or 'N'\n\n";
							cout << "\t\t\t\t        Press any key to continue...";
							cin >> reply;		
							if (reply != '\0'){ 
								continue;
							}
						}
					}	
				} else {
					if (!recordViewed) {
						system("clear");
						cout << "\t\t\t\t\t  Serendipity Booksellers\n";
						cout << "\t\t\t\t\t         Book Search\n\n";
						cout << "\t\t\t Book not found. Please search for a book within the inventory.\n";
						cout << "\t\t\t\t        Press any key to continue...";
						cin >> reply;		
						if (reply != '\0'){ 
							break;
						}
					}
					
				}
		}
		temp = "";
	} else {
		cout << "\t\t\t\t    No books currently in the database!\n";
		cout << "\t\t\t\t        Press any key to continue...";
		cin >> reply;
	}
	
}