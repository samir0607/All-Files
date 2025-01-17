#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

string canAliceWin(int n, int a, int b) {
    int d = abs(a - b);
    if (d % 2 == 1) {
        return "NO";
    } else {
        return "YES";
    }
}

int main() {
    int t;
    cin >> t;

    vector<string> results;

    while (t--) {
        int n, a, b;
        cin >> n >> a >> b;
        results.push_back(canAliceWin(n, a, b));
    }

    for (int i = 0; i<results.size(); i++) {
        cout << results[i] << endl;
    }

    return 0;
}