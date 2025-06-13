#include <iostream>
#include <string>
using namespace std;

#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);

void solve() {
	int n, k;
	cin>>n>>k;
	string s="";
	n = n - k;
	while(k--) s+='1';
	while(n--) s+='0';
	cout<<s<<endl;
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