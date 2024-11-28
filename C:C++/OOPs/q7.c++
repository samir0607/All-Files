#include <iostream>
#include <cstring>

using namespace std;

class String {
    char* str;
    int length;

    public:
    String() : str(nullptr), length(0) {}

    String(const char* s) {
        length = strlen(s);
        str = new char[length + 1];
        strcpy(str, s);
    }

    String(const String& s) {
        length = s.length;
        str = new char[length + 1];
        strcpy(str, s.str);
    }

    ~String() {
        delete[] str;
    }

    String& operator=(const String& s) {
        if (this == &s) {
            return *this;
        }
        delete[] str;
        length = s.length;
        str = new char[length + 1];
        strcpy(str, s.str);
        return *this;
    }

    bool operator==(const String& s) const {
        return strcmp(str, s.str) == 0;
    }

    String operator+(const String& s) const {
        String temp;
        temp.length = length + s.length;
        temp.str = new char[temp.length + 1];
        strcpy(temp.str, str);
        strcat(temp.str, s.str);
        return temp;
    }

    void display() const {
        if (str != nullptr) {
            cout << str << endl;
        }
    }
};

int main() {
    char input1[100], input2[100];
    
    cout << "Enter the first string(s1): ";
    cin.getline(input1, 100);
    
    cout << "Enter the second string(s2): ";
    cin.getline(input2, 100);

    String s1(input1);
    String s2(input2);

    String s3;
    s3 = s1;
    cout << "After assignment ( s3 = s1 ): s3 = ";
    s3.display();

    if (s1 == s2) {
        cout << "s1 is equal to s2." << endl;
    } else {
        cout << "s1 is not equal to s2" << endl;
    }

    String s4 = s1 + s2;
    cout << "After concatenation (s1 + s2): ";
    s4.display();

    return 0;
}
