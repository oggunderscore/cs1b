#include <iostream>
#include <string>
#include "bookdata.hpp"
#include "util.hpp"

using namespace std;

/**************** STATIC DECLARATIONS *********************/
int bookType::bookCount = 0;

//setters

void bookType::setTitle (string initTitle) {
    bookTitle = initTitle;
}

void bookType::setISBN (string initISBN) {
    isbn = initISBN;
}

void bookType::setAuthor (string initAuthor) {
    author = initAuthor;
}

void bookType::setPublisher (string initPublisher) {
    publisher = initPublisher;
}

void bookType::setDateAdded (string initDate) {
    dateAdded = initDate;
}

void bookType::setQty (int initQty) {
    qtyOnHand = initQty;
}

void bookType::setWholesale (double initWholesale) {
    wholesale = initWholesale;
}

void bookType::setRetail (double initRetail) {
    retail = initRetail;
}

void bookType::setAll(string initTitle, 
                      string initISBN, 
                      string initAuthor, 
                      string initPublisher, 
                      string initDate, 
                      int initQty, 
                      double initWholesale, 
                      double initRetail) {
    bookTitle = initTitle;
    isbn = initISBN;
    author = initAuthor;
    publisher = initPublisher;
    dateAdded = initDate;
    qtyOnHand = initQty;
    wholesale = initWholesale;
    retail = initRetail;
}

//getters

string bookType::getBookTitle() {
    return bookTitle;    
}

string bookType::getISBN() {
    return isbn;    
}

string bookType::getAuthor() {
    return author;    
}

string bookType::getPublisher() {
    return publisher;    
}

string bookType::getDateAdded() {
    return dateAdded;    
}

int bookType::getQtyAdded() {
    return qtyOnHand;
}

double bookType::getWholesale() {
    return wholesale;
}

double bookType::getRetail() {
    return retail;
}

//functions

void bookType::print() {
    system("clear");

	cout << "\t\t\t\t\t  Serendipity Booksellers\n";
	cout << "\t\t\t\t\t     Book Information\n\n";

	cout << "\t\t\t\t\t Title:              " << getBookTitle() << endl;
	cout << "\t\t\t\t\t ISBN:               " << getISBN() << endl;
	cout << "\t\t\t\t\t Author:             " << getAuthor() << endl;
	cout << "\t\t\t\t\t Publisher:          " << getPublisher() << endl;
	cout << "\t\t\t\t\t Date Added:         " << getDateAdded() << endl;
	cout << "\t\t\t\t\t Quantity on Hand:   " << getQtyAdded() << endl;
	cout << "\t\t\t\t\t Wholesale Cost:   $ " << getWholesale() << endl;
	cout << "\t\t\t\t\t Retail Price:     $ " << getRetail() << endl;
    pause();
}

void bookType::incBookCount(){
	bookCount++;
}

void bookType::decBookCount(){
	bookCount--;
}

int bookType::getBookCount(){
	return bookCount;
}





