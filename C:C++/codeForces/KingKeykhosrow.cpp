#include<iostream>
#include<vector>
using namespace std;

int max(int a,int b){
  return (a>=b)? a : b;
}

int keyM(int a, int b){
  for(int m = max(a,b); m<=a*b ; m++){
    if(m%a==m%b) return m;
  }
  return -1;
}

int main(){
  int t;
  vector<int> results;
  cin>>t;
  for(int i = 0; i<t; i++){
    int a,b;
    cin>>a>>b;
    results.push_back(keyM(a,b));
  }
  for (int result : results) {
    cout << result << endl;
  }
  return 0;
}