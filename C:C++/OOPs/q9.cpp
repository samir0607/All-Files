// Class
// A (member a1, set_a(), display_a())
// is inherited by class B (member b1, set_b(),
// display_b())
// is inherited by class C
// (member c1, set_c(),
// display_c()).
// Make object of C only. Print members of A, B, C classes using that object.
#include <iostream>
using namespace std;

class A {
protected:
    int a1;

public:
    void set_a(int value) {
        a1 = value;
    }

    void display_a() {
        cout << "Value of a1: " << a1 << endl;
    }
};

class B : public A {
protected:
    int b1;

public:
    void set_b(int value) {
        b1 = value;
    }

    void display_b() {
        cout << "Value of b1: " << b1 << endl;
    }
};

class C : public B {
private:
    int c1;

public:
    void set_c(int value) {
        c1 = value;
    }

    void display_c() {
        cout << "Value of c1: " << c1 << endl;
    }
};

int main() {
    C obj;

    obj.set_a(10);
    obj.set_b(20);
    obj.set_c(30);

    obj.display_a();
    obj.display_b();
    obj.display_c();

    return 0;
}
