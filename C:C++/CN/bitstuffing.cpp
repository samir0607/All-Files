#include<iostream>
#include<string>

using namespace std;

string bitStuffing(string s){
  string res;
  int count = 0;
  for(int i = 0; i < s.size(); i++){
    res+=s[i];
    if(s[i] == '1'){
      count++;
      if(count==5){
        res+='0';
        count=0;
      }
    } else count=0;
  }
  return res;
}

string unStuff(string s){
  string res;
  int count = 0;
  for(int i = 0; i < s.size(); i++){
    res+=s[i];
    if(s[i] == '1'){
      count++;
      if(count==5){
        res+='0';
        count=0;
      }
    }else count=0;
  }
  return res;
}

int main(){
string s;
cout<<"Enter a bit string: ";
cin>>s;
cout<<"Stuffed bit: "<<bitStuffing(s);
return 0;
}