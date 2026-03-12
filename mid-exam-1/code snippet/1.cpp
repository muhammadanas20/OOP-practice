#include <iostream>
using namespace std;
#include <string>
class ExamSession {
private:
    const int sessionID;
    static int studentCount;
    string course;

public:
    ExamSession(int id, string c):sessionID(id){ 
        // sessionID = id; // Error 1?  //const attribute be initialzed with inline constructor iniliaze
        course = c;
        studentCount++;
    }

    static void showSummary() {
        // cout << "Course: " << course << endl; // Error 2? //static static func only deal with static member it cannot hold non static
        cout << "Students: " << studentCount << endl;
    }

//     void resetCount() const {
//         studentCount = 0; // Error 3? 
//         course = "N/A";   // Error 4?  // const funct connot modify
//     }
};
int ExamSession::studentCount = 0;
int main(){

}