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
	cin >> n;
	vi a(n+1);
	for(int i=1;i<=n;i++) cin >> a[i];
	ll ans = 0;
	for(int i = 3; i <= n; i++){
		int x = (i < n ? a[n] : a[n-1]);
		int th = max(a[i], x - a[i]);
		int l = 1, r = i - 1;
		while(l < r){
			if(a[l] + a[r] > th){
				ans += (r - l);
				r--;
			} else l++;
		}
	}

	cout << ans << "\n";
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