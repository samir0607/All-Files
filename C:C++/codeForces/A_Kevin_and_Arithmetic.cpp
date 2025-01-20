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
		
		int t;
		cin >> t;

		while (t--) {
			int n;
			cin>>n;
			vector<int> a(n);
			for(int i=0; i<n; i++) {
				cin>>a[i];
			}
			//Rearranging 
			vector<int> even;
			vector<int> odd;
			for(int i =0;i<n;i++){
				if(a[i]%2==0) even.push_back(a[i]);
				else odd.push_back(a[i]);
			}
			int i=0,j=0,k=0;
			while(j<even.size()&&k<odd.size()){
				if(j<even.size()){
					a[i++]=even[j++];
				}
				if(k<odd.size()){
					a[i++]=odd[k++];
				}
			}
			while(j<even.size()){
				a[i++]=even[j++];
			}
			while(k<odd.size()){
				a[i++]=odd[k++];
			}
			long long s = 0;
			int point = 0;
			for(int x=0; x<n; x++) {
				s+=a[x];
				if(s%2==0) {
					point++;
					while(s%2==0) {
						s/=2;
					}
				}
			}
			cout<<point<<endl;
		}

		return 0;
}