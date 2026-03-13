// Question 1: Fundamentals, Static/Const Members, and Dynamic Memory Allocation
// Topics Covered: Introduction to C++ (01), Pointers & DMA (02), Classes, Objects, Access Modifiers (03), Constructors (04), Static/Const Members (05).
// Scenario: You are tasked with designing a Bank Account Management System where each account is assigned a unique account number that automatically increments when a new account is created
// . The bank also requires a way to track the total number of active accounts at any given time
// .
// Requirements:
// Account Creation & Static Members: Create an account with an initial balance of zero
// . Ensure that each new account is assigned a unique, auto-incremented account number that is immutable (cannot be modified after creation)
// .
// Constant Members: The bank name should remain constant for all accounts
// .
// Active Account Tracking: Track the total number of active accounts using a static member and provide a method to retrieve the current count
// .
// Memory Management (Pointers/DMA): Dynamically allocate account objects using references
// . Ensure proper deletion of account objects to avoid memory leaks
// .
// Basic Functions: Implement functionality to display account details (account number, balance, and bank name), and provide deposit and withdrawal functionalities that update the balance

#include <iostream>
using namespace std;

class Account{
    private:
    const int accNO;
    static int nextAccNo;
    const string BanKname;
    double balance;
    static int totalNo;
    public:
    Account(const string& name)
        : accNO(nextAccNo++), BanKname(name) {
        balance = 0.0;
        totalNo++;
    }
    ~Account() {
        totalNo--;
    }
    static int getcount(){
        return totalNo;
    }
    void display() const {
        cout << "Bank Name: " << BanKname << endl;
        cout << "Account No: " << accNO << endl;
        cout << "Balance: " << balance << endl;
    }
    void deposit(double amount) {
        if (amount > 0) balance += amount;
    }
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) balance -= amount;
    }
};

int Account::totalNo = 0;
int Account::nextAccNo = 1001; // Starting account number

int main(){
    Account* a1 = new Account("MyBank");
    a1->deposit(500);
    a1->withdraw(200);
    a1->display();
    cout << "Active Accounts: " << Account::getcount() << endl;

    Account* a2 = new Account("MyBank");
    a2->deposit(1000);
    a2->display();
    cout << "Active Accounts: " << Account::getcount() << endl;

    delete a1;
    delete a2;
    cout << "Active Accounts after deletion: " << Account::getcount() << endl;

    return 0;
}