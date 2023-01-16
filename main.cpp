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

  vector<pair<double, int> > summary = summarize(data);
  int count_data = count(data);
  double sum_data = sum(data);
  double mean_data = mean(data);
  double median_data = median(data);
  double mode_data = mode(data);
  double min_data = min(data);
  double max_data = max(data);
  double stdev_data = stdev(data);
  double percentile_0_data = percentile(data, 0.0);
  double percentile_25_data = percentile(data, 0.25);
  double percentile_50_data = percentile(data, 0.50);
  double percentile_75_data = percentile(data, 0.75);
  double percentile_100_data = percentile(data, 1.0);

  // Summary
  for (size_t i = 0; i < summary.size(); i++) {
    if (summary[i].second > 0) {
      cout << summary[i].first << ": " << summary[i].second << endl;
    }
  }
  cout << endl;

  // Count
  cout << "count = " << count_data << endl;

  // Sum
  cout << "sum = " << sum_data << endl;

  // Mean
  cout << "mean = " << mean_data << endl;

  // Standard Deviation
  cout << "stdev = " << stdev_data << endl;

  // Median
  cout << "median = " << median_data << endl;

  // Mode
  cout << "mode = " << mode_data << endl;

  // Minimum
  cout << "min = " << min_data << endl;

  // Maximum
  cout << "max = " << max_data << endl;

  // Percentile
  cout << "  0th percentile = " << percentile_0_data << endl;
  cout << " 25th percentile = " << percentile_25_data << endl;
  cout << " 50th percentile = " << percentile_50_data << endl;
  cout << " 75th percentile = " << percentile_75_data << endl;
  cout << "100th percentile = " << percentile_100_data << endl;
}