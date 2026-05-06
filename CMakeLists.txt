cmake_minimum_required(VERSION 4.2)
project(untitled2)

set(CMAKE_CXX_STANDARD 20)

add_executable(untitled2 "Car Rental System.cpp"
        Person.cpp
        Person.h
        Customer.cpp
        Customer.h
        Car.cpp
        Car.h
        Sedan.cpp
        Sedan.h
        SUV.cpp
        SUV.h
        Truck.cpp
        Truck.h
        Rental.cpp
        Rental.h
        Payment.cpp
        Payment.h
        RentalAgency.cpp
        RentalAgency.h)
