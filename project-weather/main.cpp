//--------------------------------------------------------------------------
//  File name: main.cpp 
//  Project name: Weather
//--------------------------------------------------------------------------
//  Creator's name and email: Felix Murray felix.murray@gmail.com
//  Course Selection: CS1B
//  Creation Date: 8/23/19
//  Date of Last Modification: 8/28/19
//--------------------------------------------------------------------------
//  Purpose: This program will take in user input to enter the highest and
//           lowest temperatures for each month of a given year, then 
//            outputing the highest and lowest temperatures along with the 
//            average high and low temperatures for the given user input
//            values.  
//--------------------------------------------------------------------------
//  Algorithm: 
//      Step 1: Function Call getData() for user input.
//      Step 2: Output to console calculated values in other functions.
//--------------------------------------------------------------------------
#include <iostream>
#include <iomanip>
#define TOTAL_MONTHS 12

using namespace std;

//functions: getData, averageHigh, averageLow, indexHighTemp, indexLowTemp

//--------------------------------------------------------------------------
	// DATA DICTIONARY
	//--------------------------------------------------------------------------
	// CONSTANTS
	//--------------------------------------------------------------------------
	//   NAME              DATA TYPE         VALUE
	//--------------------------------------------------------------------------
	//  DEGREE_SYMBOL       string          "\u00b0"
  //  MONTH_NAMES       string array   Months of the Year (see below declaration)
	//--------------------------------------------------------------------------

const string DEGREE_SYMBOL = "\u00b0";
const string MONTH_NAMES[TOTAL_MONTHS] = {
  "January",
  "February",
  "March",
  "April",
  "May",
  "June",
  "July",
  "August",
  "September",
  "October",
  "November",
  "December"
};

void getData(double array[TOTAL_MONTHS][2]);
void printMonth(int index);
double averageHigh(double array[TOTAL_MONTHS][2]);
double averageLow(double array[TOTAL_MONTHS][2]);
int indexHighTemp(double array[TOTAL_MONTHS][2]);
int indexLowTemp(double array[TOTAL_MONTHS][2]);

int main () {
    double months[TOTAL_MONTHS][2];

    getData(months);
    cout << "Yearly Statistics:\n\n";
    cout << "Average high temperature: ";
    cout << fixed << showpoint;
    cout << setprecision(2) << averageHigh(months) << DEGREE_SYMBOL << "\n\n";
    cout << "Average low temperature: ";
    cout << setprecision(2) << averageLow(months) << DEGREE_SYMBOL << "\n\n";
    cout << "Highest temperature: ";
    cout << setprecision(2) << indexHighTemp(months) << DEGREE_SYMBOL << "\n\n";
    cout << "Lowest temperature: ";
    cout << setprecision(2) << indexLowTemp(months) << DEGREE_SYMBOL << "\n";

    return 0;
}

void getData(double array[TOTAL_MONTHS][2]) {
  system("clear");
  for (int month = 0; month < TOTAL_MONTHS; month++) {
    printMonth(month);
    
    cout << "-- Enter High: ";
    cin >> array[month][0];
    cout << "\n";

    cout << "-- Enter Low: ";
    cin >> array[month][1];
    cout << "\n";
  }
}

void printMonth(int index) {
  cout << MONTH_NAMES[index] << ":\n\n";
}

double averageHigh(double array[TOTAL_MONTHS][2]) {
  double sum;

  for (int month = 0; month < TOTAL_MONTHS; month++) {
    sum += array[month][0];
  }

  return sum / TOTAL_MONTHS;
}

double averageLow(double array[TOTAL_MONTHS][2]) {
  double sum;

  for (int month = 0; month < TOTAL_MONTHS; month++) {
    sum += array[month][1];
  }

  return sum / TOTAL_MONTHS;
}

int indexHighTemp(double array[TOTAL_MONTHS][2]) {
  int highest = 0;

  for (int month = 0; month < TOTAL_MONTHS; month++) {
      if (array[month][0] > highest) {
        highest = array[month][0];
      }
  }
  return highest;
}

int indexLowTemp(double array[TOTAL_MONTHS][2]) {
  int lowest;

  for (int month = 0; month < TOTAL_MONTHS; month++) {
      if (array[month][1] < lowest) {
        lowest = array[month][1];
      }
  }
  return lowest;
}

