// SCENARIO:
// A construction company manages multiple building projects. Each project:
// - Has a fixed budget (const) set at project start - cannot be changed
// - Has a project name, location, and assigned project manager
// - Consists of multiple tasks (materials, labor, equipment)
// - Tracks current spent amount and must ensure budget is not exceeded

// The company maintains:
// - Total budget across all projects
// - Total spent amount across all projects

// REQUIREMENTS:

// Part A & B: Implement with these classes:

// 1. CONSTRUCTION_TASK CLASS:
//    - taskName (string): Name of task
//    - estimatedCost (double): Estimated cost in PKR
//    - actualCost (double): Actual cost incurred

// 2. PROJECT_MANAGER CLASS:
//    - managerID (int)
//    - name (string)
//    - yearsExperience (int)
//    - static int totalManagers: Total managers in company

// 3. BUILDING_PROJECT CLASS:
//    - const double budget: Fixed project budget (never changes)
//    - projectName (string)
//    - location (string)
//    - projectManager (PROJECT_MANAGER)
//    - tasks[10] (array of CONSTRUCTION_TASK): Up to 10 tasks
//    - taskCount (int)
//    - static double totalProjectBudget: Sum of all project budgets
//    - static double totalAmountSpent: Total spent across all projects

//    Functions:
//    - Constructor (takes budget, projectName, location, projectManager)
//      Use initializer list for const budget
//    - addTask(CONSTRUCTION_TASK): Add a task
//    - calculateProjectTotalSpent(): Calculate total spent on this project
//    - checkBudgetStatus():
//      - If spent < budget: Display "Within Budget: PKR XXXX remaining"
//      - If spent >= budget: Display "OVER BUDGET: By PKR XXXX"
//    - displayProjectSummary(): Show all details, tasks, spending, budget status
//    - Const function: isBudgetExceeded(): Returns boolean
//    - Static function: displayCompanyFinancials(): Show total budget and total spent

// Part C: Draw UML diagram showing all relationships

// SAMPLE OUTPUT:
// ═══════════════════════════════════════════════════════════════════════════════
// Project: Commercial Plaza Development
// Location: Islamabad
// Fixed Budget: PKR 5,000,000 (Constant)
// Project Manager: Malik Ahmed (ID: M01, Experience: 12 years)

// Tasks:
//   Task 1: Foundation Work
//     Estimated: PKR 1,200,000
//     Actual: PKR 1,150,000

//   Task 2: Steel Framework
//     Estimated: PKR 1,500,000
//     Actual: PKR 1,550,000

//   Task 3: Electrical Work
//     Estimated: PKR 800,000
//     Actual: PKR 800,000

// Total Project Spent: PKR 3,500,000
// Budget Status: Within Budget (PKR 1,500,000 remaining)

// Company Financials:
// Total Budget of All Projects: PKR 12,500,000
// Total Amount Spent: PKR 9,200,000
#include <iostream>
using namespace std;
class Construction_Task
{
private:
    string name;
    double estimateCost;
    double actualCost;

public:
    Construction_Task() : name(""), estimateCost(0.0), actualCost(0.0) {}
    Construction_Task(string name, double estimateCost, double cost) : name(name), estimateCost(estimateCost), actualCost(cost) {}
    void displayTask() const
    {
        cout << name << "\n"
             << "Estimated: " << "PKR " << estimateCost << "\n"
             << "Actual: " << "PKR " << actualCost << endl;
    }
    double getCost() const
    {
        return actualCost;
    }
};

class Project_manager
{
private:
    int managerID;
    string name;
    int yearsExperiance;
    static int totalManagers;

public:
    Project_manager(string name, int managerID, int exp)
    {
        this->name = name;
        this->managerID = managerID;
        yearsExperiance = exp;
        totalManagers++;
    }
    void displayManager() const
    {
        cout << "Project Manger :" << name << " " << "(ID: " << managerID << "," << "Experiance: " << yearsExperiance << "years" << endl;
    }
};
class Building_Project
{
private:
    const double budget;
    string projectName;
    string location;
    Project_manager projectmanger;
    Construction_Task tasks[10];
    int taskCount;
    static double totalProjectBudget;
    static double totalAmountSpent;

public:
    Building_Project(string projectname, string location, double budget, Project_manager p) : budget(budget), projectName(projectname), location(location), projectmanger(p)
    {
        taskCount = 0;
        totalProjectBudget += budget;
    }
    void addtask(const Construction_Task &task)
    {
        if (taskCount < 10)
        {
            tasks[taskCount++] = task;
        }
        else
        {
            cout << "task full\n";
        }
    }
    double calculateBugdettotalSpent() const
    {
        double temp = 0.0;
        for (int i = 0; i < taskCount; i++)
        {
            temp += tasks[i].getCost();
        }
        return temp;
    }
    void checkBudgetStatus() const
    {
        double spent = calculateBugdettotalSpent();
        if (!isBudgetExceeded())
        {
            cout << "Budget Status:With in Budget" << " (PKR" << (budget - spent) << " remaining)" << endl;
        }
        else
        {
            cout << "Budget Status:outside Budget" << " (By PKR" << (spent - budget) << ")" << endl;
        }
    }
    bool isBudgetExceeded() const
    {
        if (budget < calculateBugdettotalSpent())
        {
            return true;
        }
        return false;
    }
    static void displayCompanyFinancials(){
        cout << "Company Financials" << endl;
        cout << "Total budget of All projects: PKR" << totalProjectBudget <<endl;
        cout << "Total Amount Spent: PKR" << totalAmountSpent << endl;
    }
    void display(){
        double projectSpent = calculateBugdettotalSpent();
        totalAmountSpent += projectSpent;
        cout << "Project: " << projectName << endl;
        cout << "Location: " << location << endl;
        cout << "Fixed Budget: "<< budget << endl;
        projectmanger.displayManager();
        cout << "Tasks" << endl;
        for(int i=0;i<taskCount;i++){
            cout << "Task " << i+1 << endl;
            tasks[i].displayTask();
        }
        cout << "Total project Spent: " << projectSpent << endl;
        checkBudgetStatus();
    }
};
int Project_manager::totalManagers = 0;
double Building_Project::totalAmountSpent = 0;
double Building_Project::totalProjectBudget = 0;
int main()
{
    Project_manager p1("Malik Ahmed",1,12);
    Construction_Task t[3];
    t[0] = Construction_Task("Foundation Work",1200000,1150000);
    t[1] = Construction_Task("Steel FrameWork",1500000,1550000);
    t[2] = Construction_Task("Electrical",800000,800000);
    Building_Project b1("Comercial Plaza Development","Islamabad",5000000,p1);
    for(int i=0;i<3;i++){
        b1.addtask(t[i]);
    }
     b1.display();
     Building_Project::displayCompanyFinancials();
    return 0;
}