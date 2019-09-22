//--------------------------------------------------------------------------
//  File name: driver.cpp
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
//  Algorithm: 
//      Step 1: Initialize three credit cards using the constructor.
//      Step 2: Output to the console which account the card was made for, 
//              the number of total cards, the credit limit, and the balance 
//              for each card. 
//      Step 3: Make three purchases with each card and output the card
//              information using the print() function.
//--------------------------------------------------------------------------
#include <iostream>
#include "creditcardtype.h"

using namespace std;

int main(){
	system("clear");
	
	creditCardType cardOne("4800 1600 3456 6789", "Mr. Krabs", "12/99");
	cout << "New card created for account " << cardOne.getName() << "\n";
	cardOne.print();
	cout <<	"Number of cards is now: " << creditCardType::getCount()<< "\n\n";
	
	creditCardType cardTwo("5678 9085 4588 6578", "Mr. Krabs", "12/24");
	cout << "New card created for account " << cardTwo.getName() << "\n";
	cardTwo.print();
	cout <<	"Number of cards is now: " << creditCardType::getCount() << "\n\n";
	
	creditCardType cardThree("5558 9555 4555 6555", "Mr. Krabs", "12/20");
	cout << "New card created for account " << cardThree.getName() << "\n";
	cardThree.print();
	cout <<	"Number of cards is now: " << creditCardType::getCount() << "\n\n";

	//cardOne
	cout << "Card One\n\n";
	cardOne.purchase(500);
	cout << "Balance: $" << cardOne.getBalance() << "\n\n"; 
	
	cardOne.purchase(5000);
	cout << "Balance: $" << cardOne.getBalance() << "\n\n";

	cardOne.purchase(20000);
	cout << "Balance: $" << cardOne.getBalance() << "\n\n";

	//cardTwo
	cout << "Card Two\n\n";
	cardTwo.purchase(350);
	cout << "Balance: $" << cardTwo.getBalance() << "\n\n";  

	cardTwo.purchase(7500);
	cardTwo.getBalance(); 
	cout << "Balance: $" << cardTwo.getBalance() << "\n\n";

	cardTwo.purchase(14500);
	cardTwo.getBalance();  
	cout << "Balance: $" << cardTwo.getBalance() << "\n\n";

	//cardThree
	cout << "Card Three\n\n";
	cardThree.purchase(100);
	cout << "Balance: $" << cardThree.getBalance() << "\n\n";


	cardThree.purchase(1000);
	cout << "Balance: $" << cardThree.getBalance() << "\n\n";


	cardThree.purchase(10000);
	cout << "Balance: $" << cardThree.getBalance() << "\n\n";
	creditCardType::pause();

	return 0;
}