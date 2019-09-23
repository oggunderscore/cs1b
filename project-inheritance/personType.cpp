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
	private:
		string fName;
		string lName;
		string address;
		string dob;
		double height;
		char gender;
	public:
		bool personType::equals(personType toCompare) {
		    if (getFName() == toCompare.getFName()
		        && getLName() == toCompare.getLName()
		        && getAddress() == toCompare.getAddress()
		        && getHeight() == toCompare.getHeight()
		        && getDob() == toCompare.getDob()
		        && getGender() == toCompare.getGender()) {
        	return true;
		    } else {
		        return false;
		    }
		}
		/***************** Constructors *********************/
		personType::personType() {
			//NOTE: I set the default gender to be X since '/0' obviously won't print anything
			setInfo("DEFAULT-FIRST-NAME", 
			        "DEFAULT-LAST-NAME", 
					"DEFAULT-ADDRESS", 
					0, 
					"DEFAULT-DATE-OF-BIRTH", 
					'X');
		}

		personType::personType(string fName, string cName) {
			setInfo(fName, 
			        cName, 
					"DEFAULT-ADDRESS", 
					0, 
					"DEFAULT-DATE-OF-BIRTH", 
					'X');
		}

		personType::personType(string fName, string cName, string address, 
		           double height, string dob, char gender) {
			setInfo(fName, cName, address, height, dob, gender);     
		}
		/***************** Mutator Functions *********************/

		string personType::setFname(string initFName) {
			fName = initFName; 
		}

		string personType::setLName(string initLName) {
			lName = initLName;
		}

		string personType::setAddress(string initAddress) {
			address = initAddress;
		}

		double personType::setHeight(double initHeight) {
			height = initHeight;
		}

		string personType::setDob(string initDob) {
			dob = initDob;
		}
		
		char personType::setGender(char initGender) {
			gender = initGender;
		}

		void personType::setInfo(string initFName, string initLName, string initAddress,
			           double initHeight, string initDob, char initGender) {
			fName = initFName;
			lName = initLName;
			address = initAddress;
			dob = initDob;
			height = initHeight;
			gender = initGender;
		}

		/********************* Accessor Functions *********************/

		string personType::getFName() {
			return fName;
		}

		string personType::getLName() {
			return lName;
		}

		string personType::getAddress() {
			return address;
		}

		double personType::getHeight() {
			return height;
		}

		string personType::getDob() {
			return dob;
		}
		
		char personType::getGender() {
			return gender;
		}

		void personType::print() {
			cout << fixed;
			cout.precision(2);
			cout << "Name: " << getFName() << " " << getLName() << "\n"
			     << "Address: " << getAddress() << "\n"
					 << "Height: " << getHeight() << " inches" << "\n"
					 << "Date of Birth: " << getDob() << "\n"
					 << "Gender: " << getGender() << "\n\n";
		}
};
