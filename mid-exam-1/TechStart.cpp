#include <iostream>
#include <string>
using namespace std;
class Startup{
    private:
    int amount;
    const string uniqueID;
    string name;
    public:
    Startup(string name,int amount,string id):uniqueID(id){
        this->name = name;
        this->amount = amount;   //constructor
    }
    Startup():amount(0),uniqueID(""),name(""){}
    void display(){
        cout << "NAME:" << name << "\nAMOUNT:" << amount << "\nID:" << uniqueID << "\n" ;
    }
};
class incubator{
    private:
    int roomNo;
    Startup *obj;
    static int totalIncubator;
    public:
    incubator(int no):roomNo(no){
        obj = new Startup;
    }

    //deep copy constructor
    incubator(const incubator &other){
        this->roomNo = other.roomNo;
        this->obj = new Startup(*other.obj);
    }
    void addstartup(int amount,string name,string id){
      obj = new Startup(name,amount,id);
      totalIncubator++;
    }
    ~incubator(){
        delete obj;
    }
    void display(){
        cout << "ROOM no:" << roomNo ;
        if (obj) {
            cout << "\n";
            obj->display();
        }
    }
    
};
int incubator::totalIncubator = 0;
int main(){
     incubator a1(101);
     a1.addstartup(10000,"anastrix","422");
     incubator a2 = a1;
     
     a1.display();
     a2.display();
    return 0;
}