#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)
using namespace std;
typedef long long LL;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
inline bool valid(int x, int w) { return 0 <= x && x < w; }

void iostream_init() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.setf(ios::fixed);
    cout.precision(12);
}

void solve() {
    int W;
    cin >> W;
    vector<int> B(W);
    REP(i, W) cin >> B[i];
    vector<int> target(W);
    int cur_idx = 0;

    if (W == 1) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    vector<int> C = B;
    for(int i = 0; i < W; i++) {
        while(C[cur_idx] == 0) {
            cur_idx++;
        }
        target[i] = cur_idx;
        C[cur_idx]--;
    }

    vector<string> answer;
    bool ok = true;
    while(true) {
        string line(W, '.');
        vector<int> next_target(W, -1);
        for(int i = 0; i < W; i++) {
            if (target[i] == -1) {
                continue;
            }
            if (target[i] > i) {
                line[i] = '\\';
                next_target[i+1] = target[i];
            } else if (target[i] < i) {
                line[i] = '/';
                next_target[i-1] = target[i];
            } else {
                next_target[i] = target[i];
            }
        }
        if (line[0] != '.' || line[W-1] != '.') {
            ok = false;
            break;
        }
        answer.push_back(line);
        target = next_target;
        bool exit = true;
        REP(i, W) if (line[i] != '.') exit = false;
        if (exit) break;
    }
    if (ok) {
        cout << answer.size() << endl;
        REP(i, answer.size()) {
            cout << answer[i] << endl;
        }
    } else {
        cout << "IMPOSSIBLE" << endl;
    }
}

int main(){
    iostream_init();
    int TC;
    cin >> TC;
    for(int testcase = 1; testcase <= TC; testcase++) {
        cout << "Case #" << testcase << ": ";
        solve();
    }
    return 0;
}
