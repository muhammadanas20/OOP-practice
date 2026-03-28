// SCENARIO:
// A university manages multiple courses, each with an assigned instructor and 
// enrolled students. The system maintains:
// - Each course has a fixed capacity (const) - cannot be changed
// - Each course has a course code, title, and semester
// - Each student has ID, name, and can enroll in multiple courses
// - Each instructor has salary information
// - The university tracks total enrollment across all courses
// - The university tracks total payroll for all instructors combined

// REQUIREMENTS:

// Part A & B: Write C++ code with the following classes:

// 1. STUDENT CLASS:
//    - studentID (int): Unique student ID
//    - name (string): Student name
   
// 2. INSTRUCTOR CLASS:
//    - instructorID (int): Unique instructor ID
//    - name (string): Instructor name
//    - salary (double): Monthly salary
//    - static double totalPayroll: Total salary of all instructors

// 3. COURSE CLASS:
//    - courseCode (string): Unique course code (e.g., "CS-101")
//    - const int capacity: Fixed maximum students (const, never changes)
//    - title (string): Course title
//    - semester (string): Semester offered
//    - instructor (Instructor): The instructor teaching this course
//    - enrolledStudents[50] (array of Student): Enrolled students
//    - enrollmentCount (int): Current enrollment
//    - static int totalEnrollment: Total students enrolled across all courses
   
//    Functions:
//    - Constructor (takes courseCode, capacity, title, semester, instructor)
//      Use initializer list for const capacity
//    - enrollStudent(Student): Add student to course (check capacity)
//    - displayCourseInfo(): Shows course details with all enrolled students
//    - Const function: isAtCapacity(): Returns true if enrollment equals capacity
//    - Const function: getAvailableSeats(): Returns (capacity - enrollmentCount)
//    - Static function: displayEnrollmentStatistics(): Shows total enrollment

// Part C: Draw UML Class Diagram with:
//    - All three classes and their attributes/functions
//    - Relationships (HAS-A relationships)
//    - Mark const and static members clearly

// SAMPLE OUTPUT:
// ═══════════════════════════════════════════════════════════════════════════════
// Course Information:
// Course Code: CS-101
// Title: Introduction to Programming
// Semester: Fall 2025
// Capacity: 30 (Constant)
// Enrolled: 28
// Available Seats: 2

// Instructor: Dr. Fatima Ahmed (ID: I001, Salary: PKR 150,000)

// Enrolled Students:
//   - Ahmed Khan (ID: S101)
//   - Ayesha Ali (ID: S102)
//   (... more students ...)

// University Enrollment Statistics:
// Total Students Enrolled Across All Courses: 185
#include <iostream>
using namespace std;
class Student{
    private:
    int StduentID;
    string name;
    public:
    Student():name(""),StduentID(0){}
    Student(string name,int id):name(name){
        StduentID = id;
    }
    void dispayStudent() const {
        cout << "Name:" << name << ", " << "Student ID:" << StduentID << endl;
    }

};
class Instructor{
    private:
    int InstructorID;
    string name;
    double salary;
    static double totalPayroll;
    public:
    Instructor():name(""),InstructorID(0),salary(0){}
    Instructor(string name,int id,double salary):salary(salary),name(name),InstructorID(id){
        totalPayroll+=salary;
    }
    void displayInstructor() const {
        cout <<"Instructor Name:" << name << ", " << "Instructor ID:" << InstructorID <<  ", " << "salary" << salary << endl;
    }

};
class Course{
    private:
    string courseCode;
    const int capacity;
    string title;
    string semester;
    Instructor instructor;
    Student enroledStudent[50];
    int enrollementCount;
    static int totalEnrollment;
    public:
    Course(string code,int cap,string title,string sem,string name,int id,double salary):instructor(name,id,salary),capacity(cap){
        courseCode = code;
        this->title = title;
        semester = sem;
        enrollementCount = 0;
    }
    void EnrollStudent(const Student& s){
        if(!isAtCapacity()){
            enroledStudent[enrollementCount++] = s;
            totalEnrollment++;
        }
        else{
            cout << "seats full\n";
        }
    }
    void displayCourseInfo(){
       cout << "====Course Info====" << endl;
       cout << "Course Code:" << courseCode << ", " << "Capacity :" << capacity << ", " << "Title:" << title << ", " << "Semester:" << semester << "Enrolled: " << enrollementCount << endl;
       cout << "Available seats :" << getAvailableSeats() << endl;
       instructor.displayInstructor(); 
       for(int i=0;i<enrollementCount;i++){
         enroledStudent[i].dispayStudent();
       }
         
    }
    bool isAtCapacity() const {
        if(enrollementCount == capacity) return true;
        return false;
    }
    int getAvailableSeats() const {
        return (capacity - enrollementCount);
    }
    static void displayEnrollementSattics() {
      cout << "Enrolement Statics" << endl;
      cout << "Total Enrollments:" << totalEnrollment << endl;
    }

};
int Course::totalEnrollment = 0;
double Instructor::totalPayroll = 0;

int main(){
    Course c("CS-101",30,"Intro to programing","Spring 2026","Fatima",1001,150000);
    Student s1("Anas",101);
    Student s2("Abd",102);
    Student s3("Alyan",103);
    c.EnrollStudent(s1);
    c.EnrollStudent(s2);
    c.EnrollStudent(s3);
    c.displayCourseInfo();
    Course::displayEnrollementSattics();
    return 0;
}