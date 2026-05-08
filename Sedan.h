
#ifndef UNTITLED2_SEDAN_H
#define UNTITLED2_SEDAN_H

#include "Car.h"
using namespace std;

class Sedan : public Car {
public:
    Sedan(string brand, string model, int year);
    double calculatePrice(int days);
};

#endif //UNTITLED2_SEDAN_H
