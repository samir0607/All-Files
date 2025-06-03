#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long
#define vll vector<long long>

void solve() {
		ll n;
		cin >> n;
		vll a(n);
		for (ll i = 0; i < n; i++) {
				cin >> a[i];
		}
		ll minCost = LLONG_MAX;
		for(int i = 0; i<n; ) {
			int j = i;
			while(j+1<n && a[i] == a[j+1]) {
				j++;
			}
			ll cost = (n - (j+1 - i)) * a[i];
			minCost = min(minCost, cost);
			i = j + 1;
		}
		cout << minCost << endl;
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