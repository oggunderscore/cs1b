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
	int index = 0;
	string temp;
	string searchTitle;

	system("clear");

	cin.ignore();

	cout << "Enter the title of the book to search for: ";
	getline(cin, searchTitle);

	for (int i = 0; i < searchTitle.length(); i++) {
		searchTitle[i] = tolower(searchTitle[i]);
	}

		for (int index = 0; index < bookNums; index++) {
			for (int indexInner = 0; indexInner < title[index].length(); indexInner++) {
				temp.append(1, tolower(title[index].at(indexInner)));
			}
				if (temp.find(searchTitle) != string::npos){
					while (true) {
						system("clear"); 
						cout << "RESULT>: " << title[index] << endl;
						cout << "View this book record? (Y/N): ";
						cin >> selectRecord;
						cin.ignore(600, '\n'); //?
			
						if (selectRecord == 'Y' || selectRecord == 'y') {
							bookInfo(title, isbn, author, publisher, date,
								 	 qty, wholesale, retail, SIZE, index);
							break;
						} else if (selectRecord == 'N' || selectRecord == 'n') {
							break;
						}else {
							system("clear");
							cout << "ERROR: Input must be 'Y' or 'N'\n\n";
							cout << "Press any key to continue...";
							cin >> reply;		
							if (reply != '\0'){ 
								continue;
							}
						}
					}
					
				}else {
					cout << "\nBook not found. Please search for a book within the inventory.\n";
					cout << "Press any key to continue...";
					cin >> reply;		
					if (reply != '\0'){ 
						break;
					}
				}
		}
		temp = "";
}