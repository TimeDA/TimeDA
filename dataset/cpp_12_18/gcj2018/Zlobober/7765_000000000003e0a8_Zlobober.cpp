#include <cstdio>
#include <vector>
#include <cassert>
#include <algorithm>
#include <memory.h>
using namespace std;

const int N = 105;
const int MX = 7050;
int D[N][MX];

typedef long long llong;

const int NN = 100500;
llong W[NN];
int n;

int ans = 0;

void read() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &W[i]);
    }
}

void print(int cs) {
    printf("Case #%d: %d\n", cs, ans);
}

int slow_solve() {
    for (int j = 1; j < MX; j++) {
        D[0][j] = -MX;
    }
    for (int i = 0; i < n; i++) {
        int w = W[i];
        memcpy(D[i + 1], D[i], sizeof(D[i]));
        for (int j = 0; j <= 6 * w; j++) {
            D[i + 1][j + w] = max(D[i + 1][j + w], D[i][j] + 1);
        }
    }
    int mx = *max_element(D[n], D[n] + MX);
    return mx;
}

const llong INF = 1000 * 1000 * 1000ll * 1000 * 1000;

llong DP[NN], DC[NN];

int solve() {
    for (int i = 0; i < n; i++) {
        DP[i] = W[i];
    }
    for (int l = 0; ; l++) {
        bool any = false;
        for (int i = 0; i < n; i++) {
            if (DP[i] < INF) {
                any = true;
                break;
            }
        }
        if (!any) {
            return l;
        }
        llong mn = INF;
        for (int i = 0; i < n; i++) {
            DC[i] = INF;
            if (mn <= 6 * W[i]) {
                DC[i] = mn + W[i];
            }
            mn = min(mn, DP[i]);
        }
        memcpy(DP, DC, sizeof(llong) * n);
    }
    assert(false);
}

int main() {
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        read();
        //int slow = slow_solve();
        int fast = solve();
        /*if (slow != fast) {
            printf("Slow: %d, Fast: %d\n", slow, fast);
            assert(false);
        }*/
        ans = fast;
        print(i + 1);
    }
}
