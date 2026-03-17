// Question 4: Pure Virtual Functions, Polymorphism, and Operator Overloading
// Concepts Tested: Polymorphism, Virtual Functions, Overriding, Operator Overloading, and Late Binding (08).
// Part A: Advanced Operator Overloading
// Define a class Rational to represent fractions (e.g., 1/2, 3/4) with numerator and denominator of type int
// .
// Provide a constructor with two arguments, where the second argument defaults to 1 (allowing whole numbers to be initialized like Rational(5) for 5/1)
// .
// Overload the following operators:
// Input (>>) and Output (<<) to handle input/output in the exact format "numerator/denominator"
// .
// Relational operators: ==, <=, >=, <, > to accurately compare two fractions
// .
// Arithmetic operators: +, -, *, / to perform standard fractional math (e.g., 1/2 + 1/3 = 5/6)
// .
// Part B: Abstract Classes & Runtime Polymorphism
// You are managing an F1 Racing Team
// . Create an abstract base class TeamMember with an immutable name (const string) and a unique id
// .
// Include a pure virtual function displayDetails() inside TeamMember
// .
// Create two derived classes: Driver (attributes: carNumber, raceWins) and Engineer (attribute: specialization)
// . Both must override displayDetails().
// In main(), create an array of base class pointers (TeamMember* team
// ). Instantiate one Driver and one Engineer using new, assign them to the array, and iterate through the array using a loop to call displayDetails(), proving that late binding (runtime polymorphism) correctly executes the derived class methods
// .

// --------------------------------------------------------------------------------
// Crucial Exam Tips for this Paper:
// Memory Leaks: In Q1 and Q4, for every new keyword you use, ensure there is a corresponding delete in the destructor or at the end of main()
// .
// Const Correctness: When a variable is declared const (like BarCode or TeamMember name), it must be initialized via the constructor's member initialization list, not inside the constructor body
// .
// Virtual Destructors: When deleting derived class objects through a base class pointer in Q4, ensure your base class TeamMember has a virtual destructor to prevent undefined behavior
// .
#include <iostream>
#include <string>
using namespace std;

// Part A: Rational Class
class Rational {
private:
    int numerator;
    int denominator;
    
    int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }
    
    void simplify() {
        int g = gcd(abs(numerator), abs(denominator));
        numerator /= g;
        denominator /= g;
    }
    
public:
    Rational(int num = 0, int denom = 1) : numerator(num), denominator(denom) {
        simplify();
    }
    
    friend istream& operator>>(istream& in, Rational& r) {
        char slash;
        in >> r.numerator >> slash >> r.denominator;
        r.simplify();
        return in;
    }
    
    friend ostream& operator<<(ostream& out, const Rational& r) {
        out << r.numerator << "/" << r.denominator;
        return out;
    }
    
    bool operator==(const Rational& r) const {
        return numerator == r.numerator && denominator == r.denominator;
    }
    
    bool operator<(const Rational& r) const {
        return numerator * r.denominator < r.numerator * denominator;
    }
    
    bool operator>(const Rational& r) const { return r < *this; }
    bool operator<=(const Rational& r) const { return !(r < *this); }
    bool operator>=(const Rational& r) const { return !(*this < r); }
    
    Rational operator+(const Rational& r) const {
        return Rational(numerator * r.denominator + r.numerator * denominator,
                       denominator * r.denominator);
    }
    
    Rational operator-(const Rational& r) const {
        return Rational(numerator * r.denominator - r.numerator * denominator,
                       denominator * r.denominator);
    }
    
    Rational operator*(const Rational& r) const {
        return Rational(numerator * r.numerator, denominator * r.denominator);
    }
    
    Rational operator/(const Rational& r) const {
        return Rational(numerator * r.denominator, denominator * r.numerator);
    }
};

// Part B: Abstract Base Class and Derived Classes
class TeamMember {
protected:
    const string name;
    int id;
    
public:
    TeamMember(string n, int i) : name(n), id(i) {}
    
    virtual ~TeamMember() {}
    
    virtual void displayDetails() const = 0;
};

class Driver : public TeamMember {
private:
    int carNumber;
    int raceWins;
    
public:
    Driver(string n, int i, int car, int wins) 
        : TeamMember(n, i), carNumber(car), raceWins(wins) {}
    
    void displayDetails() const override {
        cout << "Driver: " << name << " | ID: " << id 
             << " | Car #" << carNumber << " | Wins: " << raceWins << endl;
    }
};

class Engineer : public TeamMember {
private:
    string specialization;
    
public:
    Engineer(string n, int i, string spec) 
        : TeamMember(n, i), specialization(spec) {}
    
    void displayDetails() const override {
        cout << "Engineer: " << name << " | ID: " << id 
             << " | Specialization: " << specialization << endl;
    }
};

int main() {
    // Test Rational
    Rational r1(1, 2), r2(1, 3);
    cout << r1 << " + " << r2 << " = " << (r1 + r2) << endl;
    
    // Test Polymorphism
    TeamMember* team[2];
    team[0] = new Driver("Vettel", 101, 1, 53);
    team[1] = new Engineer("Smith", 201, "Aerodynamics");
    
    for (int i = 0; i < 2; i++) {
        team[i]->displayDetails();
        delete team[i];
    }
    
    return 0;
}