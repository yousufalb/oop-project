
#ifndef UNTITLED2_SUV_H
#define UNTITLED2_SUV_H

#include "Car.h"
using namespace std;

class SUV : public Car {
public:
    SUV(string brand, string model, int year, string plateNumber);
    double calculatePrice(int days) override;
    void displayCar() override;
};

#endif //UNTITLED2_SUV_H
