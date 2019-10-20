#include <iostream>
#include "menuformatting.hpp"
#include "util.hpp"

using namespace std;

void printHeaderMenu(int option)
{
    switch (option)
    {
    case MENU_MAIN:
        system("clear");
        cout << "\t\t\t\t\t  Serendipity Book Sellers\n"
             << "\t\t\t\t\t          Main Menu\n\n";
        break;
    case MENU_CASHIER:
        system("clear");
        cout << "\t\t\t\t\t  Serendipity Book Sellers\n"
             << "\t\t\t\t\t       Cashier Module\n\n";
        break;
    case MENU_INVENTORY:
        system("clear");
        cout << "\t\t\t\t\t  Serendipity Book Sellers\n";
		cout << "\t\t\t\t\t      Inventory Database\n\n";
        break;
    case MENU_ADDBOOK:
        system("clear");
        cout << "\t\t\t\t\t  Serendipity Book Sellers\n"
             << "\t\t\t\t\t           Add Book\n\n";
        break;
    case MENU_LOOKUPBOOK:
        system("clear");
        cout << "\t\t\t\t\t  Serendipity Book Sellers\n"
             << "\t\t\t\t\t         Search Book\n\n";
        break; 
    case MENU_EDITBOOK:
         system("clear");
         cout << "\t\t\t\t\t  Serendipity Book Sellers\n"
              << "\t\t\t\t\t         Edit Book\n\n";
        break;  
    case MENU_DELETEBOOK:
        system("clear");
        cout << "\t\t\t\t\t  Serendipity Book Sellers\n"
             << "\t\t\t\t\t       Delete Book\n\n";
        break;
    case MENU_REPORTS:
        break; 
        //doesn't exist yet
    }
}

void printError(int option)
{
    switch (option)
    {
    case MENU_MAIN:
        cout << "ERROR: Choice must be a number 1 - 4.\n\n";
        pause();
        break;
    case MENU_CASHIER:
        break;
    case MENU_INVENTORY:
        break;
    case MENU_ADDBOOK:
        break;
    case MENU_LOOKUPBOOK:
        break; 
    case MENU_EDITBOOK:
        break;  
    case MENU_DELETEBOOK:
        break;
    case MENU_REPORTS:
        break; 
        //doesn't exist yet
    }
}