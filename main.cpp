#include <iostream>

class Box {
    public:
    Box(int value): data(new int(value)) {}

    ~Box() { // destructor
        delete data;
        data = nullptr; // gotta do this to say bye to dangling pointer
    }
    int value() {
        return *data;
    }
    private:
    int *data;

};

int main() {

    // int* P = new int;
    // std::cout << P << std::endl;
    // delete P;
    // P = nullptr;

    Box *box1 = new Box(6); // box pointer
    std::cout << box1->value() << std::endl; // no longer using '.' becuase it is not a stack variable anymore, pointers and heap use arrow.
    delete box1;

    return 0;
}