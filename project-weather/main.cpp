#include <iostream>
#include <iomanip>
#define TOTAL_MONTHS 12

using namespace std;

//functions: getData, averageHigh, averageLow, indexHighTemp, indexLowTemp

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
    cout << averageHigh(months) << DEGREE_SYMBOL << "\n";
    cout << "Average low temperature: ";
    cout << averageLow(months) << DEGREE_SYMBOL << "\n";
    cout << "Highest temperature: ";
    cout << indexHighTemp(months) << DEGREE_SYMBOL << "\n";
    cout << "Lowest temperature: ";
    cout << indexLowTemp(months) << DEGREE_SYMBOL << "\n";

    return 0;
}

void getData(double array[TOTAL_MONTHS][2]) {
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
  int highest;

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
