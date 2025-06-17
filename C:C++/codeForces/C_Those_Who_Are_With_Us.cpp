#include <iostream>
#include <string>
#include <set>
#include <vector>
using namespace std;

#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long
#define vi vector<int>
#define vvi vector<vector<int> >
#define vpi vector<pair<int,int> >
#define vll vector<long long>
#define pii pair<int, int>
#define all(v) v.begin(), v.end()

void solve() {
	int n,m;
	cin>>n>>m;
	vvi a(n,vi(m));
	int maxi = INT_MIN;
	for(int i = 0; i<n; i++) {
		for(int j = 0; j<m; j++) {
			cin>>a[i][j];
			maxi = max(maxi, a[i][j]);
		}
	}
	vpi pos;
	vector<bool> I(n,false), J(m, false);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(a[i][j] == maxi) {
				pos.emplace_back(i,j);
				I[i] = true;
				J[j] = true;
			}
		}
  }
	for(int r = 0; r<n; r++) {
		if(!I[r]) continue;
		int c = -1;
		bool ok = true;
		for(auto [i,j] : pos) {
			if(i==r) continue;
			if(c==-1) {
				c = j;
			} else if(c!=j) {
				ok = false;
				break;
			}
		}
		if(ok) {
			cout<<maxi-1<<endl;
			return;
		}
	}
	cout<<maxi<<endl;
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