#include <iostream>
using namespace std;
class Animal{   
    private:
    const string type;
    string name;
    static int id;
    public:
    Animal(string name,string type):type(type){
        id++;
       this->name = name;
    };
    void display(){
        cout << "Name:" << name << endl;
        cout << "type:" << type << endl;
        cout << "ID:" << id << endl;
    }
};
int Animal :: id = 0;
int main(){
   Animal cat("posh","cute");
   cat.display();
   Animal goat("aloo","mosh");
   goat.display();
   return 0;
}