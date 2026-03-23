// Design a Fleet Management System. A Fleet is a collection of Vehicles. A Fleet HAS-A dynamic array of Vehicle objects.

// Each Vehicle has an immutable registration number and an immutable vehicle type (e.g., "Truck", "Van"). Vehicles track their current fuel level (in litres).

// Fleets should support operator+= to add a vehicle to the fleet (if capacity allows), and operator[] to access a vehicle at a given index safely (with bounds checking).
// Vehicle Class
// const string registrationNo, const string vehicleType — both immutable.
// double fuelLevel (default 0.0), static int totalVehicles.
// Method refuel(double litres) — adds fuel; warns if litres is negative.
// Method display() — shows all vehicle details.
// Destructor decrements totalVehicles.
// Fleet Class
// Attributes: const string fleetName, int maxCapacity, dynamic array of Vehicle pointers, int currentCount (starts at 0).
// Static count of total fleets.
// operator+=: adds a Vehicle pointer to the fleet. If the fleet is full, print "[FLEET FULL] Cannot add vehicle.". Returns Fleet& for chaining.
// operator[]: returns a reference to Vehicle* at index. If index is out of bounds, print an error and return a reference to a null sentinel.
// Method displayFleet() — lists all vehicles in the fleet.
// Method totalFuel() — returns sum of fuel levels across all fleet vehicles.
// Destructor: frees only the array (not the vehicles).
// Testing
// Create 2 Fleet objects (different max capacities) and 5 Vehicle objects dynamically.
// Use fleet += vehicle (chained: fleet += v1 += v2 — does this even make sense? why or why not?).
// Access vehicles using fleet[0], fleet[1], and test out-of-bounds with fleet[99].
// Call totalFuel() and compare two fleets.
// Delete all objects; verify static counts.
// Think About
// operator[] returning a reference allows assignment: fleet[0] = newVehicle. Is this the right design? What safeguards are needed?
// The fleet stores Vehicle pointers, not Vehicle objects. What happens if the Fleet destructor tries to delete the pointed-to Vehicles?
// Can operator+= be a member function? Yes. Can it be a friend? It doesn't need to be — why?
// Never attempt to delete or dereference a null sentinel pointer returned from an out-of-bounds operator[]. Defensive design is required.

#include <iostream>
#include <string>
using namespace std;

class Vehicle {
private:
	const string registrationNo;
	const string vehicleType;
	double fuelLevel;
	static int totalVehicles;

public:
	Vehicle(const string& regNo, const string& type, double fuel = 0.0)
		: registrationNo(regNo), vehicleType(type), fuelLevel(fuel) {
		++totalVehicles;
	}

	void refuel(double litres) {
		if (litres < 0) {
			cout << "[ERROR] Cannot refuel negative litres." << endl;
			return;
		}
		fuelLevel += litres;
	}

	double getFuelLevel() const {
		return fuelLevel;
	}

	void display() const {
		cout << "RegNo: " << registrationNo
			 << ", Type: " << vehicleType
			 << ", Fuel: " << fuelLevel << " L" << endl;
	}

	static int getTotalVehicles() {
		return totalVehicles;
	}

	~Vehicle() {
		--totalVehicles;
	}
};

int Vehicle::totalVehicles = 0;

class Fleet {
private:
	const string fleetName;
	int maxCapacity;
	Vehicle** vehicles;
	int currentCount;
	static int totalFleets;
	static Vehicle* nullSentinel;

public:
	Fleet(const string& name, int capacity)
		: fleetName(name), maxCapacity(capacity), currentCount(0) {
		vehicles = new Vehicle*[maxCapacity];
		for (int i = 0; i < maxCapacity; ++i) {
			vehicles[i] = nullptr;
		}
		++totalFleets;
	}

	Fleet& operator+=(Vehicle* vehiclePtr) {
		if (currentCount >= maxCapacity) {
			cout << "[FLEET FULL] Cannot add vehicle." << endl;
			return *this;
		}
		vehicles[currentCount++] = vehiclePtr;
		return *this;
	}

	Vehicle*& operator[](int index) {
		if (index < 0 || index >= currentCount) {
			cout << "[ERROR] Index out of bounds for fleet access." << endl;
			return nullSentinel;
		}
		return vehicles[index];
	}

	void displayFleet() const {
		cout << "\nFleet: " << fleetName << " (" << currentCount << "/" << maxCapacity << ")" << endl;
		for (int i = 0; i < currentCount; ++i) {
			cout << "  [" << i << "] ";
			if (vehicles[i] != nullptr) {
				vehicles[i]->display();
			} else {
				cout << "nullptr" << endl;
			}
		}
	}

	double totalFuel() const {
		double sum = 0.0;
		for (int i = 0; i < currentCount; ++i) {
			if (vehicles[i] != nullptr) {
				sum += vehicles[i]->getFuelLevel();
			}
		}
		return sum;
	}

	static int getTotalFleets() {
		return totalFleets;
	}

	~Fleet() {
		delete[] vehicles;
		--totalFleets;
	}
};

int Fleet::totalFleets = 0;
Vehicle* Fleet::nullSentinel = nullptr;

int main() {
	Fleet* cityFleet = new Fleet("City Logistics", 3);
	Fleet* highwayFleet = new Fleet("Highway Cargo", 4);

	Vehicle* v1 = new Vehicle("ABC-101", "Truck", 50.0);
	Vehicle* v2 = new Vehicle("ABC-102", "Van", 30.0);
	Vehicle* v3 = new Vehicle("ABC-103", "Truck", 70.0);
	Vehicle* v4 = new Vehicle("ABC-104", "Mini Van", 20.0);
	Vehicle* v5 = new Vehicle("ABC-105", "Trailer", 90.0);

	cityFleet->operator+=(v1).operator+=(v2).operator+=(v3);
	*highwayFleet += v4;
	*highwayFleet += v5;

	*cityFleet += v4;

	cityFleet->displayFleet();
	highwayFleet->displayFleet();

	Vehicle* temp = (*cityFleet)[0];
	if (temp != nullptr) {
		temp->refuel(10.0);
	}

	Vehicle* out = (*cityFleet)[99];
	if (out != nullptr) {
		out->display();
	}

	cout << "\nTotal Fuel (City): " << cityFleet->totalFuel() << " L" << endl;
	cout << "Total Fuel (Highway): " << highwayFleet->totalFuel() << " L" << endl;

	if (cityFleet->totalFuel() > highwayFleet->totalFuel()) {
		cout << "City fleet has more fuel." << endl;
	} else if (cityFleet->totalFuel() < highwayFleet->totalFuel()) {
		cout << "Highway fleet has more fuel." << endl;
	} else {
		cout << "Both fleets have equal fuel." << endl;
	}

	cout << "\nActive Fleets: " << Fleet::getTotalFleets() << endl;
	cout << "Active Vehicles: " << Vehicle::getTotalVehicles() << endl;

	delete cityFleet;
	delete highwayFleet;

	delete v1;
	delete v2;
	delete v3;
	delete v4;
	delete v5;

	cout << "\nAfter cleanup -> Active Fleets: " << Fleet::getTotalFleets() << endl;
	cout << "After cleanup -> Active Vehicles: " << Vehicle::getTotalVehicles() << endl;

	return 0;
}