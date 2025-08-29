#include <iostream>
#include <string>
#include <unordered_map>
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
	unordered_map<int, int> mp;
	for(int i = 0; i<n; i++) {
		int x; cin>>x;
		mp[x]++;
	}
	for(auto &it: mp) {
		if(it.second>1) {
			cout<<"YES\n";
			return;
		}
	}
	cout<<"NO\n";
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