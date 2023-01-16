/* stats_tests.cpp
 *
 * Unit tests for the simple statistics library
 * Project UID 5366c7e2b77742d5b2142097e51561a5
 *
 * EECS 280 Project 1
 *
 * Protip #1: Write tests for the functions BEFORE you implement them!  For
 * example, write tests for median() first, and then write median().  It sounds
 * like a pain, but it helps make sure that you are never under the illusion
 * that your code works when it's actually full of bugs.
 *
 * Protip #2: Instead of putting all your tests in main(),  put each test case
 * in a function!
 */


#include "stats.h"
#include <iostream>
#include <cassert>
#include <vector>
#include <cmath>
using namespace std;

void test_sum_small_data_set();
void test_mean_small_data_set();
void test_median_small_data_set();
void test_mode_small_data_set();
void test_min_small_data_set();
void test_max_small_data_set();
void test_stdev_small_data_set();
void test_percentile_small_data_set();
void test_summarize_small_data_set();
void test_comprehensive();


int main() {
  test_sum_small_data_set();
  test_mean_small_data_set();
  test_median_small_data_set();
  test_mode_small_data_set();
  test_min_small_data_set();
  test_max_small_data_set();
  test_stdev_small_data_set();
  test_percentile_small_data_set();
  test_summarize_small_data_set();
  test_comprehensive();

  return 0;
}

void test_sum_small_data_set() {
  cout << "test_sum_small_data_set" << endl;

  vector<double> data;
  data.push_back(1.5);
  data.push_back(2);
  data.push_back(3);

  assert(sum(data) == 6.5);

  cout << "PASS!" << endl;
}

void test_mean_small_data_set() {
  cout << "test_mean_small_data_set" << endl;

  vector<double> data;
  data.push_back(2);
  data.push_back(4);
  data.push_back(8);

  assert(mean(data) == 14.0/3.0);

  cout << "PASS!" << endl;
}

void test_median_small_data_set() {
  cout << "test_median_small_data_set" << endl;

  vector<double> data;
  data.push_back(2);
  data.push_back(4);
  data.push_back(8);

  assert(median(data) == 4);
  cout << "PASS!" << endl;
}

void test_mode_small_data_set() {
  cout << "test_mode_small_data_set" << endl;

  vector<double> data = {1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4};

  assert(mode(data) == 2);
  cout << "PASS!" << endl;

  vector<double> data2 = {1.5, 1.5, 1.5, 2, 2, 2, 3, 3, 3, 4, 4, 4};

  assert(mode(data2) == 1.5);
  cout << "PASS!" << endl;

  vector<double> data3 = {1, 2, 3};

  assert(mode(data3) == 1);
  cout << "PASS!" << endl;

  vector<double> data4 = {-1, -2, -3, -3, -5, -1, -1, -1, -3, -4};

  assert(mode(data4) == -1);
  cout << "PASS!" << endl;
}

void test_min_small_data_set() {
  cout << "test_min_small_data_set" << endl;

  vector<double> data = {1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4};

  assert(min(data) == 1);
  cout << "PASS!" << endl;

  vector<double> data2 = {5, 6, 2, 3, 3, 2, 1};

  assert(min(data2) == 1);
  cout << "PASS!" << endl;
}

void test_max_small_data_set() {
  cout << "test_max_small_data_set" << endl;

  vector<double> data = {1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4};

  assert(max(data) == 4);
  cout << "PASS!" << endl;

  vector<double> data2 = {5, 6, 2, 3, 3, 2, 1};

  assert(max(data2) == 6);
  cout << "PASS!" << endl;
}

void test_stdev_small_data_set() {
  cout << "test_stdev_small_data_set" << endl;

  vector<double> data = {6, 7, 8, 9, 10};

  assert(stdev(data) == sqrt(2.5));
  cout << "PASS!" << endl;
}

void test_percentile_small_data_set() {
  cout << "test_percentile_small_data_set" << endl;

  vector<double> data = {15, 20, 35, 40, 50};
  // 40th percentile
  double p1 = 0.4;

  assert(percentile(data, p1) == 29);
  cout << "PASS!" << endl;

  vector<double> data2 = {6, 7, 8, 9, 10};
  // 0th percentile
  double p2_1 = 0;
  // 0th percentile
  double p2_2 = 0.25;
  // 0th percentile
  double p2_3 = 0.5;
  // 0th percentile
  double p2_4 = 0.75;
  // 0th percentile
  double p2_5 = 1;

  assert(percentile(data2, p2_1) == 6);
  assert(percentile(data2, p2_2) == 7);
  assert(percentile(data2, p2_3) == 8);
  assert(percentile(data2, p2_4) == 9);
  assert(percentile(data2, p2_5) == 10);
  cout << "PASS!" << endl;

  vector<double> data3 = {1, 4, 5, 7, 9, 10, 30, 300, 600};
  double p3 = 0;
  int percentileVal = 0;

  // generated 0 - 100th percentile with every 5th percentile
  for (size_t i = 0; i < 21; i++) {
    cout << percentileVal << "th percentile : " << percentile(data3, p3) << endl;
    p3 += 0.05;
    percentileVal += 5;
  }
}

void test_summarize_small_data_set() {
  cout << "test_summarize_small_data_set" << endl;

  vector<double> data = {4, 5, 5, 5, 6, 7};
  
  vector<pair<double, int> > result = summarize(data);

  for (size_t i = 0; i < data.size(); i++) {
    if (result[i].second > 0) {
      cout << "{" << result[i].first << ", " << result[i].second << "}" << endl;
    }
  }
}

void test_comprehensive() {
  cout << "test_comprehensive" << endl;
  vector<double> data = {0, 0, 5, 5, 6, 2};

  vector<pair<double, int> > summary = summarize(data);

  for (int i = 0; i < data.size(); i++) {
    if (summary[i].second > 0) {
      cout << summary[i].first << ": " << summary[i].second << endl;
    }
  }
  cout << endl;

  cout << "count" << count(data) << endl;
  cout << "sum" << sum(data) << endl;
  cout << "mean" << mean(data) << endl;
  cout << "median" << median(data) << endl;
  cout << "mode" << mode(data) << endl;
  cout << "min" << min(data) << endl;
  cout << "max" << max(data) << endl;
  cout << "stdev" << stdev(data) << endl;
  cout << "percentile" << percentile(data, 0.5) << endl;

  
}