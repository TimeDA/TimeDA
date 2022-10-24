#include <bits/stdc++.h>

using namespace std;

int cases = 0;


char out[256][256];

void solve() {
    for (int i = 0; i < 256; i++)
        for (int j = 0; j < 256; j++)
            out[i][j] = '.';

    cout << "Case #" << ++cases << ": ";
    int C;
    cin >> C;
    vector<int> goal(C);
    for (int i = 0; i < C; i++) cin >> goal[i];
    if (goal.front() == 0 || goal.back() == 0) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    vector<pair<int, int> > moves;
    int ri = 0;
    int mx = 0;
    for (int i = 0; i < C; i++) {
        while (goal[i]) {
            moves.push_back({ri, i});
            mx = max(abs(ri - i) + 1, mx);
            ri++;
            goal[i]--;
        }
    }
    cout << mx << endl;
    assert(moves.size() == C);
    for (auto m : moves) {
        if (m.first < m.second) {
            for (int j = 0; j < m.second - m.first; j++) {
                out[j][m.first + j] = '\\';
            }
        } else {
            for (int j = 0; j < m.first - m.second; j++) {
                out[j][m.first - j] = '/';
            }
        }
    }
    for (int i = 0; i < mx; i++) {
        for (int j = 0; j < C; j++) {
            cout << out[i][j];
        }
        cout << endl;
    }


}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }

}
