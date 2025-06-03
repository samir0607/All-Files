#include <iostream>
#include <cmath>

using namespace std;

#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long

void solve() {
		ll x;
		cin >> x;
		cout << 3 + 2 * (int)log2(x) << endl;
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