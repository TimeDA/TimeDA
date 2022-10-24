


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
#include <string>
using namespace std;

const int MaxN = 105;
const int dir_x[] = {-1,  0,  0,  1};
const int dir_y[] = { 0, -1,  1,  0};

int T, n, m, cnt;
bool c[MaxN][MaxN], p[MaxN][MaxN], q[MaxN][MaxN], v[MaxN][MaxN];

void dfs(int cur_x, int cur_y) {
    v[cur_x][cur_y] = true;
    ++ cnt;
    for (int k = 0; k < 4; ++ k) {
        int nxt_x = cur_x + dir_x[k], nxt_y = cur_y + dir_y[k];
        if (nxt_x < 0 || nxt_x >= n && nxt_y < 0 || nxt_y >= m) continue;
        if (q[nxt_x][nxt_y] && !v[nxt_x][nxt_y]) dfs(nxt_x, nxt_y);
    }
}

void construct(int px, int py, int cx, int cy) {
    memset(p, 0, sizeof p);
    memset(q, 0, sizeof q);
    for (int i = 0; i < n;  ++ i)
        for (int j = 0; j < m; ++ j) {
            int tmp_x = px, tmp_y = py;
            if (i >= cx) ++ tmp_x;
            if (j >= cy) ++ tmp_y;
            p[i][j] = c[tmp_x][tmp_y];
            if (tmp_x >= n || tmp_y >= m) return;
        }
    for (int i = 0; i < n; ++ i)
        for (int j = 0; j < m; ++ j)
            q[i][j] = (p[i][j] == c[i][j]);
}

int main() { 
    scanf("%d", &T);
    for (int testcase = 1; testcase <= T; ++ testcase) {
        scanf("%d %d", &n, &m);
        memset(c, 0, sizeof c);
        for (int i = 0; i < n; ++ i) {
            string str; cin >> str;
            for (int j = 0; j < m; ++ j)
                if (str[j] == 'B') c[i][j] = true;
        }
    
        int ans = 0;
        for (int i = 0; i < n; ++ i)
            for (int j = 0; j < m; ++ j) {
                for (int r = n; r >= 0; -- r)
                    for (int s = m; s >= 0; -- s) {
                        construct(i, j, r, s);
                        memset(v, 0, sizeof v);
                        for (int x = 0; x < n; ++ x)
                            for (int y = 0; y < m; ++ y)
                                if (q[x][y] && !v[x][y]) {
                                    cnt = 0;
                                    dfs(x, y);
                                    ans = max(ans, cnt);
                                }
                    }
            }
            
        printf("Case #%d: %d\n", testcase, ans);
    }

    return 0;
}
