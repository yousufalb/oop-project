#include "RentalAgency.h"
#include <iostream>
using namespace std;

int main() {
    RentalAgency agency;
    int choice;

    do {
        cout<<"\n=== Car Rental System ===" << endl;
        cout<<"1. Add a Car"<<endl;
        cout<<"2. Register a Customer"<<endl;
        cout<<"3. Rent a Car"<<endl;
        cout<<"4. Return a Car"<<endl;
        cout<<"5. Make a Payment"<<endl;
        cout<<"6. View All Cars"<<endl;
        cout<<"7. View All Customers"<<endl;
        cout<<"8. View All Rentals"<<endl;
        cout<<"0. Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;

        switch(choice) {
            case 1: agency.addCar(); break;
            case 2: agency.addCustomer(); break;
            case 3: agency.rentCar(); break;
            case 4: agency.returnCar(); break;
            case 5: agency.makePayment(); break;
            case 6: agency.displayCars(); break;
            case 7: agency.displayCustomers(); break;
            case 8: agency.displayRentals(); break;
            case 0: cout << "\n Goodbye!" << endl; break;
            default: cout << "Invalid choice!" << endl; break;
        }
    }while(choice != 0);

    return 0;
}