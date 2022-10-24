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
     //puts("");
     solve();
   }
 }
 
 ll m, f, n;
 int rest[2000010];
 int best[2000010];
 int price[210];
 int stale[210];
 
 void solve() {
   MEMSET(best, 0x0f);
   MEMSET(rest, 0);
   scanf("%lld %lld %lld", &m, &f, &n);
   REP(i, n) {
     scanf("%d %d", &price[i], &stale[i]);
     FOREQ(day, 0, stale[i]) { best[day] = min(best[day], price[i]); }
   }
   rest[0] = m;
   int ans = 0;
   REP(day, 200010) {
     if (rest[day] == 0) { break; }
     int v = rest[day] - f;
     REP(d, 200010) {
       v -= best[d];
       if (v < 0) { break; }
       rest[day + d + 1] = max(rest[day + d + 1], v);
       ans = max(ans, day + d + 1);
     }
   }
   printf("%d\n", ans);
 }
