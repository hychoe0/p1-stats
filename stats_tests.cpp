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

// Add prototypes for you test functions here.

int main() {
  test_sum_small_data_set();
  test_mean_small_data_set();
  test_median_small_data_set();
  test_mode_small_data_set();
  test_min_small_data_set();
  // Call your test functions here

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
}

void test_min_small_data_set() {
  cout << "test_min_small_data_set" << endl;

  vector<double> data = {1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4};

  assert(min(data) == 1);
  cout << "PASS!" << endl;
}

// Add the test function implementations here.
