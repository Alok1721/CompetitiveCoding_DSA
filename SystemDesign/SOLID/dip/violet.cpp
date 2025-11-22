class Keyboard { public: void read() { ... } };
class Mouse    { public: void read() { ... } };

class Computer {               // high-level
    Keyboard k;                // depends on concrete
    Mouse m;
public:
    void start() { k.read(); m.read(); }
};