
#include "Car.h"
#include <iostream>
using namespace std;

Car::Car(string b, string m, int y, double price) {
    brand = b;
    model = m;
    year = y;
    pricePerDay = price;
    isAvailable = true;
}

string Car::getBrand() { return brand; }
string Car::getModel() { return model; }
int Car::getYear() { return year; }
bool Car::getAvailability() { return isAvailable; }
double Car::getPricePerDay() { return pricePerDay; }

void Car::setAvailability(bool status) {
    isAvailable = status;
}

void Car::displayCar() {
    cout<< "Brand: " << brand << endl;
    cout<< "Model: " << model << endl;
    cout<< "Year: " << year << endl;
    cout<< "Price Per Day (in OMR): " << pricePerDay << endl;
    if (isAvailable == true) {
        cout << "Available: Yes" << endl;
    } else {
        cout << "Available: No" << endl;
    }
}
