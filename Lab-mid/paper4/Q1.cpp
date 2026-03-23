// Module I: System Extraction & Immutable Composition (30 Marks)
// Pattern: You are given business requirements. You must extract the classes, define their strict relationships, and manage memory without any hints. Concepts Tested: Has-A Relationship, Pointers, DMA (02, 05), Static & Constant Members (05), Member Initialization Lists (04).
// Business Scenario (Hospital Doctor Management System): A prestigious hospital requires a robust system to track doctors and their assigned departments. The system must maintain strict data integrity and efficient memory usage
// .
// Implementation Requirements:
// Department Management: Each department must have a uniquely identified name. Maintain a real-time, global count of the total number of hospital departments
// .
// Doctor Management & Immutability: Every doctor must be assigned a unique, auto-incremented doctor ID. This ID and the doctor's name must be immutable (cannot be modified after creation)
// .
// Strict Has-A Relationship: Associate each doctor permanently with a specific department upon creation using pointers. The association must be established strictly at the time of object construction
// .
// Dynamic Memory & Tracking: Dynamically allocate memory for doctor objects when they are added to the system. You must properly deallocate memory when a doctor resigns to ensure absolutely no memory leaks occur
// .
// Constraint: Use a Member Initialization List to enforce the immutability of the doctor’s ID, Name, and Department assignment
// .
#include <iostream>
#include <string>
using namespace std;

class Department {
private:
    string name;
    static int totalDepartments; // Shared among all objects [16]

public:
    Department(string deptName) : name(deptName) {
        totalDepartments++; // Increment when created
    }
    ~Department() {
        totalDepartments--; // Decrement when destroyed
    }
    
    // Static function to access static data [17]
    static int getTotalDepartments() { 
        return totalDepartments; 
    }
    
    // Const function guarantees data won't be modified [18]
    string getName() const { 
        return name; 
    }
};

// Initialization of static variable outside the class is mandatory [19]
int Department::totalDepartments = 0; 

class Doctor {
private:
    const int doctorID;        // Constant member [12]
    const string name;         // Constant member [12]
    Department* assignedDept;  // Pointer for Has-A relationship [15, 20]
    static int nextID;

public:
    // Constants MUST be initialized using a constructor initializer list [12, 13]
    Doctor(string docName, Department* dept) 
        : doctorID(nextID++), name(docName), assignedDept(dept) {
        cout << "Doctor " << name << " added dynamically." << endl;
    }

    void displayDetails() const { // Read-only operation [18]
        cout << "ID: " << doctorID << " | Name: " << name 
             << " | Dept: " << assignedDept->getName() << endl;
    }
};
int Doctor::nextID = 1;

// Driver code to test Dynamic Memory Allocation [21, 22]

int main() {
    Department cardiology("Cardiology");
    Doctor* doc1 = new Doctor("Dr. Ahmed", &cardiology); // Dynamic allocation [22]
    doc1->displayDetails();
    delete doc1; // Prevent memory leak [22]
    doc1 = nullptr; // Avoid dangling pointer [23]
    return 0;
}