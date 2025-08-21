#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;

#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define pii pair<int, int>
#define all(v) v.begin(), v.end()

void solve() {
	int n; cin>>n;
	string a,b,c;
	cin>>a;
	int m; cin>>m;
	cin>>b;
	cin>>c;

	string x = "", y = "";
	for(int i = 0; i<m; i++) {
		if(c[i]=='D') x+=b[i];
		else y+=b[i];
	}
	reverse(y.begin(), y.end());
	cout<< y + a + x <<endl;
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