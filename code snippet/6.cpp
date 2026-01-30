#include <iostream>
using namespace std;
class Buffer {
    int* data;
public:
    Buffer() { 
        data = new int; 
        *data = 0; 
    }
    int getdata(){
        return *data;
    }
    // Assume a valid parameterized constructor exists
    ~Buffer() {
        delete data;
    }
};

void process() {
    Buffer b1;
    cout << b1.getdata() ;
    // Function ends here
}
