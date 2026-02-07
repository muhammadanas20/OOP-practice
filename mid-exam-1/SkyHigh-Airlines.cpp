#include <iostream>
using namespace std;

class Passenger {
public:
    string name;
    int ticketNumber;
    Passenger() {} // Default needed for array
    Passenger(string n, int t) : name(n), ticketNumber(t) {}
};
class Flight {
    const string flightID; // Const member
    int capacity;
    Passenger* passengers; // Dynamic Array
    
public:
    static int flightCount;

    // Member Initialization List required for 'flightID'
    Flight(string id, int cap) : flightID(id) {
        capacity = cap;
        passengers = new Passenger[capacity]; // Allocate Array
        flightCount++;
    }

    ~Flight() {
        delete[] passengers; // Use delete[] for arrays
        flightCount--;
    }
// c) Deep Copy Constructor
    Flight(const Flight& other) : flightID(other.flightID) {
        capacity = other.capacity;
        
        // 1. Allocate NEW memory
        passengers = new Passenger[capacity];
        
        // 2. Copy Loop (Deep Copy)
        for(int i = 0; i < capacity; i++) {
            passengers[i] = other.passengers[i];
        }
        
        flightCount++;
    }
};
int Flight::flightCount = 0;
int main(){
    
}