//--------------------------------------------------------------------------
//  File name: professorType.cpp
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
#include <string>
#include "personType.h"
#include "professorType.h"

using namespace std;

    //--------------------------------------------------------------------------
    //  Function: equals
    //--------------------------------------------------------------------------
    //  Purpose: Compares whether two professors are the same by looking at each
    //           attribute individually.
    //--------------------------------------------------------------------------
    bool professorType::equals(professorType professor) {
        if(getEmployeeID() == professor.getEmployeeID() 
            && getDepartment() == professor.getDepartment() 
            && getDegree() == professor.getDegree()
            ) {
            return true;
        } else {
            return false;
        } 
    }
    /***************** Constructors *********************/


    professorType::professorType(){
        professorType::setInfo("DEFAULT-EMPLOYEE-ID", "DEFAULT-DEPARTMENT", "DEFAULT-DEGREE");
    }

    professorType::professorType(string fName, string lName)
                :personType(fName, lName) {
        professorType::setInfo("DEFAULT-EMPLOYEE-ID", "DEFAULT-DEPARTMENT", "DEFAULT-DEGREE");
    }

    professorType::professorType(string nameF, string nameL, 
                                string id, 
                                string subject, string diploma)
                : personType(nameF, nameL) {
        professorType::setInfo(id, subject, diploma); 
    }

    professorType::professorType(string initFName, string initLName, string initAddress,
                                double initHeight, string initDob, 
                                char initGender, string id, 
                                string subject, string diploma)
                : personType(initFName, 
                                initLName, 
                                initAddress,
                                initHeight,
                                initDob, 
                                initGender) {
        professorType::setInfo(id, subject, diploma);
    }
    /***************** Mutator Functions *********************/

    void professorType::setInfo(string id, 
                                string subject, 
                                string diploma) {
        employeeID = id;
        department = subject;
        degree = diploma;
    }

    /********************* Accessor Functions *********************/

    string professorType::getEmployeeID() {
        return employeeID;
    }

    string professorType::getDepartment() {
        return department;
    }

    string professorType::getDegree() {
        return degree;
    }

    //--------------------------------------------------------------------------
    //  Function: print
    //--------------------------------------------------------------------------
    //  Purpose: Calls the professorType print() method and then outputs the ID, 
    //           Department, and Degree level of the professor to the console.
    //--------------------------------------------------------------------------
    void professorType::print() {
        personType::print();
        cout << "Employee ID: " << getEmployeeID() << "\n" << "Department: " << getDepartment() 
                << "\n" << "Degree: " << getDegree()
                << "\n"; 
    }


