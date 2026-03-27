// LLO #: 3 Apply inheritance concepts in C++ by implementing different types of inheritance, utilizing advanced access modifiers, and demonstrating polymorphism effectively.
// [points: 14, wgt: 07]
// Q3: Create a home entertainment system management program. Create a base class Device with attributes for the device name, power rating (watts), and daily usage hours. A derived class EntertainmentRoom manages up to 5 devices, calculating total daily energy consumption in kWh.
// Include a Discount class to apply a percentage-based discount to the electricity cost. EntertainmentRoom should inherit from Device and Discount, integrating features to calculate total cost after discount. Implement displayEnergySummary() to show device details, total energy usage, total cost before and after discount, and the device consuming the most energy.
// 1.	Device Class:
// o	name (string): Device name (e.g., "TV").
// o	power (float): Power rating in watts.
// o	hours (float): Daily usage in hours.
// 2.	EntertainmentRoom Class:
// o	deviceCount (int): Number of devices added (max 5).
// o	Member Functions:
// 	addDevice(Device): Adds a device (max 5).
// 	calculateTotalEnergy(): Total energy consumption in kWh.
// 	findHighestEnergyDevice(): Returns device consuming most energy.
// 	displayEnergySummary(): Displays all device details, total energy, total cost before/after discount, and highest-consuming device.
// 3.	Discount Class:
// o	discountPercentage (float): Discount on electricity cost.
// o	Member Function:
// 	applyDiscount(float totalCost): Returns cost after discount.
// Assumptions:
// •	Electricity cost per kWh = $0.15
// Sample Output:
// Entertainment Room Devices:
// TV: 100W, 6 hours/day
// Gaming Console: 200W, 4 hours/day
// Sound System: 150W, 5 hours/day

// Total Energy Consumption: 4.3 kWh
// Total Cost before discount: $0.65
// Total Cost after discount: $0.55
// Highest Energy Consuming Device: Gaming Console (200W, 4 hours/day)

#include <iostream>
#include <iomanip>   // for precision
using namespace std;
class Discount{
    private:
    float discountPercentage;
    public:
    Discount(float discount = 0.0f) : discountPercentage(discount) {}

    float applyDiscount(float totalCost) const {
        return totalCost - (discountPercentage / 100.0f) * totalCost;
    }
};

class Device{
    private:
    string name;
    float power;
    float dailyHours;

    public:
    Device() : name(""), power(0.0f), dailyHours(0.0f) {}
    Device(string name, float power, float dailyHours)
        : name(name), power(power), dailyHours(dailyHours) {}

    string getName() const { return name; }
    float getPower() const { return power; }
    float getDailyHours() const { return dailyHours; }

    float calculateEnergy() const {
        return (power * dailyHours) / 1000.0f;
    }
};

class EntertainmentRoom : public Device, public Discount{
    private:
    Device devices[5];
    int deviceCount;
    static constexpr float COST_PER_KWH = 0.15f;  //constexpr like #define but safer complie before runs

    public:
    EntertainmentRoom(float discount = 0.0f)
        : Device("Entertainment Room", 0.0f, 0.0f), Discount(discount), deviceCount(0) {}

    void addDevice(const Device& device){
        if (deviceCount < 5) {
            devices[deviceCount++] = device;
        } else {
            cout << "full devices.\n";
        }
    }

    float calculateTotalEnergy() const {
        float totalEnergy = 0.0f;
        for (int i = 0; i < deviceCount; i++) {
            totalEnergy += devices[i].calculateEnergy();
        }
        return totalEnergy;
    }

    Device findHighestEnergyDevice() const {
        if (deviceCount == 0) {
            return Device("No Device", 0.0f, 0.0f);
        }

        int highestIndex = 0;
        for (int i = 1; i < deviceCount; i++) {
            if (devices[i].calculateEnergy() > devices[highestIndex].calculateEnergy()) {
                highestIndex = i;
            }
        }
        return devices[highestIndex];
    }

    void displayEnergySummary() const {
        cout << "Entertainment Room Devices:" << endl;
        for (int i = 0; i < deviceCount; i++) {
            cout << devices[i].getName() << ": "
                 << devices[i].getPower() << "W, "
                 << devices[i].getDailyHours() << " hours/day" << endl;
        }

        float totalEnergy = calculateTotalEnergy();
        float totalCostBeforeDiscount = totalEnergy * COST_PER_KWH;
        float totalCostAfterDiscount = applyDiscount(totalCostBeforeDiscount);
        Device highest = findHighestEnergyDevice();

        cout << fixed << setprecision(2); // for printing decimal value upto 2 places
        cout << "\nTotal Energy Consumption: " << totalEnergy << " kWh" << endl;
        cout << "Total Cost before discount: $" << totalCostBeforeDiscount << endl;
        cout << "Total Cost after discount: $" << totalCostAfterDiscount << endl;
        cout << "Highest Energy Consuming Device: " << highest.getName()
             << " (" << highest.getPower() << "W, "
             << highest.getDailyHours() << " hours/day)" << endl;
    }
};

int main(){
    EntertainmentRoom room(15.0f);

    room.addDevice(Device("TV", 100.0f, 6.0f));
    room.addDevice(Device("Gaming Console", 200.0f, 4.0f));
    room.addDevice(Device("Sound System", 150.0f, 5.0f));

    room.displayEnergySummary();
    return 0;
}
