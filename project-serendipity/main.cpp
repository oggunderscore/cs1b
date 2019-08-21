#include <iostream>
#include <iomanip>

using namespace std; 

void cashierModule (){
  string date; 
  int quantity; 
  string ISBN; 
  string title; 
  float price; 

  system("clear");

  cout << "Serendipity Booksellers"
       << "\nCashier Module\n\n";
  cout << "Date: ";
  cin.ignore();
  getline (cin, date);
  cout << "Quantity of Book: ";
  cin.ignore();
  cin >> quantity;
  cout << "ISBN: ";
  cin.ignore();
  getline (cin, ISBN);
  cout << "Title: ";
  cin.ignore();
  getline (cin, title);
  cout << "Price: ";
  cin >> price;

  cout << 
}

void mainMenu (char userSelection){
   //system("clear");
   switch (userSelection){
      case '1': 
        cashierModule(); 
        break; 
      case '2': 
        system("read");
        cout << "You entered option 2. Nothing to see here yet!";
        cout << "Press any key to continue...";
        
        break; 
      case '3': 
        cout << "You entered option 3."
             << "\nNothing to see here yet!"; 
        cout << "Press any key to continue...\n";
        cin.ignore();
        // system("read");
        break; 
      case '4':
        userSelection = '4';
        break; 
    }
}

void printMainMenu () {
    system("clear");
    cout << "Serendipity Book Sellers"
         << "\n" << "Main Menu" << "\n\n";
    cout << "1.   Cashier Module"
         << "\n"
         << "2.   Inventory Database Module"
         << "\n"
         << "3.   Report Module"
         << "\n"
         << "4.   Exit"
         << "\n\n"
         << "Enter Your Choice: ";    
  }

int main () {
    char menuOption;
    do {
      printMainMenu();
      cin >> menuOption;
      mainMenu (menuOption);
    } while (menuOption != '4');
    
	return 0; 
}


