#include <iostream>
#include <string>
#include <set>
#include <vector>
using namespace std;

#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define vpi vector<pair<int, int> >
#define pii pair<int, int>
#define all(v) v.begin(), v.end()

void solve() {
	int n;
	cin>>n;
	vi a(n+1),b(n+1);
	for(int i = 1; i<=n; i++) cin>>a[i];
	for(int i = 1; i<=n; i++) cin>>b[i];

	vpi ans;
	for(int i = 1; i<=n; i++) {
		if(a[i]!=i) {
			bool ok = false;
			for(int j = i+1; j<=n; j++) {
				if(a[j]==i) {
					for(int k = j; k>i; k--) {
						swap(a[k-1],a[k]);
						ans.emplace_back(1,k-1);
					}
					ok = true;
					break;
				}
			}
			if(ok) continue;
			for(int j = 1; j<=n; j++) {
				if(b[j]==i) {
					if(j<i) {
						for(int k = j; k<i; k++) {
							swap(b[k],b[k+1]);
							ans.emplace_back(2,k);
						}
					} 
					else {
						for(int k = j; k>i; k--) {
							swap(b[k-1],b[k]);
							ans.emplace_back(2,k-1);
						}
					}
					swap(a[i],b[i]);
					ans.emplace_back(3,i);
					break;
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
    for (int j = 1; j < n; j++) {
			if (b[j] > b[j+1]) {
				swap(b[j],b[j+1]);
				ans.emplace_back(2, j);
			}
    }
	}
	cout<< ans.size() << endl;
	for(auto [x,y] : ans) {
		cout<<x<<" "<<y<<endl;
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