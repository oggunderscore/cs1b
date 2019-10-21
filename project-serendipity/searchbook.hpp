#ifndef SEARCHBOOK_HPP_
#define SEARCHBOOK_HPP_

#include "bookdata.hpp"
#include "resultstype.hpp"

int lookUpBook(bookType *books[], resultsType[], int amtResults);
void executeFind(bookType *books_[]);

#endif