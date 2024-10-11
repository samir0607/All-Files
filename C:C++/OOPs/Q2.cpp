#include <iostream>
using namespace std;

class MyClass {
private:
    int val; 

public:
    MyClass(int initial_val = 0) : val(initial_val) {}

    void update_val() {
        cout << "Enter a new value: ";
        cin >> val;
    }

    void get_val() const {
        cout << "The current value is: " << val << endl;
    }
};

int main() {
    MyClass obj;  

    obj.get_val();

    obj.update_val();

    obj.get_val();

    return 0;
}
