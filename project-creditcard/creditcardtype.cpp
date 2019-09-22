//--------------------------------------------------------------------------
//  File name: creditcardtype.cpp
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
#include "creditcardtype.h"

/**************** STATIC DECLARATIONS *********************/

int creditCardType::count = 0;
float creditCardType::creditLimit = 10000.00;
float creditCardType::balance = 0;

//--------------------------------------------------------------------------
//  Function: incCount
//--------------------------------------------------------------------------
//  Purpose: Increments static int count by one.
//--------------------------------------------------------------------------
void creditCardType::incCount(){
	count++;
}

//--------------------------------------------------------------------------
//  Function: getCount
//--------------------------------------------------------------------------
//  Purpose: Returns value of static int count.
//--------------------------------------------------------------------------
int creditCardType::getCount(){
	return count;
}

/**************** SETTER FUNCTIONS *********************/

void creditCardType::setCardNumber(string initNumber){
	number = initNumber;
	return;
}

void creditCardType::setName(string initName){
	name = initName;
	return;
}

void creditCardType::setExpiration(string initExpiration){
	expiration = initExpiration;
	return;
}

void creditCardType::setAllInfo(string initNumber, 
                                string initName, 
								string initExpiration){
	
	setCardNumber(initNumber);
	setName(initName);
	setExpiration(initExpiration);
	
	return;
}

/**************** CONSTRUCTORS *********************/

creditCardType::creditCardType(){
	setAllInfo("DEFAULT-NUMBER", "DEFAULT-NAME", "DEFAULT-EXPIRATION");
	incCount();
}

creditCardType::creditCardType(string number, 
                               string name, 
							   string expiration){
	setAllInfo(number, name, expiration);
	incCount();
}

/**************** GETTER FUNCTIONS *********************/
		
float creditCardType::getBalance() {
	return creditCardType::balance;
}

string creditCardType::getName() {
	return name;
}

string creditCardType::getNumber() {
	return number;
}

float creditCardType::getLimit() {
	return creditLimit;
}

//--------------------------------------------------------------------------
//  Function: print
//--------------------------------------------------------------------------
//  Purpose: Outputs the card number, account holder, and balance for the 
//           specified credit card.
//--------------------------------------------------------------------------
void creditCardType::print(){
	cout << "Credit Card Number: " << getNumber() << endl;
	cout << "Name of Cardholder: " << getName() << endl;
	cout << "Current Balance: $" << getBalance() << "\n\n";
	return;
}

//--------------------------------------------------------------------------
//  Function: purchase
//--------------------------------------------------------------------------
//  Purpose: Determines if the passed purchase cost is within the credit 
//           limit of a given credit card by comparing the cost to the credit
//           limit minus the card balance. If the cost is greator than the 
//           equation, the purchase is cancelled as it is not within budget.
//           If the equation is not true, the purchase is made.
//--------------------------------------------------------------------------
void creditCardType::purchase(float cost) {
	cout << "Making a $" << cost << " purchase..." << "\n";

	if (cost > creditLimit - balance) {
		cout << "Purchase Cancelled. Not enough funds.\n";
	} else {
		balance += cost;
		cout << "Purchase Successful!\n";
	}
}

//--------------------------------------------------------------------------
//  Function: pause
//--------------------------------------------------------------------------
//  Purpose: Pauses the flow of console output until the user presses a key
//           on their keyboard.
//--------------------------------------------------------------------------
void creditCardType::pause() {
	char reply;
	cout << "Press any key to continue...";
	cin >> reply;
	system("clear");
}


	