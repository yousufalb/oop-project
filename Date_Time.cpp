
#include "Date_Time.h"
#include <iostream>
#include <sstream>
#include <iomanip>
using namespace std;

Date_Time::Date_Time(int d, int mo, int y, int hr, int mi) {
    timeStruct ={};
    timeStruct.tm_mday = d;
    timeStruct.tm_mon = mo - 1;
    timeStruct.tm_year = y - 1900;
    timeStruct.tm_hour = hr;
    timeStruct.tm_min = mi;
    timeStruct.tm_sec = 0;
    mktime(&timeStruct);

}

int Date_Time::getDay() { return timeStruct.tm_mday; }
int Date_Time::getMonth() { return timeStruct.tm_mon + 1; }
int Date_Time::getYear() { return timeStruct.tm_year + 1900; }
int Date_Time::getHour() { return timeStruct.tm_hour; }
int Date_Time::getMinute() { return timeStruct.tm_min; }

double Date_Time::differenceInHours(Date_Time &other) {
    tm t1 = timeStruct;
    tm t2 = other.timeStruct;
    time_t time1 = mktime(&t1);
    time_t time2 = mktime(&t2);
    double seconds = difftime(time2, time1);
    return seconds / 3600.0;
}

double Date_Time::differenceInDays(Date_Time &other) {
    return differenceInHours(other) / 24.0;
}

void Date_Time::display() {
    cout << getDay() <<"/"
         << getMonth() <<"/"
         << getYear() <<" "
         << getHour() <<":"
         << set2(2) << setfill('0') << getMinute();

    return oss.str();
}
