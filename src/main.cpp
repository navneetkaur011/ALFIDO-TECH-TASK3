#include <iostream>
#include <vector>
#include <memory> // For smart pointers
#include "../include/Hostel.h"

int main() {
    // Vector to store our university hostels
    std::vector<std::unique_ptr<Hostel>> campusHostels;

    // Adding 10 different hostels with various facilities
    campusHostels.push_back(std::make_unique<UniversityHostel>("Hostel A (Boys)", "Wi-Fi, Gym, Laundry", 100));
    campusHostels.push_back(std::make_unique<UniversityHostel>("Hostel B (Girls)", "Wi-Fi, Library, Canteen", 120));
    campusHostels.push_back(std::make_unique<UniversityHostel>("Hostel C (Post-Grad)", "Private Study Rooms, Wi-Fi", 80));

    std::cout << "--- University Hostel Management System ---" << std::endl;

    for (const auto& hostel : campusHostels) {
        hostel->displayInfo();
    }

    return 0;
}