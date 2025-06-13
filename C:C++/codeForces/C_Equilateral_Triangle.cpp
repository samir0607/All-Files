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
		// Write your solution here
}

int main() {
		fast_io;
		int n, L;
		cin>>n>>L;
		vi a(n-1);
		for(int i = 0; i<n-1; i++) cin>>a[i];
		vi pos(n);
		pos[0] = 0;
		for(int i = 1; i<n; i++) {
			pos[i] = (a[i-1] + pos[i-1])%L;
		}
		set<int> positions(all(pos));
		int ans = 0, step = L/3;
		for(int p: positions) {
			int p2 = (p + step)%L;
			int p3 = (p + 2*step)%L;
			if(positions.count(p2) && positions.count(p3)) ans++;
		}
		cout<<ans/3<<endl;

		return 0;
}