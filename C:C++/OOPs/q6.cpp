#include <iostream>
using namespace std;

class FriendFunc2;

class FriendFunc1 {
  double n1, n2;
  public:
  FriendFunc1(double a, double b) : n1(a), n2(b) {}
  friend double average(FriendFunc1, FriendFunc2);
};

class FriendFunc2 {
    double n3, n4, n5;
    public:
    FriendFunc2(double c, double d, double e) : n3(c), n4(d), n5(e) {}
    friend double average(FriendFunc1, FriendFunc2);
};

double average(FriendFunc1 f1, FriendFunc2 f2) {
    double sum = f1.n1 + f1.n2 + f2.n3 + f2.n4 + f2.n5;
    return sum/5.0;
}

int main() {
    double a, b, c, d, e;
    cout << "Enter five different numbers:\n";
    cin >> a >> b >> c >> d >> e;
    FriendFunc1 obj1(a, b);
    FriendFunc2 obj2(c, d, e);
    double avg = average(obj1, obj2);
    cout << "The average of the five numbers is: " << avg << endl;
    return 0;
}
