//bismillah

#include <iostream>
#include <sstream>
using namespace std;

class Ward;

class Patient{
    private:
    const string name;
    const int patientID;
    static int nextID;
    static int totalCount;
    Ward* assignedWard;
    int age;

    public:
    Patient(const string& patientName, Ward* ward, int patientAge = 0)
        : name(patientName), patientID(nextID++), assignedWard(ward), age(patientAge) {
        ++totalCount;
    }

    ~Patient() {
        --totalCount;
    }

    bool operator==(const Patient& other) const {
        return assignedWard == other.assignedWard;
    }

    friend istream& operator>>(istream& in, Patient& p) {
        in >> p.age;
        return in;
    }

    static int getTotalPatients() {
        return totalCount;
    }

    Ward* getAssignedWard() const {
        return assignedWard;
    }

    void display() const;
};

class Ward {
    private:
    const string wardName;
    int capacity;
    Patient** patients;
    int currentCount;
    static int totalWards;

    public:
    Ward(const string& name, int cap)
        : wardName(name), capacity(cap), currentCount(0) {
        patients = new Patient*[capacity];
        for (int i = 0; i < capacity; ++i) {
            patients[i] = nullptr;
        }
        ++totalWards;
    }

    ~Ward() {
        delete[] patients;
        --totalWards;
    }

    void admitPatient(Patient* p) {
        if (currentCount >= capacity) {
            cout << "[WARNING] Ward " << wardName << " is full." << endl;
            return;
        }

        if (p->getAssignedWard() != this) {
            cout << "[WARNING] Patient belongs to a different ward." << endl;
            return;
        }

        patients[currentCount++] = p;
    }

    void listPatients() const {
        cout << "Patients in ward " << wardName << ":" << endl;
        if (currentCount == 0) {
            cout << "No patients admitted." << endl;
            return;
        }

        for (int i = 0; i < currentCount; ++i) {
            patients[i]->display();
        }
    }

    static int getTotalWards() {
        return totalWards;
    }

    const string& getWardName() const {
        return wardName;
    }
};

void Patient::display() const {
    cout << "Patient ID: " << patientID << endl;
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Assigned Ward: "
         << (assignedWard ? assignedWard->getWardName() : "None") << endl;
    cout << "--------------------------" << endl;
}

int Patient::nextID = 1;
int Patient::totalCount = 0;
int Ward::totalWards = 0;

int main(){
    Ward* w1 = new Ward("General", 2);
    Ward* w2 = new Ward("ICU", 2);

    Patient* p1 = new Patient("Ali", w1, 21);
    Patient* p2 = new Patient("Sara", w1, 24);
    Patient* p3 = new Patient("Hamza", w2, 30);
    Patient* p4 = new Patient("Ayesha", w2, 26);

    w1->admitPatient(p1);
    w1->admitPatient(p2);
    w1->admitPatient(p3);

    w2->admitPatient(p3);
    w2->admitPatient(p4);

    w1->listPatients();
    w2->listPatients();

    cout << "Do p1 and p2 share same ward? " << ((*p1 == *p2) ? "Yes" : "No") << endl;
    cout << "Do p1 and p3 share same ward? " << ((*p1 == *p3) ? "Yes" : "No") << endl;

    istringstream ageInput("29");
    ageInput >> *p4;
    cout << "Updated p4 details after operator>>:" << endl;
    p4->display();

    cout << "Total wards: " << Ward::getTotalWards() << endl;
    cout << "Total patients: " << Patient::getTotalPatients() << endl;

    delete p1;
    delete p2;
    delete p3;
    delete p4;
    delete w1;
    delete w2;

    cout << "After cleanup -> Total wards: " << Ward::getTotalWards() << endl;
    cout << "After cleanup -> Total patients: " << Patient::getTotalPatients() << endl;

    return 0;
}