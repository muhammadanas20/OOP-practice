// Question 3: Resolving the Diamond Problem in Multiple Inheritance
// Concepts Tested: Inheritance, Advanced Access Modifiers, and Resolving the Diamond Problem (07).
// Scenario: A prestigious software house manages employees based on their technical roles
// . They need an object-oriented model to represent their hierarchy without data redundancy.
// Requirements:
// Base Class: Create a base class Employee with attributes name, age, and joiningDate
// . Include a parameterized constructor.
// Intermediate Derived Classes:
// Create a Developer class that inherits from Employee and adds a role attribute (e.g., "frontend developer" or "backend developer")
// .
// Create a Debugger class that also inherits from Employee and adds a role attribute (e.g., "manual debugger" or "auto debugger")
// .
// The Diamond Problem: Create a TeamLead class that inherits from both Developer and Debugger
// .
// Resolution: Because a TeamLead is both a developer and a debugger, inheriting from both creates two copies of the Employee attributes (The Diamond Problem). Resolve this using virtual inheritance
// .
// Execution: Ensure the TeamLead constructor properly passes initialization data directly to the Employee base class. Instantiate a TeamLead object in main() and call a method to display all data with respect to their dual roles
// .
#include <iostream>
using namespace std;

class Employee {
protected:
    string name;
    int age;
    string joiningDate;

public:
    Employee(string n, int a, string jd) : name(n), age(a), joiningDate(jd) {}
    
    void displayEmployee() {
        cout << "Name: " << name << ", Age: " << age << ", Joining Date: " << joiningDate << endl;
    }
};

class Developer : virtual public Employee {
protected:
    string devRole;

public:
    Developer(string n, int a, string jd, string dr) : Employee(n, a, jd), devRole(dr) {}
    
    void displayDeveloper() {
        cout << "Developer Role: " << devRole << endl;
    }
};

class Debugger : virtual public Employee {
protected:
    string debugRole;

public:
    Debugger(string n, int a, string jd, string dr) : Employee(n, a, jd), debugRole(dr) {}
    
    void displayDebugger() {
        cout << "Debugger Role: " << debugRole << endl;
    }
};

class TeamLead : public Developer, public Debugger {
public:
    TeamLead(string n, int a, string jd, string dr, string dbr) 
        : Employee(n, a, jd), Developer(n, a, jd, dr), Debugger(n, a, jd, dbr) {}
    
    void displayAll() {
        displayEmployee();
        displayDeveloper();
        displayDebugger();
    }
};

int main() {
    TeamLead lead("Ahmed Khan", 30, "2020-01-15", "Backend Developer", "Auto Debugger");
    lead.displayAll();
    return 0;
}





