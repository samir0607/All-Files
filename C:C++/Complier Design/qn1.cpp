#include <iostream>
#include <string>
using namespace std;

#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);

void solve() {
	string s;
	cin >> s;
	int state = 0;
	for (int i = 0; i<s.size(); i++) {
        if (s[i] != '0' && s[i] != '1') {
            cout << "Rejected" << endl;
            return;
        }
        switch (state) {
            case 0:
                state = 1;
                break;
            case 1:
                state = 2;
                break;
            case 2:
                state = 2;
                break;
        }
    }
    if (state == 2) cout << "Accepted" << endl;
    else cout << "Rejected" << endl;
}

int main() {
	fast_io;
	solve();
	return 0;
}