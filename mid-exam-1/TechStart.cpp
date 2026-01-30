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
    Startup(){

    }


};
class incubator{
    private:
    int roomNo;
    Startup *obj;
    static int totalIncubator;
    public:

};
int main(){
    return 0;
}