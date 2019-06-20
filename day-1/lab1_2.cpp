//Enter Your name: Tom Lee 
//Enter your age: 21
//OUTPUT: Tom Lee is 21 years old

#include <string>
#include <iostream>

using namespace std; 

/* 
int main () {
    string name; 
    int age; 

    getInfo(name, age);
    showInfo(name, age);
    
    return 0; 
}

void getInfo (string &name, int &age) {
    cout << "Enter your name: ";
    getline (cin, name);
    cout << "Enter your age: ";
}

void showInfo (string name, int age) {
    cout << name << " is " << age << " years old.\n\n"; 
}

*/





int main () {
    int x = 4;
    int y = 42;

    cout << x; // say 4
    cout << x; // say 42
    add_2_by_reference(x, y);
    cout << x; // say 8
    cout << y; // say 44

    add_2_by_value(x, y);

    phonebook book; // has 1000000000000 people in it

    sort_phonebook(book);
    search_phonebook(sorted_book);
}

//pass by reference - access given to modify the variable (x, see above)
int add_2_by_reference (int &x, int &y) {
    x = x + 2;
    y = y + 2;
}

//pass by value - *copies* value of the variable
int add_2_by_value (int x, int y) {
    // how do you return multiple things???
}

void sort_phonebook (phonebook &book) {
    // sort book....
}

//pass by reference without changing value
void search_phonebook (const phonebook &book) {
    // search
}

//C++ doesn't round, it chops off past decimal
int x = 4 / 6;

(4.0 / 6.0)

// fixed point to 5 decimal places:
5.00000
6.23472

10101010101010101011010101010 | 000000000000

// floating point:
128937192837.12387912387238947239847

//double precision floating point
double x = 0.1283712837812738127381273812731287











