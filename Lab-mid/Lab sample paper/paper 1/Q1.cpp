// SCENARIO:
// A hospital needs to manage patient records and their treatments. Each patient
// has a constant patient ID (assigned at creation and never changes), a name,
// age, and a list of medications they are currently taking. The system must track:
// - Individual patient information
// - Total number of patients registered in the hospital
// - Total number of medications prescribed across ALL patients

// The billing department needs to know: each medication has a cost, and they need
// to track the total medication cost per patient and globally across all patients.

// REQUIREMENTS:

// Part A & B: Write a C++ program with the following classes:

// 1. MEDICATION CLASS:
//    - name (string): Name of medication (e.g., "Aspirin")
//    - cost (double): Cost of medication in PKR

//    Functions:
//    - Constructor to initialize medication
//    - displayInfo(): to show medication details

// 2. PATIENT CLASS:
//    - const int patientID: Unique patient ID (constant, never changes)
//    - name (string): Patient name
//    - age (int): Patient age
//    - medications[5] (array of Medication): Up to 5 medications per patient
//    - medCount (int): Current medication count
//    - static int totalPatients: Total patients registered
//    - static double totalMedicationCost: Total medication cost across all patients

//    Functions:
//    - Constructor (takes patientID, name, age) - uses initializer list for const patientID
//      Initialize static members appropriately
//    - addMedication(Medication): Add medication to patient (max 5)
//    - calculatePatientMedicationCost(): Returns total medication cost for this patient
//    - displayPatientDetails(): Shows complete patient info including medications
//    - Const member function: getMedicationCount(): Returns number of medications
//    - Static function: displayStatistics(): Shows total patients and total medication cost

// Part C: Draw UML Class Diagram showing:
//    - Both classes with all attributes and member functions
//    - Relationships between Patient and Medication
//    - Indicate which members are const and which are static
#include <iostream>
using namespace std;
class Medication
{
private:
    string name;
    double Cost;

public:
    Medication() : name(""), Cost(0) {}
    Medication(string name, double cost) : name(name), Cost(cost) {}
    void displayinfo() const
    {
        cout << "Name :" << name << endl;
        cout << "Cost :" << Cost << "PKR" << endl;
    }
    double getCost() const
    {
        return Cost;
    }
};
class Patient
{
private:
    const int PatientID;
    string name;
    int age;
    Medication medication[5];
    int medcount;
    static int totalPatients;
    static double totalMedicationCost;

public:
    Patient(int id, string name, int age) : PatientID(id), name(name), age(age)
    {
        medcount = 0;
        totalPatients++;
    }
    void addMedication(const Medication &m)
    {
        if (medcount < 5)
        {
            medication[medcount++] = m;
        }
        else
        {
            cout << "seats full" << endl;
        }
    }
    double calculatePatientMedicationCost() const
    {
        if (medcount == 0)
        {
            cout << "No medication added\n";
        }
        double temp = 0;
        for (int i = 0; i < medcount; i++)
        {
            temp += medication[i].getCost();
        }
        totalMedicationCost += temp;
        return temp;
    }
    void displayPatientDetail() const
    {
        cout << "======patient details========" << endl;
        cout << "Patient ID:" << PatientID << endl;
        cout << "Patient Name:" << name << endl;
        cout << "Age :" << age << endl;
        for(int i=0;i<medcount;i++){
            medication[i].displayinfo();
        }
        cout << "Patient total medication Cost:" << calculatePatientMedicationCost() << endl;
    }
    int getMedicationCount() const
    {
        return medcount;
    }
    static void displayStatics(){
        cout << "Hospital statics\n";
        cout << "Total patients Registered:" << totalPatients << endl;
        cout << "Total medictaion Cost across hospital :"  << totalMedicationCost << endl;
    }
};
double Patient::totalMedicationCost = 0;
int Patient::totalPatients = 0;
int main()
{
    Patient p1(101,"anas",18);
    Medication med1("Aspirin",150);
    Medication med2("metformin",300);
    Medication med3("Lisinopril",250);
    p1.addMedication(med1);
    p1.addMedication(med2);
    p1.addMedication(med3);
    p1.displayPatientDetail();
    Patient::displayStatics();
    return 0;
}