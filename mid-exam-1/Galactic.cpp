#include <iostream>
// Scenario: The "Galactic" Agency manages space missions.
// 1. Astronaut Class: Each astronaut has a name (string) and experience (int years).
// 2. Mission Class: A mission has:
//     ◦ A missionID (string).
//     ◦ A capacity (int) determining how many astronauts can join.
//     ◦ A dynamic array of Astronaut objects (representing the crew).
//     ◦ A variable currentCount to track how many astronauts have been added.
// Tasks:
// a) (5 Marks) Implement the Astronaut class with a parameterized constructor and a getter for the name.
// b) (8 Marks) Implement the Mission class containing:
// • A Constructor that accepts the missionID and capacity. It must dynamically allocate an array of Astronaut objects based on the capacity.
// • A function addAstronaut(Astronaut a) that adds an astronaut to the array if capacity allows.
// c) (7 Marks) The agency needs to create a backup mission by copying an existing one (Mission backup = original;). Implement the Deep Copy Constructor for the Mission class. Critical Requirement: You must allocate a new array for the backup mission and copy all existing astronauts from the source mission to the new one.
#include <string>
using namespace std;
class Astronuat{
    private:
    string name;
    int year;
    public:
    Astronuat(){}
    Astronuat(string name,int year){
        this->name = name;
        this->year = year;
    }
    string getName(){
       return name;
    }
};
class Mission{
    private:
    string MisssionID;
    int capacity;
    int currentCount;
    Astronuat *Crew;
    public:
    Mission(string MissionID,int capacity){
        this->capacity = capacity;
        this->MisssionID = MissionID;
        currentCount = 0;
        Crew = new Astronuat[capacity];
    }
    void addAstronuat(Astronuat a){
        if(currentCount < capacity){
            Crew[currentCount++] = a;
        }else{
            cout << "Capacity is full\n" ;
        }

    }
    Mission (const Mission& other){
        MisssionID = other.MisssionID;
        capacity = other.capacity;
        Crew = new Astronuat[other.capacity];
        currentCount = other.currentCount;
        for(int i=0;i<currentCount;i++){
            Crew[i] = other.Crew[i];
        }
    }
    ~Mission(){
        delete[] Crew;
    }

};
int main(){
   Mission m1("101",2);
   Astronuat a("anas",2);
   m1.addAstronuat(a);
   Mission m2 = m1;
   cout << a.getName();
   return 0;
}