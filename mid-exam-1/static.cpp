// Q3. Class Relationships: "EduManager" System [12 Marks]
// A University system needs to manage Course projects and Faculty members.

// Faculty Class: * Attributes: facultyID, baseSalary, and designation (e.g., "Lecturer" or "Professor").

// Use a static data member totalPayroll to track the sum of salaries of all faculty objects created.
// +1

// Course Class:

// Information includes courseCode, title, and creditHours.

// Each Course Composition: It must have exactly one Faculty member assigned as the "Course Coordinator".
// +1

// Explain the lifetime of the Faculty object in this Composition relationship if the Course object is deleted.
// +1

// Memory Management:

// If the Course class uses a pointer to dynamically allocate an array of student IDs, explain why a user-defined destructor is mandatory and what would happen if only the default destructor were used.
// +1
#include <iostream>
using namespace std;
class Faculty
{
private:
    int facultyID;
    double baseSalary;
    string designation;
    static double totalPayroll;

public:
    Faculty(int ID, double salary, string designation)
    {
        facultyID = ID;
        baseSalary = salary;
        this->designation = designation;
        totalPayroll += salary;
    }
    static double gettotalpayroll()
    {
        return totalPayroll;
    }
    void display() const
    {
        cout << "Faculty ID:" << facultyID << endl;
        cout << "base salary:" << baseSalary << endl;
        cout << "Designation:" << designation << endl;
        cout << "===============\n";
    }
    ~Faculty(){
        totalPayroll -= baseSalary;
    }
};
double Faculty::totalPayroll;
class Course
{
private:
    int courseCode;
    string title;
    int creditHr;
    Faculty courseCoordinator;

public:
    Course(int courseCode, string title, int cthr, string designation, double salary, int id) : courseCoordinator(id, salary, designation)
    {
        this->courseCode = courseCode;
        this->title = title;
        creditHr = cthr;
    }
    void display() const
    {
        cout << "course title:" << title << endl;
        cout << "Cousre code:" << courseCode << endl;
        cout << "credit Hr:" << creditHr << endl;
        cout << "===============\n";
        courseCoordinator.display();
    }
    // we need destructor when we we use student array which Dynamically allocatted to free them when object goes out of scope memory leak error may occur if not
};
int main()
{
    // lifetime of faculty object is when course objgoes out of scope the course coodrinatot obj destroy automatically
    Course course1(101, "OOP", 3, "Proffesor", 200000, 25);
    Course course2(102, "DLD", 3, "Proffesor", 200000, 26);
    course1.display();
    cout << Faculty::gettotalpayroll()<< endl;
    return 0;
}