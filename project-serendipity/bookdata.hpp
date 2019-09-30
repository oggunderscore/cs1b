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

void setTitle(string title, int index);
void setISBN(string isbn, int index);
void setAuthor(string author, int index);
void setPublisher(string publisher, int index);
void setDateAdded(string date, int index);
void setQty(int qty, int index);
void setWholesale(double wholesale, int index);
void setRetail(double retail, int index);

#endif