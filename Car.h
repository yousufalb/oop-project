
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
    string plateNumber;
    string carId;
    static int carCount;

public:
    // The Constructor
    Car(string brand, string model, int year, double pricePerDay, string plateNumber);
    virtual ~Car();

    virtual double calculatePrice(int days) =0;
    virtual void displayCar();

    // Our getters
    string getBrand();
    string getModel();
    int getYear();
    bool getAvailability();
    double getPricePerDay();
    string getPlateNumber();
    string getCarId();
    static int getCarCount();

    // Setters
    void setAvailability(bool status);

};

#endif
