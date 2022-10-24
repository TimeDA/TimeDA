


/*
    Prob:
    Author: 
    Time:   
    Description:
*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
#include <string>

const int MaxN = 105;

int T, n, m;
int b[MaxN], r[MaxN][MaxN], c[MaxN];

bool check() {
    int cnt = 0;
    memset(r, 0, sizeof r);
    for (int k = 0; k < n; ++ k) {
        for (int t = 0; t < b[k]; ++ t)
            c[cnt + t] = k;
        cnt += b[k];
    }
    if (cnt != n || c[0] != 0 || c[n - 1] != n - 1) return false;
    for (int k = 0; k < n; ++ k) {
        m = max(m, abs(k - c[k]));
        int d = (k == c[k] ? 0 : (c[k] - k) / abs(c[k] - k));
        for (int t = 0; t < abs(k - c[k]); ++ t)
            r[t][k + t * d] = d;
    }
    ++ m;
    return true;
}

int main() { 
    scanf("%d", &T);
    for (int testcase = 1; testcase <= T; ++ testcase) {
        scanf("%d", &n);
        m = 0;
        for (int k = 0; k < n; ++ k)
            scanf("%d", b + k);

        printf("Case #%d: ", testcase);
        if (check()) {
            printf("%d\n", m);
            for (int i = 0; i < m; ++ i) {
                for (int j = 0; j < n; ++ j) {
                    if (r[i][j] ==  0) putchar('.');
                    if (r[i][j] == -1) putchar('/');
                    if (r[i][j] ==  1) putchar('\\');
                }
                puts("");
            }
        }
        else puts("IMPOSSIBLE");
    }

    return 0;
}
