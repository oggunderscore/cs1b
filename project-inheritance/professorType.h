//--------------------------------------------------------------------------
//  File name: professorType.h
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
#ifndef PROFESSORTYPE_H
#define PROFESSORTYPE_H

#include <iostream>
#include "personType.h"

using namespace std;

class professorType : public personType{
    public:
        //--------------------------------------------------------------------------
	    // DATA DICTIONARY
	    //--------------------------------------------------------------------------
	    // VARIABLES
	    //
	    //   NAME              DATA TYPE         VALUE
	    //--------------------------------------------------------------------------
	    //    employeeID         string           null
        //    department         string           null
        //    degree             string           null
	    //--------------------------------------------------------------------------

        /***************** Constructors *********************/
        
        professorType();

        //fName, lName
        professorType(string, string);

        // fName, lName, employeeID, department, degree
        professorType(string, string, string, string, string);

        //super constructor including all personType attributes
        professorType(string, string, string, double, string, 
                    char, string, string, string);
        
              
        /***************** Mutator Functions *********************/

        void setEmployeeID(string);
        void setDepartment(string);
        void setDegree(string);
        void setInfo(string, string, string);
        
        /********************* Accessor Functions *********************/ 

        string getEmployeeID();
        string getDepartment();
        string getDegree();
        
        /********************* Override Functions *********************/ 

        void print() ; //override the parents' print method
        bool equals(professorType);
        
    private:
        string employeeID; //added every id 'should' be unique
        string department;
        string degree;
        
};
#endif