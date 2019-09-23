//--------------------------------------------------------------------------
//  File name: main.cpp
//  Project name: Constructors
//--------------------------------------------------------------------------
//  Creator's name and email: Felix Murray felix.murray@gmail.com
//  Course Selection: CS1B
//  Creation Date: 9/13/19
//  Date of Last Modification: 9/15/19
//--------------------------------------------------------------------------
//  Purpose: This program will hardcode 5 people of type personType using 
//           the personType class and print their relevent information 
//           (name, address, DOB, height, and gender). The program will then
//           make to comparisons between 2 different people and the same 
//           person to test the equals function.
//--------------------------------------------------------------------------
//  Algorithm: 
//      Step 1: Initialize the personType variables and clear the console. 
//      Step 2: Set the information for the personType variables using the 
//              three constructors.
//      Step 3: Print out the 3 personType variables using print function.
//      Step 4: Prompt the user to "Press any key to continue..." and clear
//              console once input has been recieved.
//--------------------------------------------------------------------------
#include <iostream>
#include <string>
#include "studentType.h"
#include "personType.h"

using namespace std;



class studentType : public personType {
	//--------------------------------------------------------------------------
	// DATA DICTIONARY
	//--------------------------------------------------------------------------
	// VARIABLES
	//
	//   NAME              DATA TYPE         VALUE
	//--------------------------------------------------------------------------
	//  fName	           string				null
	//  lName              string               null
	//  address            string               null
	//  dob                string               null
	//  height             double               null
	//  gender              char   			    null
	//--------------------------------------------------------------------------
	public:
		bool studentType::equals(studentType student) {
            if(personType::equals(student)
               && getGPA() == student.getGPA() 
               && getID() == student.getID() 
               && getClassification() == student.getClassification()
              ) {
				cout << "These students are the same person." << endl;
				return true;
			} else {
                cout << "These students are the same person." << endl;
            } 
		}
		/***************** Constructors *********************/


        studentType::studentType(){
            studentType::setInfo(0.0, "DEFAULT-STANDING", "DEFAULT-ID");
        }

		studentType::studentType(string fName, string lName)
                    :personType(fName, lName) {
            studentType::studentType();
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

		void studentType::print() {
			personType::print();
            cout << fixed;
			cout.precision(2);
			cout << "ID: " << getID() << "\n" << "GPA: " << getGPA() 
                 << "\n" << "Classification: " << getClassification()
                 << "\n\n"; 
		}

    private:
	    string id; //added every id 'should' be unique
        double gpa;
        string classification;
};
