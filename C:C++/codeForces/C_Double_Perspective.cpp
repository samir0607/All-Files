#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <numeric> // for iota
using namespace std;

#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define pii pair<int, int>
#define all(v) v.begin(), v.end()

struct DSU {
    int size;
    vi parent;
    DSU(int n) : size(n), parent(n + 1) {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int node) {
        return parent[node] == node ? node : parent[node] = find(parent[node]);
    }

    bool unite(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) return false;
        parent[v] = u;
        return true;
    }
};

struct Edge {
    int u, v;
    int weightDiff;
    int index;
};

void solve() {
    int numEdges;
    cin >> numEdges;
    vector<Edge> edgeList(numEdges);
    int maxNode = 0;

    for (int i = 0; i < numEdges; i++) {
        cin >> edgeList[i].u >> edgeList[i].v;
        edgeList[i].weightDiff = edgeList[i].v - edgeList[i].u;
        edgeList[i].index = i + 1;
        maxNode = max(maxNode, max(edgeList[i].u, edgeList[i].v));
    }

    sort(edgeList.begin(), edgeList.end(), [](const Edge &a, const Edge &b) {
        return a.weightDiff > b.weightDiff;
    });

    DSU dsuStructure(maxNode);
    vi selectedEdgeIndices;

    for (size_t i = 0; i < edgeList.size(); ++i) {
        if (dsuStructure.unite(edgeList[i].u, edgeList[i].v)) {
            selectedEdgeIndices.push_back(edgeList[i].index);
        }
    }

    cout << selectedEdgeIndices.size() << "\n";
    for (size_t i = 0; i < selectedEdgeIndices.size(); ++i) {
        cout << selectedEdgeIndices[i] << (i + 1 < selectedEdgeIndices.size() ? ' ' : '\n');
    }
}

int main() {
    fast_io
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
