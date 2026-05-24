#ifndef UNTITLED2_RENTALAGENCY_H
#define UNTITLED2_RENTALAGENCY_H

#include <vector>
#include <string>
#include "Car.h"
#include "Customer.h"
#include "Rental.h"
#include "Payment.h"
#include "Sedan.h"
#include "SUV.h"
#include "Truck.h"
#include "Date_Time.h"



class RentalAgency {
private:
    vector<Car*> cars;
    vector<Customer*> customers;
    vector<Rental*> rentals;
    vector<Payment*> payments;

public:
    RentalAgency();
    ~RentalAgency();

    void addCar();
    void addCustomer();
    void rentCar();
    void returnCar();
    void makePayment();
    void displayCars();
    void displayCustomers();
    void displayRentals();

};



#endif //UNTITLED2_RENTALAGENCY_H
