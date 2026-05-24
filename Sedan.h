
#ifndef UNTITLED2_SEDAN_H
#define UNTITLED2_SEDAN_H

#include "Car.h"
using namespace std;

class Sedan : public Car {
public:
    Sedan(string brand, string model, int year, string plateNumber);
    double calculatePrice(int days) override;
    void displayCar() override;
};

#endif //UNTITLED2_SEDAN_H
