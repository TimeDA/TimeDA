#include <cstdio>
#include <algorithm>
#include <string>
#include <set>
using namespace std;

const int N = 25;

char F[N][N];

char T[2][2];

int r0, c0;
int r, c;

int curver = 0;
int used[N][N];

int vy[] = {1, 0, -1, 0};
int vx[] = {0, 1, 0, -1};

bool valid(int y, int x) {
    int sy = y >= r0;
    int sx = x >= c0;
    return 1 <= y && y <= r && 1 <= x && x <= c && F[y][x] == T[sy][sx];
}

int DFS(int y, int x) {
    int res = 1;
    used[y][x] = curver;
    for (int v = 0; v < 4; v++) {
        int ty = y + vy[v];
        int tx = x + vx[v];
        if (!valid(ty, tx)) {
            continue;
        }
        if (used[ty][tx] == curver) {
            continue;
        }
        res += DFS(ty, tx);
    }
    return res;
}

void solve(int cs) {
    scanf("%d %d", &r, &c);
    for (int i = 0; i < r; i++) {
        scanf("%s", F[i + 1] + 1);
    }
    for (int i = 0; i < r + 2; i++) {
        F[i][0] = F[i][c + 2] = 'X';
    }
    int ans = 0;
    set<string> was;
    for (int i = 0; i <= r; i++) {
        for (int j = 0; j <= c; j++) {
            for (int a = 0; a < 2; a++) {
                for (int b = 0; b < 2; b++) {
                    T[a][b] = F[i + a][j + b];
                }
            }
            string s = {T[0][0], T[0][1], T[1][0], T[1][1]};
            if (was.count(s)) {
                continue;
            }
            was.insert(s);
            for (r0 = 1; r0 <= r + 1; r0++) {
                for (c0 = 1; c0 <= c + 1; c0++) {
                    ++curver;
                    for (int y = 1; y <= r; y++) {
                        for (int x = 1; x <= c; x++) {
                            if (used[y][x] != curver && valid(y, x)) {
                                ans = max(ans, DFS(y, x));
                            }
                        }
                    }
                }
            }
        }
    }
    printf("Case #%d: %d\n", cs, ans);
}

int main() {
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        solve(i + 1);
    }
}
