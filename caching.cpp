#include "caching.h"

#include <iostream>
#include <memory>
#include <sstream>
#include <time.h>

using namespace std;

#define SEED 42
// for varying random values use: #define SEED time(0)

void fillWithRandomData(vector<dataElement> &buffer) {
  cout << "Filling buffer with random temperature data... ";
  for (long i = 0; i < buffer.size(); i++) {
    buffer[i].temperature =
        static_cast<float>(rand()) / static_cast<float>(RAND_MAX / 30.0);
  }

  // TODO: ggf. so ergänzen, dass Ihre für den Cache optimierte Datenstruktur
  // gefüllt wird.

  cout << "Done. " << endl;
}

void calculateAverageTemp(vector<dataElement> &buffer, bool optimized) {
  double sum = 0.0;

  for (long i = 0; i < NR_RECORDS; i++) {
    if (optimized) {
      // TODO: HIER optimieren
      // Ersetzen Sie die nachfolgende Zeile so, dass der Cache besser genutzt
      // wird.
      sum += buffer[i].temperature;
    } else
      sum += buffer[i].temperature;
  }

  cout << "  Calculated average temperature: " << sum / NR_RECORDS << endl;
}

void printTimes(double startTime, double stopTime, string msg) {
  double duration = (stopTime - startTime) / CLOCKS_PER_SEC;
  duration *= 1000; // convert to milliseconds

  cout << "==> Calculation \"" << msg << "\" took " << duration << " ms."
       << endl;
}

int main() {
  cout << "Starting.." << endl;

  srand(static_cast<unsigned>(SEED));

  // allocate vector for our measurement data
  vector<dataElement> dataVector(NR_RECORDS);

  fillWithRandomData(dataVector);

  // run experiments:
  //   experiment 1: not optimized for cache
  //   experiment 2: optimized for cache
  for (int experiment = 1; experiment <= 2; experiment++) {
    double startTime = clock();
    calculateAverageTemp(dataVector, experiment == 2);
    printTimes(startTime, clock(),
               experiment == 2 ? "optimized" : "not optimized");
  }

  return 0;
}
