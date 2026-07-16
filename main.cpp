#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include <limits>

// ==========================================
// 1. Base Class: Person
// ==========================================
class Person {
protected:
    std::string name;
    int age;

public:
    Person(std::string n, int a) : name(n), age(a) {}
    virtual ~Person() = default; // Virtual destructor for safe inheritance
    
    std::string getName() const { return name; }
    int getAge() const { return age; }
};

// ==========================================
// 2. Derived Class: Student (Inheritance)
// ==========================================
class Student : public Person {
private:
    std::string studentID;
    int roomNumber;

public:
    Student(std::string n, int a, std::string id, int room) 
        : Person(n, a), studentID(id), roomNumber(room) {}
    
    std::string getID() const { return studentID; }
    int getRoom() const { return roomNumber; }
    void assignRoom(int room) { roomNumber = room; }
};

// ==========================================
// 3. Management Class: HostelManager
// ==========================================
class HostelManager {
private:
    std::vector<Student> students; // STL Container
    const std::string filename = "hostel_records.txt";
    
    void saveToFile() const {
        std::ofstream outFile(filename);
        if (!outFile) return;
        for (const auto& s : students) {
            outFile << s.getName() << "," << s.getAge() << "," << s.getID() << "," << s.getRoom() << "\n";
        }
        outFile.close();
    }

    void loadFromFile() {
        std::ifstream inFile(filename);
        if (!inFile) return;
        
        std::string name, id, ageStr, roomStr;
        while (std::getline(inFile, name, ',') && 
               std::getline(inFile, ageStr, ',') && 
               std::getline(inFile, id, ',') && 
               std::getline(inFile, roomStr)) {
            if(!name.empty()) {
                students.push_back(Student(name, std::stoi(ageStr), id, std::stoi(roomStr)));
            }
        }
        inFile.close();
    }

public:
    HostelManager() {
        loadFromFile();
    }

    void allocateRoom(const std::string& name, int age, const std::string& id, int room) {
        for (const auto& student : students) {
            if (student.getID() == id) {
                std::cout << "\n Error: Student ID " << id << " is already registered!\n";
                return;
            }
            if (student.getRoom() == room) {
                std::cout << "\n Error: Room Number " << room << " is already occupied!\n";
                return;
            }
        }
        students.push_back(Student(name, age, id, room));
        saveToFile();
        std::cout << "\n Success: Room " << room << " allocated to " << name << " successfully.\n";
    }

    void deallocateRoom(const std::string& id) {
        for (auto it = students.begin(); it != students.end(); ++it) {
            if (it->getID() == id) {
                std::cout << "\n Success: Room " << it->getRoom() << " vacated by student " << it->getName() << ".\n";
                students.erase(it);
                saveToFile();
                return;
            }
        }
        std::cout << "\n Error: Student ID not found.\n";
    }

    void displayAllStudents() const {
        if (students.empty()) {
            std::cout << "\n Hostel is currently empty.\n";
            return;
        }
        std::cout << "\n" << std::setw(15) << "Student ID" << std::setw(20) << "Name" 
                  << std::setw(10) << "Age" << std::setw(12) << "Room No\n";
        std::cout << std::string(57, '-') << "\n";
        for (const auto& s : students) {
            std::cout << std::setw(15) << s.getID() << std::setw(20) << s.getName() 
                      << std::setw(10) << s.getAge() << std::setw(12) << s.getRoom() << "\n";
        }
    }

    void searchStudent(const std::string& id) const {
        for (const auto& s : students) {
            if (s.getID() == id) {
                std::cout << "\n Student Record Found:\n";
                std::cout << "-----------------------\n";
                std::cout << "Name:     " << s.getName() << "\n";
                std::cout << "Age:      " << s.getAge() << "\n";
                std::cout << "ID:       " << s.getID() << "\n";
                std::cout << "Room No:  " << s.getRoom() << "\n";
                return;
            }
        }
        std::cout << "\n Error: No record found for Student ID: " << id << "\n";
    }
};

// ==========================================
// Helper function to clear standard input stream
// ==========================================
void clearBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// ==========================================
// 4. Interactive Console Menu System
// ==========================================
int main() {
    HostelManager manager;
    int choice;

    while (true) {
        std::cout << "\n======= ALFIDO HOSTEL MANAGEMENT SYSTEM =======";
        std::cout << "\n1. Allocate New Room";
        std::cout << "\n2. Deallocate / Vacate Room";
        std::cout << "\n3. Display All Resident Records";
        std::cout << "\n4. Search Resident Student";
        std::cout << "\n5. Exit System";
        std::cout << "\n===============================================";
        std::cout << "\nEnter your choice (1-5): ";
        
        if (!(std::cin >> choice)) {
            std::cout << "\n Invalid input. Please enter a number.\n";
            clearBuffer();
            continue;
        }

        switch (choice) {
            case 1: {
                std::string name, id;
                int age, room;
                clearBuffer();
                std::cout << "Enter Student Full Name: ";
                std::getline(std::cin, name);
                std::cout << "Enter Student Age: ";
                while (!(std::cin >> age) || age <= 0) {
                    std::cout << "Invalid age. Re-enter: ";
                    clearBuffer();
                }
                clearBuffer();
                std::cout << "Enter Unique Student ID: ";
                std::getline(std::cin, id);
                std::cout << "Enter Target Room Number: ";
                while (!(std::cin >> room) || room <= 0) {
                    std::cout << "Invalid room number. Re-enter: ";
                    clearBuffer();
                }
                manager.allocateRoom(name, age, id, room);
                break;
            }
            case 2: {
                std::string id;
                clearBuffer();
                std::cout << "Enter Student ID to vacate room: ";
                std::getline(std::cin, id);
                manager.deallocateRoom(id);
                break;
            }
            case 3:
                manager.displayAllStudents();
                break;
            case 4: {
                std::string id;
                clearBuffer();
                std::cout << "Enter Student ID to search: ";
                std::getline(std::cin, id);
                manager.searchStudent(id);
                break;
            }
            case 5:
                std::cout << "\n Exiting Hostel Management System. Data saved. Goodbye!\n";
                return 0;
            default:
                std::cout << "\n Option out of bounds. Select a choice from 1 to 5.\n";
        }
    }
    return 0;
}