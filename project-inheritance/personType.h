#ifndef PERSONTYPE_H
#define PERSONTYPE_H

#include <iostream>

using namespace std;

class personType {
    public: 
        bool equals (personType);
        personType();
        personType(string, string);
        personType(string, string, string, 
		           double, string, char);
        string setFname(string);
        string setLname(string);
        string setAddress(string);
        double setHeight(double);
        string setDob(string);
        char setGender(char);
        void setInfo(string, string, string, 
		           double, string, char);
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

