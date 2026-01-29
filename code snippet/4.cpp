// class Battery {
//     int level;
// public:
//     Battery(int l) : level(l) {}

//     // Error 1? // const missing in parameter

//     Battery operator+(Battery b) {
//         return Battery(this->level + b.level);
//     }

//     // Error 2? // static can't acess non static member
//     static bool operator==(const Battery& b) {
//         return this->level == b.level;
//     }

//     // Error 3?n missing friend in func name
//     ostream& operator<<(ostream& out, Battery b) {
//         out << b.level;
//         return out;
//     }
// };