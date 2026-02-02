// Question 3: Design Scenario [15 Marks]
// (Ref: Adapted from "Space Exploration Agency" Spring '24 and "Geass Corp")
// Scenario: "GalaxySystems" manufactures high-end laptops.
// 1. Processor Class: Contains a model (string) and speed (float).
// 2. Laptop Class: Contains:
//     ◦ A serialNumber (string).
//     ◦ A pointer to a Processor object (Composition).
//     ◦ A static variable laptopCount to track how many laptops exist.
// Tasks:
// a) (4 Marks) Implement the Processor class with a parameterized constructor.
// b) (6 Marks) Implement the Laptop class.
// • Initialize laptopCount to 0.
// • Write a Constructor that takes a serial number, processor model, and speed. It must dynamically allocate a new Processor object and increment the count.
// • Write the Destructor to free memory.
// c) (5 Marks) The company needs to clone laptops for testing. Implement the Deep Copy Constructor for the Laptop class. Ensure that the new laptop gets its own distinct Processor in memory, not a shared pointer.
#include <iostream>
using namespace std;
#include <string>
class Processor
{
public:
    string model;
    float speed;

public:
    Processor(string madel, float speed) : model(model), speed(speed) {}
};
class Laptop
{
private:
    string serialNumber;
    Processor *composition;
    static int laptopcount;

public:
    Laptop(string serialNo, string model, float speed) : serialNumber(serialNo)
    {
        composition = new Processor(model, speed);
        laptopcount++;
    }
    ~Laptop()
    {
        delete composition;
    }
    Laptop(const Laptop &other)
    {
        this->serialNumber = other.serialNumber;
        this->composition = new Processor(other.composition->model, other.composition->speed);
        laptopcount++;
    }
    void display()
    {
        cout << "serialNo:" << serialNumber << "\nModel:" << composition->model << "\nSpeed:" << composition->speed << "\nLaptop count:" << laptopcount;
    }
};
int Laptop::laptopcount = 0;
int main()
{
    Laptop l1("5282", "AMD", 440);
    Laptop l2 = l1;
    l1.display();
    l2.display();
    return 0;
}