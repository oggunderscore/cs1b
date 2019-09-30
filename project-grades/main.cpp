//--------------------------------------------------------------------------
//  File name: main.cpp 
//  Project name: Grades
//--------------------------------------------------------------------------
//  Creator's name and email: Felix Murray felix.murray@gmail.com
//  Course Selection: CS1B
//  Creation Date: 8/27/19
//  Date of Last Modification: 8/28/19
//--------------------------------------------------------------------------
//  Purpose: This program will take in file input for student test scores 
//           and compare each student's scores to the answer key to determine
//           their percentage grade and then letter grade. 
//--------------------------------------------------------------------------
//  Algorithm: 
//      Step 1: Recieve file input.
//      Step 1.5: Populate answerKey with first line of file. 
//      Step 2: Populate parallel arrays with student IDs, student answers.
//      Step 3: Compare student answers to answer key and calculate percent
//              score.
//      Step 4: Convert percent to letter grade. 
//      Step 5: Output file information and student scores & grades to 
//              console.
//--------------------------------------------------------------------------
#include <iostream>
#include <fstream>

#define TOTAL_TESTS 150

using namespace std; 

int main () {
    //--------------------------------------------------------------------------
	// DATA DICTIONARY
	//--------------------------------------------------------------------------
	// CONSTANTS
	//
	//   NAME              DATA TYPE         VALUE
	//--------------------------------------------------------------------------
	//  FILE_NAME           string       "Ch8_Ex6Data.txt"
	//--------------------------------------------------------------------------
    // VARIABLES
    //
    //   NAME              DATA TYPE         VALUE
    //--------------------------------------------------------------------------
    //    answerKey         string             unitialized
    //    studentIDs      string array         unitialized
    //    studentAnswers  string array         unitialized
    //    studentScores   int array            unitialized
    //    studentGrades   char array           unitialized
    //    studentIndex        int                   0
    //    id                string                  ""
    //    answers           string                  ""
    //    percent           float               unitialized
    //--------------------------------------------------------------------------

    const string FILE_NAME = "Ch8_Ex6Data.txt"; 

    string wholeLine;

    string answerKey;
    string studentIDs[TOTAL_TESTS];
    string studentAnswers[TOTAL_TESTS];
    int studentScores[TOTAL_TESTS];
    char studentGrades[TOTAL_TESTS];
    int studentIndex = 0;

    ifstream inFile; 

    inFile.open(FILE_NAME);

    getline(inFile, answerKey);

    while (getline(inFile, wholeLine)) { 
        string id = "";
        string answers = "";
        bool collectAnswers = false;

        for (int index = 0; index < wholeLine.length(); index++) { 
            if (!collectAnswers) {
                //collect id
                id += wholeLine[index];

                if (index + 1 < wholeLine.length() && wholeLine[index + 1] == ' ') {
                    index++;
                    collectAnswers = true;
                }
            } else { 
                //collect answers
                answers += wholeLine[index];
            }
        }

        studentIDs[studentIndex] = id;
        studentAnswers[studentIndex] = answers; 
        studentIndex++;
    }
    system("clear");
    cout << "Processing Data\n"; 
    cout << "Key: " << answerKey << "\n";

    for (int testIndex = 0; testIndex < TOTAL_TESTS; testIndex++) {
        int correctAnswers;
        if (studentIDs[testIndex] != "") { 
            correctAnswers = 0;
            float percent;
            for (int answerIndex = 0; answerIndex < answerKey.length(); answerIndex++) {
                if (studentAnswers[testIndex][answerIndex] == answerKey[answerIndex]) {
                    correctAnswers += 2;
                    //cout << "RIGHT " << correctAnswers << "\n";
                } else if (studentAnswers[testIndex][answerIndex] != ' ') {
                    correctAnswers--;
                    //cout << "WRONG " << correctAnswers << "\n";
                }  
            }

            percent = (correctAnswers / answerKey.length()) * 100;
            //cout << "AFTER FOR " << correctAnswers << "\n";
            if (percent < 60.0) {
                studentGrades[testIndex] = 'F';
            } else if (percent < 70.0) { 
                studentGrades[testIndex] = 'D';
            } else if (percent <  80.0 ) {
                studentGrades[testIndex] = 'C';
            } else if (percent <  90.0) { 
                studentGrades[testIndex] = 'B';
            } else {
                studentGrades[testIndex] = 'A';
            }

            
            cout << studentIDs[testIndex] << " " 
                 << studentAnswers[testIndex] << " " 
                 << correctAnswers << " "; 
            cout << studentGrades[testIndex] << "\n";
        }
    }

    inFile.close();
    return 0; 
}
