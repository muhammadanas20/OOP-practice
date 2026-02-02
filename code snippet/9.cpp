// a) A good programming practice is that getter functions are constant functions. Why is that so? (Ref: Spring '24)
// b) What is the specific error in the following code related to the this pointer? static void setVal(int v) { this->val = v; } (Ref: Fall '19, Spring '20)
// c) Why are Destructors considered crucial in classes that use Dynamic Memory Allocation? (Ref: Re-Mid '23)
// d) What happens if we declare a constructor as private? (Ref: Fall '24)
// a) Getter functions are meant to read data, not modify it. Making them const ensures the compiler prevents accidental modification of member variables inside the function, increasing code safety. b) Static functions belong to the class, not an object instance. Therefore, they do not have a this pointer and cannot access instance variables like this->val. c) If a class allocates memory (using new), that memory is not automatically freed when the object dies. The destructor is the only place to call delete to prevent Memory Leaks. d) We cannot create objects of that class from outside the class (e.g., in main). This is often used for the Singleton pattern or to force usage of static methods. e) 12 Bytes (8 for double + 4 for int). Static variables do not count towards the size of an object as they are stored in a separate memory region.
// e) Calculate the size of the following class:
#include <iostream>
using namespace std;
class Token {
    double value;  // 8 bytes
    int id;        // 4 bytes
    static int count; 
};


// --------------------------------------------------------------------------------
// Question 2: Code Analysis & Debugging [10 Marks]
// a) Identify the Error (5 Marks) The following code fails to compile. Identify the error regarding const correctness and write the reason. (Ref: Spring '24)
class Container {
    int value;
public:
    Container(int v) : value(v) {}
    
    // Function to display data
    void display() const {
        cout << value << endl;
        // value = 0;  // LINE A //cannot change value cuz const method
    }
};
// b) Constructor Tracing (5 Marks) Determine which output is printed for lines A and B. (Ref: Spring '20, Spring '22)
class Test {
public:
    Test() { cout << "1"; }
    Test(int x) { cout << "2"; }
    Test(const Test &t) { cout << "3"; }
};

void func(Test t) { } // Pass by Value

int main() {
    Test t1(5);      // Output: ___
    Test t2 = t1;    // Output: ___ (Line A)
    func(t2);        // Output: ___ (Line B)
}