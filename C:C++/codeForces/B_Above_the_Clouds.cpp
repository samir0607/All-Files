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
	cin>>n;
	string s;
	cin>>s;
	vi freq(26,0);
	for(int i = 0; i<n; i++) {
		freq[s[i]-'a']++;
	}
	for(int i = 1; i<n-1; i++) {
		if(freq[s[i]-'a']>1) {
			cout<<"Yes\n";
			return;
		}
	}
	cout<<"No\n";
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