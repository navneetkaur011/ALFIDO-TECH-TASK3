# ALFIDO-TECH-TASK3
# Internship Task 3 (Final Task): University Hostel Management System

## Project Overview
A robust C++ application designed to efficiently manage student hostel records, facility details, and room allocations. This project was developed as a final task for the ALFIDO TECH internship, focusing on Object-Oriented Programming (OOP) principles, standard template libraries (STL), and persistent file storage.

## Key Features
- **Object-Oriented Design**: Utilizes inheritance to differentiate between hostel types while maintaining a shared base structure.
- **Modern Memory Management**: Implements smart pointers (`std::unique_ptr`) to ensure efficient memory allocation and prevent leaks.
- **Scalable Architecture**: Designed to easily accommodate 8–10+ hostels by extending the class hierarchy.
- **Data Persistence**: Includes a structured data storage approach for future expansion into file-based database management.

## Technical Stack
- **Language**: C++17
- **Build System**: Make
- **Compiler**: g++

## Project Structure
- `include/`: Contains the header file (`Hostel.h`) with class declarations.
- `src/`: Contains implementation logic (`Hostel.cpp`) and the main execution entry point (`main.cpp`).
- `data/`: Contains external storage (`hostel_db.txt`) for persistent data.
- `Makefile`: Automates the compilation process for consistency across environments.

## How to Compile and Run
1. Ensure you have `g++` and `make` installed.
2. Open your terminal in the project root directory: `Alfido tech task3`
3. Compile the project:
   ```bash
   make
4. Execute the program:
   ```bash
   ./university_hostel
## Troubleshooting
- If you receive a 'make: command not found' error, ensure you have the GCC compiler (MinGW on Windows) installed and added to your system PATH. 
- Alternatively, you can compile manually using:
  `g++ -std=c++17 src/main.cpp src/Hostel.cpp -Iinclude -o university_hostel`