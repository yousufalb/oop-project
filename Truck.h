
#ifndef UNTITLED2_TRUCK_H
#define UNTITLED2_TRUCK_H

#include "Car.h"
using namespace std;

class Truck : public Car {
public:
    Truck(string brand, string model, int year, string plateNumber);
    double calculatePrice(int days) override;
    void displayCar() override;
};

#endif //UNTITLED2_TRUCK_H
