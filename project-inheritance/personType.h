//--------------------------------------------------------------------------
//  File name: personType.h
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
#ifndef PERSONTYPE_H
#define PERSONTYPE_H

#include <iostream>

using namespace std;

class personType {
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
        bool equals (personType);

        /***************** Constructors *********************/

        personType();
        personType(string, string);
        personType(string, string, string, 
		           double, string, char);

       /***************** Mutator Functions *********************/

        void setFname(string);
        void setLname(string);
        void setAddress(string);
        void setHeight(double);
        void setDob(string);
        void setGender(char);
        void setInfo(string, string, string, 
		           double, string, char);

       /********************* Accessor Functions *********************/                   

        string getFName();
        string getLName();
        string getAddress();
        double getHeight();
        string getDob();
        char getGender();

        void print();
    private:
        string fName;
		string lName;
		string address;
		string dob;
		double height;
		char gender;
};

#endif

