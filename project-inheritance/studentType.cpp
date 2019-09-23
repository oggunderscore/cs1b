//--------------------------------------------------------------------------
//  File name: studentType.cpp
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
#include <string>
#include "studentType.h"
#include "personType.h"

using namespace std;

    //--------------------------------------------------------------------------
    //  Function: equals
    //--------------------------------------------------------------------------
    //  Purpose: Compares whether two students are the same by looking at each
    //           attribute individually.
    //--------------------------------------------------------------------------
    bool studentType::equals(studentType student) {
        if(getGPA() == student.getGPA() 
            && getID() == student.getID() 
            && getClassification() == student.getClassification()
            ) {
            return true;
        } else {
            return false;
        } 
    }
    /***************** Constructors *********************/


    studentType::studentType(){
        studentType::setInfo(0.0, "DEFAULT-STANDING", "DEFAULT-ID");
    }

    studentType::studentType(string fName, string lName)
                :personType(fName, lName) {
        studentType::setInfo(0.0, "DEFAULT-STANDING", "DEFAULT-ID");
    }

    studentType::studentType(string nameF, string nameL, 
                                double grade, 
                                string standing, string identify)
                : personType(nameF, nameL) {
        studentType::setInfo(grade, standing, identify);    
    }

    studentType::studentType(string initFName, string initLName, string initAddress,
                                double initHeight, string initDob, 
                                char initGender, double grade, 
                                string standing, string identify)
                : personType(initFName, 
                                initLName, 
                                initAddress,
                                initHeight,
                                initDob, 
                                initGender) {
        studentType::setInfo(grade, standing, identify);
    }
    /***************** Mutator Functions *********************/

    void studentType::setInfo(double grade, 
                                string standing, 
                                string identify) {
        gpa = grade;
        classification = standing;
        id = identify;	
    }

    /********************* Accessor Functions *********************/

    double studentType::getGPA() {
        return gpa;
    }

    string studentType::getID() {
        return id;
    }

    string studentType::getClassification() {
        return classification;
    }

    //--------------------------------------------------------------------------
    //  Function: print
    //--------------------------------------------------------------------------
    //  Purpose: Calls the personType print() method and then outputs the ID, 
    //           GPA, and Classification of the student to the console.
    //--------------------------------------------------------------------------
    void studentType::print() {
        personType::print();
        cout << fixed;
        cout.precision(2);
        cout << "ID: " << getID() << "\n" << "GPA: " << getGPA() 
                << "\n" << "Classification: " << getClassification()
                << "\n\n"; 
    }

