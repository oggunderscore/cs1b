//--------------------------------------------------------------------------
//  File name: util.hpp
//  Project name: Serendipity
//--------------------------------------------------------------------------
//  Creator's name and email: Felix Murray felix.murray@gmail.com
//  Course Selection: CS1B
//  Creation Date: 8/24/19
//  Date of Last Modification: 8/28/19
//--------------------------------------------------------------------------
//  Purpose: Header file corresponding to util.cpp
//--------------------------------------------------------------------------
//  Algorithm:
//      n/a
//--------------------------------------------------------------------------
#include "bookdata.hpp"


#ifndef UTIL_HPP_
#define UTIL_HPP_

void pause();
size_t findCaseInsensitive(std::string data, std::string target);
bookType** bookValueToPointer(bookType array[]); 

#endif
