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
#include "bookdata.hpp"

using namespace std;

const int SIZE = 20;

bookType books[SIZE];

int main () {
    
    int bookCount = 0; 

    mainMenu(bookCount); 

    return 0; 
}