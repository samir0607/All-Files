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
	cin >> n >> s;
	vi a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
	int maxi = INT_MIN, mini = INT_MAX;
	for(int i = 0; i<n; i++) {
		maxi = max(maxi, a[i]);
		mini = min(mini, a[i]);
	}
	int ans;
	if(s<=mini) {
		ans = maxi - s;
	}
	else if(s>=maxi) ans = s-mini;
	else{
		if(s-mini>maxi-s) ans = 2*(maxi-s) + (s-mini);
		else ans = 2*(s-mini) + (maxi-s);
	}
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