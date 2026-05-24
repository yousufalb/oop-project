
#include "SUV.h"

#include <iostream>
#include <ostream>
using namespace std;

SUV::SUV(string brand, string model, int year, string plateNumber)
    : Car(brand, model, year, 15.0, plateNumber){} // A SUV costs 15 OMR per day

double SUV::calculatePrice(int days) {
    return getPricePerDay() * days;
}

void SUV::displayCar() {
    cout <<"Type:                  SUV"<<endl;
    Car::displayCar();
}