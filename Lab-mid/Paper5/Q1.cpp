// Scenario: MegaMart — Warehouse Inventory System
// MegaMart runs a chain of warehouses. Each warehouse stores a collection of Product objects. A Product has-a Category (e.g., Electronics, Grocery). The warehouse manager needs to:

// •  Merge the stock of two Products of the same category using the + operator (returns a new Product with combined stock).
// •  Check if two Products belong to the same Category using the == operator.
// •  Print a Product's full details (name, category, stock, price) using the << operator (friend function).
// •  Track the total number of Product objects live in the system via a static counter.

// Requirements:
// 1. Design a Category class with a name and a unique auto-incremented category ID. Its name is immutable after creation.
// 2. Design a Product class with: a name (immutable), a Category object embedded via Has-A, a stock count, and a price. The product's name cannot change after creation. Static counter tracks total live products.
// 3. Overload operator+ to merge two Products. If their categories differ, print a warning and return the left-hand Product unchanged. Otherwise return a new Product with combined stock.
// 4. Overload operator== to return true only when both Products share the same category name.
// 5. Overload operator<< as a friend function to display a Product's details in a clean, formatted manner.
// 6. In main(): dynamically create at least 3 Products across 2 categories. Demonstrate all three operators. Verify static counter changes on deletion.

#include <iostream>
using namespace std;
class p
int main(){
    return 0;
}