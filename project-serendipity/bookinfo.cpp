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
#include "bookdata.hpp"

using namespace std;


void bookInfo(int index, bookType books[]) {
	char reply; 
	system("clear");

	cout << "\t\t\t\t\t  Serendipity Booksellers\n";
	cout << "\t\t\t\t\t     Book Information\n\n";

	cout << "\t\t\t\t\t Title:              " << books[index].bookTitle << endl;
	cout << "\t\t\t\t\t ISBN:               " << books[index].isbn << endl;
	cout << "\t\t\t\t\t Author:             " << books[index].author << endl;
	cout << "\t\t\t\t\t Publisher:          " << books[index].publisher << endl;
	cout << "\t\t\t\t\t Date Added:         " << books[index].dateAdded << endl;
	cout << "\t\t\t\t\t Quantity on Hand:   " << books[index].qtyOnHand << endl;
	cout << "\t\t\t\t\t Wholesale Cost:   $ " << books[index].retail << endl;
	cout << "\t\t\t\t\t Retail Price:     $ " << books[index].retail << endl;

	while (true)
	{
		cout << "\n\t\t\t\t        Press any key to continue...";
		cin >> reply;
		if (reply != '\0')
		{
			break;
		}
	}
}