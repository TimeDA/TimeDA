


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
vector<int> num[2];

int main() { 
    scanf("%d", &T);
    for (int testcase = 1; testcase <= T; ++ testcase) {
        num[0].clear(); num[1].clear();
        scanf("%d", &n);
        for (int k = 0; k < n; ++ k) {
            int tmp; scanf("%d", &tmp);
            num[k & 1].push_back(tmp);
        }
        sort(num[0].begin(), num[0].end());
        sort(num[1].begin(), num[1].end());
        
        int ans = -1, cur = num[0][0], nxt = num[1][0];
        for (int k = 1; k < n; ++ k) {
            nxt = num[k & 1][k >> 1];
            if (ans < 0 && cur > nxt) ans = k - 1;
            cur = nxt;
        }
        printf("Case #%d: ", testcase);
        if (ans < 0) puts("OK"); else printf("%d\n", ans);
    }

    return 0;
}
