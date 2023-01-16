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

  vector<double> data = extract_column(fileName, columnName);

  // Statistics Output
  // Summary
  vector<pair<double, int> > summary = summarize(data);

  for (size_t i = 0; i < summary.size(); i++) {
    cout << summary[i].first << ": " << summary[i].second << endl;
  }
  cout << endl;

  
  
  
  
  
  
  
  
  

  // Count
  int count_data = count(data);
  cout << "count = " << count_data << endl;

  // Sum
  double sum_data = sum(data);
  cout << "sum = " << sum_data << endl;

  // Mean
  double mean_data = mean(data);
  cout << "mean = " << mean_data << endl;

  // Standard Deviation
  double stdev_data = stdev(data);
  cout << "stdev = " << stdev_data << endl;

  // Median
  double median_data = median(data);
  cout << "median = " << median_data << endl;

  // Mode
  double mode_data = mode(data);
  cout << "mode = " << mode_data << endl;

  // Minimum
  double min_data = min(data);
  cout << "min = " << min_data << endl;

  // Maximum
  double max_data = max(data);
  cout << "max = " << max_data << endl;

  // Percentile
  double percentile_0_data = percentile(data, 0.0);
  double percentile_25_data = percentile(data, 0.25);
  double percentile_50_data = percentile(data, 0.50);
  double percentile_75_data = percentile(data, 0.75);
  double percentile_100_data = percentile(data, 1.0);
  
  cout << "  0th percentile = " << percentile_0_data << endl;
  cout << " 25th percentile = " << percentile_25_data << endl;
  cout << " 50th percentile = " << percentile_50_data << endl;
  cout << " 75th percentile = " << percentile_75_data << endl;
  cout << "100th percentile = " << percentile_100_data << endl;
}