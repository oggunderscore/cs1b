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
		bool equals(personType toCompare) {
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
		// 1. default constructor that takes no parameters
		// 2. constructor which is only passed first name and last name
		// 3. constructor which is passed all the data members.
		// 4. Create a driver program that creates 3 different people using the 
		//    3 different constructors. After creating the 3 different people, neatly print them.
		personType() {
			//NOTE: I set the default gender to be X since '/0' obviously won't print anything
			setInfo("DEFAULT-FIRST-NAME", 
			        "DEFAULT-LAST-NAME", 
					"DEFAULT-ADDRESS", 
					0, 
					"DEFAULT-DATE-OF-BIRTH", 
					'X');
		}

		personType(string fName, string cName) {
			setInfo(fName, 
			        cName, 
					"DEFAULT-ADDRESS", 
					0, 
					"DEFAULT-DATE-OF-BIRTH", 
					'X');
		}

		personType(string fName, string cName, string address, 
		           double height, string dob, char gender) {
			setInfo(fName, cName, address, height, dob, gender);     
		}
		/***************** Mutator Functions *********************/

		void setInfo(string initFName, string initLName, string initAddress,
			           double initHeight, string initDob, char initGender) {
			fName = initFName;
			lName = initLName;
			address = initAddress;
			dob = initDob;
			height = initHeight;
			gender = initGender;
		}

		/********************* Accessor Functions *********************/

		string getFName() {
			return fName;
		}

		string getLName() {
			return lName;
		}

		string getAddress() {
			return address;
		}

		double getHeight() {
			return height;
		}

		string getDob() {
			return dob;
		}
		
		char getGender() {
			return gender;
		}

		void print() {
			cout << fixed;
			cout.precision(2);
			cout << "Name: " << getFName() << " " << getLName() << "\n"
			     << "Address: " << getAddress() << "\n"
					 << "Height: " << getHeight() << " inches" << "\n"
					 << "Date of Birth: " << getDob() << "\n"
					 << "Gender: " << getGender() << "\n\n";
		}
};

int main() {
	//--------------------------------------------------------------------------
	// DATA DICTIONARY
	//--------------------------------------------------------------------------
	// VARIABLES
	//
	//   NAME              DATA TYPE               VALUE
	//--------------------------------------------------------------------------
	//  reply              char                     null 
	//  person	           personType		  (see below call)
	//  firstCompare       personType         (see below call)
	//  secondCompare      personType         (see below call)
	//  thirdCompare       personType         (see below call)
    //  fourthCompare      personType         (see below call)
	//--------------------------------------------------------------------------
	char reply; 

	//OLD SETTER PERSONTYPES
	// personType person;
	// personType firstCompare;
	// personType secondCompare;
	// personType thirdCompare;
	// personType fourthCompare;

	personType normal; 
	personType names("John", "Smith"); 
	personType all("Felix", "Murray", 
	               "1600 Pennsylvania Avenue", 
				    74.40, "05/11/2000", 'M');

	system("clear");

	normal.print(); 
	names.print(); 
	all.print();

	//OLD PRINT
	// person.setInfo("Felix", "Murray", "1600 Pennsylvania Avenue", 74.40, "05/11/2000", 'M');
	// person.print();

	// person.setInfo("John", "Smith", "2 Space Park", 50.33, "08/23/1987", 'M');
	// person.print();

	// firstCompare = person;

	// person.setInfo("Alicia", "Hernandez", "54 Western Avenue", 80.00, "01/14/1998", 'F');
	// person.print();

	// secondCompare = person;

	// person.setInfo("Napolean", "Bonaparte", "150 France Street", 30.00, "08/15/1769", 'M');
	// person.print();

	// thirdCompare = person;
	// fourthCompare = thirdCompare;

	// person.setInfo("Gabe", "Newell", "10400 NE 4th Sreet", 60, "11/03/1962", 'M');
	// person.print();

	// if (firstCompare.equals(secondCompare)) {
	// 	cout << firstCompare.getFName() << " and " 
	// 	    << secondCompare.getFName() << " are the same person." << "\n\n";
	// } else {
	//     cout << firstCompare.getFName() << " and " 
	// 	     << secondCompare.getFName() << " are NOT the same person." << "\n\n";
	// }

	// if (thirdCompare.equals(fourthCompare)) {
	// 	cout << thirdCompare.getFName() << " and " 
	// 	     << fourthCompare.getFName() << " are the same person." << "\n\n";
	// } else {
	//     cout << thirdCompare.getFName() << " and " 
	// 	     << fourthCompare.getFName() << " are NOT the same person." << "\n\n";
	// }

	cout << "\nPress any key to continue...";
	cin >> reply;

	if (reply != '\0') {
			system("clear");
			return 0;
	}
}
