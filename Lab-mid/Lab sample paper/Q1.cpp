// Q1: You are asked to design a gym membership system. Each member has a constant membership ID, name, and the number of training sessions attended. The system should also track shared statistics: the total number of members registered and the total number of sessions attended across all members.
// Create a Member class with private data members and public functions. Include a parameterized constructor to initialize all attributes using an initializer list and update shared statistics. Implement a function to display individual member details, a const member function to return the number of sessions attended, and a static function to display total members and sessions.
// In main(), create an array of three members with different details, display their information in a loop, and finally show the overall statistics.
// Sample Output:
// Member Details:
// ID: 201, Name: Sara Ali, Sessions Attended: 5
// ID: 202, Name: Omar Shah, Sessions Attended: 3
// ID: 203, Name: Aisha Khan, Sessions Attended: 4

// Total Members Registered: 3
// Total Sessions Attended: 12
#include <iostream>
using namespace std;
class Members
{
private:
    const int membershipID;
    string name;
    int NOofSession;
    static int totalMembers;
    static int sessionShared;

public:
    Members(string name, int id, int noofsession) : membershipID(id), name(name), NOofSession(noofsession)
    {
        totalMembers++;
        sessionShared += noofsession;
    }
    int getsession() const
    {
        return NOofSession;
    }
    static void displayshareddetail()
    {
        cout << "Total members Registred:" << totalMembers << endl;
        cout << "Total Session Attended:" << sessionShared << endl;
    }
    void displaydetails() const
    {
        cout << "ID:" << membershipID << "," << "Name:" << name << ',' << "Sessions :" << NOofSession << endl;
    }
};

int Members::totalMembers = 0;
int Members::sessionShared = 0;

int main()
{
    Members *m[3];
    m[0] = new Members("Anas", 101, 3);
    m[1] = new Members("Abdullah", 102, 4);
    m[2] = new Members("Alyan", 103, 5);
    for (int i = 0; i < 3; i++)
    {
        m[i]->displaydetails();
    }
    Members::displayshareddetail();
     for(int i=0;i<3;i++){
        delete m[i];
    }
    return 0;
}  