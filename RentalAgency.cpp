#include "RentalAgency.h"
#include <iostream>
#include <stdexcept>
using namespace std;

RentalAgency::RentalAgency() {}
RentalAgency::~RentalAgency() {
    for (int i = 0 ; i < (int)cars.size(); i++) {delete cars[i];}
    for (int i = 0 ; i < (int)customers.size(); i++) {delete customers[i];}
    for (int i = 0 ; i < (int)rentals.size(); i++) {delete rentals[i];}
    for (int i = 0 ; i < (int)payments.size(); i++) {delete payments[i];}
}

void RentalAgency::addCar() {
    int type;
    string brand, model, plateNumber;
    int year;

    cout <<"\nSelect Car Type:" << endl;
    cout << "1. Sedan (9 OMR/day)" << endl;
    cout << "2. SUV (15 OMR/day)" << endl;
    cout << "3. Truck(20 OMR/day)" << endl;
    cout << "Enter choice:"; cin >> type;
    cout << "Enter brand:"; cin >> brand;
    cout << "Enter model:"; cin >> model;
    cout << "Enter Year:"; cin >> year;
    cout << "Enter plateNumber:"; cin >> plateNumber;

    try {
        if (year < 1900 || year > 2026) {
            throw invalid_argument("Year should be between 1900 and 2026");
        }
        if (type == 1) {
            cars.push_back(new Sedan(brand , model, year ,plateNumber));
        } else if (type == 2) {
            cars.push_back(new SUV(brand, model, year, plateNumber));
        } else if (type == 3) {
            cars.push_back(new Truck(brand, model, year, plateNumber));
        } else {
            throw invalid_argument("Invalid car type selected!");
        }
        cout  << "\nCar added! Car ID: " << cars.back()->getCarId() << endl;
    }catch (invalid_argument &e) {
        cout << "Error:" << e.what() << endl;
    }
}

void RentalAgency::addCustomer() {
    string name, id , phone , license;

    cout << "\nEnter name:"; cin >> name;
    cout << "Enter ID:"; cin >> id;
    cout << "Enter Phone Number:"; cin >> phone;
    cout << "Enter License Number:"; cin >> license;

    try {
        if (name.empty() || id.empty() || phone.empty() || license.empty()) {
            throw invalid_argument("All customer fields must be filled!");
        }
        customers.push_back(new Customer(name , id , phone , license));
        cout << "\nCustomer registered successfully!" << endl;
    } catch (invalid_argument &e) {
        cout << "Error:" << e.what() << endl;
    }
}

void RentalAgency::rentCar() {
    try {
        if (cars.empty()) {
            throw runtime_error("No cars available in the system!");
        }
        if (customers.empty()) {
            throw runtime_error("No customers registered in the system!");
        }

        displayCars();
        int carChoice;
        cout << "Select Car Number:";
        cin >> carChoice;
        carChoice--;

        if (carChoice < 0 || carChoice >= (int)cars.size()) {
            throw out_of_range("Invalid car selected!");
        }
        if (cars[carChoice]->getAvailability() == false) {
            throw runtime_error("This car is not available for rent!");
        }

        displayCustomers();
        int custChoice;
        cout << "Select Customer Number:";
        cin >> custChoice;
        custChoice--;

        if (custChoice < 0 || custChoice >= (int)customers.size()) {
            throw out_of_range("Invalid customer selection!");
        }
        if (customers[custChoice]->gethasActiveRental() == true) {
            throw runtime_error("This customer already has an active rental!");
        }
        int sDay , sMonth , sYear , sHour , sMin;
        cout << "\nEnter start date (day month year):";
        cin >> sDay , sMonth , sYear;
        cout << "\nEnter start time (hour minute):";
        cin >> sHour , sMin;

        int eDay , eMonth, eYear , eHour , eMin;
        cout << "Enter expected return date (day month year)";
        cin >> eDay , eMonth , eYear;
        cout << "Enter expected return time (hour minute)";
        cin >> eHour , eMin;

        Date_Time startDT(sDay , sMonth , sYear , sHour , sMin);
        Date_Time expectedDT(eDay , eMonth , eYear , eHour , eMin);

        cars[carChoice]->setAvailability(false);
        customers[custChoice]->sethasActiveRental(true);

        Rental* rental = new Rental(
            cars[carChoice], customers[custChoice], startDT, expectedDT
        );
        rentals.push_back(rental);

        cout<<"\nCar rented successfully!"<<endl;
        rental ->displayRental();
    } catch (runtime_error &e) {
        cout << "Error:" << e.what() << endl;
    } catch (out_of_range &e) {
            cout << "Error:" << e.what() << endl;
    }
}

