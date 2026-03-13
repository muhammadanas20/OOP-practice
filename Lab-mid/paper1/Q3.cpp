// Question 3: Multiple Inheritance and Resolving the Diamond Problem
// Topics Covered: Inheritance, Inheritance Types, Advanced Access Modifiers, and Resolving the Diamond Problem (07).
// Scenario: A software house has employees who are passionate about their roles. Some are developers and some are debuggers
// . All affiliated employees are collectively known as Employees (with attributes: name, age, and joining date)
// .
// Requirements:
// Base and Derived Classes:
// A Developer has the attribute role (frontend developer or backend developer)
// .
// A Debugger has the attribute role (manual debugger or auto debugger)
// .
// The Diamond Problem: A TeamLead is both a Developer and a Debugger
// . Identify the type of inheritance present here (Multiple/Multipath)
// .
// Implementation: Implement this scenario in code. Provide appropriate constructors, advanced access modifiers (like protected if needed), and accessor functions
// .
// Resolution: Use virtual inheritance to resolve the Diamond Problem so that the TeamLead class only inherits a single copy of the base Employee attributes
// . Create an object of TeamLead in main() to demonstrate your solution
#include <iostream>
using namespace std;
class Employee{
    private:
    string name;
    int age;
    string joiningDate;
    public:
    Employee(string name,int age,string date){
        this->name = name;
        this->age = age;
        joiningDate = date;
    }

    string getName() const {
        return name;
    }

    int getAge() const {
        return age;
    }

    string getJoiningDate() const {
        return joiningDate;
    }
};
class Developer: virtual public Employee{
     private:
     string role;
     public:
     Developer(string role,string name,int age,string date):Employee(name,age,date),role(role){}

     string getDeveloperRole() const {
        return role;
     }
};
class Debugger: virtual public Employee{
    private:
    string role;
    public:
    Debugger(string role,string name,int age,string date):Employee(name,age,date),role(role){}

    string getDebuggerRole() const {
        return role;
    }
};

class TeamLead : public Developer, public Debugger {
    public:
    TeamLead(string name, int age, string date, string developerRole, string debuggerRole)
        : Employee(name, age, date),
          Developer(developerRole, name, age, date),
          Debugger(debuggerRole, name, age, date) {}

    void displayDetails() const {
        cout << "Name: " << getName() << endl;
        cout << "Age: " << getAge() << endl;
        cout << "Joining Date: " << getJoiningDate() << endl;
        cout << "Developer Role: " << getDeveloperRole() << endl;
        cout << "Debugger Role: " << getDebuggerRole() << endl;
    }
};

int main() {
    TeamLead tl("Anas", 18, "2025-06-01", "frontend developer", "manual debugger");
    tl.displayDetails();
    return 0;
}