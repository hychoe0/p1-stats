// Project UID 5366c7e2b77742d5b2142097e51561a5
#include "stats.h"
#include "p1_library.h"
#include <iostream>

using namespace std;

int main() {
  string fileName = "";
  string columnName = "";
  
  cout << "enter a filename" << endl;
  cin >> fileName;

  cout << "enter a column name" << endl;
  cin >> columnName;

  cout << "reading column " << columnName << " from " << fileName << endl;
  cout << "Summary (value: frequency)" << endl;

}