
#include "Truck.h"
using namespace std;

Truck::Truck(string brand, string model, int year)
    : Car(brand, model, year, 20.0){} // A Truck costs 20 OMR per day

double Truck::calculatePrice(int days) {
    return getPricePerDay() * days;
}
