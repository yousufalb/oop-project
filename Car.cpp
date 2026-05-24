
#include "Car.h"
#include <iostream>
using namespace std;

int Car::carCount = 0;

Car::Car(string b, string m, int y, double price, string plate) {
    brand = b;
    model = m;
    year = y;
    pricePerDay = price;
    plateNumber = plate;
    isAvailable = true;
    carCount++;
    carId = "C00" + to_string(carCount);
}
Car::~Car() {}

string Car::getBrand() { return brand; }
string Car::getModel() { return model; }
int Car::getYear() { return year; }
bool Car::getAvailability() { return isAvailable; }
double Car::getPricePerDay() { return pricePerDay; }
string Car::getPlateNumber() { return plateNumber; }
string Car::getCarId() { return carId; }
int Car::getCarCount() { return carCount; }

void Car::setAvailability(bool status){
    isAvailable = status;
}

void Car::displayCar() {
    cout<< "Car ID: " << carId << endl;
    cout<< "Plate Number: " << plateNumber << endl;
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
