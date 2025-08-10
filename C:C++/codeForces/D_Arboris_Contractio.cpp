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

vector<vi> adj;   
vi d;           
vll sz, lf, op;  
int n;

void dfs(int u, int p) {
    sz[u] = 1;
    lf[u] = (d[u] == 1);
    op[u] = 0;
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
        sz[u] += sz[v];
        lf[u] += lf[v];
        if (sz[v] > 1) op[u] += lf[v];
    }
}

void solve() {
    cin >> n;
    adj.assign(n + 1, vi());
    d.assign(n + 1, 0);

    for(int i = 0; i < n - 1; ++i) {
        int u, v; cin >>u>>v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
        d[u]++; 
		d[v]++;
    }

    bool star = false;
    for(int i = 1; i <= n; ++i) {
        if (d[i] == n - 1) { 
			star = true; 
			break; 
		}
    }
    if(star) { 
		cout << 0<< endl; 
		return; 
	}

    sz.assign(n + 1, 0);
    lf.assign(n + 1, 0);
    op.assign(n + 1, 0);

    dfs(1, 0);

    ll ans = -1, tot_lf = lf[1];
    for(int i = 1; i <= n; ++i) {
        ll cur = op[i];
        if(i != 1) {
            ll p_sz = n - sz[i];
            if (p_sz > 1) cur += (tot_lf - lf[i]);
        }
        if(ans == -1 || cur < ans) ans = cur;
    }
    cout << ans<<endl;
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
