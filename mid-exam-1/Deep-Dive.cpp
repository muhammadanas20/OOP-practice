#include <iostream>
#include <string>
using namespace std;

class Drone
{
private:
    const int modelId;
    string status;
    int batteryLevel;

public:
    Drone(int model, string status, int level)
        : modelId(model), status(status), batteryLevel(level) {}

    Drone() : modelId(0), status(""), batteryLevel(0) {}

    void display() const
    {
        cout << "Model: " << modelId
             << "\nStatus: " << status
             << "\nBattery Level: " << batteryLevel << "%\n";
    }
};

class Squadron
{
private:
    string commanderName;
    int maxDrones;
    int current_count;
    Drone **List;
    static int total;

public:
    Squadron(string commanderName, int maxDrone)
        : commanderName(commanderName),
          maxDrones(maxDrone),
          current_count(0)
    {

        List = new Drone *[maxDrones];
    }

    void addDrone(int id, int batt, string stat)
    {
        if (current_count < maxDrones)
        {
            List[current_count] = new Drone(id, stat, batt);
            total++;
            cout << "Drone added successfully\n";
            List[current_count]->display();
            current_count++;
        }
        else
        {
            cout << "Squadron full\n";
        }
    }
    Squadron(const Squadron &other)
    {
        this->commanderName = other.commanderName;
        this->maxDrones = other.maxDrones;
        this->current_count = other.current_count;

        // 1. Allocate the array of pointers
        this->List = new Drone *[maxDrones];

        // 2. DEEP COPY: Create new drone objects for each pointer
        for (int i = 0; i < current_count; i++)
        {
            // Assuming Drone has a copy constructor (compiler provides a default one)
            this->List[i] = new Drone(*other.List[i]);
        }
    }
    ~Squadron()
    {
        for (int i = 0; i < current_count; i++)
        {
            delete List[i]; // delete each drone
        }
        delete[] List; // delete pointer array
        total -= current_count;
    }
};

int Squadron::total = 0;

int main()
{
    Squadron s1("Alpha-class", 3);
    s1.addDrone(1, 87, "Complete");
    return 0;
}
