#include <iostream>
using namespace std;

class Swapper {
private:
    int a, b;  

public:
    Swapper(int x, int y) : a(x), b(y) {}

    void swapByValue() {
        int temp = a;
        int copyA = a, copyB = b;
        copyA = copyB;
        copyB = temp;
        cout << "After swapping (call by value): a = " << copyA << ", b = " << copyB << endl;
        cout << "Original values remain unchanged: a = " << a << ", b = " << b << endl;
    }

    void swapByReference() {
        int temp = a;
        a = b;
        b = temp;
        cout << "After swapping (call by reference): a = " << a << ", b = " << b << endl;
    }

    void display() {
        cout << "a = " << a << ", b = " << b << endl;
    }
};

int main() {
    int a, b, choice;
    cout << "Enter two numbers: " << endl;
    cout << "a: ";
    cin >> a;
    cout << "b: ";
    cin >> b;
    Swapper swapObj(a, b);
    cout << "\nChoose the swapping method: " << endl;
    cout << "1. Call by value" << endl;
    cout << "2. Call by reference" << endl;
    cout << "Enter your choice (1 or 2): ";
    cin >> choice;
    switch (choice) {
        case 1:
            cout << "\nBefore swapping (call by value): ";
            swapObj.display();
            swapObj.swapByValue();
            break;
        case 2:
            cout << "\nBefore swapping (call by reference): ";
            swapObj.display();
            swapObj.swapByReference();
            break;
        default:
            cout << "Invalid choice. Please select 1 or 2." << endl;
            break;
    }
    return 0;
}
