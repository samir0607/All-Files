#include <iostream>
#include <vector>
#include <set>
using namespace std;

#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define pii pair<int, int>
#define all(v) v.begin(), v.end()

int n;
ll m;
ll total = 0;
vi a;


ll f(const vi &a) {
	set<int> tokens;
	for (int i = 1; i <= n; i++) tokens.insert(i);

	ll ways = 1;
	for (int i = 0; i < n; i++) {
		if (a[i] == 0) continue;
		int cnt = 0;
		for (int t : tokens) {
			if (t >= a[i] && t <= i + 1) cnt++;
		}

		if (cnt == 0) return 0; 
		ways = (ways * cnt) % m;
		for (int t = a[i]; t <= i + 1; t++) {
			if (tokens.count(t)) {
				tokens.erase(t);
				break;
			}
		}
	}
	return ways;
}

void dfs(int i) {
	if (i == n) {
		total = (total + f(a)) % m;
		return;
	}
	for (int val = 0; val <= i + 1; val++) {
		a[i] = val;
		dfs(i + 1);
	}
}

void solve() {
	cin >> n >> m;
	a.assign(n, 0);
	total = 0;
	dfs(0);
	cout << total << "\n";
}

int main() {
	fast_io;
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}
