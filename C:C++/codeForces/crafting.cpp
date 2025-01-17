#include<iostream>
#include<vector>
using namespace std;
int main(){
  int t;
  cin>>t;
  vector<string> results;
  for(int i = 0; i<t; i++){
    int n;
    cin >> n;
    vector<long long> a(n), b(n);
    long long sumA = 0, sumB=0;
    for(int i = 0; i<n; i++){
      cin >> a[i];
    }
    for(int i = 0; i<n; i++){
      cin >> b[i];
    }
    bool possible = true;
    for(int i = 0; i<n; i++){
      if(a[i]<b[i]){
        a[i]++;
      }
      
    }
    if(possible) results.push_back("YES");
    else results.push_back("NO");
  }
  for (int i = 0; i<results.size(); i++) {
    cout << results[i] << endl;
  }
  return 0;
}