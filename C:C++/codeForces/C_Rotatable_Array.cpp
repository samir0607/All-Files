#include <iostream>
#include <vector>
using namespace std;

#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);
#define vi vector<int>

int main() {
    fast_io;
    int n, q;
    cin >> n >> q;
    vi a(n);
    int K = 0;  
    for (int i = 0; i < n; i++) a[i] = i + 1;
    for (int j = 0; j < q; j++) {
        int type;
        cin >> type;
        if (type == 1) {
            int p, x;
            cin >> p >> x;
            a[(K + p - 1) % n] = x;
        } else if (type == 2) {
            int p;
            cin >> p;
            cout << a[(K + p - 1) % n] << '\n';
        } else if (type == 3) {
            int k;
            cin >> k;
            K = (K + k) % n;
        }
    }

    return 0;
}
