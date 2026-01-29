#include <iostream>
#include <string>
using namespace std;
class Player{
    private:
    string name;
    int score;
    public:
    Player(string name = "",int score = 0):name(name),score(score){} 
    Player operator+(int points){
        return Player(this->name,this->score+ points);
    }
    bool operator == (const Player& other)const{
        return (this->score == other.score);
    }
    bool operator > (const Player& other)const{
        return (this->score > other.score);
    }
    friend ostream& operator<<(ostream& out, const Player& p) {
        out << "Player: " << p.name << " | Score: " << p.score;
        return out; // Return reference to allow: cout << p1 << p2; 
    }
};

int main(){
    Player p1("Anas", 150);
    Player p2("Alyan", 200);

    // Using + operator
    p1 = p1 + 50; 

    // Using << operator
    cout << p1 << endl; 

    // Using == and > operators
    if (p1 == p2) {
        cout << "It's a tie!" << endl;
    } else if (p2 > p1) {
        cout << p2 << " is winning!" << endl;
    }

    return 0;
}