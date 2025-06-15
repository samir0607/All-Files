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

int main() {
		fast_io;

		int n,q;
		cin>>n>>q;
		vi a(q);
		for(int i = 0; i<q; i++) cin>>a[i];
		vi b(n+1,0);
		for(int i = 0; i<q; i++) {
			if(a[i]>=1) {
				b[a[i]]++;
				cout<<a[i]<<" ";
			}
			else {
				int mini = 1;
				for(int j = 2; j<=n; j++) {
					if(b[j]<b[mini]) {
						mini = j;
					}
				}
				b[mini]++;
				cout<<mini<<" ";
			}
		}
		return 0;
}