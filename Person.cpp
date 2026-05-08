
#include "Person.h"
#include <iostream>
using namespace std;

Person::Person(string n , string i, string phone) {
    name = n;
    id = i;
    phoneNumber = phone;

}
string Person::getName() {return name;}
string Person::getId() {return id;}
string Person::getPhoneNumber() {return phoneNumber;}

void Person::displayPerson() {
    cout << "Name: " << name << endl;
    cout << "Id: " << id << endl;
    cout << "PhoneNumber: " << phoneNumber << endl;
}
