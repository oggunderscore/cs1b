//--------------------------------------------------------------------------
//  File name: personType.cpp
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

using namespace std;

	
    //--------------------------------------------------------------------------
    //  Function: equals
    //--------------------------------------------------------------------------
    //  Purpose: Compares whether two people are the same by looking at each
    //           attribute individually.
    //--------------------------------------------------------------------------
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

	void personType::setFname(string initFName) {
		fName = initFName; 
	}

	void personType::setLname(string initLName) {
		lName = initLName;
	}

	void personType::setAddress(string initAddress) {
		address = initAddress;
	}

	void personType::setHeight(double initHeight) {
		height = initHeight;
	}

	void personType::setDob(string initDob) {
		dob = initDob;
	}
	
	void personType::setGender(char initGender) {
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

	string personType::personType::getLName() {
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

	//--------------------------------------------------------------------------
    //  Function: print
    //--------------------------------------------------------------------------
    //  Purpose: Outputs a person's name, address, height, date of birth, and 
	//           gender to the console.
    //--------------------------------------------------------------------------
	void personType::print() {
		cout << fixed;
		cout.precision(2);
		cout << "Name: " << getFName() << " " << getLName() << "\n"
				<< "Address: " << getAddress() << "\n"
					<< "Height: " << getHeight() << " inches" << "\n"
					<< "Date of Birth: " << getDob() << "\n"
					<< "Gender: " << getGender() << "\n";
	}
