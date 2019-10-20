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
	books[index].print();
}