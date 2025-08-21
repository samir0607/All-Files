#include <iostream>
#include <vector>
using namespace std;

#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);
#define vi vector<int>

void solve() {
	int n;
	cin>>n;
	vi a(n);
	int i = 0, j = n - 1;
	int cnt = 1;
	while(i<j) {
		a[i++] = cnt++;
		a[j--] = cnt++;
	}
	if(n % 2 == 1)
		a[i] = cnt;
	for(int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
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