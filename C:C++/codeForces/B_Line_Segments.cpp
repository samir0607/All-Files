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
	cin>>n;
	ll px,py,qx,qy;
	cin>>px>>py>>qx>>qy;
	vll a(n);
	ll sum = 0, maxi = 0;
	for (int i = 0; i < n; i++){
		cin>>a[i];
		sum+= a[i];
		maxi = max(maxi, a[i]);
	}
	ll Rmin = max(0LL, 2*maxi-sum);
	ll dx = qx- px;
	ll dy = qy - py;
	ll D2 = dx*dx + dy*dy;
	if((D2<= sum*sum) && (D2>= Rmin*Rmin)) cout<<"Yes\n";
	else cout<<"No\n";
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