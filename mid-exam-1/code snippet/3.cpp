class Battery {
    int level;
public:
    Battery(int l) : level(l) {}

    // Error 1: What is missing in the parameter? //const
    Battery operator+(const Battery b) {
        return Battery(this->level + b.level);
    }

    // Error 2: Why can't this be a member function?
    //friend func
    // ostream& operator<<(ostream& out, const Battery& b) {
    //    out << b.level;
    //     return out;
    // }
};