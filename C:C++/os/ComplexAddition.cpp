#include <iostream>
using namespace std;

class Complex {
private:
    float real, imag;

public:
    // Constructor to initialize complex number
    Complex(float r = 0.0, float i = 0.0) : real(r), imag(i) {}

    // Friend function to add two complex numbers
    friend Complex add(Complex c1, Complex c2);

    // Function to display the result
    void display() {
        cout << real << " + " << imag << "i" << endl;
    }
};

// Friend function to add two complex numbers
Complex add(Complex c1, Complex c2) {
    Complex temp;
    temp.real = c1.real + c2.real;
    temp.imag = c1.imag + c2.imag;
    return temp;
}

int main() {
    Complex c1(2.5, 3.5), c2(1.5, 2.5);
    Complex result = add(c1, c2);
    cout << "Result using friend function: ";
    result.display();
    return 0;
}
