//bismillah

#include <iostream>
#include <string>
#include <utility>
using namespace std;

class Product {
protected:
    const int productID;
    const string name;
    double basePrice;
    static int totalCount;
    static int nextID;

public:
    Product(const string& productName, double price)
        : productID(nextID++), name(productName), basePrice(price) {
        ++totalCount;
    }

    virtual double calculatePrice() const = 0;
    virtual void displayInfo() const = 0;

    // Virtual destructor is required so deleting via Product* calls derived destructors correctly.
    virtual ~Product() {
        --totalCount;
    }

    static int getCount() {
        return totalCount;
    }
};

class PhysicalProduct : public Product {
private:
    double weightKg;

public:
    PhysicalProduct(const string& productName, double price, double weight)
        : Product(productName, price), weightKg(weight) {
    }

    PhysicalProduct(PhysicalProduct&& other) noexcept
        : Product(other.name, other.basePrice), weightKg(other.weightKg) {
        other.basePrice = 0.0;
        other.weightKg = 0.0;
    }

    double calculatePrice() const override {
        return basePrice + (weightKg * 50.0);
    }

    void displayInfo() const override {
        cout << "[Physical] ID: " << productID
             << ", Name: " << name
             << ", Weight: " << weightKg << " kg"
             << ", Final Price: " << calculatePrice() << "\n";
    }

    friend ostream& operator<<(ostream& out, const PhysicalProduct& p) {
        out << "PhysicalProduct{ID=" << p.productID
            << ", Name=" << p.name
            << ", Weight=" << p.weightKg << "kg"
            << ", FinalPrice=" << p.calculatePrice() << "}";
        return out;
    }
};

class DigitalProduct : public Product {
private:
    double downloadSizeMB;

public:
    DigitalProduct(const string& productName, double price, double sizeMB)
        : Product(productName, price), downloadSizeMB(sizeMB) {
    }

    double calculatePrice() const override {
        return basePrice * 1.10;
    }

    void displayInfo() const override {
        cout << "[Digital] ID: " << productID
             << ", Name: " << name
             << ", Size: " << downloadSizeMB << " MB"
             << ", Final Price: " << calculatePrice() << "\n";
    }

    friend ostream& operator<<(ostream& out, const DigitalProduct& p) {
        out << "DigitalProduct{ID=" << p.productID
            << ", Name=" << p.name
            << ", Size=" << p.downloadSizeMB << "MB"
            << ", FinalPrice=" << p.calculatePrice() << "}";
        return out;
    }
};

int Product::totalCount = 0;
int Product::nextID = 1;

int main() {
    Product* products[4];
    products[0] = new PhysicalProduct("Keyboard", 2500.0, 0.8);
    products[1] = new DigitalProduct("Antivirus", 1500.0, 250.0);
    products[2] = new PhysicalProduct("Chair", 12000.0, 12.0);
    products[3] = new DigitalProduct("E-Book", 600.0, 15.0);

    cout << "--- Polymorphism Demo ---\n";
    for (int i = 0; i < 4; ++i) {
        cout << "Calculated Price: " << products[i]->calculatePrice() << "\n";
        products[i]->displayInfo();
    }

    cout << "\n--- Move Constructor Demo ---\n";
    {
        PhysicalProduct original("Gaming Mouse", 3000.0, 0.4);
        PhysicalProduct movedProduct(std::move(original));

        cout << "Moved object: " << movedProduct << "\n";
        cout << "Source after move (valid/empty state): " << original << "\n";
    }

    for (int i = 0; i < 4; ++i) {
        delete products[i];
    }

    cout << "\nTotal products alive: " << Product::getCount() << "\n";
    return 0;
}