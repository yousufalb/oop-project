
#ifndef UNTITLED2_PAYMENT_H
#define UNTITLED2_PAYMENT_H

#include <string>
using namespace std;

class Payment {
private:
    double amount;
    string paymentType;
    bool isPaid;
    int renatalID;

public:
    Payment(int rentalID, double amount);
    double getAmount();
    string getPaymentType();
    bool getIsPaid();
    int getRentalID();

    void setpaymentType(string paymentType);
    void processPayment();
    void displayInvoice();


};


#endif //UNTITLED2_PAYMENT_H
