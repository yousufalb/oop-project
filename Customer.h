#ifndef UNTITLED2_CUSTOMER_H
#define UNTITLED2_CUSTOMER_H

#include "Person.h"
using namespace std;


class Customer : public Person {
private:
    string licenseNumber;
    bool hasActiveRental;

public:
    //Constructor
    Customer(string name , string id , string phoneNumber , string licenseNumber);

    // Getters
    string getLicenseNumber();
    bool gethasActiveRental();

    //Setters
    void sethasActiveRental(bool status);

    //Display
    void displayCustomer();

};


#endif //UNTITLED2_CUSTOMER_H