#include<iostream>
using namespace std;

template <typename T>
class Pair{
  T x, y;
  public:
  Pair(T a, T b): x(a), y(b){}
  T getMax() {
    return (x>y)? x:y;
  }
};

int main(){
  Pair<int> intPair(1,2);
  cout<< "Max of int Number: "<< intPair.getMax() << endl;
  Pair<float> floatPair(1.1f,2.1f);
  cout<< "Max of float Number: "<< floatPair.getMax() << endl;
  Pair<double> doublePair(11.112,22.122);
  cout<< "Max of double Number: "<< doublePair.getMax() << endl;
}