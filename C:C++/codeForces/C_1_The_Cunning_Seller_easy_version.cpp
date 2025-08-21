#include <iostream>
#include <string>
#include <set>
#include <vector>
using namespace std;

#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);
#define ull unsigned long long
#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define vull vector<unsigned long long>
#define pii pair<int, int>
#define all(v) v.begin(), v.end()

ll sumOfBase3Digits(ll n) {
    ll sum = 0;
    while (n) {
        sum += n % 3;
        n /= 3;
    }
    return sum;
}

void solve() {
    ll n;
    cin >> n;
	ll s3 = sumOfBase3Digits(n);
    ll remOp = (n - s3) / 2;
    vull powersOf3(40, 1);
	bool isPrecomputed = false;
    if (!isPrecomputed) {
        for (int i = 1; i < 40; ++i) 
            powersOf3[i] = powersOf3[i - 1] * 3ull;
        isPrecomputed = true;
    }
    vull digitCount(1, (ull)n); 
    ull extraValue = 0;
    int pos = 0;

    while (remOp > 0) {
        if (pos >= (int)digitCount.size()) 
            digitCount.push_back(0);

        ull availGroups = digitCount[pos] / 3ull;
        if (availGroups == 0) { 
            pos++; 
            continue; 
        }

        ull groupsToTake = (ull)min<ll>(availGroups, remOp);
        extraValue += groupsToTake * powersOf3[pos];

        digitCount[pos] -= groupsToTake * 3ull;

        if (pos + 1 >= (int)digitCount.size()) 
            digitCount.push_back(0);

        digitCount[pos + 1] += groupsToTake;
        remOp -= (ll)groupsToTake;
    }

    cout << (3ull * (ull)n + extraValue) << "\n";
}

int main() {
    fast_io;
    int testCases; 
    cin >> testCases;
    while (testCases--) {
        solve();
    }
    return 0;
}
