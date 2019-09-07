#ifndef ADDBOOK_HPP_
#define ADDBOOK_HPP_

#include <string>

using namespace std;

void addBook(string title[], string isbn[], string author[], string publisher[],
	string date[], int qty[], double wholesale[], double retail[], const int SIZE, int &bookNums);

#endif