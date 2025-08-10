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
    int n; cin>>n;
    if(n % 2 != 0) {
        for(int i = 0; i < n; ++i) {
            if (i % 2 == 0) cout << -1 << " ";
            else cout << 3 << " ";
        }
    } else {
        if(n == 2) cout << -1 << " " << 2;
        else {
            for(int i = 0; i < n - 2; ++i) {
                if(i % 2 == 0) cout << -1 << " ";
				else cout << 3 << " ";
            }
            cout << -1 << " " << 2;
        }
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