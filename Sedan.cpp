
#include "Sedan.h"
using namespace std;

Sedan::Sedan(string brand, string model, int year)
    : Car(brand, model, year, 9.0){} // A sedan costs 9 OMR per day

double Sedan::calculatePrice(int days) {
    return getPricePerDay() * days;
}
