//--------------------------------------------------------------------------
//  File name: driver.cpp
//  Project name: Inheritance
//--------------------------------------------------------------------------
//  Creator's name and email: Felix Murray felix.murray@gmail.com
//  Course Selection: CS1B
//  Creation Date: 9/20/19
//  Date of Last Modification: 9/22/19
//--------------------------------------------------------------------------
//  Purpose: This program will hardcode 3 people of type studentType using 
//           the studentType class and inherit from the personType class
//           the attributes of a person. The program will then print out the
//           students and people and make comparisons amongst the 3 students 
//           to test the equals function override in studentType.
//--------------------------------------------------------------------------
//  Algorithm: 
//      Step 1: Initialize the personType, studentType variables 
//              and clear the console. 
//      Step 2: Set the information for the variables using relevent 
//              constructors.
//      Step 3: Print out the variables using the print function.
//      Step 4: Prompt the user to "Press any key to continue..." and clear
//              console once input has been recieved.
//--------------------------------------------------------------------------
#include <iostream>
#include "personType.h"
#include "studentType.h"

using namespace std; 

int main() {
    char reply;
    system("clear");

    studentType student1("Felix", "Murray", "25671 Good Street", 75.5, "5/11/2000", 'M', 3.4, "Sophmore", "1111499");
	studentType student2("Felix", "Murray", "25671 Good Street", 75.5, "5/11/2000", 'M', 3.4, "Sophmore", "1111499");
	studentType student3("John", "Smith", "2000 West Coast Road", 6.9, "12/12/1999", 'F', 3.8, "Senior", "1111111");
	personType person1("Donald", "Bain", "20201 Hollywood Avenue", 60.6, "2/20/1991", 'M');
	personType person2("Karen", "Spivak", "1 Space Park Blvd", 90.1, "1/1/1981", 'F');
	
	student1.print();
	//cout << "\n\n";
	student2.print();
	//cout << "\n\n";
	student3.print();
	//cout << "\n\n";
    person1.print();
    cout << "\n\n";

    cout << "Comparing student1 & student2..."
         << "\n";

	if (student1.equals(student2)) {
		cout << "These Students are the same person."
             << "\n\n";
	} else {
        cout << "These Students are different."
             << "\n\n";
    }

    cout << "Comparing student1 & student3..."
         << "\n";

    if (student1.equals(student3)) {
		cout << "These Students are the same person."
             << "\n\n";
	} else {
        cout << "These Students are different."
             << "\n\n";
    }

    cout << "Comparing student2 & student3..."
         << "\n";

    if (student2.equals(student3)) {
		cout << "These Students are the same person."
             << "\n";
	} else {
        cout << "These Students are different."
             << "\n\n";
    }

	cout << "Press any key to continue...";
	cin >> reply;
	system("clear");

    return 0;
}