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
    int H, W;
    cin >> H >> W;
    const int MAX_L = 22;
    int answer = min(2, H) * min(2, W);

    string grid[MAX_L];
    REP(y, H) cin >> grid[y];

    set<tuple<char, char, char, char>> s;

    for(int y = 0; y < H; y++) {
        for(int x = 0; x < W; x++) {
            const char A = grid[y][x];
            const char B = (x+1 < W ? grid[y][x+1] : '?');
            const char C = (y+1 < H ? grid[y+1][x] : '?');
            const char D = (y+1 < H && x+1 < W ? grid[y+1][x+1] : '?');
            const auto state = make_tuple(A, B, C, D);

            if (s.count(state)) continue;
            s.insert(state);

            for (int lr = 0; lr <= H; lr++) {
                if (C == '?' && D == '?' && lr < H) continue;

                for(int lc = 0; lc <= W; lc++) {
                    if (B == '?' && D == '?' && lc < W) continue;

                    auto get = [&](int r, int c) {
                        if (r < lr) {
                            if (c < lc) { return A; } else { return B; }
                        } else {
                            if (c < lc) { return C; } else { return D; }
                        }
                    };
                    auto can_pick = [&](int r, int c) {
                        return get(r, c) == grid[r][c];
                    };

                    bool used[MAX_L][MAX_L] = {};

                    for(int sr = 0; sr < H; sr++) {
                        for(int sc = 0; sc < W; sc++) {
                            if (!can_pick(sr, sc)) {
                                continue;
                            }
                            if (used[sr][sc]) {
                                continue;
                            }

                            int counter = 0;
                            queue<int> qr, qc;
                            qr.push(sr);
                            qc.push(sc);
                            used[sr][sc] = true;
                            counter++;
                            while(!qr.empty()) {
                                int r = qr.front(); qr.pop();
                                int c = qc.front(); qc.pop();
                                for(int k = 0; k < 4; k++) {
                                    int nr = r + dy[k];
                                    int nc = c + dx[k];
                                    if (valid(nr, H) && valid(nc, W) && !used[nr][nc] && can_pick(nr, nc)) {
                                        counter++;
                                        used[nr][nc] = true;
                                        qr.push(nr);
                                        qc.push(nc);
                                    }
                                }
                            }

                            answer = max(answer, counter);
                        }
                    }
                }
            }
        }
    }
    cout << answer << endl;

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
