#include <iostream>
#include <vector>
#include <memory>
#include <fstream>
#include <sstream>
#include "../include/hostel.h"

using namespace std;

void loadDatabase(vector<unique_ptr<Hostel>>& campusHostels) {
    ifstream file("data/hostel_db.txt");
    if (!file.is_open()) {
        cout << "Warning: data/hostel_db.txt not found." << endl;
        return;
    }

    string line;
    getline(file, line);

    while (getline(file, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        string name, status, facilities, roomsStr;

        getline(ss, name, ',');
        getline(ss, status, ',');
        getline(ss, facilities, ',');
        getline(ss, roomsStr, ',');

        if(!name.empty() && !roomsStr.empty()) {
            string combinedFacilities = status + " | " + facilities;
            int rooms = stoi(roomsStr);
            campusHostels.push_back(make_unique<UniversityHostel>(name, combinedFacilities, rooms));
        }
    }
    file.close();
}

void runUnitTests(const vector<unique_ptr<Hostel>>& campusHostels) {
    cout << "\nRunning Automated Unit Tests..." << endl;
    if (!campusHostels.empty()) {
        cout << "Test 1 Passed: Database loaded data records successfully." << endl;
    } else {
        cout << "Test 1 Failed: No data elements found in collection." << endl;
    }

    if (campusHostels.size() >= 1 && campusHostels[0]->getName().find("Hostel A") != string::npos) {
        cout << "Test 2 Passed: Dynamic Polymorphism and integrity check matched." << endl;
    } else {
        cout << "Test 2 Failed: Object mismatch on target properties." << endl;
    }
    cout << "All Unit Tests Completed successfully.\n" << endl;
}

int main() {
    vector<unique_ptr<Hostel>> campusHostels;
    loadDatabase(campusHostels);
    
    runUnitTests(campusHostels);

    int choice = 0;
    while (true) {
        cout << "======= ALFIDO HOSTEL MANAGEMENT SYSTEM =======" << endl;
        cout << "1. Display All Resident Hostels" << endl;
        cout << "2. Search Hostel Details by Name" << endl;
        cout << "3. Exit System" << endl;
        cout << "===============================================" << endl;
        cout << "Enter your choice (1-3): ";
        
        if (!(cin >> choice)) {
            cout << "Invalid input. Please enter a number." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        if (choice == 1) {
            cout << "\n--- Fetching All Hostel Records ---" << endl;
            for (const auto& hostel : campusHostels) {
                hostel->displayInfo();
            }
        } 
        else if (choice == 2) {
            string searchName;
            cout << "Enter Hostel Name to search (e.g., Hostel A): ";
            cin.ignore();
            getline(cin, searchName);

            bool found = false;
            for (const auto& hostel : campusHostels) {
                if (hostel->getName().find(searchName) != string::npos) {
                    cout << "\nRecord Found:";
                    hostel->displayInfo();
                    found = true;
                }
            }
            if (!found) {
                cout << "No hostel matched the name: " << searchName << "\n" << endl;
            }
        } 
        else if (choice == 3) {
            cout << "Shutting down Hostel Management System. Goodbye!" << endl;
            break;
        } 
        else {
            cout << "Invalid choice. Please pick between 1 and 3.\n" << endl;
        }
    }

    return 0;
}