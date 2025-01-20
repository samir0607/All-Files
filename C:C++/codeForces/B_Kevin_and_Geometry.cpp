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
			vector<int> ans;
			unordered_map<int,int> mp;
			for(int i=0; i<n; i++) {
				cin>>a[i];
			}
			sort(a.begin(),a.end());
			for(int i=0; i<n; i++){
				mp[a[i]]++;
			}
			for(auto& [x,y]:mp){
				if(y>1){
					ans.push_back(x);
					ans.push_back(x);
					y-=2;
					if(y>1){
						ans.push_back(x);
						ans.push_back(x);
						y-=2;
					}
					break;
				}
			}
			if(ans.size()==4){
				for(int i=0; i<4; i++){
					cout<<ans[i]<<" ";
				}
				cout<<endl;
				continue;
			}
			if(ans.size()==0){
				cout<<-1<<endl;
				continue;
			}
			int leg = ans[0];
    for(auto& it : mp) {
        if(it.second() > 1 && ans.size() < 4) {
            ans.push_back(it.first());
						ans.push_back(x);
            break;
        } else if(it.second() > 0 && (it+1).second() > 0 && (it+1).second()-it.second()<=leg && ans.size() < 4) {
						ans.push_back(it.first());
						ans.push_back((it+1).first());
						break;
				}
    }
			if(ans.size()==4){
				for(int i=0; i<4; i++){
					cout<<ans[i]<<" ";
				}
				cout<<endl;
			} else{
				cout<<-1<<endl;
			}
		}
		return 0;
}