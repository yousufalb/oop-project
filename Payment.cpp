#include "Payment.h"
#include <iostream>
using namespace std;

Payment::Payment(int rID, double amt) {
    rentalID = rID;
    amount = amt;
    isPaid = false;
    paymentType ="Not Selected";
}

double Payment::getAmount() {return amount;}
string Payment::getPaymentType() {return paymentType;}
bool Payment::getIsPaid() {return isPaid;}
int Payment::getRentalID() { return rentalID; }

void Payment::setpaymentType(string type) {
    paymentType = type;
}

void Payment::processPayment() {
    int choice;
    cout<<"=== Select Payment Method ==="<<endl;
    cout<<"1. Cash"<<endl;
    cout<<"2. Credit Card"<<endl;
    cout<<"3. Debit Card"<<endl;
    cout<<"Enter choice: ";
    cin>>choice;

    if (choice == 1) {
        paymentType = "Cash";
    } else if (choice == 2) {
        paymentType = "Credit Card";
    }else if (choice == 3) {
        paymentType = "Debit Card";
    }else {
        cout<<"Invalid Choice!!!"<<endl;
        return;
    }

    isPaid = true;
    cout<<"Payment processed successfully!"<<endl;
    displayInvoice();
}

void Payment::displayInvoice() {
    cout<<"=== Payment Invoice ==="<<endl;
    cout<<"Rental ID:          R00"<< rentalID <<endl;
    cout<<"Amount:                "<<amount<< "OMR"<<endl;
    cout<<"Payment Method:        "<<paymentType<<endl;
    if (isPaid == true) {
        cout<<"Status:             Paid"<<endl;
    }else {
        cout<<"Status:             Unpaid"<<endl;
    }
    cout<<"======================="<<endl;
}
