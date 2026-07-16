# ALFIDO-TECH-TASK3
# Internship Task 3 (Final Task): C++ Hostel Management System

Welcome to the repository for my third and final task of the C/C++ Programming Internship at **Alfido Tech**. 

This project implements an enterprise-style, console-based **Hostel Management System** written in modern C++. By pivoting away from standard introductory projects, this system addresses a real-world utility scenario: managing student room allocations, maintaining room occupancy rules, and persisting records securely across sessions using flat-file storage.

---

## 🛠️ Key Architectural & OOP Pillars

This application demonstrates a strong command of modern Object-Oriented Programming (OOP) design patterns and C++ Standard Template Library (STL) integration:

* **Encapsulation & Abstraction:** Sensitive properties (such as Room Numbers and Student IDs) are hidden under `private` and `protected` scopes, exposed safely only via public getters and state-changing setters.
* **Inheritance:** A polymorphic base class `Person` is extended by the derived `Student` class, promoting clean code reuse and structural extensibility.
* **Standard Template Library (STL):** Memory management is handled dynamically using `std::vector` rather than legacy raw pointer arrays, eliminating manual heap allocations and potential memory leaks.
* **Robust File Persistence:** All records are dynamically written to and loaded from a flat-file database (`hostel_records.txt`), ensuring data is never lost when the console session terminates.
* **Input Validation & Buffer Management:** Features strict input stream handling to prevent infinite loops, buffer overflows, or invalid system choices.

---

## 📁 File Structure

The project has been unified into a single, cohesive file for direct, compilation-friendly deployment:

* **`main.cpp`**: Contains the full class definitions (`Person`, `Student`, `HostelManager`), system file storage routines, and the interactive command-line interface (CLI) menu.
* **`hostel_records.txt`**: *(Auto-generated)* Acts as the local storage database for student and room metadata.

---

## ⚙️ Compilation and Execution

To run this application on your local machine, make sure you have a working C++ compiler (such as GCC/MinGW) installed.

1. **Clone the repository:**
   ```bash
   git clone <your-repository-link>
   cd "ALFIDO TECH TASK3"