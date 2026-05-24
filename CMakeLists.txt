cmake_minimum_required(VERSION 4.2)
project(untitled2)

set(CMAKE_CXX_STANDARD 20)

add_executable(untitled2
        Car Rental System.cpp
        Car.cpp          Car.h
        Person.cpp       Person.h
        Customer.cpp     Customer.h
        Sedan.cpp        Sedan.h
        SUV.cpp          SUV.h
        Truck.cpp        Truck.h
        Date_Time.cpp     Date_Time.h
        Rental.cpp       Rental.h
        Payment.cpp      Payment.h
        RentalAgency.cpp RentalAgency.h
)