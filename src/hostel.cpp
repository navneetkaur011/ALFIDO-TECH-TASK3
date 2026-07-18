#include "../include/Hostel.h"
#include <iostream>

void UniversityHostel::displayInfo() const {
    std::cout << "\nHostel Name: " << hostelName << std::endl;
    std::cout << "Facilities : " << facilities << std::endl;
    std::cout << "Total Rooms: " << totalRooms << std::endl;
}