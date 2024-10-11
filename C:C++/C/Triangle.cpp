#include <iostream>
using namespace std;

struct Complex {
    float real;
    float imag;
};

Complex addComplexNumbers(Complex num1, Complex num2) {
    Complex result;
    result.real = num1.real + num2.real;
    result.imag = num1.imag + num2.imag;
    return result;
}

int main() {
    Complex num1, num2, result;

    cout << "Enter real and imaginary parts of first complex number: ";
    cin >> num1.real >> num1.imag;

    cout << "Enter real and imaginary parts of second complex number: ";
    cin >> num2.real >> num2.imag;

    result = addComplexNumbers(num1, num2);

    cout << "Result = " << result.real << " + " << result.imag << "i" << endl;
    return 0;
}