#ifndef CASHIER_HPP_
#define CASHIER_HPP_

#include "bookdata.hpp"

struct tempBookData {
    string title;
    string isbn;
    double retail;
    int qty;
};

void cashier(bookType *books_[]);

#endif
