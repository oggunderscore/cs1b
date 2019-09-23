#ifndef STUDENTTYPE_H
#define STUDENTTYPE_H

#include <iostream>
#include "personType.h"

using namespace std;

class studentType : public personType{
    public:
        //constructors
        //studentType();
        

        //       fName, lName//
        studentType(string, string);

              // fName, lName, GPA, classification, id //
        studentType(string, string, double, string, string);
        
              
        //setters
        void setGPA(double);
        void setID(string);
        void setClassification(string);
        
        //getters
        double getGPA();
        string getID();
        string getClassification();
        
        //overridden methods
        void print() ; //override the parents' print method
        bool equals(studentType);
        
    private:
        string id; //added every id 'should' be unique
        double gpa;
        string classification;
        
};
//Create 5 people: 3 students and 2 persons(base class). Print all 5 "people".
//upload the .cpp and screenshot(s).

//+1 extra credit put the 3 students into a studentType array and the 2 persons into a personType array. 
//Then use for loops to call the print methods for these objects when printing.
#endif