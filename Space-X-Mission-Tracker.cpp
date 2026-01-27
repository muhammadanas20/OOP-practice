#include <iostream>
#include <string>
using namespace std;

class Astronaut {
private:
    string name;
    const int passportId; // [cite: 636]
public:
    // Member initialization list is mandatory for const [cite: 449]
    Astronaut() : name(""), passportId(0) {} 
    Astronaut(string n, int id) : name(n), passportId(id) {}
    
    // Copy assignment operator
    Astronaut& operator=(const Astronaut &other) {
        if (this != &other) {
            name = other.name;
            // Note: passportId is const and cannot be reassigned
        }
        return *this;
    }
};

class Mission {
private:
    const int uniqueID;
    int maxcapacity;
    int current_count;
    static int total_count; // [cite: 496]
    Astronaut *List;

public:
    Mission(int id, int cap) : uniqueID(id), maxcapacity(cap), current_count(0) {
        List = new Astronaut[maxcapacity]; // [cite: 639]
    }

    // DEEP COPY CONSTRUCTOR [cite: 437, 505]
    Mission(const Mission &other) : uniqueID(other.uniqueID + 100) { // IDs must be unique
        maxcapacity = other.maxcapacity;
        current_count = other.current_count;
        List = new Astronaut[maxcapacity];
        for (int i = 0; i < current_count; i++) {
            List[i] = other.List[i];
        }
    }

    static int getTotal_Astronaut() { return total_count; }

    ~Mission() {
        delete[] List; // 
    }

    // Deep Assignment Operator [cite: 146]
    Mission& operator=(const Mission &other) {
        if (this != &other) { // Self-assignment check
            delete[] List; // Free existing memory first
            maxcapacity = other.maxcapacity;
            current_count = other.current_count;
            List = new Astronaut[maxcapacity];
            for (int i = 0; i < current_count; i++) {
                List[i] = other.List[i];
            }
        }
        return *this;
    }
};

int Mission::total_count = 0; // 

int main() {
    Mission m1(1, 5);
    Mission m2 = m1; // Calls Copy Constructor
    return 0;
}