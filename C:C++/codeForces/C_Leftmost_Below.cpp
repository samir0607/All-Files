#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long

void solve() {
    int n;
    cin >> n;
    vector<ll> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    
    // The key insight: think of this as a "water filling" problem
    // Each operation adds some amount to the leftmost position that needs it
    
    // Correct approach: check from right to left
    // At each position, verify that we can achieve the target value
    // given the constraints of the leftmost-below rule
    
    ll suffix_sum = 0;
    bool possible = true;
    
    for (int i = n - 1; i >= 0; i--) {
        suffix_sum += b[i];
        
        // Key condition: b[i] should not exceed half of suffix_sum
        // This is because operations are "shared" - an operation that
        // could go to position i could also go to positions j > i
        if (b[i] * 2 > suffix_sum) {
            possible = false;
            break;
        }
    }
    
    cout << (possible ? "YES" : "NO") << "\n";
}if (prefix_sum < b[i]) {
            cout << "NO\n";
            return;
        }
    }
    
    cout << "YES\n";
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