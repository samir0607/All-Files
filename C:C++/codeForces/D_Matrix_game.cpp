#include <iostream>
#include <string>
#include <set>
#include <vector>
#include<tuple>
using namespace std;

#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define pii pair<int, int>
#define all(v) v.begin(), v.end()
static const int MOD = 1e9+7;

// fast exponentiation
ll modexp(ll x, ll e) {
    ll r = 1, p = x % MOD;
    while (e) {
        if (e & 1) r = r * p % MOD;
        p = p * p % MOD;
        e >>= 1;
    }
    return r;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    vector<tuple<int,int,int> > Q(T);
    int maxA = 0;
    for (int i = 0; i < T; i++) {
        int a,b,k;
        cin >> a >> b >> k;
        Q[i] = {a,b,k};
        maxA = max(maxA, a);
    }

    // precompute factorials and inverse factorials up to maxA
    vector<ll> fact(maxA+1,1), invfact(maxA+1,1);
    for (int i = 1; i <= maxA; i++) {
        fact[i] = fact[i-1] * i % MOD;
    }
    invfact[maxA] = modexp(fact[maxA], MOD-2);
    for (int i = maxA; i > 0; i--) {
        invfact[i-1] = invfact[i] * i % MOD;
    }

    // answer each test case
    for (auto &tup : Q) {
        ll a,b,k;
        tie(a,b,k) = tup;

        // n = (a-1)*k + 1  (mod)
        ll n = ((a-1)%MOD * (k%MOD) + 1) % MOD;

        // compute binom(n_real, a) mod via falling product:
        // P = n * (n-1) * ... * (n-(a-1))  mod
        ll P = 1;
        for (int i = 0; i < a; i++) {
            P = P * ((n - i + MOD) % MOD) % MOD;
        }
        ll C = P * invfact[a] % MOD;  // C(n_real, a)

        // m = (b-1)*k % * C % + 1
        ll m = ((b-1)%MOD * (k%MOD) % MOD * C % MOD + 1) % MOD;

        cout << n << " " << m << "\n";
    }
    return 0;
}
