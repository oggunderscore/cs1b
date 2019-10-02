#include <iostream>
#include <string>
#include <iomanip>
#include "addbook.hpp"
#include "bookdata.hpp"
#define SIZE 20

using namespace std;

void editBook(bookType books[]) {  
	// char selectRecord; 
	// bool found = false;
    // bool recordViewed = false;
    // string temp;
    // string searchTitle;

    // bool empty = false;
    // bool exit = false;
    // int index = 0;
    // char reply;
    // char choice;

    // string tempBookTitle;
    // string tempISBN;
    // string tempAuthor;
    // string tempPublisher;
    // string tempDateAdded;
    // int tempQtyOnHand;
    // double tempWholeSale;
    // double tempRetail;

    // //newTransaction:
    // if (bookNums > 0)
    // {
    //     cout << "\t\t\t   Enter the title or ISBN of the book to search for:\n";
    //     cout << "\t\t\t\t\t\t      ";

    //     getline(cin, searchTitle);

    //     for (int i = 0; i < searchTitle.length(); i++)
    //     {
    //         searchTitle[i] = tolower(searchTitle[i]);
    //     }

    //     for (int index = 0; index < bookNums; index++)
    //     {
    //         temp = "";
    //         for (int indexInner = 0; indexInner < books[index].bookTitle.length(); indexInner++)
    //         {
    //             temp.append(1, tolower(books[index].bookTitle.at(indexInner)));
    //         }
    //         //uncomment below if temp value seems to be causing issues
    //         //cout << temp << " " << "\n" << index << " ";
    //         if (temp.find(searchTitle) != string::npos)
    //         {
    //             found = true;

    //             while (true)
    //             {
    //                 system("clear");
    //                 cout << "\t\t\t\t\t  Serendipity Book Sellers\n";
    //                 cout << "\t\t\t\t\t         Book Search\n\n";
    //                 cout << "\t\t\t\t\t      RESULT>: " << books[index].bookTitle << "\n\n";
    //                 cout << "\t\t\t\t\tView this book record? (Y/N): ";
    //                 cin >> selectRecord;
    //                 cin.ignore(600, '\n');

    //                 if (selectRecord == 'Y' || selectRecord == 'y')
    //                 {
    //                     recordViewed = true;
    //                     while (!exit)
    //                     {
    //                         system("clear");
    //                         cout << fixed;
    //                         cout.precision(2);
    //                         cout << "\t\t\t\t\t  Serendipity Book Sellers\n"
    //                              << "\t\t\t\t\t           Edit Book\n"
    //                              << "\t\t\t\t       Current Database Size: " << bookNums
    //                              << " (Max " << SIZE << ")\n"
    //                              << endl;
    //                         cout << "\t\t\t\t\t\t\t\t     + Current Values +" << endl;
    //                         cout << "\t\t\t\t(1) Edit Book Title\t\t\t >   --" << books[index].bookTitle << endl;
    //                         cout << "\t\t\t\t(2) Edit ISBN\t\t\t\t >   --" << books[index].isbn << endl;
    //                         cout << "\t\t\t\t(3) Edit Author\t\t\t >   --" << books[index].author << endl;
    //                         cout << "\t\t\t\t(4) Edit Publisher\t\t\t >   --" << books[index].publisher << endl;
    //                         cout << "\t\t\t\t(5) Edit Date Added\t\t\t >   --" << books[index].dateAdded << endl;
    //                         cout << "\t\t\t\t(6) Edit Quantity on Hand\t\t >   --" << books[index].qtyOnHand << endl;
    //                         cout << "\t\t\t\t(7) Edit Wholesale Cost\t\t >   --$" << books[index].wholesale << endl;
    //                         cout << "\t\t\t\t(8) Edit Retail Price\t\t\t >   --$" << books[index].retail << endl;
    //                         cout << "\t\t\t\t(9) Save Changes to Database\t" << endl;
    //                         cout << "\t\t\t\t(0) Return to Inventory Menu" << endl;
    //                         cout << "\t\t\t\t\t\tChoice (0-9): ";
    //                         cin >> choice;

    //                         switch(choice) {
    //                             case '1':
    //                                 system("clear");
    //                                 cout << "\n\tInput Book Title: ";
    //                                 cin.ignore(numeric_limits<streamsize>::max(),'\n'); //Clear input buffer from previous text.
    //                                 getline(cin, tempBookTitle);
    //                                 break;
    //                             case '2':
    //                                 system("clear");
    //                                 cout << "\n\tInput ISBN: ";
    //                                 cin.ignore(numeric_limits<streamsize>::max(),'\n'); //Clear input buffer from previous text.
    //                                 getline(cin, tempISBN);
    //                                 break;
    //                             case '3':
    //                                 system("clear");
    //                                 cout << "\n\tInput Author: ";
    //                                 cin.ignore(numeric_limits<streamsize>::max(),'\n'); //Clear input buffer from previous text.
    //                                 getline(cin, tempAuthor);
    //                                 break;
    //                             case '4':
    //                                 system("clear");
    //                                 cout << "\n\tInput Publisher: ";
    //                                 cin.ignore(numeric_limits<streamsize>::max(),'\n'); //Clear input buffer from previous text.
    //                                 getline(cin, tempPublisher);
    //                                 break;
    //                             case '5':
    //                                 system("clear");
    //                                 cout << "\n\tInput Date: ";
    //                                 cin.ignore(numeric_limits<streamsize>::max(),'\n'); //Clear input buffer from previous text.
    //                                 getline(cin, tempDateAdded);
    //                                 break;
    //                             case '6':
    //                                 system("clear");
    //                                 cout << "\n\tInput Quantity on Hand: ";
    //                                 cin.ignore(numeric_limits<streamsize>::max(),'\n'); //Clear input buffer from previous text.
    //                                 cin >> tempQtyOnHand;
    //                                 break;
    //                             case '7':
    //                                 system("clear");
    //                                 cout << "\n\tInput Wholesale Cost: ";
    //                                 cin.ignore(numeric_limits<streamsize>::max(),'\n'); //Clear input buffer from previous text.
    //                                 cin >> tempWholeSale;
    //                                 break;
    //                             case '8':
    //                                 system("clear");
    //                                 cout << "\n\tInput Retail Price: ";
    //                                 cin.ignore(numeric_limits<streamsize>::max(),'\n'); //Clear input buffer from previous text.
    //                                 cin >> tempRetail;
    //                                 break;
    //                             case '9':
    //                                 system("clear");
                                    
    //                                 setTitle(tempBookTitle, bookNums, books);
    //                                 setISBN(tempISBN, bookNums, books);
    //                                 setAuthor(tempAuthor, bookNums, books);
    //                                 setPublisher(tempPublisher, bookNums, books);
    //                                 setDateAdded(tempDateAdded, bookNums, books);
    //                                 setQty(tempQtyOnHand, bookNums, books);
    //                                 setWholesale(tempWholeSale, bookNums, books);
    //                                 setRetail(tempRetail, bookNums, books);
                                    
    //                                 cout << "\t\t\t\t\t  Serendipity Book Sellers\n"
    //                                         << "\t\t\t\t\t           Edit Book\n\n";
    //                                 cout << "\t\t\t\t             Save was successful.\n\n";
    //                                 cout << "\t\t\t\t        Press any key to continue...";
    //                                 cin >> reply; 
    //                                 cin.ignore(numeric_limits<streamsize>::max(),'\n'); //Clear input buffer from previous text.
    //                                 exit = true;
    //                                 break;
    //                                 //goto top;
    //                             case '0':
    //                                 exit = true;
    //                                 break;
    //                             default:
    //                                 system("clear");
    //                                 cout << "\t\t\t\t\t  Serendipity Book Sellers\n"
    //                                         << "\t\t\t\t\t           Add Book\n";
    //                                 cout << "\n\t\t\t\t     ERROR: Choice must be a number 0 - 9.\n\n";
    //                                 cout << "\t\t\t\t        Press any key to continue...";
    //                                 cin >> reply; 
    //                         }
    //                     }
    //                 }
    //                 else if (selectRecord == 'N' || selectRecord == 'n')
    //                 {
    //                     break;
    //                 }
    //                 else
    //                 {
    //                     system("clear");
    //                     cout << "\t\t\t\t\t  Serendipity Book Sellers\n";
    //                     cout << "\t\t\t\t\t         Book Search\n\n";
    //                     cout << "\t\t\t\t       ERROR: Input must be 'Y' or 'N'\n\n";
    //                     cout << "\t\t\t\t        Press any key to continue...";
    //                     cin >> reply;
    //                     if (reply != '\0')
    //                     {
    //                         continue;
    //                     }
    //                 }
    //             }
    //             if (recordViewed)
    //             {
    //                 break;
    //             }
    //         }
    //         if (index > bookNums - 1)
    //         {
    //             found = false;
    //         }
    //     }

    //     if (!found)
    //         system("clear");
    //     cout << "\t\t\t\t\t  Serendipity Book Sellers\n";
    //     cout << "\t\t\t\t\t         Book Search\n\n";
    //     cout << "\t\t\t Book not found. Please search for a book within the inventory.\n";
    //     cout << "\t\t\t\t        Press any key to continue...";
    //     cin >> reply;
    // }
    // else
    // {
    //     cout << "\t\t\t\t    No books currently in the database!\n\n";
    //     cout << "\t\t\t\t        Press any key to continue...";
    //     cin >> reply;
    // }
}