#include <iostream>
#include <vector>
using namespace std;

#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);
#define vi vector<int>

void solve() {
		int n,x;
		cin>>n>>x;
		vi a(n);
		int first = -1, last = -1;
		for(int i = 0; i < n; i++) {
			cin >> a[i];
			if(first == -1 && a[i] == 1) 
				first = i;
			if(a[i] == 1)
				last = i;
		}
		if(last-first+1 > x) 
			cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
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