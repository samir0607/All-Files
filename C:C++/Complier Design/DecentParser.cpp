#include <iostream>
using namespace std;

string input;
int pos = 0;

bool E();
bool E1();
bool T();
bool T1();
bool F();

bool match(char expected) {
    if (pos < input.size() && input[pos] == expected) {
        pos++;
        return true;
    }
    return false;
}

bool E() {
    if (!T()) return false;
    if (!E1()) return false;
    return true;
}

bool E1() {
    if (pos < input.size() && input[pos] == '+') {
        pos++;
        if (!T()) return false;
        if (!E1()) return false;
    }
    return true;
}

bool T() {
    if (!F()) return false;
    if (!T1()) return false;
    return true;
}

bool T1() {
    if (pos < input.size() && input[pos] == '*') {
        pos++;
        if (!F()) return false;
        if (!T1()) return false;
    }
    return true;
}

bool F() {
    if (match('(')) {
        if (!E()) return false;
        if (!match(')')) return false;
        return true;
    }
    if (pos < input.size() && isalpha(input[pos])) {
        pos++;
        return true;
    }
    return false;
}

int main() {
    cout << "Enter expression: ";
    cin >> input;
    pos = 0;

    if (E() && pos == input.size()) {
        cout << "Valid expression\n";
    } else {
        cout << "Invalid expression\n";
    }

    return 0;
}
