#include <iostream>
#include <string>
#include "bookdata.hpp"

using namespace std;

extern bookType books[20];

void setTitle (string title, int index) {
    books[index].bookTitle = title;
}

void setISBN (string isbn, int index) {
    books[index].isbn = isbn;
}

void setAuthor (string author, int index) {
    books[index].author = author;
}

void setPublisher (string publisher, int index) {
    books[index].publisher = publisher;
}

void setDateAdded (string date, int index) {
    books[index].dateAdded = date;
}

void setQty (int qty, int index) {
    books[index].qtyOnHand = qty;
}

void setWholesale (double wholesale, int index) {
    books[index].wholesale = wholesale;
}

void setRetail (double retail, int index) {
    books[index].retail = retail;
}

// bool isEmpty () {

// }

// void removeBook () {

// }


