
#ifndef UNTITLED2_DATE_TIME_H
#define UNTITLED2_DATE_TIME_H

#include <string>
#include <ctime>
using namespace std;

class Date_Time {
private:
    tm timeStruct;

public:
    Date_Time(int day, int month, int year, int hour, int minute);

    int getDay();
    int getMonth();
    int getYear();
    int getHour();
    int getMinute();

    double differenceInHours(Date_Time& other);
    double differenceInDays(Date_Time& other);

    void display();
    string toString();
};

#endif //UNTITLED2_DATE_TIME_H
