#include <iostream>
#include <string>
#include "bookdata.hpp"

using namespace std;

void setTitle (string title, int index, bookType books[]) {
    books[index].bookTitle = title;
}

void setISBN (string isbn, int index, bookType books[]) {
    books[index].isbn = isbn;
}

void setAuthor (string author, int index, bookType books[]) {
    books[index].author = author;
}

void setPublisher (string publisher, int index, bookType books[]) {
    books[index].publisher = publisher;
}

void setDateAdded (string date, int index, bookType books[]) {
    books[index].dateAdded = date;
}

void setQty (int qty, int index, bookType books[]) {
    books[index].qtyOnHand = qty;
}

void setWholesale (double wholesale, int index, bookType books[]) {
    books[index].wholesale = wholesale;
}

void setRetail (double retail, int index, bookType books[]) {
    books[index].retail = retail;
}

// bool isEmpty () {

// }

// void removeBook () {

// }


