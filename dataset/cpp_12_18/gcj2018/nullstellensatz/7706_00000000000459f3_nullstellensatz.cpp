


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

const int MaxN = 505;
const int MaxL = 115;

int T, n, m;
int opt[MaxN][MaxN]; // minimum Blue while i's Red and j's juggler

int main() { 
    scanf("%d", &T);
    memset(opt, -1, sizeof opt);
    int R = 500, len = 110;
    for (int k = 0; k <= R; ++ k)
        opt[k][0] = 0;
    for (int i = 0; i <= R; ++ i)
        for (int j = 0; j <= R; ++ j) {
            if (i + j == 0) continue;
            for (int p = R; p >= i; -- p)
                for (int q = len; q >= 1; -- q) {
                    if (opt[p - i][q - 1] < 0) continue;
                    if (opt[p][q] < 0 || opt[p][q] > opt[p - i][q - 1] + j)
                        opt[p][q] = opt[p - i][q - 1] + j;
                }
        }
    for (int testcase = 1; testcase <= T; ++ testcase) {
        scanf("%d %d", &n, &m);
        int ans = 0;
        while (ans <= len && opt[n][ans] <= m) ++ ans;
        printf("Case #%d: %d\n", testcase, ans - 1);
    }

    return 0;
}
