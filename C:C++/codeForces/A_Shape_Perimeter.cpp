#include <iostream>
#include <unordered_set>
#include <vector>
#include <utility>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int total_perimeter = 4 * m * n;
        vector<pair<int, int > > given(n);


        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            if (i == 0) {
                given [i].first = x;
                given [i].second = y;
            } else {
                given [i].first = x + given [i - 1].first;
                given [i].second = y + given [i - 1].second;
            }
        }
        vector<pair<int, int> >corner(n);
        for (int i = 0; i < n; i++) {
            corner [i].first = given [i].first + m;
            corner [i].second = given [i].second + m;
        }
        int extraLength = 0;
        for (int i = 0; i < n - 1; i++) {
            int dx = abs(corner [i].first - given [i + 1].first);
            int dy = abs(corner [i].second - given [i + 1].second);
            extraLength += 2 * (dx + dy);
        }
        int ans = total_perimeter - extraLength;
        cout << ans << endl;
    }

    return 0;
}