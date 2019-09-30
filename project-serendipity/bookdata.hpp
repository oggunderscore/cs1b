#ifndef BOOKDATA_HPP_
#define BOOKDATA_HPP_

#include <string>

using namespace std;

struct bookType
{
    string bookTitle;
    string isbn;
    string author;
    string publisher;
    string dateAdded;
    int qtyOnHand;
    double wholesale;
    double retail;
};

void setTitle (string title, int index, bookType books[]);
void setISBN (string isbn, int index, bookType books[]);
void setAuthor (string author, int index, bookType books[]);
void setPublisher (string publisher, int index, bookType books[]);
void setDateAdded (string date, int index, bookType books[]);
void setQty (int qty, int index, bookType books[]);
void setWholesale (double wholesale, int index, bookType books[]);
void setRetail (double retail, int index, bookType books[]);

#endif