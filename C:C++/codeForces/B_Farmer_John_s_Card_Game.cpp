#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Card {
    int value, cowIndex, cardIndex;
    bool operator<(const Card& other) const {
        return value > other.value;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> decks(n, vector<int>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> decks[i][j];
            }
            sort(decks[i].begin(), decks[i].end());
        }

        priority_queue<Card> pq;
        for (int i = 0; i < n; ++i) {
            pq.push({decks[i][0], i, 0});
        }

        vector<int> order;
        int centerPile = -1;
        bool valid = true;

        for (int round = 0; round < m && valid; ++round) {
            order.clear();
            for (int i = 0; i < n; ++i) {
                while (!pq.empty() && pq.top().value <= centerPile) {
                    pq.pop();
                }
                if (pq.empty()) {
                    valid = false;
                    break;
                }

                Card topCard = pq.top();
                pq.pop();

                centerPile = topCard.value;
                order.push_back(topCard.cowIndex + 1);

                int nextCardIndex = topCard.cardIndex + 1;
                if (nextCardIndex < m) {
                    pq.push({decks[topCard.cowIndex][nextCardIndex], topCard.cowIndex, nextCardIndex});
                }
            }
        }

        if (valid) {
            for (int cow : order) {
                cout << cow << " ";
            }
            cout << endl;
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}
