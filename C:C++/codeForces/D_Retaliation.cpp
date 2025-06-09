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
	ll n;
	cin >> n;
	vll a(n+1);
	for (int i = 1; i <= n; i++) cin >> a[i];
	ll D = n * n - 1;
	ll Y = n * a[1] - a[n];
	if (D<=0 || Y<0 || Y%D!= 0) {
		cout<<"NO"<<endl;
		return;
	}
	ll y = Y / D;
	ll x = a[1] - y * n;
	if (x < 0) {
		cout<<"NO"<<endl;
		return;
	}
	for (int i = 1; i <= n; i++) {
		ll expect = x * i + y * (n - i + 1);
		if (expect != a[i]) {
			cout<<"NO"<<endl;
			return;
		}
	}
	cout<<"YES"<<endl;
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