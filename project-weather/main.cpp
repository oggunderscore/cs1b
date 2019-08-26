#include <iostream>
#define months 12

using namespace std;

//functions: getData, averageHigh, averageLow, indexHighTemp, indexLowTemp

void getData(double array[][months]);
double averageHigh(double array[][months]);
double averageLow(double array[][months]);
int indexHighTemp(double array[][months]);
int indexLowTemp(double array[][months]);

int main () {
    double temps[2][months];

    getData(temps);
    cout << "Yearly Statistics:/n/n";
    cout << "\nAverage high temperature: ";
    cout << averageHigh(temps);
    cout << "\nAverage low temperature: ";
    cout << averageLow(temps);
    cout << "\nHighest temperature: ";
    cout << indexHighTemp(temps);
    cout << "\nLowest temperature: ";
    cout << indexLowTemp(temps);

    return 0;
}

//High Temperatures are stored in first row (index 0)
//Low Temperatures are stored in second row (index 1)
void getData(double array[][months]) {
  for (int r = 0; r < 2; r++){
    for (int c = 0; c < months; c++){
        switch (r) {
          case 0:
            cout << "Enter High: ";
            cin >> array[r][c];
            cout << "\n";
            break;
          case 1:
            cout << "Enter Low: ";
            cin >> array[r][c];
            cout << "\n";
            break;
        }
    }
  }
}

double averageHigh(double array[][months]) {
  double avgHigh;

  for (int c = 0; c < months; c++) {
    avgHigh += array[0][c];
  }
  return avgHigh / months;
}

double averageLow(double array[][months]) {
  double avgLow;

  for (int c = 0; c < months; c++) {
    avgLow += array[1][c];
  }
  return avgLow / months;
}

int indexHighTemp(double array[][months]) {
  int temp;

  for (int c = 0; c < months; c++) {
      temp = (temp < array[0][c]) ? temp : array[0][c];
  }
  return temp;
}

int indexLowTemp(double array[][months]) {
  int temp;

  for (int c = 0; c < months; c++) {
      temp = (temp < array[1][c]) ? temp : array[1][c];
  }
  return temp;
}
