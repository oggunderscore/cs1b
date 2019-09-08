#include <iostream>
#include <fstream> 
#include <string> 

#define SIZE 10

using namespace std; 



struct playerType {
    string playerName;
    string playerPosition;
    int numTouchdowns;
    int numCatches;
    float numPassYards;
    float numRecieveYards;
    float numRushYards;
};

void readFile(playerType team[]);

int main () { 
    char choice;
    bool exit = false; 

    playerType team[SIZE];
    
    system("clear");
    readFile(team);

    // do {
    //     system("clear");
    //     cout << "\t\t\t\t     **********************************\n";
    //     cout << "\t\t\t\t     *     Assignment A5: Structs     *\n";
    //     cout << "\t\t\t\t     *                                *\n";
	//     cout << "\t\t\t\t     * <1> Look Up a Player           *\n";
    //     cout << "\t\t\t\t     * <2> Edit a Player              *\n";
    //     cout << "\t\t\t\t     * <3> Print Team Roster          *\n";
    //     cout << "\t\t\t\t     * <4> To Quit                    *\n";
    //     cout << "\t\t\t\t     **********************************\n";
    //     cout << "\t\t\t\t     * Choice: ";

    //     cin >> choice; 

    //     switch (choice) {
    //         case '1':
    //             //lookUp()
    //             break; 
    //         case '2':
    //             //edit()
    //             break;
    //         case '3':
    //             //print()
    //             break;
    //         case '4':
    //             exit = true; 
    //             system("clear");
    //             break;
    //     }
    // } while (!exit);
    
    return 0; 
}

// //editPlayer: is a void fn, which takes an array of playerType and 
// //calls lookUpPlayer which returns the index of the target (-1 if not found). 
// //If found allows the user to edit any of the data members of the player via a menu system.

// void editPlayer () {

// }

// //lookUpPlayer: is a int fn, which takes an array of playerTypes, 
// //prompts the user for the name of the player and attempts to find them. 
// //If found, prints message "found" and returns the index, otherwise prints "not found" 
// //and returns -1. 
// //** Extra credit 2 pts if you make it case insensitive and substrings work (i.e. "lex" is found in the string "Lexacon".

// int lookUpPlayer () { 

// }

// //printPlayer is a void fn, that that takes a playerType variable by value and prints a single players' record.

// void printPlayer () {

// }

// //printTeam, is a void fn, takes the entire array and calls printPlayer for each record.

// void printTeam () {

// }

//readFile, is a void fn which populates the array from a file "input.txt" make it local

void readFile (playerType team[]) { 
    ifstream inFile; 
    int index = 0;
    int playerCount = 0;

    inFile.open("input.txt");
    cout << "Reading input.txt\n";

    for (int index = 0; index < SIZE; index++) {
        inFile.ignore();
        getline(inFile, team[index].playerName);
        getline(inFile, team[index].playerPosition);
        inFile >> team[index].numTouchdowns;
        inFile >> team[index].numCatches;
        inFile >> team[index].numPassYards;
        inFile >> team[index].numRecieveYards;
        inFile >> team[index].numRushYards;
        inFile.ignore();
        // cout << "Player " << index + 1 << ". Name: " << team[index].playerName << "\n";
        // cout << "Player " << index + 1 << ". Pos: " << team[index].playerPosition << "\n";
        // cout << "Player " << index + 1 << ". TD: " << team[index].numTouchdowns << "\n";
        // cout << "Player " << index + 1 << ". C: " << team[index].numCatches << "\n";
        // cout << "Player " << index + 1 << ". PY: " << team[index].numPassYards << "\n";
        // cout << "Player " << index + 1 << ". RY: " << team[index].numRecieveYards<< "\n";
        // cout << "Player " << index + 1 << ". Rush: " << team[index].numRushYards<< "\n";

        playerCount++;
    }

    cout << "\n";

    for (int index = 0; index < playerCount; index++) {
        cout << "Counted Player: " << index + 1 << ". Name: " << team[index].playerName << "\n";
    }

    cout << "\nRead File input.txt Successfully.\n\n";
    inFile.close();
}

//writeFile, is a void fn which saves the database to "output.txt"

// void writeFile () {

// }