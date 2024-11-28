#include <iostream>
using namespace std;

class Polygon {
  public:
    virtual double area() {
        return 0;
    }
};

class Rectangle : public Polygon {
  double width, height;
  public:
    Rectangle(double w, double h) : width(w), height(h) {}

    double area() {
        return width * height;
    }
};

class Triangle : public Polygon {
  double base, height;
  public:
    Triangle(double b, double h) : base(b), height(h) {}
    double area() {
        return 0.5 * base * height;
    }
};

void displayArea(Polygon* p) {
    cout << "Area: " << p->area() << endl;
}

int main() {
    Polygon* poly1 = new Rectangle(5.0, 4.0);
    Polygon* poly2 = new Triangle(6.0, 3.0);
    displayArea(poly1);
    displayArea(poly2);
    return 0;
}
