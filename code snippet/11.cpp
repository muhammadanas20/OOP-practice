// Question 1: Concepts & Theory [10 Marks]
// Write single-line short answers/justifications.
// a) What is the specific error in the following program line? Explain. Test ob1(); (Ref: Re-Mid '23)
// b) What is the size (in bytes) of a class that contains two int variables and one static int variable? (Ref: Fall '24)
// c) Can a constructor be declared private? If yes, what is the consequence? (Ref: Fall '24)
// d) Why does a const object generate a compiler error when calling a non-constant member function? (Ref: Spring '24)
// e) Can we call a non-static member function without creating an object of the class? (Ref: Re-Mid '23)

// --------------------------------------------------------------------------------
// Question 2: Code Analysis & Debugging [10 Marks]
// a) Identify the Errors (5 Marks) The following code has logic and syntax errors regarding const and static. Identify them. (Ref: Spring '24, Spring '21)
#include <iostream>
using namespace std;

class Account {
    int balance;
    static int totalAccounts;
public:
    Account(int b) : balance(b) {}
    
    // Function to display balance
    void show() const {
        cout << balance;
        // balance = 0;       // ERROR A
    }

    static void resetCount() {
        totalAccounts = 0;
        // this->balance = 0;  // ERROR B
    }
};
// b) Output Tracing (5 Marks) Determine the output. Pay attention to Pass by Value vs Pass by Reference. (Ref: Spring '20, Spring '22)
class Alpha {
public:
    Alpha() { cout << "1"; }
    Alpha(const Alpha &a) { cout << "2"; }
    ~Alpha() { cout << "3"; }
};

void run(Alpha a) {
    cout << "R";
}

int main() {
    Alpha a1;      // Line A
    run(a1);       // Line B
    cout << "E";
    // End of main
}
// Answer 1
// a) This is the "Most Vexing Parse". The compiler interprets Test ob1(); as a function declaration (a function named ob1 returning a Test object), not as an object instantiation. Correct: Test ob1;. b) 8 Bytes. (4 + 4). The static int is stored in global memory, not inside the object instance, so it does not contribute to sizeof(object). c) Yes. The consequence is that you cannot create objects of that class from outside the class (e.g., in main). This is used for the Singleton Pattern. d) A const object guarantees its state won't change. Non-constant member functions might change the state (the compiler assumes they will), so calling one violates the guarantee. e) No. Non-static functions require a this pointer, which is only available when called on a valid object instance.
// Answer 2
// a) Errors:
// • Error A: balance = 0; inside show(). You cannot modify a member variable inside a const member function.
// • Error B: this->balance = 0; inside resetCount(). Static functions do not have a this pointer and cannot access non-static members.
// b) Output: 1 2 R 3 E 3
// 1. Alpha a1; -> Prints 1 (Default Constructor).
// 2. run(a1); -> Pass by value calls Copy Constructor. Prints 2.
// 3. cout << "R"; -> Inside function. Prints R.
// 4. Function run ends. Local copy a is destroyed. Prints 3.
// 5. cout << "E"; -> Back in main. Prints E.
// 6. Main ends. a1 is destroyed. Prints 3.