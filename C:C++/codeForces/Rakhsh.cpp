#include<iostream>
#include<vector>
using namespace std;

int timar(int n, int m, int k, string s){
  int WeakSpotCount = 0;
  int timarCount = 0;

  for(int i = 0; i<n; i++){
    if(s[i]=='0'){ 
      WeakSpotCount++;
      if(WeakSpotCount>=m){
        timarCount++;
        WeakSpotCount = 0;
        i += k - 1;
      }
    }
  }
  return timarCount;
}
int main(){
  int t;
  cin>>t;
  vector<int> res;
  for(int i=0;i<t;i++){
    int m,n,k;
    cin>>n>>m>>k;
    string s;
    cin>>s;
    res.push_back(timar(n,m,k,s));
  }
  for(int i=0;i<t;i++){
    cout<<res[i]<<endl;
  }
  return 0;
}