void RentalAgency::returnCar() {
    try{
        if (rentals.empty()) {
            throw runtime_error("No rentals in the system!");
        }

        displayRentals();
        int choice;
        cout << "Select rental number to return:";
        cin >> choice;
        choice--;

        if (choice < 0 || choice >= (int)rentals.size()) {
            throw out_of_range("Invalid rental selection!");
        }
        if (rentals[choice]->getIsActive() == false) {
            throw runtime_error("This rental is already closed!");
        }

        int rDay , rMonth , rYear , rHour , rMin;
        cout << "\nEnter return date (day month year):";
        cin >> rDay , rMonth , rYear;
        cout << "Enter return time (hour minute)";
        cin >> rHour , rMin;

        Date_Time returnDT(rDay , rMonth , rYear , rHour , rMin);

        rentals[choice]->returnCar(returnDT);
        rentals[choice]->getCar()->setAvailability(true);
        rentals[choice]->getCustomer()->sethasActiveRental(false);

        cout << "\nCar rented successfully!" << endl;
        rentals[choice]->displayRental();

    } catch (runtime_error &e) {
        cout << "Error:" << e.what() << endl;
    } catch (out_of_range &e) {
        cout << "Error:" << e.what() << endl;
    }
}

void RentalAgency::makePayment() {
    try{
        if (rentals.empty()) {
            throw runtime_error("No rentals in the system!");
        }
        displayRentals();
        int choice;
        cout << "Select rental number to pay:";
        cin >> choice;
        choice--;
        if (choice < 0 || choice >= (int)rentals.size()) {
            throw out_of_range("Invalid rental selection!");
        }
        Payment* payment = new Payment(
            rentals[choice]->getRentalId(),
            rentals[choice]->getTotalCost()
        );
        payment->processPayment();
        payments.push_back(payment);
    } catch (runtime_error &e) {
        cout << "Error:" << e.what() << endl;
    } catch (out_of_range &e) {
        cout << "Error:" << e.what() << endl;
    }
}
void RentalAgency::displayCars() {
    cout << "\n === All cars ===" << endl;
    if (cars.empty()) {
        cout << "No cars in the system." << endl;
        return;
    }
    for (int i = 0; i < (int)cars.size(); i++) {
        cout << i + 1 << ".";
        cars[i]->displayCar();
        cout << "---------------------" << endl;
    }
}

void RentalAgency::displayCustomers() {
    cout << "\n === All Customers ===" << endl;
    if (customers.empty()) {
        cout << "No customers in the system." << endl;
        return;
    }
    for (int i = 0; i < (int)customers.size(); i++) {
        cout << i + 1 << ".";
        customers[i]->displayCustomer();
        cout << "---------------------" << endl;
    }
}
void RentalAgency::displayRentals() {
    cout << "\n === All Rentals ===" << endl;
    if (rentals.empty()) {
        cout << "No Rentals in the system." << endl;
        return;
    }
    for (int i = 0; i < (int)rentals.size(); i++) {
        cout << i + 1 << ".";
        rentals[i]->displayRental();
        cout << "---------------------" << endl;
    }
}