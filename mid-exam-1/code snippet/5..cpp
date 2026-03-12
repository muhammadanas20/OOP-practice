#include <iostream>
using namespace std;
class Score {
    int value;
public:
    Score(int v) : value(v) {}

    // Error 1? static func cant acess non static value 
    // static Score operator+(const Score& s) {
    //     return Score(this->value + s.value);
    // }

    // Error 2? missing cinst in parameter to prevent chnage in dat of that object
    bool operator==(Score s) {
        return value == s.value;
    }

    // Error 3? return type should be refrence as this process contionue for other so 
    // void operator<<(ostream& out, const Score& s) {
    //     out << s.value;
    // }
};
int main(){
    return 0;
}