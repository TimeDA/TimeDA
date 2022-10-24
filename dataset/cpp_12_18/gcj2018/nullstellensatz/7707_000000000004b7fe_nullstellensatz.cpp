


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

const int MaxN = 10005;

int T, n;
int r[MaxN], c[MaxN];

int calc(int t) {
    return (t + 1) >> 1;
}

int main() { 
    scanf("%d", &T);
    for (int testcase = 1; testcase <= T; ++ testcase) {
        scanf("%d", &n);
        for (int k = 0; k < n; ++ k)
            scanf("%d %d", r + k, c + k);
        sort(r, r + n);
        sort(c, c + n);
        printf("Case #%d: %d\n", testcase, 
            max(calc(r[n - 1] - r[0]), calc(c[n - 1] - c[0])));
    }

    return 0;
}
