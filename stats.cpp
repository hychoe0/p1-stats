// stats.cpp
// Project UID 5366c7e2b77742d5b2142097e51561a5
#include "stats.h"
#include "p1_library.h"
#include <cassert>
#include <vector>
#include <cmath>


using namespace std;


vector<pair<double, int> > summarize(vector<double> v) {
  assert(false);
}


int count(vector<double> v) {
  return v.size();
}


double sum(vector<double> v) {
  double sum = 0;
  for (size_t i = 0; i < v.size(); ++i) {
    sum += v[i];
  }
  return sum;
}


double mean(vector<double> v) {
  double sum = 0;
  for (size_t i = 0; i < v.size(); ++i) {
    sum += v[i];
  }
  return sum / v.size();
}


double median(vector<double> v) {
 sort(v);

  if (v.size() % 2 == 0) {
    return ((v[v.size() / 2] + v[(v.size() / 2) - 1]) / 2);
  }
  return v[v.size() / 2];
}


double mode(vector<double> v) {
  assert(false);
}


double min(vector<double> v) {
  assert(false);
}


double max(vector<double> v) {
  assert(false);
}


double stdev(vector<double> v) {
  assert(false);
}


double percentile(vector<double> v, double p) {
  assert(false);
}
