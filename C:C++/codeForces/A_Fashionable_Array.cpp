#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);
#define vi vector<int>
#define all(v) v.begin(), v.end()

void solve() {
		int n; 
		cin >> n;
		vi arr(n);
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		sort(all(arr));
		if((arr[0]+arr[n-1])%2==0) {
			cout << 0 << endl;
			return;
		}
		int i = 1;
		int j = n - 1;
		while((arr[i]+arr[i-1])%2 == 0 && i < n) {
			i++;
		}
		while((arr[j]+arr[j-1])%2 == 0 && j > 0) {
			j--;
		}
		cout<<min(i, n - j) << endl;
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