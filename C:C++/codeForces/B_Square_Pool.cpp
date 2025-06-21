#include <iostream>
#include <string>
#include <set>
#include <vector>
using namespace std;

#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define pii pair<int, int>
#define all(v) v.begin(), v.end()

void solve() {
	int n, s;
	cin>>n>>s;
	int cnt = 0;
	for(int i = 0; i<n; i++) {
		int a,b,x,y;
		cin>>a>>b>>x>>y;
		if(x==y && a==b) cnt++;
		else if(x==s-y && a!=b) cnt++;
	}
	cout<<cnt<<endl;
}

int main() {
		fast_io;

		int t;
		cin >> t;

		while (t--) {
				solve();
		}

		return 0;
}