#include <iostream>
#include <iomanip>
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

int lookUpPlayer (playerType team[]);
void printPlayer (playerType team[], int index);
void readFile(playerType team[]);

int main () { 
    int index = 0; 
    char choice;
    char reply;
    bool exit = false; 

    playerType team[SIZE];
    
    system("clear");

    readFile(team);

    cout << "Press any key to continue...";
    cin >> reply;

    do {
        system("clear");
        cout << "\t\t\t\t     **********************************\n";
        cout << "\t\t\t\t     *     Assignment A5: Structs     *\n";
        cout << "\t\t\t\t     *                                *\n";
	    cout << "\t\t\t\t     * <1> Look Up a Player           *\n";
        cout << "\t\t\t\t     * <2> Edit a Player              *\n";
        cout << "\t\t\t\t     * <3> Print Team Roster          *\n";
        cout << "\t\t\t\t     * <4> To Quit                    *\n";
        cout << "\t\t\t\t     **********************************\n";
        cout << "\t\t\t\t     * Choice: ";

        cin >> choice; 

        switch (choice) {
            case '1':
                cout << lookUpPlayer(team);
                break; 
            case '2':
                //edit()
                break;
            case '3':
                system("clear");
                cout << index;
                printPlayer(team, index);
                cout << "\nPress any key to continue...";
                cin >> reply;
                break;
            case '4':
                exit = true; 
                system("clear");
                break;
        }
    } while (!exit);
    
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

int lookUpPlayer (playerType team[]) { 
    string searchName;
    string temp; 

    cout << "\nSearch: "; 
    getline(cin, searchName);

    for (int index = 0; index < searchName.length(); index++) {
			searchName[index] = tolower(searchName[index]);
    }

    for (int index = 0; index < SIZE; index++) { 
        for (int indexInner = 0; indexInner < team[index].playerName.length(); indexInner++) {
            temp.append(1, tolower(team[index].playerName.at(indexInner)));
        }
        if (temp.find(searchName) != string::npos) {
            cout << "Player Found!\n";
            return index; 
            cout << "\n";
        }
    }
    cout << "\nPlayer Not Found!\n";
    return -1;
}

// //printPlayer is a void fn, that that takes a playerType variable by value and prints a single players' record.

void printPlayer (playerType team[], int index) {
    cout << " ---------------------------------------------------------------------\n"
     << team[0].playerName
     << "\t\t\t" + team[index].playerPosition
     << "\t"   
     << team[index].numTouchdowns
     << "\t"   
     << team[index].numCatches
     << "\t"   
     << team[index].numPassYards
     << "\t" 
     << team[index].numRecieveYards
     << "\t"  
     << team[index].numRushYards;
}

// //printTeam, is a void fn, takes the entire array and calls printPlayer for each record.

// void printTeam () {

// }

//readFile, is a void fn which populates the array from a file "input.txt" make it local

void readFile (playerType team[]) { 
    ifstream inFile; 
    int playerCount = 0;

    inFile.open("input.txt");
    cout << "Reading input.txt\n";
    
    for (int index = 0; index < SIZE; index++) {
        getline(inFile, team[index].playerName);
        getline(inFile, team[index].playerPosition);
        inFile >> team[index].numTouchdowns;
        inFile >> team[index].numCatches;
        inFile >> team[index].numPassYards;
        inFile >> team[index].numRecieveYards;
        inFile >> team[index].numRushYards;

        //simnple solution to capturing 1 word and then a \n
        // the 2 ensures the data is captured and the newline is consumed

        inFile.ignore(2, '\n');
        // cout << "INDEX:" << index << "\n";
        // cout << "LOG:" << team[index].playerName << "\n";
        // cout << "LOG:" << team[index].playerPosition << "\n";
        // cout << "LOG:" << team[index].numTouchdowns << "\n";
        // cout << "LOG:" << team[index].numCatches << "\n";
        // cout << "LOG:" << team[index].numPassYards << "\n";
        // cout << "LOG:" << team[index].numRecieveYards << "\n";
        // cout << "LOG:" << team[index].numRushYards << "\n";

        //inFile.ignore();
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