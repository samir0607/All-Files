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
    int n;
    cin >> n;
    cout << 2*n-3 << endl;
    for(int i = 1; i <= n; i++) {
        if (i >= 2) 
            cout << i << " " << 1 << " " << i << endl;
        if (i <= n-2) 
            cout << i << " " << i+1 << " " << n << endl;
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