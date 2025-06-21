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
	ll n, m;
	cin>>n>>m;
	if(1LL*n*(n+1)/2 < m || n > m) {
		cout<<-1<<endl;
		return;
	}
	if(n*(n+1)/2==m) {
		cout<<n<<endl;
		while(n>1) {
			cout<<n<<" "<<n-1<<endl;
			n--;
		}
		return;
	}
	if (m == n) {
    cout << 1 << endl;            
    for (ll i = 2; i <= n; i++)   
        cout << 1 << " " << i << endl;
    return;
}
	ll root = m-n+1;
	cout<<root<<endl;
	if(root!=1) cout<<root<<" "<<1<<endl;
	for (ll i = 1; i < n; i++) {
		if (i + 1 == root && root != n)
			cout << i << " " << i + 2 << endl;
		else if (i != root)
			cout << i << " " << i + 1 << endl;
  }
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