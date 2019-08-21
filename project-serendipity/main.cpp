#include <iostream>
#include <iomanip>

using namespace std; 

void cashierModule (){
  const float SALES_TAX = 0.06; 
  string date; 
  int quantity; 
  string ISBN; 
  string title; 
  float price; 
  float total;
  float taxToAdd;

  system("clear");

  cout << "Serendipity Booksellers"
       << "\nCashier Module\n\n";
  cout << "Date: ";
  cin.ignore();
  getline (cin, date);
  cout << "Quantity of Book: ";
  cin >> quantity;
  cout << "ISBN: ";
  cin.ignore();
  getline (cin, ISBN);
  cout << "Title: ";
  cin.ignore();
  getline (cin, title);
  cout << "Price: ";
  cin >> price;

  total = quantity * price; 
  taxToAdd = total * SALES_TAX;

  system("clear");
  cout << "Serendipity Booksellers\n\n"; 
  cout << "Date: " << date; 
  cout << "\n\n";
  cout << "Qty     ISBN          Title                    Price          Total\n";
  cout << "_______________________________________________________________________\n";
  cout << quantity << "     " << ISBN << "     " 
       << title << "         $  " << price 
       << "           $  " << total << "\n\n\n";
  cout << "            Subtotal                         "
       << total;
  cout << "            Tax                         $ " << taxToAdd;
  cout << "            Total                       $ " << total + taxToAdd; 
  cout << "Thank you for shopping at Serendipity!";
  system("read");
}
void printInventoryMenu () {
    system("clear");
    cout << "Serendipity Book Sellers"
         << "\n" << "Inventory Database" << "\n\n";
    cout << "1.   Look Up a Book"
         << "\n"
         << "2.   Add a Book"
         << "\n"
         << "3.   Edit a Book's Record"
         << "\n"
         << "4.   Delete a Book"
         << "\n"
         << "5.   Return to the Main Menu"
         << "\n\n"
         << "Enter Your Choice: ";    
}

void inventoryModule (char userSelection) {
  do {
    switch (userSelection){
      case '1':
        cout << "nothing here yet (1)";
        break;
      case '2':
        cout << "nothing here yet (2)";
        break;
      case '3':
        cout << "nothing here yet (3)";
        break;
      case '4':
        cout << "nothing here yet (4)";
        break;
      case '5':
        break;
      default: 
        cout << "ERROR: Input Must be an Option from 1 - 4.";
        break;
    }
  } while (userSelection != '5');
}


void mainMenu (char userSelection){
   system("clear");
   switch (userSelection){
      case '1': 
        cashierModule(); 
        break; 
      case '2': 
        printInventoryMenu();
        cin >> userSelection; 
        inventoryModule(userSelection); 
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
      default: 
        cout << "ERROR: Input Must be an Option from 1 - 4.";
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


