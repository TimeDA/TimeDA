#include <bits/stdc++.h>

using namespace std;

typedef vector<string> Board;

int match(Board b, Board p) {
    for (int i = 0; i < b.size(); i++) {
        for (int j = 0; j < b[0].size(); j++) {
            int f = 1;
            for (int k = 0; k < p.size(); k++) {
                for (int l = 0; l < p[0].size(); l++) {
                    int y = i + k;
                    int x = j + l;
                    if (p[k][l] == '*') continue;
                    if (y >= b.size() || x >= b[0].size()) f = 0;
                    if (b[y][x] != p[k][l]) f = 0;
                }
            }
            if (f) return true;
        }
    }
    return false;
}

Board expand(Board s) {
    Board t(s.size() * 2, string(s[0].size() * 2, '.'));
    for (int i = 0; i < s.size(); i++) {
        for (int j = 0; j < s[0].size(); j++) {
            t[i * 2][j * 2] = s[i][j];
            t[i * 2 + 1][j * 2] = s[i][j];
            t[i * 2][j * 2 + 1] = s[i][j];
            t[i * 2 + 1][j * 2 + 1] = s[i][j];
        }
    }
    return t;
}


void dfs(Board &b, int x, int y) {
    if (b.size() <= y || b[0].size() <= x || x < 0 || y < 0) return;
    if (b[y][x] == '*') return;
    b[y][x] = '*';
    dfs(b, x + 1, y);
    dfs(b, x, y + 1);
    dfs(b, x - 1, y);
    dfs(b, x, y - 1);
}

bool connected(Board b) {
    for (int i = 0; i < b.size(); i++) {
        for (int j = 0; j < b[0].size(); j++) {
            if (b[i][j] != '*') {
                dfs(b, j, i);
                goto go;
            }
        }
    }
    go:;
    for (int i = 0; i < b.size(); i++) {
        for (int j = 0; j < b[0].size(); j++) {
            if (b[i][j] != '*') return false;
        }
    }
    return true;
}

void solve(int cs) {
    int R, C;
    cin >> R >> C;
    Board b(R, string(C, '.'));
    for (int i = 0; i < R; i++) {
        cin >> b[i];
    }
    vector<Board> bs;
    Board w = b;
    for (int i = 0; i < 4; i++) {
        w = expand(w);
        bs.push_back(w);
    }

    int ans = 0;
    for (int i = 0; i < (1 << (R * C)); i++) {
        Board p = b;
        for (int j = 0; j < R * C; j++) {
            int x = j % C;
            int y = j / C;
            if (i >> j & 1) {
                p[y][x] = b[y][x];
            } else {
                p[y][x] = '*';
            }
        }
        int sz = __builtin_popcount(i);
        if (!connected(p)) continue;

        for (auto &&w : bs) {
            if (match(w, p)) {
                ans = max(ans, sz);
            }
        }
    }
    cout << "Case #" << cs << ": " << ans << endl;
}

int main() {
    int T;
    cin >> T;
    int cs = 1;
    while (T--) {

        solve(cs++);
    }

}
