#include <iostream>
#include <string>
#include <set>
#include <vector>
using namespace std;

#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);
#define ull unsigned long long
#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define vull vector<unsigned long long>
#define pii pair<int, int>
#define all(v) v.begin(), v.end()

void solve() {
	ull n; cin>>n;
	vull ans;
	ull z = 10;
	for(int i = 1; i<=18; i++) {
		ull x = z+1;
		if(n%x==0) 
			ans.push_back(n/x);
		if(i<18) z*=10;
	}
	if(ans.empty()) {
		cout << 0 << endl;
		return;
	}
	sort(all(ans));
	int k = ans.size();
	cout<<k<<endl;
	for(int i = 0; i<k; i++) cout<<ans[i]<<" ";
	cout<<endl;
}

int main() {
	fast_io;

	ll t;
	cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}