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

		int n;
		cin>>n;
		vi a(n);
		for(int i = 0;i <n; i++) cin>>a[i];
		int k;
		cin>>k;
		int cnt = 0;
		for(int i = 0 ;i <n; i++) {
			if(k<=a[i]) cnt++;
		}
		cout<<cnt<<endl;

		return 0;
}