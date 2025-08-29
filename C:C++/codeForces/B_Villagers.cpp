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
	int n; cin>>n;
	vll a(n);
	ll sum = 0;

	for(int i = 0; i<n; i++) 
		cin>>a[i];

	sort(a.begin(), a.end());

	for(int i = n-1; i>=0; i-=2) 
		sum+=a[i];

	cout << sum <<endl;
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