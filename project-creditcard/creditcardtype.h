//--------------------------------------------------------------------------
//  File name: creditcardtype.h
//  Project name: Credit Card
//--------------------------------------------------------------------------
//  Creator's name and email: Felix Murray felix.murray@gmail.com
//  Course Selection: CS1B
//  Creation Date: 9/18/19
//  Date of Last Modification: 9/19/19
//--------------------------------------------------------------------------
//  Purpose: This program will create three credit cards using the 
//           creditCardType class on the same account (same name) and make
//           3 purchases with each card to demonstrate the use of static 
//           functions.
//--------------------------------------------------------------------------
#ifndef CREDITCARDTYPE_H
#define CREDITCARDTYPE_H

#include <iostream>

using namespace std;

class creditCardType
{
	public:
		/**************** CONSTRUCTORS *********************/

		creditCardType(); //default
		creditCardType(string, string, string);  //take all 3 data members
	
		/**************** SETTER FUNCTIONS *********************/

		void setCardNumber(string);
		void setName(string);
		void setExpiration(string);
		void setAllInfo(string, string, string);
		
		/**************** GETTER FUNCTIONS *********************/

		static int getCount();  
		static void incCount();
		static float getLimit();
		static float getBalance();
		string getNumber();
		string getName();  
		
		
		/* Print */
		void print();

		/* Purchase */
		static void purchase(float);

		/* Pause */
		static void pause();		
		
	private:
		string number; 
		string name;
		string expiration;
		static int count;
		static float creditLimit;
		static float balance;
};

#endif