// stats.cpp
// Project UID 5366c7e2b77742d5b2142097e51561a5
#include "stats.h"
#include "p1_library.h"
#include <cassert>
#include <vector>
#include <cmath>

using namespace std;


vector<pair<double, int> > summarize(vector<double> v) {
  sort(v);

  vector<pair<double, int> > value;
  double repeatedNum;

  for (size_t i = 0 ; i < v.size(); i++) {
    int frequency = 1;
    for (size_t j = i; j < v.size() - 1; j++) {
      if (v[i] == v[j + 1]) {
       frequency++;
      }
    }
    if (repeatedNum != v[i]) {
      value.push_back({v[i], frequency});
      repeatedNum = v[i];
    }
  } 
  return value;
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
 // sort vector v from smallest to greatest
 sort(v);

// if the size is even
  if (v.size() % 2 == 0) {
    return ((v[v.size() / 2] + v[(v.size() / 2) - 1]) / 2);
  }
  // if the size is odd
  return v[v.size() / 2];
}


double mode(vector<double> v) {

  // boolean variable repeat will make sure if there's a repeat or not
  bool repeat = false;
  vector<pair<double, int> > count;

 // sort vector v from smallest to greatest
  sort(v);

  for (size_t i = 0; i < v.size(); i++) {
    int frequency = 0;
      for (size_t j = i + 1; j < v.size(); j++) {
        if (v[i] == v[j]) {
          repeat = true;
          frequency++;
        }
      }

      // if repeat is true, then set values in the vector 'count'
      if (repeat == true) {
      count.push_back({v[i], frequency});
      }
    }

  // find the largest value of frequency in the vector 'count'
  if (repeat == true) {
    double modeValue = count[0].first;
    int modeFrequency = count[0].second;

    for (int x = 1; x < count.size(); x++) {
      if (modeFrequency < count[x].second) {
        modeFrequency = count[x].second;
        modeValue = count[x].first;
      }
    }
    return modeValue;
  }

  // if repeat is false, then return the first(smallest) value
  return v[0];
}

double min(vector<double> v) {
  
  // sort the data and return the first value
  sort(v);

  return v[0];
}


double max(vector<double> v) {

  // sort the data and return the last value
  sort(v);

  return v[v.size() - 1];
}


double stdev(vector<double> v) {
  
  // Expected value is a mean value of the data
  double expectedVal = mean(v);

  // Deviations are (each value in data - expected)
  vector<double> dev;

  // stdev = sqrt(((actual - expected)^2) / sample size)
  for (size_t i = 0; i < v.size(); i++) {
    dev.push_back(pow((v[i] - expectedVal),2));
  }

  // sum of deviations
  double devTotal = sum(dev);

  double stdev = sqrt(devTotal / (v.size() - 1));

  return stdev;
}


double percentile(vector<double> v, double p) {
  // sort the data in vector
  sort(v);

  // n = (P/100)(N - 1) + 1
  // P/100 is already p
  double ordinalRank = p * (v.size() - 1) + 1;

  // n = k + d
  // k represents intPart and d represents fractPart
  double intPart = 0;
  double fractPart = modf(ordinalRank, &intPart);

  // initializing percentile
  double percentile = 0;

  // equation to get percentile
  // k == intPart - 1 since the index starts from 0, not 1
  percentile = v[intPart - 1] + fractPart * (v[intPart] - v[intPart - 1]);

  return percentile;

}
