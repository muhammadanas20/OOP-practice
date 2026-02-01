#include <iostream>
using namespace std;
#include <string>
class Battery
{
public:
    int capacity;
    string model;
    Battery(string model, int capacity)
    {
        this->capacity = capacity;
        this->model = model;
    }
};
class Drone
{
private:
    const int droneId;
    Battery *batt;
    static int totalDorne;

public:
    Drone(string model, int capacity, int id) : droneId(id)
    {
        batt = new Battery(model, capacity);
        totalDorne++;
    }
    Drone(const Drone &other):droneId(other.droneId)
    {
        batt = new Battery(other.batt->model,other.batt->capacity);
    }
    ~Drone()
    {
        delete batt;
    }
    void display(){
        cout << "Drone ID:" << droneId << "\nCapacity:" << batt->capacity << "\nModel Name:" << batt->model <<"\n";
    }
};
int Drone::totalDorne = 0;
int main()
{
    Drone d1("Osaka",100,1);
    Drone d2 = d1;
    d1.display();
    d2.display();
    return 0;
}