#ifndef UNTITLED2_PERSON_H
#define UNTITLED2_PERSON_H

#include <string>
using namespace std;

class Person {
private:
    string name;
    string id;
    string phoneNumber;

public:
    // constructor
    Person(string name, string id, string phoneNumber);

    // Getters
    string getName();
    string getId();
    string getPhoneNumber();

    //Display
    void displayPerson();


};


#endif //UNTITLED2_PERSON_H
