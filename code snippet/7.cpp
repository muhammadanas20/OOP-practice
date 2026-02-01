// Question 2: Code Analysis & Debugging (10 Marks)
// a) Identify the Constructor Calls (5 Marks) Consider the code below. Identify which constructor (1, 2, or 3) is called for the lines labeled A, B, and C. (Ref: Spring '20)
class Server {
public:

    Server(){

    }                // 1. Default
    Server(int id) {

    }           // 2. Parameterized
    Server(const Server &s) {

    }   // 3. Copy Constructor
};

int main() {
    Server s1(101);       // Line A: _parameterize 2______
    Server s2 = s1;       // Line B: _copy constructor______
    Server s3;            // Line C: ___default constructo____
    s3 = s1;              // Line D: ___no this calls assignment copy contrcutor____ (Bonus: Is this a constructor?)
}
// b) Find the Error (5 Marks) The following class has a major memory management error. Identify the error and rewrite the code to fix it (Hint: Look at the Destructor and Copy logic). (Ref: Spring '21)
class Buffer {
    int* data;
public:
    Buffer() { 
        data = new int; 
        *data = 0; 
    }
    // Assume a valid parameterized constructor exists
    ~Buffer() {
        // MISSING CODE HERE
        delete data;
    }
};

void process() {
    Buffer b1;
    // Function ends here
}