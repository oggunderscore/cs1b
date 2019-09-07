#ifndef SEARCHBOOK_HPP_
#define SEARCHBOOK_HPP_

#include <string>

using namespace std;

void lookUpBook(string title[], string isbn[], string author[], string publisher[],
	string date[], int qty[], double wholesale[], double retail[], const int SIZE, int &bookNums);

#endif