#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll INF = (ll)4e18;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<ll> b(n+1);
        for (int i = 1; i <= n; i++) {
            cin >> b[i];
        }

        // Build adjacency list of the DAG
        vector< vector< pair<int, ll> > > adj(n+1);
        for (int i = 0; i < m; i++) {
            int s, t;
            ll w;
            cin >> s >> t >> w;
            adj[s].push_back(make_pair(t, w));
        }

        // need[u] = minimum battery required upon arriving at u
        // to still be able to finish (reach n).
        vector<ll> need(n+1, INF);
        need[n] = 0;               // at n, no further battery is needed

        // Process nodes in reverse topological order: n-1, n-2, ..., 1
        // (since edges only go from smaller→larger index)
        for (int u = n-1; u >= 1; u--) {
            ll best = INF;
            for (size_t ei = 0; ei < adj[u].size(); ++ei) {
                pair<int, ll>& e = adj[u][ei];
                int v = e.first;
                ll w = e.second;
                if (need[v] == INF) 
                    continue;            // v can't reach n
                // to use edge u→v and then finish from v,
                // you need at least max(w, need[v]) AFTER picking at u,
                // so before picking you need that minus b[u].
                ll req = max(w, need[v]) - b[u];
                best = min(best, req);
            }
            if (best < 0) best = 0;      // never a negative requirement
            need[u] = best;
        }

        // If need[1] is still INF, there's no path from 1→n
        ll ans = (need[1] >= INF/2 ? -1LL : need[1]);
        cout << ans << "\n";
    }
    return 0;
}
