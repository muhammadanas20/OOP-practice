// Question 3: Complex Design Scenario (20 Marks)
// This question tests Nested Dynamic Memory, Composition, and Multi-Layer Deep Copy. This is significantly harder than standard single-class questions.
// Scenario: "SafeCloud" is a secure storage system.
// 1. File Class: Represents a single file. Contains:
//     ◦ fileName (string).
//     ◦ sizeMB (double).
// 2. Folder Class: Represents a directory. Contains:
//     ◦ folderName (string).
//     ◦ files: A dynamic array of File objects.
//     ◦ fileCount: Current number of files.
//     ◦ capacity: Max capacity.
// 3. Drive Class: Represents a physical hard drive. Contains:
//     ◦ driveID (const int).
//     ◦ root: A pointer to a single Folder object (The root directory).
// Tasks:
// a) (5 Marks) Implement the Folder class.
// • Include a constructor that takes name and capacity.
// • Allocates the dynamic array of File objects.
// • Destructor: Properly frees the memory.
// b) (7 Marks) Implement the Drive class.
// • Constructor: Takes an ID, creates a new Folder named "Root" (Capacity 10).
// • Deep Copy Constructor: This is the critical part.
//     ◦ When a Drive is copied (e.g., Drive backup = original;), it must create a new root Folder.
//     ◦ The new root Folder must contain a copy of all the Files from the original.
//     ◦ Note: Since Folder manages its own memory (in part a), you must ensure Folder also has a logic (like a copy constructor or manual copy) to handle the array copy, or handle it manually inside Drive. Show the most robust approach.
// c) (8 Marks) Trace the memory map for the following code (Draw or describe connections).
// • Specifically, show where the Deep Copy separates the data.
// Drive d1(101);
// // Assume we added files to d1 here...
// Drive d2 = d1; 
// Explain what happens if d1 is destroyed but d2 is still used, assuming your Deep Copy is correct.
#include <iostream>
using namespace std;

