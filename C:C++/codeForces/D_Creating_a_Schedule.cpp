#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// Extract floor number by removing last 2 digits
int get_floor(int classroom) {
    return classroom / 100;
}

// Comparator for sorting by floor
bool cmp_by_floor(int a, int b) {
    return get_floor(a) < get_floor(b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> classrooms(m);
        for (int i = 0; i < m; ++i) cin >> classrooms[i];

        // Sort classrooms by floor to pair high and low
        sort(classrooms.begin(), classrooms.end(), cmp_by_floor);

        // Select 2 * n classrooms from both ends (low-high pairs)
        vector<pair<int, int> > pairs;
        int l = 0, r = m - 1;
        for (int i = 0; i < n; ++i) {
            pairs.emplace_back(classrooms[l++], classrooms[r--]);
        }

        // Build schedule for each group with alternating pattern
        for (int i = 0; i < n; ++i) {
            vector<int> schedule(6);
            for (int j = 0; j < 6; ++j) {
                if (j % 2 == 0)
                    schedule[j] = pairs[i].first;
                else
                    schedule[j] = pairs[i].second;
            }
            for (int i=0;i<schedule.size(); i++) cout << schedule[i]<< " ";
            cout << "\n";
        }
    }

    return 0;
}
