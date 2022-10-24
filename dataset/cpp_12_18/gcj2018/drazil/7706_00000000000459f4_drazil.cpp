#include <bits/stdc++.h>

using namespace std;

char arr[110][110];
char frr[110][110];
int p[5][5];
int vis[5][5];

int t;
int my, mx;

int cnt(int y, int x) {
    if (x < 0 || y < 0 || x >= mx || y >= my) return 0;
    if (p[y][x] == 0) return 0;
    int ans = 0;
    if (vis[y][x] == 0) {
        vis[y][x] = 1;
        ++ans;
        ans += cnt(y + 1, x);
        ans += cnt(y - 1, x);
        ans += cnt(y, x + 1);
        ans += cnt(y, x - 1);
    }
    return ans;
}

int main() {
    int T;
    scanf("%d", &T);

    for (t = 1; t <= T; ++t) {
        scanf("%d%d", &my, &mx);
        memset(frr, 0, sizeof(frr));
        for (int i = 0; i < my; ++i) scanf("%s", arr[i]);
        for (int y = 0; y < 20 * my; ++y) {
            for (int x = 0; x < 20 * mx ; ++x) {
                frr[y][x] = arr[y / 20][x / 20];
            }
        }
        int ans = 0;
        for (int y = -20; y < 20 * my; ++y) {
            for (int x = -20; x < 20 * mx; ++x) {
                for (int yy = 0; yy < my; ++yy) {
                    for (int xx = 0; xx < mx; ++xx) {
                        int ty = y + yy;
                        int tx = x + xx;
                        if (ty < 0 || tx < 0 || ty >= 20 * my || tx >= 20 * mx) {
                            p[yy][xx] = 0;
                           continue;
                        }
                        if (frr[ty][tx] == arr[yy][xx]) {
                            p[yy][xx] = 1;
                        } else {
                            p[yy][xx] = 0;
                        }
                    }
                }
                for (int yy = 0; yy < my; ++yy) {
                    for (int xx = 0; xx < mx; ++xx) {
                        memset(vis, 0, sizeof(vis));
                        ans = max(cnt(yy, xx), ans);
                    }
                }
            }
        }
        printf("Case #%d: %d\n", t, ans);
    }

    return 0;
}
