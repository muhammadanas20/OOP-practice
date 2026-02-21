#include <iostream>
#include <string>
using namespace std;
class SmartThermostat
{
private:
    double currentTemp;
    double targetTemp;
    string roomName;

public:
    SmartThermostat(string roomName = "", double current = 0.0, double target = 0.0) : currentTemp(current), targetTemp(target)
    {
        this->roomName = roomName;
    }
    SmartThermostat(const SmartThermostat &other)
    {
        roomName = other.roomName;
        currentTemp = other.currentTemp;
        targetTemp = 22.0;
    }
    void adjustTemp(string command)
    {
        for (int i = 0; command[i] != '\0'; i++)
        {
            if (command[i] == 'U' || command[i] == 'u')
            {
                targetTemp++;
            }
            else if (command[i] == 'D' || command[i] == 'd')
            {
                targetTemp--;
            }
        }
    }
    void displayInfo() const
    {
        cout << "Room Name:" << roomName << endl;
        cout << "Target Temp:" << targetTemp << " C" << endl;
        cout << "Current Temp:" << currentTemp << " C" << endl;
    }
};
int main()
{
   SmartThermostat s1;
   s1.adjustTemp("UUDD");
   s1.displayInfo();
    return 0;
}