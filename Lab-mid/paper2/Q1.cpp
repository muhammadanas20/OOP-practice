
#include <iostream>
using namespace std;

class Employee {
private:
    int ID;
    string name;
    static int nextEmployeeID;
    const float MAX_SALARY;
    float salary;
public:
    Employee(string name) : MAX_SALARY(1000) {
        this->name = name;
        ID = generateEmployeeID();
        salary = 0;
    }
    void setSalary(float s) {
        if (s > MAX_SALARY) {
            salary = MAX_SALARY;
        } else {
            salary = s;
        }
    }
    static int generateEmployeeID() {
        return nextEmployeeID++;
    }
    void displayEmployeeInfo() const {
        cout << "Employee ID: " << ID << endl;
        cout << "Name: " << name << endl;
        cout << "Salary: " << salary << endl;
    }
};

int Employee::nextEmployeeID = 100;

int main() {
    Employee e1("ALI");
    Employee e2("Anas");
    e1.setSalary(200);
    e2.setSalary(2000);
    e1.displayEmployeeInfo();
    e2.displayEmployeeInfo();
    return 0;
}
