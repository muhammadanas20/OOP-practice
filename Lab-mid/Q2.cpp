// Question 2: Has-A Relationship, Array of Objects, and Member Initialization Lists
// Topics Covered: Fundamentals of OOP (03), Constructors, "this" Keyword, Member Initialization List (04), Has-a Relationship, Array of Objects (05).
// Scenario: Mappa animation studio aims to manage their projects and staff. Every movie the studio makes has a total budget allocated at the time the movie is initially started
// . This budget is fixed and Mappa does not allow it to be changed
// .
// Requirements:
// Classes: Create a Staff class and a Movie class
// .
// Has-A Relationship: The Movie class must contain instances of the Staff class (one for ProjectLead and one for ChiefAnimator)
// .
// Member Initialization List: The Movie class must have a const double budget
// . Because it is a constant, you must use a member initialization list in the constructor to assign its value
// .
// "this" Keyword: Use the this keyword in the parameterized constructor of the Staff class to differentiate between the member variables and the constructor parameters (e.g., this->salary = salary)
// .
// Static Members & Arrays: Maintain a static record of totalBudget for all movies combined and totalSalary for all staff members combined
// . In your main() function, create an array of Movie objects to test your code.

#include <iostream>
using namespace std;
class Staff{
    private:
    double salary;
    static double totalSalary;
    public:
    Staff(double salary = 0) {
        this->salary = salary;
        totalSalary += salary;
    }
    static double getTotalSalary() {
        return totalSalary;
    }
    double getSalary() const {
        return salary;
    }
};
double Staff::totalSalary = 0;

class Movie{
    private:
    Staff ProjectLead;
    Staff chiefAnimator;
    const double budget;
    static double totalBudget;
    public:
    Movie(double budget = 0, double leadSalary = 0, double animatorSalary = 0)
        : ProjectLead(leadSalary), chiefAnimator(animatorSalary), budget(budget) {
        totalBudget += budget;
    }
    static double getTotalBudget() {
        return totalBudget;
    }
    double getBudget() const {
        return budget;
    }
};
double Movie::totalBudget = 0;

int main(){
    Movie movies[2] = {
        Movie(100000, 20000, 15000),
        Movie(200000, 25000, 18000)
    };
    cout << "Total Budget: " << Movie::getTotalBudget() << endl;
    cout << "Total Salary: " << Staff::getTotalSalary() << endl;
    return 0;
}