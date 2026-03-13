// Question 2: Dynamic Memory Allocation, Copy Constructors, and Destructors
// Topics Covered: Pointers & DMA (02), Array of Objects (05), Constructors & Destructors (04).
// Scenario: You are working for a library, and they want an automated system to manage their books
// .
// Requirements:
// Class Definition: Create a class called Book with the following private attributes: Name (String), ISBN (String), Author (Char pointer, assume 30 characters), Genre (String), and Count (to keep track of the number of Book objects created)
// .
// Constraints: The ISBN is issued at the time of object creation and cannot be changed afterwards
// .
// Constructors: Make use of parameterized and copy constructors as necessary
// . Constructors should increase the static [Count] by 1
// .
// Destructor & DMA: Your class must have a destructor that deallocates memory dynamically allocated for [Author] using pointers, and it should also decrease the [Count] by 1
// .
// Implementation: Allow the user to input the number of books they want to add, then dynamically create an array to store those books
// . Provide a menu-driven program to allow users to edit all attributes (except ISBN and Count) and display the current number of books in the library
// . Finally, demonstrate the working of your copy constructor by copying one Book object to another
// .

