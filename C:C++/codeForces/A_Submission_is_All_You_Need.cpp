#include <iostream>
#include <string>
#include <unordered_set>
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
	vector<int> v;
	int cnt0 = 0, ans = 0;
	for(int i = 0; i<n; i++) {
		int x;
		cin>>x;
		v.push_back(x);
		if(x==0) cnt0++;
		ans+=x;
	}
	ans += cnt0;
	cout<<ans<<endl;
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