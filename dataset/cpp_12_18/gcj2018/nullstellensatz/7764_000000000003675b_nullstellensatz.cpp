


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

const int MaxN = 100005;

int T, n;
int s[MaxN][2], len[MaxN][2], opt[MaxN][2], num[MaxN][2][2];

int main() { 
    scanf("%d", &T);
    for (int testcase = 1; testcase <= T; ++ testcase) {
        scanf("%d", &n);
        for (int k = 0; k < n; ++ k) {
            int D, A, B; scanf("%d %d %d", &D, &A, &B);
            s[k][0] = D + A;
            s[k][1] = D - B + (1 << 20);
        }
        memset(len, 0, sizeof len);
        len[n - 1][0] = len[n - 1][1] = 1;
        for (int i = n - 2; i >= 0; -- i)
            for (int j = 0; j <= 1; ++ j)
                if (s[i][j] == s[i + 1][j])
                    len[i][j] = len[i + 1][j] + 1;
                else len[i][j] = 1;
        
        memset(opt,  0, sizeof opt);
        memset(num, -1, sizeof num);
        for (int i = n - 1; i >= 0; -- i)
            for (int j = 0; j <= 1; ++ j) {
                if (i + len[i][j] >= n) {
                    opt[i][j] = len[i][j];
                    num[i][j][j] = s[i][j];
                }
                else {
                    if (s[i][j] == s[i + 1][j]) {
                        opt[i][j] = opt[i + 1][j] + 1;
                        num[i][j][0] = num[i + 1][j][0];
                        num[i][j][1] = num[i + 1][j][1];
                    }
                    else {
                        int tmp = num[i + 1][j ^ 1][j];
                        if (tmp == s[i][j] || tmp < 0)
                            opt[i][j] = opt[i + 1][j ^ 1] + 1;
                        else opt[i][j] = len[i + 1][j ^ 1] + 1;
                        num[i][j][j] = s[i][j];
                        num[i][j][j ^ 1] = s[i + 1][j ^ 1];
                    }
                }
            }
        
        int ans = 0, cnt = 0;
        for (int k = 0; k < n; ++ k) {
            int tmp = max(opt[k][0], opt[k][1]);
            if (tmp > ans) {
                ans = tmp;
                cnt = 0;
            }
            if (tmp == ans) ++ cnt;
        }

        printf("Case #%d: %d %d\n", testcase, ans, cnt);
    }

    return 0;
}
