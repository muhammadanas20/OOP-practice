#include <iostream>
using namespace std;
#include <string>
class Citizen{
    private:
    string name;
    const long int Nic;
    public:
    Citizen(string name,long int NIC):Nic(NIC),name(name){}
    Citizen operator=(const Citizen& other){
        if(this != &other){
            this->name = other.name;
        }
        return *this;
    }
    friend ostream& operator<<(ostream& out,const Citizen c1){
      out << "NAME:" << c1.name << "| NIC: " << c1.Nic ;
      return out;
    }
};
int main(){
    Citizen c1("Anas",42201);
    Citizen c2("Alyan",32000);
    c2 = c1;
    cout << c1 << "\n " << c2 << endl;

}