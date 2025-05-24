#include <iostream>
#include <string>
#include <stack>

using namespace std;

#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define pii pair<int, int>
#define all(v) v.begin(), v.end()

void solve() {
		// Write your solution here
	string s;
	cin >> s;
	stack<int> st;
	int n = s.size();
	for (size_t i = 0; i < n; i++)
	{
		if (s[i] == '(') {
			st.push(i);
		} else if (!st.empty()) {
			st.pop();
		}
		if(st.empty() && i!=n-1) {
			cout << "YES" << endl;
			return;
		}
	}
	cout << "NO" << endl;
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