#include <iostream>
#include <vector>
#include <memory> // For smart pointers
#include "../include/hostel.h"
using namespace std;

int main() {
    cout << "System initialized successfully." << endl;
    // Vector to store our university hostels
    vector<unique_ptr<Hostel>> campusHostels;

    // Adding 10 different hostels with various facilities
    campusHostels.push_back(std::make_unique<UniversityHostel>("Hostel A (Boys)", "Wi-Fi, Gym, Laundry", 100));
    campusHostels.push_back(std::make_unique<UniversityHostel>("Hostel B (Girls)", "Wi-Fi, Library, Canteen", 120));
    campusHostels.push_back(std::make_unique<UniversityHostel>("Hostel C (Post-Grad)", "Private Study Rooms, Wi-Fi", 80));

    cout << "--- University Hostel Management System ---" << endl;

    for (const auto& hostel : campusHostels) {
        hostel->displayInfo();
    }

    return 0;
}