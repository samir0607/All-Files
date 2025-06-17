#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long
#define vi vector<int>
#define vvi vector<vector<int> >
#define vpi vector<pair<int,int> >
#define vll vector<long long>
#define pii pair<int, int>
#define all(v) v.begin(), v.end()

int dp[20][2][2];

void solve() {
	ll L, R;
	cin >> L >> R;
	string l = to_string(L);
	string r = to_string(R);
	int d = l.size();
	for (int i = 0; i <= d; i++)
		for (int lo = 0; lo < 2; lo++)
			for (int hi = 0; hi < 2; hi++)
				dp[i][lo][hi] = 1e9;

	for (int lo = 0; lo < 2; lo++)
		for (int hi = 0; hi < 2; hi++)
			dp[d][lo][hi] = 0;

	for (int i = d - 1; i >= 0; i--) {
		int ld = l[i] - '0';
		int rd = r[i] - '0';
		for (int lo = 0; lo < 2; lo++) {
			for (int hi = 0; hi < 2; hi++) {
				int &res = dp[i][lo][hi];
				res = 1e9;
				for (int dig = 0; dig < 10; dig++) {
					if (lo && dig < ld) continue;
					if (hi && dig > rd) continue;
					int nlo = lo && (dig == ld);
					int nhi = hi && (dig == rd);
					int cost = (dig == ld) + (dig == rd);
					res = min(res, cost + dp[i+1][nlo][nhi]);
				}
			}
		}
	}
	cout<<dp[0][1][1]<<endl;
}

int main(){
	fast_io;
	int T;
	cin >> T;
	while (T--) {
			solve();
	}
	return 0;
}
