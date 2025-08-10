#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define pii pair<int, int>
#define all(v) v.begin(), v.end()

void solve() {
    ll n,k; cin>>n>>k;
    vll s(n), t(n);
    for(int i = 0; i<n; i++) cin>>s[i];
    for(int i = 0; i<n; i++) cin>>t[i];

    if(k == 0) {
        sort(all(s));
        sort(all(t));
        if(s == t) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        return;
    }

    unordered_map<ll,ll> cnt;
    cnt.reserve(n * 2);

    for (auto &x : s) {
        ll rem = x % k;
        if(rem < 0) rem += k;
        ll mini = min(rem, k - rem);
        cnt[mini]++;
    }
    for (auto &x : t) {
        ll rem = x % k;
        if(rem < 0) rem += k;
        ll mini = min(rem, k - rem);
        cnt[mini]--;
    }

    for (auto &it : cnt) {
        if(it.second != 0) { 
			cout<<"NO"<<endl;
			return;
		}
    }
    cout<<"YES"<<endl;
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
