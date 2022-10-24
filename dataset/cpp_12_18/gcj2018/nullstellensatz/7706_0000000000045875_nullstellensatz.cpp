


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

const int MaxN = 105;

int T, n;
int c[MaxN][MaxN], p[MaxN];
bool v[MaxN], f[MaxN][MaxN];

bool dfs(int cur) {
    for (int k = 0; k < n; ++ k)
        if (f[cur][k] && !v[k]) {
            v[k] = true;
            if (p[k] < 0 || dfs(p[k])) {
                p[k] = cur;
                return true;
            }
        }
    return false;
}

int maxmatch() {
    int res = 0;
    memset(p, -1, sizeof p);
    for (int k = 0; k < n; ++ k) {
        memset(v, 0, sizeof v);
        if (dfs(k)) ++ res;
    }
    return res;
}

int main() { 
    scanf("%d", &T);
    for (int testcase = 1; testcase <= T; ++ testcase) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++ i)
            for (int j = 0; j < n; ++ j)
                scanf("%d", &c[i][j]);
        int ans = 0;
        for (int k = -n; k <= n; ++ k) {
            int cnt = 0;
            memset(f, 0, sizeof f);
            for (int i = 0; i < n; ++ i)
                for (int j = 0; j < n; ++ j)
                    if (c[i][j] == k) {
                        f[i][j] = true;
                        ++ cnt;
                    }
            if (cnt > 0) ans += cnt - maxmatch();
        }
        printf("Case #%d: %d\n", testcase, ans);
    }

    return 0;
}
