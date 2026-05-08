
#ifndef UNTITLED2_TRUCK_H
#define UNTITLED2_TRUCK_H

#include "Car.h"
using namespace std;

class Truck : public Car {
public:
    Truck(string brand, string model, int year);
    double calculatePrice(int days);
};

#endif //UNTITLED2_TRUCK_H
