#include <iostream>
#include "personType.h"

using namespace std; 

int main () {
    int numPersons; 

    system("clear");
    cout << "Enter the number of people you wish to create: ";
    cin >> numPersons; 
    cin.ignore();
    cout << "\n";

    personType *personArray;
    personArray = new personType[numPersons];

    string first;
    string last;
    string house;
    string birthday;
    double heightLength;
    char senumPersons;

    for (int i = 0; i < numPersons; i++) {
        system("clear");
        cout << "Person " << i + 1 << "\n";

        cout << "First Name: ";
        getline(cin, first);
        
        cout << "Last Name: ";
        getline(cin, last);

        cout << "Address: ";
        getline(cin, house);

        cout << "Height: ";
        cin >> heightLength;
        cin.ignore();

        cout << "Date of Birth: ";
        getline(cin, birthday);

        cout << "Gender: ";
        cin >> senumPersons;
        cin.ignore();

        personArray[i].setInfo(first, last, house, heightLength, birthday, senumPersons);

        first = "";
        last = "";
    }

    cout << "\nFinished Input. Outputting your array...\n";
    
    for (int i = 0; i < numPersons; i++) {
        personArray[i].print();
        cout << "\n";
    }

    delete[] personArray;

    return 0;
}