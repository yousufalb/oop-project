#include "Rental.h"
#include <iostream>
using namespace std;

int Rental::rentalCount = 0;

Rental::Rental(Car* c, Customer* cust, Date_Time start, Date_Time expectedReturn)
    : startDate_time(start), expectedReturnDate_time(expectedReturn){
    car = c;
    customer = cust;
    isActive = true;
    actualReturnDate_time = nullptr;
    rentalCount++;
    rentalId = rentalCount;
    calculateTotalCost();
}

Rental::~Rental() {
    if (actualReturnDate_time != nullptr) {
        delete actualReturnDate_time;
    }
}

bool Rental::operator==(const Rental& other) {
    return rentalId == other.rentalId;
}

int Rental::getRentalId() { return rentalId; }
Car* Rental::getCar() { return car; }
Customer* Rental::getCustomer() { return customer; }
Date_Time Rental::getStartDate_time() { return startDate_time; }
Date_Time Rental::getExpectedReturnDate_time() { return expectedReturnDate_time; }
double Rental::getTotalCost() { return totalCost; }
bool Rental::getIsActive() {  return isActive; }
int Rental::getRentalCount() { return rentalCount; }

void Rental::calculateTotalCost() {
    double days = startDate_time.differenceInDays(expectedReturnDate_time);
    if (days<=0) {
        days = 1;
    }
    totalCost = car->calculatePrice(int(days));
}

void Rental::returnCar(Date_Time returnDate_time) {
    actualReturnDate_time = new Date_Time(returnDate_time);
    isActive = false;
    double lateFee = calculateLateFee(returnDate_time);
    if (lateFee > 0) {
        totalCost += lateFee;
        cout << "Late return fee applied: "<< lateFee << " OMR "<< endl;
    }
}

double Rental::calculateLateFee(Date_Time returnDate_time) {
    double extraDays = expectedReturnDate_time.differenceInDays(returnDate_time);
    if (extraDays>0) {
        return extraDays * car ->getPricePerDay() * 1.5;
    }
    return 0;
}

void Rental::displayRental() {
    cout<<"=== Rental Details ==="<< endl;
    cout<<"Rental ID:      R00"<< rentalId<< endl;
    cout<<"Customer:          "<<customer->getName()<<endl;
    cout<<"Car:               "<<car->getBrand()<< " "<< car->getModel()<<endl;
    cout<<"Car ID:            "<<car->getCarId()<< endl;
    cout<<"Plate Number:      "<<car->getPlateNumber()<< endl;
    cout<<"Start:             "; startDate_time.display(); cout<<endl;
    cout<<"Expected Return:   "; expectedReturnDate_time.display(); cout<<endl;
    cout<<"Total Cost:        "<< totalCost << "OMR"<< endl;
    if (isActive == true) {
        cout<<"Status:                Active"<< endl;
    } else {
        cout<<"Status:                Returned"<< endl;
        if (actualReturnDate_time != nullptr) {
            cout << "Returned on:     ";
            actualReturnDate_time->display();
            cout << endl;
        }
    }
}
