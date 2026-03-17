#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Abstract Base Class
class UniversityStaff {
public:
    virtual void displayDetails() const = 0;
    virtual ~UniversityStaff() {}
};

// Derived Class: Professor
class Professor : public UniversityStaff {
    std::string name;
    std::string specialization;
public:
    Professor(const std::string& n, const std::string& s) : name(n), specialization(s) {}
    void displayDetails() const override {
        std::cout << "Professor Name: " << name << ", Specialization: " << specialization << std::endl;
    }
};

// Derived Class: AdministrativeStaff
class AdministrativeStaff : public UniversityStaff {
    std::string name;
    std::string department;
public:
    AdministrativeStaff(const std::string& n, const std::string& d) : name(n), department(d) {}
    void displayDetails() const override {
        std::cout << "Admin Staff Name: " << name << ", Department: " << department << std::endl;
    }
};

class Rational{
private:
    int a;
    int b;       //rational a/b
public:
    Rational():a(0),b(1){}
    Rational(int a,int b){
        this->a = a;
        this->b = b;
    }
    friend istream& operator>>(istream& in, Rational& r){
        char slash;
        in >> r.a >> slash >> r.b;
        if (slash != '/' || r.b == 0) {
            cout << "Invalid input. Please enter in the format numerator/denominator and denominator != 0." << endl;
            r.a = 0;
            r.b = 1;
        }
        return in;
    }
    friend ostream& operator<<(ostream& out, const Rational& r){
        out << r.a << "/" << r.b;
        return out;
    }

    // Helper function to compute gcd
    int gcd(int x, int y) const {
        while (y != 0) {
            int temp = y;
            y = x % y;
            x = temp;
        }
        return x;
    }

    // Reduce the rational number to its lowest terms
    void reduce() {
        int g = gcd(abs(a), abs(b));
        if (g != 0) {
            a /= g;
            b /= g;
        }
        if (b < 0) { // keep denominator positive
            a = -a;
            b = -b;
        }
    }

    bool operator==(const Rational& r) const {
        Rational lhs = *this, rhs = r;
        lhs.reduce();
        rhs.reduce();
        return lhs.a == rhs.a && lhs.b == rhs.b;
    }

    bool operator<(const Rational& r) const {
        return (a * r.b) < (r.a * b);
    }

    bool operator<=(const Rational& r) const {
        return (*this < r) || (*this == r);
    }

    bool operator>(const Rational& r) const {
        return !(*this <= r);
    }

    bool operator>=(const Rational& r) const {
        return !(*this < r);
    }

    Rational operator+(const Rational& r) const {
        Rational res(a * r.b + r.a * b, b * r.b);
        res.reduce();
        return res;
    }

    Rational operator-(const Rational& r) const {
        Rational res(a * r.b - r.a * b, b * r.b);
        res.reduce();
        return res;
    }

    Rational operator*(const Rational& r) const {
        Rational res(a * r.a, b * r.b);
        res.reduce();
        return res;
    }

    Rational operator/(const Rational& r) const {
        Rational res(a * r.b, b * r.a);
        res.reduce();
        return res;
    }
};

int main(){
    // Part A: Rational class demonstration
    Rational r1, r2;
    cout << "Enter first rational number (format: numerator/denominator): ";
    cin >> r1;
    cout << "Enter second rational number (format: numerator/denominator): ";
    cin >> r2;

    cout << "First Rational: " << r1 << endl;
    cout << "Second Rational: " << r2 << endl;

    cout << "Addition: " << (r1 + r2) << endl;
    cout << "Subtraction: " << (r1 - r2) << endl;
    cout << "Multiplication: " << (r1 * r2) << endl;
    cout << "Division: " << (r1 / r2) << endl;

    cout << "Equality: " << (r1 == r2 ? "Equal" : "Not Equal") << endl;
    cout << "Less than: " << (r1 < r2 ? "True" : "False") << endl;
    cout << "Greater than: " << (r1 > r2 ? "True" : "False") << endl;

    // Part B: Polymorphism demonstration
    UniversityStaff* staff1 = new Professor("Dr. Smith", "Computer Science");
    UniversityStaff* staff2 = new AdministrativeStaff("Alice", "Admissions");

    cout << "\nStaff Details (Polymorphism Demo):" << endl;
    staff1->displayDetails();
    staff2->displayDetails();

    delete staff1;
    delete staff2;

    return 0;
}