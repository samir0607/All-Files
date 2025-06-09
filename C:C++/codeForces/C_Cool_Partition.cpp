#include <iostream>
#include <vector>
using namespace std;

#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);
#define vi vector<int>

void solve() {
	int n;
	cin>>n;
	vi a(n);
	for(int i = 0; i < n; i++) cin>>a[i];
	int cool = 0;
	int closest = INT_MAX;
	for(int i = 0; i<n; i++) {
		for(int j = i+1; j<n; j++) {
			if(a[i]==a[j] || j==closest) {
				closest = j;
				break;
			}
			if(closest==i){
				closest = INT_MAX;
				cool++;
				if(i!=0) i--;
				break;
			}
		}
	}
	cout<<cool+1<<endl;
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