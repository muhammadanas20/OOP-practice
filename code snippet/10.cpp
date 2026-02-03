// a) What is the specific logical error in the following line of code? Student s1(); Explanation: The programmer intends to create an object using the default constructor. (Ref: Re-Mid '23)
// b) Why can’t a const object call a non-constant member function? (Ref: Spring '24)
// c) Why is it considered bad practice to create a single "Combined Setter" (e.g., setValues(int a, float b, string c)) instead of separate setters for each variable? (Ref: Fall '24)
// d) If a class has a static data member, does that member increase the size (in bytes) of the individual objects of that class? (Ref: Fall '24)
// e) Explain the difference between "Data Hiding" and "Code Hiding". (Ref: Fall '24)

// --------------------------------------------------------------------------------
// Question 2: Code Analysis & Debugging [10 Marks]
// a) Identify the Errors (5 Marks) The following code contains three distinct errors (syntax or logical). Identify them and briefly explain why. (Ref: Spring '24, Re-Mid '23)
#include <iostream>
using namespace std;
class Complex {
    double x, y;
    static int count;
public:
    Complex(double val) { x = val; }
    
    // Function to update count
    static void increment() {
        count++;
        // this->x = 0;  // ERROR 1  //static can't have this pointer to point nonstatic member
    }
    
    // Function to display
    void display() const {
        cout << x << endl;
        // x = 10;       // ERROR 2 // can't modify value const func
    }
};

int main() {
    Complex c1();     // ERROR 3 (Logical)
    // c1.display();
}
// b) Output Tracing (5 Marks) What will be the output of the following code? (Ref: Spring '22)
class Item {
public:
    Item() { cout << "A"; }
    Item(int x) { cout << "B"; }
    Item(const Item &i) { cout << "C"; }
    ~Item() { cout << "D"; }
};

void process(Item i) {
    // do nothing
}

int main() {
    Item i1(5);    // Line 1
    process(i1);   // Line 2
    // End of main
}
// a) This is a Function Declaration Parsing Error. The compiler treats Student s1(); as a function named s1 that returns a Student object, not as an object instantiation. Correct usage: Student s1;. b) A const object treats all its data members as read-only. A non-constant member function might modify data members (the compiler assumes it will), so calling it violates the const contract. c) It creates needless dependencies. If you only want to update one variable, a combined setter forces you to provide dummy values for the others or creates complex logic inside the function. d) No. Static members are stored in a separate global memory region, shared by all objects. They do not affect the sizeof() an individual object. e) Data Hiding restricts access to variables (using private). Code Hiding (Encapsulation) abstracts the implementation details of functions so the user only sees the interface.
// Answer 2
// a)
// 1. this->x = 0;: Static functions cannot access instance variables (x) or the this pointer.
// 2. x = 10;: A const member function cannot modify member variables.
// 3. Complex c1();: This declares a function, it does not create an object (as explained in Q1a). c1.display() will fail because c1 is not an object.
// b) Output: B C D D
// 1. i1(5) prints B (Parameterized).
// 2. process(i1) passes by value, calling the Copy Constructor. Prints C.
// 3. Function process ends, destroying the local copy. Prints D.
// 4. main ends, destroying i1. Prints D.