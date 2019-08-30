#include <iostream>
#include <fstream>

using namespace std; 

int main () {
    const int TEST_LENGTH = 21;
    const int ID_LENGTH = 9;

    char filename[20];
    char answerKey[TEST_LENGTH];
    string studentID[ID_LENGTH];
    char studentAnswers[TEST_LENGTH];

    ifstream inFile; 

    cout << "Enter the filename (no more than 20 characters): ";
    cin >> filename; 
    inFile.open(filename);

    

    for (int index = 0; index < 20; index++){
        inFile >> answerKey[index];
    }

   

    inFile >> studentID[count];

    int count;

    while (inFile && !cin.fail()) {
        inFile >> studentAnswers
    }


    inFile.close();
    return 0; 
}