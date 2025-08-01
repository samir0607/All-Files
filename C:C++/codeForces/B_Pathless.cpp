#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
using namespace std;

typedef long long ll;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    int delta = k - sum;
    if (delta < 0) {
        for (int x : a) cout << x << ' ';
        cout << '\n';
        return;
    }
    if (delta == 0) {
        cout << -1 << '\n';
        return;
    }

    int cnt[3] = {0, 0, 0};
    for (int x : a) cnt[x]++;
    int ord[3] = {0, 1, 2};
    do {
        vector<int> arr;
        arr.reserve(n);
        for (int t = 0; t < 3; ++t) {
            int v = ord[t];
            for (int i = 0; i < cnt[v]; ++i)
                arr.push_back(v);
        }
        vector<int> coins;
        coins.reserve(n-1);
        for (int i = 0; i + 1 < n; ++i) {
            int b = arr[i] + arr[i+1];
            if (b > 0) coins.push_back(b);
        }
        static bitset<1001> dp;
        dp.reset();
        dp[0] = 1;
        for (int c : coins) {
            for (int x = c; x <= delta; ++x) {
                if (dp[x - c]) dp[x] = 1;
            }
		}
        if (!dp[delta]) {
            for (int v : arr) cout << v << ' ';
            cout<<endl;
            return;
        }
    } while (next_permutation(ord, ord + 3));

    cout << -1 <<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}