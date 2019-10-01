//--------------------------------------------------------------------------
//  File name: driver.cpp
//  Project name: Inheritance
//--------------------------------------------------------------------------
//  Creator's name and email: Felix Murray felix.murray@gmail.com
//  Course Selection: CS1B
//  Creation Date: 9/20/19
//  Date of Last Modification: 9/22/19
//--------------------------------------------------------------------------
//  Purpose: This program will create 5 people:
//           (1 personType, 2 studentType, 2 professorType)
//           and output each of them to the console as well as calling the 
//           equals() function on the 2 students.
//--------------------------------------------------------------------------
//  Algorithm: 
//      Step 1: Initialize the personType, studentType, and professorType 
//       variables and clear the console. 
//      Step 2: Set the information for the variables using relevent 
//              constructors.
//      Step 3: Print out the variables using the print function.
//      Step 4: Prompt the user to "Press any key to continue..." and clear
//              console once input has been recieved.
//--------------------------------------------------------------------------
#include <iostream>
#include "personType.h"
#include "studentType.h"
#include "professorType.h"

using namespace std; 

int main() {
    char reply;
    system("clear");

    studentType student1("Felix", "Murray", "25671 Good Street", 75.5, "5/11/2000", 'M', 3.4, "Sophmore", "1111499");
    studentType student2("Jude", "McCartney", "Penny Lane", 40.5, "4/13/1969", 'F', 2.6, "Junior", "46638596");
    personType person1("Donald", "Bain", "20201 Hollywood Avenue", 60.6, "2/20/1991", 'M');
    professorType professor1("Jedidiah", "Smith", "28000 Maggy Pkwy", 85.5, "2/16/1999", 'M', "11413431", "Humanities", "Master's of Arts");
    professorType professor2("Jedidiah", "Smith", "28000 Maggy Pkwy", 85.5, "2/16/1999", 'M', "11413431", "Humanities", "Master's of Arts");
	
	student1.print();
	student2.print();
	person1.print();
    cout << "\n";
    professor1.print();
    professor2.print();

    cout << "Comparing student1 & student2..."
         << "\n";

	if (student1.equals(student2)) {
		cout << "These Students are the same person."
             << "\n\n";
	} else {
        cout << "These Students are different."
             << "\n\n";
    }

    cout << "Comparing professor1 & professor2..."
         << "\n";

    if (professor1.equals(professor2)) {
		cout << "These Professors are the same person."
             << "\n\n";
	} else {
        cout << "These Professors are different."
             << "\n\n";
    }

	 #ifdef _WIN32
        // pause on windows
        system("pause");
    #else
        // on unix systems, read one character and then continue
        system("read -n 1 -s -p \"Press any key to continue...\"");
    #endif
	system("clear");

    return 0;
}
