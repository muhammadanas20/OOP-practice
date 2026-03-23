// Design a University Course Registration System. Each Course has an auto-incremented, immutable course code and an immutable course name. The university name is constant across all courses. Each course has a seat capacity and a current enrollment count (initially 0).

// When a student drops a course, the enrollment count decrements. You must overload prefix -- to represent a student dropping the course (decrement enrollment, but never below 0). You must also overload operator< to compare two courses by their available seats (seats left = capacity - enrollment) — the course with fewer seats left is "greater" (more popular).
// Course Class
// const int courseCode (auto-incremented from a static counter).
// const string courseName — set once at construction.
// static const string universityName — same for all courses.
// int capacity, int enrolled (default 0).
// Static count of active course objects.
// Method enroll() — increments enrollment if seats available; warns otherwise.
// Method display() — shows code, name, enrolled, capacity, seats left.
// Operator Overloading
// Prefix operator--: decrements enrollment by 1. If enrollment is already 0, print "[ERROR] No enrolled students to drop." and do nothing. Returns a reference to *this.
// operator< (friend): compares two courses — returns true if the left course has more seats left than the right (i.e., less popular). Allows sorting by popularity.
// Testing
// Create 3 courses dynamically. Enroll various counts in each.
// Call --course multiple times on one course, including attempting to go below 0.
// Compare all three courses using operator< and identify the most popular one.
// Delete all objects and verify the active count.
// Think About
// Prefix -- returns Course&. Postfix -- returns Course (value). What is the difference and why does prefix not take a parameter?

// Why does operator< need to be a friend if it compares two different Course objects?
// Can you chain --(--course)? With prefix -- returning a reference, yes. What would postfix chaining do?

#include <iostream>
#include <string>
using namespace std;
class Course{
    private:
    const int courseCode;
    const string courseName;
    static const string UniName;
    int capacity;
    int enrolled;
    static int activeCount;
    static int nextCode;
    public:
    Course(string name = "",int cap = 0,int enroll = 0):courseCode(nextCode++),courseName(name){
        capacity = cap;
        enrolled = enroll;
        activeCount++;
    }
    void enroll(){
        if((capacity - enrolled ) > 0){
           enrolled++;
        } else {
            cout << "[WARN] No seats available." << endl;
        }
    }
    static int gettotal(){
        return activeCount;
    }
    void display()const{
        cout << "Name:" << courseName << endl;
        cout << "Code:" << courseCode << endl;
        cout << "Capacity:" << capacity << endl;
        cout << "Enrolled:" << enrolled << endl;
        cout << "Left:" << (((capacity - enrolled) > 0) ? (capacity - enrolled) : 0)<< endl;

    }
    Course& operator--(){
         if(enrolled <= 0) cout << "Error no enrolled student to drop" << endl;
         else{
            --enrolled;
         }
         return *this;
    }
        friend bool operator<(const Course& left, const Course& right){
            return (left.capacity - left.enrolled) > (right.capacity - right.enrolled);
        }
    ~Course(){
        --activeCount;
    }
};

int Course::activeCount = 0;
int Course::nextCode = 1000;
const string Course::UniName = "FAST-NUCES";
int main(){
  Course *c[3];
    c[0] = new Course("PF",40,35);
    c[1] = new Course("OOP",50,49);
    c[2] = new Course("DSA",45,20);

    c[0]->display();
    c[1]->display();
    c[2]->display();

    --(*c[2]);
    --(*c[2]);

    for(int i = 0; i < 3; i++){
        delete c[i];
    }

    return 0;
}