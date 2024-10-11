#include<iostream>
using namespace std;

class Item{
  int itemId;
  public:
  Item(){
    itemId = 1001;
    cout<<"Item Id of this item is "<<itemId<<endl;
  }
  Item(int id){
    itemId = id;
    cout<<"Item Id of this item is "<<itemId<<endl;
  }
};

int main(){
  Item b;
  Item a(12);
  return 0;
}