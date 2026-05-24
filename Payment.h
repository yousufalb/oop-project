
#ifndef UNTITLED2_PAYMENT_H
#define UNTITLED2_PAYMENT_H

#include <string>
using namespace std;

class Payment {
private:
    double amount;
    string paymentType;
    bool isPaid;
    int rentalID;

public:
    Payment(int rentalID, double amt);

    double getAmount();
    string getPaymentType();
    bool getIsPaid();
    int getRentalID();

    void setpaymentType(string type);
    void processPayment();
    void displayInvoice();
};


#endif //UNTITLED2_PAYMENT_H
