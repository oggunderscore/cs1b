//--------------------------------------------------------------------------
//  File name: studentType.h
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
#ifndef STUDENTTYPE_H
#define STUDENTTYPE_H

#include <iostream>
#include "personType.h"

using namespace std;

class studentType : public personType{
    public:
        //--------------------------------------------------------------------------
	    // DATA DICTIONARY
	    //--------------------------------------------------------------------------
	    // VARIABLES
	    //
	    //   NAME              DATA TYPE         VALUE
	    //--------------------------------------------------------------------------
	    //    id                 string           null
        //    gpa                double           null
        // classification        string           null
	    //--------------------------------------------------------------------------

        /***************** Constructors *********************/
        
        studentType();

        //fName, lName
        studentType(string, string);

        // fName, lName, GPA, classification, id
        studentType(string, string, double, string, string);

        studentType(string, string, string, double, string, 
                    char, double, string, string);
        
              
        /***************** Mutator Functions *********************/

        void setGPA(double);
        void setID(string);
        void setClassification(string);
        void setInfo(double, string, string);
        
        /********************* Accessor Functions *********************/ 

        double getGPA();
        string getID();
        string getClassification();
        
        /********************* Override Functions *********************/ 

        void print() ; //override the parents' print method
        bool equals(studentType);
        
    private:
        string id; //added every id 'should' be unique
        double gpa;
        string classification;
        
};
#endif