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
	int a,b,x,y;
	cin>>a>>b>>x>>y;
	if(a>b) {
		if(a-b==1 && a%2!=0) cout<<y<<endl;
		else cout<<-1<<endl;
	}
	else if(x<=y) {
		cout<<(b-a)*x<<endl;
	} else {
		int evenSteps = (b - a + (a % 2 == 0 ? 1 : 0)) / 2;
		cout<<(b-a-evenSteps) * x + evenSteps * y<<endl;
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