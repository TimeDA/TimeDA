#include <stdio.h>
 #include <string.h>
 #include <algorithm>
 #include <iostream>
 #include <math.h>
 #include <assert.h>
 #include <vector>
 
 using namespace std;
 typedef long long ll;
 typedef unsigned int uint;
 typedef unsigned long long ull;
 static const double EPS = 1e-9;
 static const double PI = acos(-1.0);
 
 #define REP(i, n) for (int i = 0; i < (int)(n); i++)
 #define FOR(i, s, n) for (int i = (s); i < (int)(n); i++)
 #define FOREQ(i, s, n) for (int i = (s); i <= (int)(n); i++)
 #define FORIT(it, c) for (__typeof((c).begin())it = (c).begin(); it != (c).end(); it++)
 #define MEMSET(v, h) memset((v), h, sizeof(v))
 
 void solve();
 int main() {
   int test;
   scanf("%d", &test);
   char str[1000];
   fgets(str, 999, stdin);
   int test_case = 0;
   while (test--) {
     test_case++;
     printf("Case #%d: ", test_case);
     // puts("");
     solve();
   }
 }
 
 int n, p;
 int memo[4][111][111][111];
 int calc(int r, int c1, int c2, int c3) {
   if (c1 == 0 && c2 == 0 && c3 == 0) { return 0; }
   if (memo[r][c1][c2][c3] != -1) { return memo[r][c1][c2][c3]; }
   int cnts[4] = { 0, c1, c2, c3 };
   int ret = 0;
   REP(i, 4) {
     if (cnts[i] == 0) { continue; }
     int nr = (r + i) % p;
     cnts[i]--;
     int nret = calc(nr, cnts[1], cnts[2], cnts[3]);
     if (r == 0) { nret++; }
     cnts[i]++;
     ret = max(ret, nret);
   }
   return memo[r][c1][c2][c3] = ret;
 }
 
 void solve() {
   int cnts[4];
   MEMSET(cnts, 0);
   MEMSET(memo, -1);
   scanf("%d %d", &n, &p);
   REP(i, n) {
     int cnt;
     scanf("%d", &cnt);
     cnts[cnt % p]++;
   }
   int ans = calc(0, cnts[1], cnts[2], cnts[3]) + cnts[0];
   printf("%d\n", ans);
 }
