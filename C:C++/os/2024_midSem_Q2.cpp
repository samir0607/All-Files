#include <iostream>
using namespace std;

// Forward declaration of class B
class B;

// Class A to store the number and provide options
class A {
    int number;

public:
    // Constructor to initialize number
    A(int num) : number(num) {
        cout << "Constructor called! Number initialized to " << this->number << endl;
    }

    // Destructor to display a message when an object is destroyed
    ~A() {
        cout << "Destructor called! Object destroyed." << endl;
    }

    // Function to get the number using `this` pointer
    int getNumber() {
        return this->number;
    }

    // Friend class B to access private members of class A
    friend class B;
};

// Class B to provide functionality for sum of digits and reverse digits
class B {
public:
    // Function to calculate the sum of digits
    int sumOfDigits(A* obj) {
        int num = obj->getNumber();  // Using the public getter function of class A
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }

    // Function to reverse the digits
    int reverseDigits(A* obj) {
        int num = obj->getNumber();  // Using the public getter function of class A
        int reversed = 0;
        while (num > 0) {
            reversed = reversed * 10 + (num % 10);
            num /= 10;
        }
        return reversed;
    }
};

// Main function for user interaction
int main() {
    int choice, num;
    
    cout << "Please Enter a number: ";
    cin >> num;

    // Dynamically allocate memory for an object of class A
    A* obj = new A(num);

    B b;  // Object of class B to call its functions
    
    do {
        cout << "\nPlease Enter a Choice\n1. Sum of digits\n2. Reverse digits\n3. Exit\n";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Sum of digits: " << b.sumOfDigits(obj) << endl;
                break;
            case 2:
                cout << "Reversed digits: " << b.reverseDigits(obj) << endl;
                break;
            case 3:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 3);

    // Deallocate memory using delete
    delete obj;

    return 0;
}
