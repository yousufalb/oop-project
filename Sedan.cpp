
#include "Sedan.h"

#include <iostream>
#include <ostream>
using namespace std;

Sedan::Sedan(string brand, string model, int year, string plateNumber)
    : Car(brand, model, year, 9.0, plateNumber){} // A sedan costs 9 OMR per day

double Sedan::calculatePrice(int days) {
    return getPricePerDay() * days;
}

void Sedan::displayCar() {
    cout<<"Type:                Sedan"<<endl;
    Car::displayCar();
}
