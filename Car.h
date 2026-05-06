
#ifndef UNTITLED2_CAR_H
#define UNTITLED2_CAR_H

#include <string>
using namespace std;

class Car {
private:
    string brand;
    string model;
    int year;
    bool isAvailable;
    double pricePerDay;
public:
    // The Constructor
    Car(string brand, string model, int year, double pricePerDay);

    // Our getters
    string getBrand();
    string getModel();
    int getYear();
    bool getAvailability();
    double getPricePerDay();

    // Setters
    void setAvailability(bool status);

    // Display
    void displayCar();
};

#endif
