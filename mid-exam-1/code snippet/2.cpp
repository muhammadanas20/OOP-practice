#include <iostream>
using namespace std;
#include <string>
class Product {
    const int sku;
    static int globalStock;
public:
    Product(int s) : sku(s) { globalStock++; }
    
    static void updateStock(int n) {
       // sku = n; // Error 1?  // static func cannot modify non static member
        globalStock = n;
    }
};

class Store {
    Product** inventory; // Array of Pointers
    int count;
public:
    Store(int c) : count(c) {
        //inventory = new Product[count]; // Error 2? // no dafualt constructor found in product for initiliazation
    }
    
    void clearInventory() const {
        delete inventory; // Error 3?  //const func cannot modify anything in class and also inventary is pointer to delete we need  to delete pointer like delete [] inventary
    }
};
int globalStock = 0; // Error 4? // static must declare with class name like int profuct::globalStock=0;