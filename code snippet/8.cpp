// Question 2: Code Analysis & Debugging (10 Marks)
// a) Identify the Output/Constructor Calls (5 Marks) Look at the class Point below. Identify which constructor is called for the lines labeled A, B, and C. (Ref: Spring '20)
#include <iostream>
using namespace std;
#include <string>

class Point {
public:
    Point() { cout << "Default"; }      // 1
    Point(int x) { cout << "Param"; }   // 2
    Point(const Point &p) { cout << "Copy"; } // 3
};

int main() {
    Point p1;             // Line A: 1-Defualt_______
    Point p2(50);         // Line B: 2-param_______
    Point *ptr = new Point(p2); // Line C: 3-Copy_______
}
// b) Find the Error and Fix (5 Marks) The following code has a logical error regarding static members. Identify the error and rewrite the corrected class structure. (Ref: Spring '21)
class ABC {
    int x;
    static int y;
public:
    ABC(int val) {
        x = val;
        y = val; 
    }
    void set_y(int val) {
        y = val;
        x = val; // ERROR HERE // static func can't modify non static member or atribute
    }
};
int ABC::y = 0;

int main(){
    return 0;
}