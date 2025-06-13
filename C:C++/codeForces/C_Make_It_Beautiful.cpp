#include <iostream>
#include<queue>
#include<vector>

using namespace std;

#define ll                     long long int
#define ld                     long double
#define mod                    1000000007
#define MOD1                   998244353
#define inf                    1e18
#define pb                     push_back
#define vi                     vector<int>
#define vll                    vector<ll>
#define vs                     vector<string>
#define vc                     vector<char>
#define vb                     vector<bool>
#define pii                    pair<int, int>
#define pll                    pair<ll, ll>
#define vpii                   vector<pair<int, int>>
#define vpll                   vector<pair<ll, ll>>
#define vvi                    vector<vector<int>>
#define vvl                    vector<vector<ll>>
#define all(n)                 n.begin(),n.end()
#define mid(l, r)              (l + (r - l) / 2)
#define ff                     first
#define ss                     second
#define forloop(var, a, b)     for(ll var = (a); var <= (b); var++)
#define forlooprev(var, a, b)  for(ll var = (a); var >= (b); var--)
#define logarr(arr, a, b)      for(ll z = (a); z <= (b); z++) cout << (arr[z]) << " "; cout << endl;

void solve( ) {
    ll n, k;
    cin >> n >> k;
    vll a(n);
    forloop(i, 0, n - 1) cin >> a [i];

    ll beauty = 0;
    vll upgrades;

    forloop(i, 0, n - 1) {
        ll x = a [i];
        beauty += __builtin_popcountll(x);

        // Generate upgrade steps
        while (true) {
            int pos = __builtin_ctzll(~x); // position of lowest 0-bit
            ll cost = 1LL << pos;
            if (k < cost) break;
            upgrades.pb(cost);
            x += cost; // flip the 0-bit at position pos
        }
    }

    // Sort upgrades by cost and pick cheapest until k is exhausted
    sort(all(upgrades));
    for (ll cost : upgrades) {
        if (k >= cost) {
            k -= cost;
            ++beauty;
        }
        else break;
    }

    cout << beauty << '\n';
}

int main( ) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin.exceptions(cin.failbit);
    ll t = 1;
    cin >> t;
    while (t--) {
        solve( );
    }

    return 0;
}
