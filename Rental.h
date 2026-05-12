//
// Created by yousu on 5/6/2026.
//

#ifndef UNTITLED2_RENTAL_H
#define UNTITLED2_RENTAL_H

#include "Car.h"
#include "Customer.h"

class Rental {
private:
    Car* car;
    Customer* customer;
    int startDay;
    int endDay;
    double totalCost;
    bool isActive;

public:
    Rental(Car* car, Customer* customer, int startDay, int endDay);

    Car* getCar();
    Customer* getCustomer();
    int getStartDay();
    int getEndDay();
    double getTotalCost();
    bool getIsActive();
    
    void setIsActive(bool status);
    void calculateTotalCost();
    void displayRental();

};

#endif //UNTITLED2_RENTAL_H
