// // Q1. Answer the following precisely:

// // Memory Allocation: If a class contains two int variables and one static int, what is the size of its object? Explain why. 
// //  memory of class is the sum of two int variable that is 8 bytes

// // Constructor Logic: Why is a default constructor necessary even if it does nothing? 
// // it is used to initiliaze a array in other class like in nested classes

// // Data Protection: How is "Code Hiding" different from "Data Hiding"? 
// // code hiding is generally diffirent form data hiding like we gave a acess upto our choice with others to use 

// // Copy Prevention: If we want to prevent any object from being copied in our program, what should be done to the copy constructor?
// // we use const to not data change and also we use refrence and change the adress by deep copy constructor or assignment operator Question 1 Assessment
// 1. Memory Allocation

// Your Answer: Memory of class is the sum of two int variable that is 8 bytes.

// Status: Correct, but needs a "Why."


// Pro Tip for Full Marks: You must state that static members are stored in a separate static/global memory area, not within the object itself. Therefore, they do not contribute to the sizeof the object.

// 2. Constructor Logic

// Your Answer: It is used to initialize an array in other class like in nested classes.

// Status: Correct.


// Pro Tip for Full Marks: Specifically mention that when you create a dynamic array of objects (e.g., new Car[10]), the compiler automatically calls the default constructor for every element in that array. If it's missing, the code won't compile.

// 3. Data Protection

// Your Answer: Code hiding is generally different from data hiding like we gave a access upto our choice with others to use.

// Status: Partially Correct (a bit vague).

// Pro Tip for Full Marks:


// Data Hiding: Protecting variables by making them private and using setters/getters.


// Code Hiding: Providing the function interface (what it does) while hiding the internal logic/implementation (how it does it) via encapsulation.

// 4. Copy Prevention

// Your Answer: We use const to not data change and also we use reference and change the address by deep copy constructor or assignment operator.

// Status: Incorrect. This describes how to copy safely, not how to prevent it.


// Pro Tip for Full Marks: To prevent copying, you must declare the copy constructor in the private section of the class. This makes it inaccessible to the user and the compiler.