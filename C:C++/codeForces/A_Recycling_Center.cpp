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

vector<ll>::iterator findJustSmaller(vector<ll>& a, ll target) {
    ll left = 0, right = a.size() - 1;
    vector<ll>::iterator result = a.end();  
    
    while (left <= right) {
        ll mid = left + (right - left) / 2;
        if (a[mid] < target) {
            result = a.begin() + mid;  
            left = mid + 1;           
        } else {
            right = mid - 1;           
        }
    }
    return result;
}

void solve() {
	ll n, c;
	cin>>n>>c;
	vll a(n);
	for(ll i = 0; i<n; i++) cin>>a[i];

	sort(a.begin(), a.end());
	ll lb = 0;
	while (true) {
        auto it = findJustSmaller(a, c);
        if (it == a.end()) break;
        a.erase(it);
        for (ll& num : a) num *= 2;
        lb++;
    }
	cout << n-lb << endl;
}

int main() {
	fast_io;

	ll t;
	cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}