// This file contains the class definition for the University Hostel management system.
#ifndef HOSTEL_H
#define HOSTEL_H

#include <string>
#include <iostream>

class Hostel {
protected:
    std::string hostelName;
    std::string facilities;
public:
    Hostel(std::string name, std::string fac) : hostelName(name), facilities(fac) {}
    virtual void displayInfo() const = 0; // Pure virtual function
};

class UniversityHostel : public Hostel {
private:
    int totalRooms;
public:
    UniversityHostel(std::string name, std::string fac, int rooms) 
        : Hostel(name, fac), totalRooms(rooms) {}
    
    void displayInfo() const override;
};

#endif