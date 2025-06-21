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
	int l1,b1,l2,b2,l3,b3;
	cin>>l1>>b1>>l2>>b2>>l3>>b3;
	bool ok = false;
	if(l1==l2 && l2==l3 && l1 == b1+b2+b3) {
		ok = true;
	}
	else if(b1==b2 && b2==b3 && b1 == l1+l2+l3) {
		ok = true;
	}
	else if(l2==l3 && b1==b2+b3 && l1+l2==b1) {
		ok = true;
	}
	else if(b2==b3 && l1==l2+l3 && b1+b2==l1) {
		ok = true;
	}

	if(ok) cout<<"YES\n";
	else cout<<"NO\n";
	
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