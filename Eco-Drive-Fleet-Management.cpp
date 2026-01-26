#include <iostream>
#include <string>
using namespace std;
class Car
{
private:
    const int plateNo;
    string modelName;
    float batteryCapacity;

public:
    Car(string name, int cap, int no) : plateNo(no)
    {
        modelName = name;
        batteryCapacity = cap;
    }
    Car() : plateNo(0), modelName(""), batteryCapacity(0.0) {} // default for initliaze object array
    Car &operator=(const Car &other)
    {
        modelName = other.modelName;
        batteryCapacity = other.batteryCapacity;
        return *this;
    }
    void display() const
    {
        cout << "model Name:" << modelName << "\nplate No" << plateNo << "\nbatery capacity:" << batteryCapacity;
    }
};
class Garage
{
private:
    int maxCapacity;
    static int current_count;
    string location;
    Car *cars;

public:
    Garage(string loc, int max) : location(loc), maxCapacity(max)
    {
        cars = new Car[maxCapacity];
    }
    void addCar(string name, int no, float cap)
    {
        if (current_count < maxCapacity)
        {
            cars[current_count] = Car(name, cap, no);
            cout << "Car added sucessfully" << ++current_count << endl;
        }
        else
        {
            cout << "garage is full";
        }
    }
    ~Garage()
    {
        delete[] cars;
    }
};
int Garage::current_count = 0;
int main()
{
    Garage one("KHI", 10);
    one.addCar("alto", 4303, 43.3);
    one.addCar("alto", 4303, 43.3);
    one.addCar("alto", 4303, 43.3);
    one.addCar("alto", 4403, 43.3);
    one.addCar("alto", 4303, 43.3);
    one.addCar("rlto", 4303, 43.3);
    one.addCar("alto", 4303, 43.3);
    one.addCar("alto", 4303, 43.3);
    one.addCar("ylto", 4303, 43.3);
    one.addCar("alto", 4303, 43.3);
    one.addCar("alto", 4303, 43.3);

    return 0;
}