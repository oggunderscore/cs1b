//--------------------------------------------------------------------------
//  File name: mainmenu.hpp
//  Project name: Serendipity
//--------------------------------------------------------------------------
//  Creator's name and email: Felix Murray felix.murray@gmail.com
//  Course Selection: CS1B
//  Creation Date: 8/24/19
//  Date of Last Modification: 8/28/19
//--------------------------------------------------------------------------
//  Purpose: Header file corresponding to mainmenu.cpp
//--------------------------------------------------------------------------
//  Algorithm: 
//      n/a
//--------------------------------------------------------------------------

#ifndef MAINMENU_HPP_
#define MAINMENU_HPP_

#include <string> 

using namespace std; 

void menu(string title[], string isbn[], string author[], string publisher[],
	string date[], int qty[], double wholesale[], double retail[], const int SIZE, int &bookNums);

#endif