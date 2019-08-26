#include <iostream>
#include <iomanip>
#include <string>

#include "util.hpp"

using std::cout; 
using std::cin; 
using std::system;
using std::string;
using std::getline;

#define SALES_TAX 0.06;

void cashier () {
    string date; 
    int quantity; 
    string ISBN; 
    string title; 
    float price; 
    
    float total;
    float taxToAdd;

    system("clear");

    cout
        << "Serendipity Booksellers\n"
        << "Cashier Module\n\n";

    cout << "Date: ";
    cin.ignore();
    getline(cin, date);

    cout << "Quantity of Book: ";
    cin >> quantity;

    cout << "ISBN: ";
    cin.ignore();
    getline(cin, ISBN);

    cout << "Title: ";
    cin.ignore();
    getline(cin, title);

    cout << "Price: ";
    cin >> price;

    total = quantity * price; 
    taxToAdd = total * SALES_TAX;

    //output for the reciept is *almost* working, but is cut off for some reason
    system("clear");
    cout << "Serendipity Booksellers\n\n"; 
    cout << "Date: " << date; 
    cout << "\n\n";
    cout << "Qty     ISBN          Title                    Price          Total\n";
    cout << "_______________________________________________________________________\n";
    cout << quantity << "     " << ISBN << "     " 
        << title << "         $  " << price 
        << "          $  " << total << "\n\n\n";
    cout << "            Subtotal                         "
        << total;
    cout << "            Tax                         $ " << taxToAdd;
    cout << "            Total                       $ " << total + taxToAdd; 
    cout << "Thank you for shopping at Serendipity!";

    pause();
}