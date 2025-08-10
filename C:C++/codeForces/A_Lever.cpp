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
	vector<int> a(n), b(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];
	int ans = 0;
	while(true) {
		bool op1 = false, op2 = false;
		for (int i = 0; i < n; i++) 
			if(a[i] > b[i]) 
				op1 = true;
		for (int i = 0; i < n; i++) 
			if (a[i] < b[i]) 
				op2 = true;
		ans++;
		if(op1) {
			for (int i = 0; i < n; i++) {
				if (a[i] > b[i]) { 
					a[i]--; 
					break; 
				}
			}
		}
		if(op2) {
			for (int i = 0; i < n; i++) {
				if (a[i] < b[i]) {
					a[i]++; 
					break;
				}
			}
		}
		if(!op1) break;
	}
	cout << ans << endl;
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