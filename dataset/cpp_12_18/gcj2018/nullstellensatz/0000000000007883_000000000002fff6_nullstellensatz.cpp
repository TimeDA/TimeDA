


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

const int MaxN = 1005;

int T, n, C, B;
int m[MaxN], s[MaxN], p[MaxN];
long long t[MaxN];

long long check(long long lim) {
    memset(t, 0, sizeof t);
    for (int k = 0; k < C; ++ k) {
        if (lim >= p[k]) t[k] = (lim - p[k]) / s[k];
        if (t[k] > m[k]) t[k] = m[k];
    }
    sort(t, t + C);
    reverse(t, t + C);
    
    long long ans = 0;
    for (int k = 0; k < n; ++ k)
        ans += t[k];
    return ans;
}

int main() { 
    scanf("%d", &T);
    for (int testcase = 1; testcase <= T; ++ testcase) {
        scanf("%d %d %d", &n, &B, &C);
        for (int k = 0; k < C; ++ k)
            scanf("%d %d %d", m + k, s + k, p + k);
        
        long long l = 0, r = 1LL << 60;
        while (l < r - 1) {
            long long mid = (l + r) >> 1;
            if (check(mid) - B >= 0) r = mid; else l = mid;
        }
        while (check(r) - B >= 0) -- r;

        printf("Case #%d: ", testcase);
        cout << r + 1 << endl;
    }

    return 0;
}
