#include <iostream>
using namespace std;

class Constructor {
private:
    int value;

public:
    Constructor() { //Default constructor
        value = 0;
        cout << "Default constructor's Value: " << value << endl;
    }

    Constructor(int val) { //Parameterized constructor
        value = val;
        cout << "Parameterized constructor's Value: " << value << endl;
    }

    Constructor(const Constructor &obj) { //Copy constructor
        value = obj.value;
        cout << "Copy constructor's Value: " << value << endl;
    }

    void display() const {
        cout << "Value: " << value << endl;
    }
};

int main() {
    Constructor obj1;
    obj1.display();

    Constructor obj2(100);
    obj2.display();

    Constructor obj3 = obj2;
    obj3.display();

    return 0;
}
