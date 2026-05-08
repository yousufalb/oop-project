
#include "SUV.h"
using namespace std;

SUV::SUV(string brand, string model, int year)
    : Car(brand, model, year, 15.0){} // A SUV costs 15 OMR per day

double SUV::calculatePrice(int days) {
    return getPricePerDay() * days;
}