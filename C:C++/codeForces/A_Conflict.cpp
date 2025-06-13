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
	int n;
	cin>>n;
	string t,a;
	cin>>t;
	cin>>a;
	for(int i = 0; i<n; i++) {
		if(t[i]=='o' && a[i]=='o') {
			cout<<"Yes\n";
			return;
		}
	}
	cout<<"No\n";
	
}

int main() {
		fast_io;

		int t = 1;
		//cin >> t;

		while (t--) {
				solve();
		}

		return 0;
}