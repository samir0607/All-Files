#include <iostream>
#include <unordered_set>
#include <vector>
#include <utility>
using namespace std;

struct PairHash {
    size_t operator()(const pair<int, int>& p) const {
        return hash<int>()(p.first) ^ hash<int>()(p.second);
    }
};

void solve() {
    int n, m;
    int res = 0;
    cin >> n >> m;
    int X = 0, Y = 0;
    unordered_set<pair<int, int>, PairHash> cell;

    for (int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < m; k++) {
                cell.emplace(X + x + j, Y + y + k);
            }
        }
        X += x;
        Y += y;
    }

    for (const auto& p : cell) {
        int x = p.first, y = p.second;
        int cnt = 0;
        if (cell.count(make_pair(x + 1, y))) cnt++;
        if (cell.count(make_pair(x - 1, y))) cnt++;
        if (cell.count(make_pair(x, y + 1))) cnt++;
        if (cell.count(make_pair(x, y - 1))) cnt++;
        res += 4 - cnt;
    }

    cout << res << endl;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
