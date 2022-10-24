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
 
 const ll MOD = 1e+9 + 7;
 int w, h;
 ll memo[1000][10];
 
 ll calc(int depth, int prev) {
   if (depth == h) { return 1; }
   if (depth > h) { return 0; }
   ll &ret = memo[depth][prev];
   if (ret != -1) { return ret; }
   ret = 0;
   if (prev != 3) {
     ret = (ret + calc(depth + 2, 3)) % MOD;
   }
   if (prev != 2) {
     ret = (ret + calc(depth + 1, 2)) % MOD;
     if (w % 3 == 0) {
       ret = (ret + calc(depth + 2, 2)) % MOD;
     }
     if (w % 4 == 0) {
       ret = (ret + calc(depth + 3, 2)) % MOD;
     }
     if (w % 6 == 0) {
       ret = (ret + calc(depth + 2, 2)) % MOD;
     }
   }
   // cout << depth << " " << prev << " " << ret << endl;
   return ret;
 }
 
 void solve() {
   MEMSET(memo, -1);
   scanf("%d %d", &h, &w);
   ll ans = calc(0, 0);
   printf("%lld\n", ans);
 }
