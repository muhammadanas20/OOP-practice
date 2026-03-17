// Question 1: Deep Memory Management, Copy Constructors, and Immutability
// Concepts Tested: Pointers & DMA (02), Constructors/Destructors (04), Static/Const Members (05).
// Scenario: You are developing a high-performance Supermarket Inventory System to handle thousands of items efficiently
// . Memory leaks or shallow copy issues will crash the system.
// Requirements:
// Class Design: Create a class InventoryItem with the following private attributes: Name (std::string), BarCode (std::string), BrandName (char pointer for dynamic array), Stock (int), and ItemCount (static tracking variable)
// .
// Immutability & Const: The BarCode is issued strictly at the time of object creation and cannot be changed afterwards under any circumstances
// .
// Advanced Constructors:
// Implement a parameterized constructor that dynamically allocates memory for BrandName and correctly initializes the const BarCode using a member initialization list
// .
// Implement a Copy Constructor that performs a deep copy of the BrandName character array to prevent dangling pointers when objects are copied
// .
// Both constructors must increment the static ItemCount by 1
// .
// Destructor: Implement a destructor that safely deallocates the dynamically allocated BrandName memory and decrements the ItemCount by 1
// .
// Execution: In main(), demonstrate the deep copy by creating InventoryItem itemOne, copying it to InventoryItem itemTwo(itemOne), and then modifying itemOne's brand name without affecting itemTwo

#include <iostream>
#include <string>
#include <cstring>
using namespace std;
class InventoryItem{
    private:
    string Name;
    const string BarCode;
    char* BrandName;
    int Stock;
    static int ItemCount;
    public:
    InventoryItem(string name, string barcode, char* brandName, int stock)
        : BarCode(barcode), Name(name), Stock(stock) {
        int len = strlen(brandName) + 1;
        BrandName = new char[len];
        strcpy(BrandName, brandName);
        ItemCount++;
    }
    
    InventoryItem(const InventoryItem& other)
        : BarCode(other.BarCode), Name(other.Name), Stock(other.Stock) {
        int len = strlen(other.BrandName) + 1;
        BrandName = new char[len];
        strcpy(BrandName, other.BrandName);
        ItemCount++;
    }
    
    ~InventoryItem() {
        delete[] BrandName;
        ItemCount--;
    }
};

int InventoryItem::ItemCount = 0;
int main(){
    InventoryItem itemOne("Apple", "APP001", "FreshFarm", 100);
    InventoryItem itemTwo(itemOne);
    cout << "Deep copy created successfully!" << endl;
    return 0;
}