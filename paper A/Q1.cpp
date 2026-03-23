// Bismillah

#include <iostream>
using namespace std;
class Product{
    private:
    static int nextID;
    static int activeCount;
    const int productID;
    int stockQuantity;
    static const string warehouse;
    const string category;
    public:
    Product(int stock = 0, string cat = "") : productID(nextID++), stockQuantity(stock), category(cat) {
        ++activeCount;
    }

    Product(const Product& other)
        : productID(nextID++), stockQuantity(other.stockQuantity), category(other.category) {
        ++activeCount;
    }

    static int getTotalActiveProducts() {
        return activeCount;
    }

   ~Product(){
    --activeCount;
   }

   Product operator+(const Product& p) const {
    if (category == p.category) {
        return Product(stockQuantity + p.stockQuantity, category);
    }
    cout << "[WARNING] Cannot merge products of different categories." << endl;
    return Product(stockQuantity, category);
   }  
   void display() const {
    cout << "Product ID: " << productID << endl;
    cout << "Category: " << category << endl;
    cout << "Stock:" << stockQuantity << endl;
    cout << "Warehouse: " << warehouse << endl;
   } 
};
int Product::nextID = 1;
int Product::activeCount = 0;
const string Product::warehouse = "FAST Warehouse";
int main(){
   Product *products[3];
   products[0] = new Product(30,"Grocery");
   products[1] = new Product(20,"Grocery");
   products[2] = new Product(40,"Electronics");

   Product* sameCategoryMerge = new Product(*products[0] + *products[1]);
   Product* differentCategoryMerge = new Product(*products[0] + *products[2]);

   sameCategoryMerge->display();
   differentCategoryMerge->display();
   products[0]->display();
   products[1]->display();
   products[2]->display();

   cout << "Total active products: " << Product::getTotalActiveProducts() << endl;

   delete products[0];
   delete products[1];
   delete products[2];
   delete sameCategoryMerge;
   delete differentCategoryMerge;

   cout << "Total active products: " << Product::getTotalActiveProducts() << endl;
}