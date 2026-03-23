// Module II: Architectural Design & The Diamond Problem (40 Marks)
// Pattern: Complex Multi-level System Design with Overloading. Concepts Tested: Multiple Inheritance, Resolving the Diamond Problem (07), Polymorphism & Pure Virtual Functions, Operator Overloading (08).
// System Architecture (Karachi Court Management System): You are tasked with designing a software system specifically tailored for managing operations within a court system.
// Implementation Requirements:
// Abstract Base Entity: Create a base class Person with common attributes (name, ID). It must include a pure virtual function displayRole()
// .
// Intermediate Entities:
// Victim class: Inherits from Person. Has attributes like victim history and role (e.g., Guilty or not guilty)
// .
// Lawyer class: Inherits from Person. Has attributes such as license number, specialization, years of practice, and victim evidence
// .
// Judge class: Inherits from Person. Has attributes like judicial ID, years of experience, and specialization
// .
// Complex Multiple Inheritance: Create an Admin class that represents a physical courtroom. It manages the legal proceedings and facility (attributes: room number, capacity, availability schedule). The Admin class must inherit from multiple classes to process interactions between the Victim, Lawyer, and Judge
// .
// Challenge: Resolve any ambiguity (Diamond Problem) that arises if multiple paths lead back to the base Person class using virtual inheritance
// .
// Operator Overloading: Overload the + operator in the Admin class so that adding two Admin objects together combines their capacity and returns a new updated Admin object. Overload the << operator to print the Admin details directly.
#include <iostream>
using namespace std;

class Victim{
    
};
int main(){

}