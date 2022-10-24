#include <bits/stdc++.h>

using namespace std;

int n, nn;
int arr[110][110];
int frr[110][110];

bool ok() {
    set<int> x[5], y[5];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (frr[i][j] == 1) continue;
            if (x[i].find(arr[i][j]) != x[i].end()) return false;
            if (y[j].find(arr[i][j]) != y[j].end()) return false;
            x[i].insert(arr[i][j]);
            y[j].insert(arr[i][j]);
        }
    }
    return true;
}

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t) {
        scanf("%d", &n);
        nn = n * n;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                scanf("%d", &arr[i][j]);
            }
        }
        int ans = nn;
        for (int i = 0; i < (1 << nn); ++i) {
            int v = i;
            int ccnt = 0;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    frr[i][j] = (v & 1);
                    v >>= 1;
                    ccnt += frr[i][j];
                }
            }
            if (ok()) ans = min(ans, ccnt);
        }

        printf("Case #%d: %d\n", t, ans);
    }

    return 0;
}
