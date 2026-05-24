#include "Customer.h"
#include <iostream>
using namespace std;

Customer::Customer(string n , string i, string phone , string lNumber)
    : Person(n ,i,phone){
    licenseNumber = lNumber;
    hasActiveRental = false;
}
    
string Customer::getLicenseNumber() {return licenseNumber;}
bool Customer::gethasActiveRental() {return hasActiveRental;}

void Customer::sethasActiveRental(bool status) {hasActiveRental = status;}

void Customer::displayCustomer() {
    displayPerson(); // It calls the person display
    cout <<"License Number:" <<licenseNumber <<endl;
    if (hasActiveRental == true) {
        cout << "Active Rental: Yes" << endl;
    } else {
        cout << "Active Rental: No" << endl;
    }

}