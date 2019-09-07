//--------------------------------------------------------------------------
//  File name: main.cpp
//  Project name: Serendipity
//--------------------------------------------------------------------------
//  Creator's name and email: Felix Murray felix.murray@gmail.com
//  Course Selection: CS1B
//  Creation Date: 8/24/19
//  Date of Last Modification: 8/28/19
//--------------------------------------------------------------------------
//  Purpose: Runs the main method of the Serendipity store and calls the 
//           main menu function.  
//--------------------------------------------------------------------------
//  Algorithm: 
//      Step 1: Call menu() function.
//--------------------------------------------------------------------------
#include <iostream>
#include <iomanip>
#include <string>

#include "mainmenu.hpp"

using namespace std;

int main () {
    const int SIZE = 20;
    int bookCount = 0; 
    
    string bookTitle[SIZE];
    string isbn[SIZE];
    string author[SIZE];
    string publisher[SIZE];
    string dateAdded[SIZE];
    int qtyOnHand[SIZE];
    double wholesale[SIZE];
    double retail[SIZE];


    menu(bookTitle, isbn, author, publisher, dateAdded, qtyOnHand, wholesale, retail, SIZE, bookCount); 

    return 0; 
}