//--------------------------------------------------------------------------
//  File name: bookinfo.cpp
//  Project name: Serendipity
//--------------------------------------------------------------------------
//  Creator's name and email: Felix Murray felix.murray@gmail.com
//  Course Selection: CS1B
//  Creation Date: 8/24/19
//  Date of Last Modification: 9/2/19
//--------------------------------------------------------------------------
//  Purpose: This program will display the book information for the passed
//           parameters.
//--------------------------------------------------------------------------
//  Algorithm: 
//      Step 1: Display Book Information. 
//--------------------------------------------------------------------------

#include <iostream>
#include "bookinfo.hpp"

using namespace std;

void bookInfo(string title[], string isbn[], string author[], string publisher[],
	string date[], int qty[], double wholesale[], double retail[], const int SIZE, int index) {
	char reply; 
	system("clear");

	cout << "\t\t\t\t\t  Serendipity Booksellers\n";
	cout << "\t\t\t\t\t     Book Information\n\n";

	cout << "\t\t\t\t\t Title:              " << title[index] << endl;
	cout << "\t\t\t\t\t ISBN:               " << isbn[index] << endl;
	cout << "\t\t\t\t\t Author:             " << author[index] << endl;
	cout << "\t\t\t\t\t Publisher:          " << publisher[index] << endl;
	cout << "\t\t\t\t\t Date Added:         " << date[index] << endl;
	cout << "\t\t\t\t\t Quantity on Hand:   " << qty[index] << endl;
	cout << "\t\t\t\t\t Wholesale Cost:   $ " << wholesale[index] << endl;
	cout << "\t\t\t\t\t Retail Price:     $ " << retail[index] << endl;

	while (true) {
		cout << "\n\t\t\t\t        Press any key to continue...";
		cin >> reply;		
		if (reply != '\0'){ 
			break;
		}
	}
}