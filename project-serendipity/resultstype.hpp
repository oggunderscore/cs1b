#ifndef RESULTSTYPE_HPP_
#define RESULTSTYPE_HPP_

#include <iostream>

class resultsType {
	public: 
		std::string bookTitle, ISBN;
		double retail;
		int qty;
		int index;
		static int amount;
};

#endif