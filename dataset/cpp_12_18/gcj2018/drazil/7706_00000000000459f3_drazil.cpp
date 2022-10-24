#include <bits/stdc++.h>

using namespace std;

int dpt[510][510][40];
bool done[510][510][40];
int ans[510][510];
long long dcnt = 0;
long long icnt = 0;

void go(int a, int b, int bcnt) {
    if (a == 0 && b == 0) return;
    if (bcnt >= 40) return;
    if (!done[a][b][bcnt]) {
        int ar = 0;
        int br = 0;
        int ans = 0;
        go(a, b, bcnt + 1);
        dpt[a][b][bcnt] = dpt[a][b][bcnt + 1];
        for (int aa = (bcnt == 0) ? 1 : 0; ; ++aa) {
            ar += aa;
            br += bcnt;
            ++ans;
            if (ar > a) break;
            if (br > b) break;
            int na = a - ar;
            int nb = b - br;
            go(na, nb, bcnt + 1);
            dpt[a][b][bcnt] = max(dpt[a][b][bcnt], dpt[na][nb][bcnt + 1] + ans);
        }
        done[a][b][bcnt] = true;
    }
}

int main() {
    for (int a = 0; a <= 500; ++a) {
        for (int b = 0; b <= 500; ++b) {
            go(a, b, 0);
            for (int v = 0; v < 40; ++v) {
                ans[a][b] = max(ans[a][b], dpt[a][b][v]);
            }
        }
    }
    for (int a = 0; a <= 500; ++a) {
        for (int b = 0; b <= 500; ++b) {
            ans[a + 1][b] = max(ans[a + 1][b], ans[a][b]);
            ans[a][b + 1] = max(ans[a][b + 1], ans[a][b]);
        }
    }
    
    int T;
    scanf("%d", &T);
    
    for (int t = 1; t <= T; ++t) {
        int a, b;
        scanf("%d%d", &a, &b);
        printf("Case #%d: %d\n", t, ans[a][b]);
    }

    return 0;
}
