#include "../include/hostel.h"
#include <iostream>

using namespace std;

void UniversityHostel::displayInfo() const {
    cout << "\n🏠 Hostel Name: " << hostelName << endl;
    cout << "⚡ Facilities : " << facilities << endl;
    cout << "🛏️ Total Rooms: " << totalRooms << endl;
}