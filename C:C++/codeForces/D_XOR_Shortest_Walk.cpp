#include <iostream>
#include <string>
#include <set>
#include <vector>
using namespace std;

#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long
#define vi vector<int>
#define vb vector<bool>
#define vvpi vector<vector<pair<int,int> > >
#define vll vector<long long>
#define pii pair<int, int>
#define all(v) v.begin(), v.end()


void dfs(vvpi &adj, int node, int dest, int currXOR, int&minXOR, vb &vis) {
	if(node==dest) {
		minXOR = min(minXOR, currXOR);
		for(auto it: adj[node]) {
			int v = it.first;
			int wt = it.second;
			if(!vis[v])
				dfs(adj, v, dest, currXOR^wt, minXOR, vis);
		}
		return;
	}
	vis[node] = true;
	for(auto it: adj[node]) {
		int v = it.first;
		int wt = it.second;
		if(!vis[v])
			dfs(adj, v, dest, currXOR^wt, minXOR, vis);
	}
	vis[node] = false;
}

int main() {
		fast_io;

		int n, m;
		cin>>n>>m;

		vvpi adj(n+1);
		for(int i = 0; i<m; i++) {
			int u,v,wt;
			cin>>u>>v>>wt;
			adj[u].emplace_back(v,wt);
		}
		int minXOR = INT_MAX;
		vb vis(n+1,false);
		vis[1] = true;
		dfs(adj, 1, n, 0, minXOR, vis);
		if(minXOR==INT_MAX) cout<<-1<<endl;
		else cout<<minXOR<<endl;
		return 0;
}