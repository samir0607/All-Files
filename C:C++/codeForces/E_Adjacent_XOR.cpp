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
	vll a(n),b(n);
	for(int i = 0; i<n; i++) cin>>a[i];
	for(int i = 0; i<n; i++) cin>>b[i];

	if(a[n-1] != b[n-1]) { 
		cout<<"NO"<<endl; 
		return; 
	}

	vll c(n-1);
	for(int i=0;i<n-1;i++) c[i] = a[i] ^ b[i];

	bool ok = true;
	for(int i=0;i<n-1 && ok; ){
		if(c[i]==0){ 
			i++; 
			continue; 
		}
		int j=i;
		while (j<n - 1) { 
			if (c[j] == a[j+1]) { 
				i = j + 1; 
				break; 
			}
			if (j + 1 >= n - 1) { 
				ok = false; 
				break; 
			}
			if (c[j+1] != (c[j]^ a[j+1])) { 
				ok = false; 
				break; 
			}
        	j++;
    	}
		if(j >= n - 1 && c[j] != a[j]) { 
			ok = false;
		}
	}
	cout<<(ok ?"YES" : "NO")<<endl;
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