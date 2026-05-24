
#include "Truck.h"

#include <iostream>
#include <ostream>
using namespace std;

Truck::Truck(string brand, string model, int year, string plateNumber)
    : Car(brand, model, year, 20.0, plateNumber){} // A Truck costs 20 OMR per day

double Truck::calculatePrice(int days) {
    return getPricePerDay() * days;
}

void Truck::displayCar() {
    cout<< "Type:                 Truck"<<endl;
    Car::displayCar();
}