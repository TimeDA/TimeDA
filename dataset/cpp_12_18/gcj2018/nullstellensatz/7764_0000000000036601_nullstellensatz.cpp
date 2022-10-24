


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
#include <queue>

const int MaxN = 100005;

int T, n, L;
int c[MaxN], p[MaxN];
priority_queue<pair<int, int> > Q;

int main() { 
    scanf("%d", &T);
    for (int testcase = 1; testcase <= T; ++ testcase) {
        scanf("%d %d", &n, &L);
        while (!Q.empty()) Q.pop();
        int cnt = 0;
        memset(c, 0, sizeof c);
        for (int k = 0; k < L; ++ k) {
            scanf("%d", c + k);
            cnt += c[k];
            Q.push(make_pair((c[k] * 100 + (n / 2)) % n, c[k])); 
        }
        for (int k = L; k < n; ++ k)
            Q.push(make_pair(n / 2, 0));
        memset(p, 0, sizeof p);
        for (int k = 1; k <= n; ++ k) {
            int tmp = k * 100 + n / 2;
            p[k] = tmp / n;
        }

        for (int k = 1; k + cnt <= n; ++ k) {
            pair<int, int> cur = Q.top();
            Q.pop();
            cur.first = (cur.first + 100) % n;
            cur.second ++;
            Q.push(cur);
        }
        
        int ans = 0;
        while (!Q.empty()) {
            pair<int, int> cur = Q.top();
            Q.pop();
            ans += p[cur.second];
        }
        printf("Case #%d: %d\n", testcase, ans);
    }

    return 0;
}
