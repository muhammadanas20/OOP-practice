#include <iostream>
using namespace std;
class Passenger
{
private:
    string name;
    int passNum;

public:
    Passenger() {} // default constructor
    Passenger(string name, int PassNum) : name(name), passNum(PassNum) {}
    void display()
    {
        cout << "Name: " << name << "Passpost No:" << passNum << endl;
    }
};
class Flight
{
private:
    const int flightno;
    string destination;
    int capacity;
    int count;
    Passenger *List;

public:
    Flight() : flightno(0), destination(""), capacity(0), count(0), List(nullptr) {}
    Flight(string destination, int capacity, int flightNo) : flightno(flightNo), destination(destination), capacity(capacity), count(0)
    {
        List = new Passenger[capacity];
    }
    void addPassenger(string name, int pNum)
    {
        if (count < capacity)
        {
            List[count] = Passenger(name, pNum);
            ++count;
            cout << "Passenger " << count << " added successfully" << endl;
        }
        else
        {
            cout << "Capacity is full " << endl;
        }
    }
    ~Flight()
    {
        delete[] List;
    }
};
int main()
{
    Flight **p;
    p = new Flight *[10];
    for (int i = 0; i < 10; i++)
    {
        int no;
        string dest;
        int cap;
        cout << "Enter flight no,dest,capcity:";
        cin >> no >> dest >> cap;
        p[i] = new Flight(dest, cap, no);
        int numPassengers;
        cout << "Enter number of passengers: ";
        cin >> numPassengers;
        for (int j = 0; j < numPassengers; j++)
        {
            string name;
            int pNum;
            cout << "Enter passenger name and passport number: ";
            cin >> name >> pNum;
            p[i]->addPassenger(name, pNum);
        }
    }

    for (int i = 0; i < 10; i++)
    {
        delete p[i];
    }
    delete[] p;
}