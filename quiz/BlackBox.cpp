// Topic: Classes, Memory Management, and The Object Lifecycle Difficulty: Hard / Edge-Case Focused Scenario: "The BlackBox Secure Storage"
// Context: You are designing a class named BlackBox for a high-security banking system.
// 1. Identity: Each box has a const int boxID that cannot be changed once the box is created.
// 2. Data: Each box holds a pointer to a secret integer value (int* secretData) stored in dynamic memory.
// 3. Security: The system must strictly control how boxes are copied to prevent data leaks (Shallow Copy issues).
// 4. Logging: The system tracks exactly when a box is created or destroyed to monitor for intruders.

// --------------------------------------------------------------------------------
// Question 1: Implementation & Syntax (15 Marks)
// Write the complete C++ class definition for BlackBox satisfying the following strict requirements:
// 1. Member Variables:
//     ◦ boxID (integer, constant).
//     ◦ secretData (integer pointer).
// 2. Constructor:
//     ◦ Accepts id and data as parameters.
//     ◦ CRITICAL: You must use an Initializer List to initialize the boxID. (Why? See Source 2, Slide 30)
//     ◦ Allocates memory for secretData and assigns the value.
//     ◦ Prints: "Box [ID] created".
// 3. Setter with Validation:
//     ◦ Create a function setSecret(int data).
//     ◦ Validation Rule: The secret data cannot be negative. If a negative value is passed, print an error and do not update the data. (Ref: Source 2, Slide 19)
// 4. Destructor:
//     ◦ Properly releases the memory to avoid leaks.
//     ◦ Prints: "Box [ID] deleted".

// --------------------------------------------------------------------------------
#include <iostream>
using namespace std;
class BlackBox{
    private:
    const int id;
    int *secretData;
    public:
    BlackBox(int id,int data):id(id){
        secretData = new int(data);
        cout << "Box with " << id << " created" << endl;
    }
    void setData(int data){
        if(data >= 0){
          *secretData = data;
        }else{
            cout << "error" << endl;
        }
    }
    ~BlackBox(){
        delete secretData;
        cout << "Box with " << id << " deleted" << endl;
    }


};
int main(){
    BlackBox b1(1,787);
    b1.setData(85);
  return 0;
}