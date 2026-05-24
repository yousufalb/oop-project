
#ifndef UNTITLED2_RENTAL_H
#define UNTITLED2_RENTAL_H

#include "Car.h"
#include "Customer.h"
#include "Date_Time.h"

class Rental {
private:
    int rentalId;
    static int rentalCount;
    Car* car;
    Customer* customer;
    Date_Time startDate_time;
    Date_Time expectedReturnDate_time;
    Date_Time* actualReturnDate_time;
    double totalCost;
    bool isActive;

public:
    Rental(Car* car, Customer* customer, Date_Time start, Date_Time expectedReturn);
    ~Rental();

    bool operator==(const Rental& other);

    int getRentalId();
    Car* getCar();
    Customer* getCustomer();
    Date_Time getStartDate_time();
    Date_Time getExpectedReturnDate_time();
    double getTotalCost();
    bool getIsActive();
    static int getRentalCount();

    void setIsActive(bool status);
    void calculateTotalCost();
    void returnCar(Date_Time returnDate_time);
    double calculateLateFee(Date_Time  returnDate_time);
    void displayRental();

};

#endif //UNTITLED2_RENTAL_H
