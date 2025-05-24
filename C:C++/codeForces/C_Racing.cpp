#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define pii pair<int, int>
#define all(v) v.begin(), v.end()

void solve() {
	// Write your solution here
	int n;
	cin >> n;
	vector<int> d(n+1), ans(n+1);
	for(int i=1;i<=n;i++) cin >> d[i];

	vector<ll> L(n+1), R(n+1), l(n+1), r(n+1);
	for(int i=1;i<=n;i++) cin >> l[i] >> r[i];

	L[0] = R[0] = 0;
	for(int i=1;i<=n;i++){
		ll lo = L[i-1] + (d[i]==1);
		ll hi = R[i-1] + (d[i]!=0);
		L[i] = max(lo, l[i]);
		R[i] = min(hi, r[i]);
		if(L[i] > R[i]) {
			cout << "-1" << endl;
			return;
		}
	}

	// backward reconstruction
	ll h = R[n];
	for(int i=n;i>=1;i--){
		if(d[i]<0){
			if(h < L[i-1] || h > R[i-1]) d[i] = 1;
			else d[i] = 0;
		}
		ans[i] = d[i];
		if(d[i]==1) h--;
	}

	for(int i=1;i<=n;i++) 
		cout << ans[i] << ' ';
	cout << endl;
}

int main(){
	fast_io;
	int T; 
	cin >> T;
	while(T--){
			solve();
	}
	return 0;
}
