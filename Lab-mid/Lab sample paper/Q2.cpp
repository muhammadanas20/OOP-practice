// Q2: Develop a restaurant order management system. The system should manage tables, orders assigned to each table, and menu items included in the orders. Each table can have up to 4 orders, and each order can contain up to 3 menu items. The system should calculate the total bill for each table and display complete details.
// Classes:
// 1.	Table Class:
// o	tableNumber (int): Table number (e.g., 1).
// o	orders[4] (array of Order): Orders placed at the table (max 4).
// o	orderCount (int): Current number of orders (max 4).
// o	Member Functions:
// 	addOrder(Order): Adds an order to the table (max 4).
// 	calculateTotalBill(): Returns the total cost of all orders.
// 	displayTableInfo(): Displays table number, orders, and total bill.
// 2.	Order Class:
// o	orderID (int): Unique order ID.
// o	items[3] (array of MenuItem): Up to 3 menu items per order.
// o	itemCount (int): Number of items in the order.
// o	Member Functions:
// 	addItem(MenuItem): Adds an item to the order (max 3).
// 	calculateOrderTotal(): Returns total cost of the order.
// 3.	MenuItem Class:
// o	name (string): Item name (e.g., "Burger").
// o	price (float): Price of the item (e.g., 12.5).
// Sample Output:
// Table 1 Orders:
// Order 101:
//    Burger - $12.5
//    Fries - $4.0
// Order 102:
//    Pizza - $18.0

// Total Bill for Table 1: $34.5
// ________________________________________
#include <iostream>
using namespace std;
class MenuItem{
    public:
    float price;
    string name;
    MenuItem(){}
    MenuItem(string name,float price):name(name),price(price){
    }
    void displayItem() const {
        cout << name << " -$ " << price << endl;
    }
};

class Order{
    private:
    int OrderID;
    MenuItem item[3];
    int itemcount;
    public:
    Order() : OrderID(0), itemcount(0) {}
    Order(int id) : OrderID(id), itemcount(0) {}

    void addItems(const MenuItem &menuItem){
        if(itemcount < 3){
            item[itemcount++] = menuItem;
        } else {
            cout << "items full\n";
        }
    }

    float calculateOrdertotal() const {
        float temp = 0;
        for(int i = 0; i < itemcount; i++){
            temp += item[i].price;
        }
        return temp;
    }

    void displayorder() const {
        cout << "Order " << OrderID << ":" << endl;
        for(int i = 0; i < itemcount; i++){
            item[i].displayItem();
        }
    }
};

class Table{
    private:
    int tableNumber;
    Order orders[4];
    int Ordercount;
    public:
    Table(int tablenumber): tableNumber(tablenumber), Ordercount(0) {}

    void addOrder(const Order &order){
        if(Ordercount < 4){
            orders[Ordercount++] = order;
        } else {
            cout << "order exceeds\n";
        }
    }

    float calculatetotalbill() const {
        float temp = 0;
        for(int i = 0; i < Ordercount; i++){
            temp += orders[i].calculateOrdertotal();
        }
        return temp;
    }

    void displayTableinfo() const {
        cout << "Table " << tableNumber << " Orders:" << endl;
        for(int i = 0; i < Ordercount; i++){
            orders[i].displayorder();
        }
        cout << "Total bill for Table " << tableNumber << ": " << calculatetotalbill() << endl;
    }
};

int main(){
    Table t1(1);
    Order order(101);
    Order order2(102);
    MenuItem item1("ice cream",1500);
    MenuItem item2("burger",1000);
    MenuItem item3("Drink",200);
    order.addItems(item1);
    order.addItems(item2);
    order2.addItems(item3);
    t1.addOrder(order);
    t1.addOrder(order2);
    t1.displayTableinfo();
    return 0;

}