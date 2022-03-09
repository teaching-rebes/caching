#ifndef CACHING_H
#define CACHING_H

#include <string>
#include <vector>


// Note: if your system does not have sufficient RAM and you get a bad
// allocation error, reduce NR_RECORDS
#define NR_RECORDS (2 * 1024 * 1024)
#define NR_OTHER_DATA 512

// define data structure to store our measurement data
struct dataElement {
  double temperature;              // temperature measurement
  double otherData[NR_OTHER_DATA]; // other measurement data
};

// TODO: Warum ist die obige Datenstruktur evtl. ungünstig hinsichtlich Caching?
// TODO: Ergänzen Sie hier so, dass der Cache besser genutzt werden kann.

void fillWithRandomData(std::vector<dataElement> &buffer);
void calculateAverageTemp(std::vector<dataElement> &buffer, bool optimized);
void printTimes(double startTime, double stopTime, std::string msg);

#endif // CACHING_H