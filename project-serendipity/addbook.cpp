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
		cin.ignore();
		cout << "\nEnter Title: ";
		getline(cin, title[index]);

		cout << "\nEnter ISBN: ";
		getline(cin, isbn[index]);

		cout << "\nEnter Author: ";
		getline(cin, author[index]);

		cout << "\nEnter Publisher: ";
		getline(cin, publisher[index]);

		cout << "\nEnter Date Added to Inventory: ";
		getline(cin, date[index]);

		cout << "\nEnter Quantity Added: ";
		cin >> qty[index];

		cout << "\nEnter Wholesale Price: ";
		cin >> wholesale[index];

		cout << "\nEnter Retail Price: ";
		cin >> retail[index];

		cout << "\nRecord was entered.\n\n";

		bookNums++;
		
		while (true) {
			cout << "Press any key to continue...";
			cin >> reply;		
			if (reply != '\0'){ 
				break;
			}
		}
		
	} else {
        cout << "No more books may be added\n";
    }
}