#include <iostream>
#include <string> 
#include "addbook.hpp"

using namespace std; 

void addBook(string title[], string isbn[], string author[], string publisher[],
	string date[], int qty[], double wholesale[], double retail[], const int SIZE, int &bookNums) {
	bool empty = false;
	int index = 0;
	char reply;

	while (!empty && index < SIZE) {
		if (title[index] == "")
			empty = true;
		else
			index++;
	}

	if (empty) {
		system("clear");
		cout << "\t\t\t\t\t  Serendipity Booksellers\n";
		cout << "\t\t\t\t\t          Add Book\n\n";

		cin.ignore();

		cout << "\t\t\t\t\t Enter Title:              "; 
		getline(cin, title[index]);
		cout << "\t\t\t\t\t Enter ISBN:               ";
		getline(cin, isbn[index]);
		cout << "\t\t\t\t\t Enter Author:             ";
		getline(cin, author[index]);
		cout << "\t\t\t\t\t Enter Publisher:          ";
		getline(cin, publisher[index]);
		cout << "\t\t\t\t\t Enter Date Added:         ";
		getline(cin, date[index]);
		cout << "\t\t\t\t\t Enter Quantity Added:     ";
		cin >> qty[index];
		cout << "\t\t\t\t\t Enter Wholesale Price:    ";
		cin >> wholesale[index];
		cout << "\t\t\t\t\t Enter Retail Price:       ";
		cin >> retail[index];
		cout << "\n\n\t\t\t\t\t     Record was entered.\n\n";
		
		bookNums++;
		
		while (true) {
			cout << "\t\t\t\t        Press any key to continue...";
			cin >> reply;		
			if (reply != '\0'){ 
				break;
			}
		}
		
	} else {
        cout << "No more books may be added\n";
    }
}