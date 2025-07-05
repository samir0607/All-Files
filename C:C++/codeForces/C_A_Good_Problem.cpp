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
	ll n,l,r,k;
	cin>>n>>l>>r>>k;
	if(n==2) {
		cout<<-1<<endl;
		return;
	}
	if(n%2!=0) {
		cout<<l<<endl;
		return;
	}
	ll x = l+1;
	ll pow = 1LL << (64 - __builtin_clzll(x) - ( (x & (x - 1)) == 0 ? 1 : 0 ));
	if(pow>r) cout<<-1<<endl;
	else if(n-k>=2) cout<<l<<endl;
	else cout<<pow<<endl;
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