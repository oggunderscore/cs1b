#include <iostream>
#include "bookinfo.hpp"

using namespace std;

void bookInfo(string title[], string isbn[], string author[], string publisher[],
	string date[], int qty[], double wholesale[], double retail[], const int SIZE, int index) {
	char reply; 
	system("clear");

	cout << "Serendipity Booksellers\n";
	cout << "   Book Information\n\n";

	cout << "Title:: " << title[index] << endl;
	cout << "ISBN: " << isbn[index] << endl;
	cout << "Author: " << author[index] << endl;
	cout << "Publisher: " << publisher[index] << endl;
	cout << "Date Added: " << date[index] << endl;
	cout << "Quantity on Hand: " << qty[index] << endl;
	cout << "Wholesale Cost: " << wholesale[index] << endl;
	cout << "Retail Price: " << retail[index] << endl;

	while (true) {
		cout << "Press any key to continue...";
		cin >> reply;		
		if (reply != '\0'){ 
			break;
		}
	}
}