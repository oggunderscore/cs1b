//--------------------------------------------------------------------------
//  File name: arrays.cpp
//  Project name: Copy Constructors
//--------------------------------------------------------------------------
//  Creator's name and email: Felix Murray felix.murray@gmail.com
//  Course Selection: CS1B
//  Creation Date: 9/20/19
//  Date of Last Modification: 10/19
//--------------------------------------------------------------------------
//  Purpose: This program will create 4 people:
//           (1 personType, 2 studentType, 1 professorType)
//           and output each of them to the console.
//--------------------------------------------------------------------------
//  Algorithm: 
//      Step 1: Prompt user Initialize the personType, studentType, and 
//              professorType variables and clear the console. 
//      Step 2: Set the information for the variables using relevent 
//              constructors.
//      Step 3: Print out the variables using the print function.
//--------------------------------------------------------------------------
#include <iostream>
#include "personType.h"
#include "studentType.h"
#include "professorType.h"

using namespace std;

int main()
{
    //--------------------------------------------------------------------------
	// DATA DICTIONARY
	//--------------------------------------------------------------------------
	// VARIABLES
	//
	//   NAME                    DATA TYPE             VALUE
	//--------------------------------------------------------------------------
	//  first	                  string			   null
	//  last                      string               null
	//  house                     string               null
	//  birthday                  string               null
	//  heightLength              double               null
	//  identifcation             string   			   null
    //  grade                     double               null
    //  classLevel                string               null
    //  employeeIdentification    string               null
    //  subject                   string               null
    //  diploma                   string               null
    //  personGender              char                 null
    //  personChoice              char                 null
    //  valid                     bool                 false
    //  numPersons                int                  null
	//--------------------------------------------------------------------------
    bool valid = false;
    int numPersons;
    string first;
    string last;
    string house;
    string birthday;
    string identification;
    double grade;
    string classLevel;
    string employeeIdentification;
    string subject;
    string diploma;
    double heightLength;
    char personGender;
    char personChoice;

    system("clear");
    cout << "Enter the number of people you wish to create: ";
    cin >> numPersons;
    cin.ignore();
    cout << "\n";

    personType **personArray = new personType *[numPersons];

    for (int i = 0; i < numPersons - 1; i++)
    {
        while (!valid)
        {
            system("clear");

            cout << "Current Size: " << i << " (Max: " << numPersons << ")\n\n"
                 << "1. Create Person\n"
                 << "2. Create Student\n"
                 << "3. Create Professor\n"
                 << "> ";
            cin >> personChoice;
            cin.ignore();

            switch (personChoice) {
                case '1': 
                case '2':
                case '3':
                    valid = true;
                    break;
                default:
                    system("clear");
                    valid = false;
                    cout << "ERROR: Please enter a value 1-3\n";
                    system("read -n 1 -s -p \"Press any key to continue...\"");
                    break;
            }
        }

        valid = false;

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
        cin >> personGender;
        cin.ignore();

        switch (personChoice)
        {
        case '1':
            personArray[i] = new personType(first,
                                            last,
                                            house,
                                            heightLength,
                                            birthday,
                                            personGender);
            break;
        case '2':
            cout << "GPA: ";
            cin >> grade;
            cin.ignore();

            cout << "Class Standing (e.g. Freshmen, etc.): ";
            getline(cin, classLevel);

            cout << "ID Number: ";
            getline(cin, identification);

            personArray[i] = new studentType(first,
                                             last,
                                             house,
                                             heightLength,
                                             birthday,
                                             personGender,
                                             grade,
                                             classLevel,
                                             identification);
            break;
        case '3':
            cout << "Employee ID: ";
            getline(cin, employeeIdentification);

            cout << "Department: ";
            getline(cin, subject);

            cout << "Degree: ";
            getline(cin, diploma);

            personArray[i] = new professorType(first,
                                               last,
                                               house,
                                               heightLength,
                                               birthday,
                                               personGender,
                                               employeeIdentification,
                                               subject,
                                               diploma);
            break;
        }
    }

    cout << "\nFinished Input. Outputting your array...\n\n";

    personArray[0] -> setMother(personArray[1]);
	personArray[0] -> setFather(personArray[2]);

    personArray[3] = personArray[0];

    for (int i = 0; i < numPersons; i++)
    {
        personArray[i] -> print();
        cout << "\n";
    }

    delete[] personArray;

    return 0;
}