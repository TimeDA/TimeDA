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
     solve();
   }
 }
 
 ll b, n;
 ll seq[100];
 
 void solve() {
   MEMSET(seq, 0);
   scanf("%lld %lld", &b, &n);
   REP(i, n) {
     scanf("%lld", &seq[i]);
   }
   seq[n++] = 1e+13;
   sort(seq, seq + n);
   reverse(seq, seq + n);
   long double ans = 0.0;
   REP(i, n) {
     const ll now = seq[i];
     const ll next = seq[i + 1];
     if (now == next) { continue; }
     const ll cnt = 38 - (i + 1);
     if (cnt == 0) { continue; }
     ll gsum = 0;
     FOR(j, i + 1, 38) {
       gsum += next - seq[j];
     }
     REP(pay, cnt) {
       ll sum = gsum;
       if (sum + pay > b) { continue; }
       ll lsum = 0;
       FOR(j, i + 1 + pay, 38) {
         lsum += next - seq[j];
       }
       long double lans = lsum * 36.0L / (cnt - pay) - (sum + pay);
       ans = max(ans, lans);
       ll lb = (b - sum - pay) / cnt;
       lb = min(lb, now - next - 1);
       sum += lb * cnt;
       lsum += lb * (cnt - pay);
       lans = lsum * 36.0L / (cnt - pay) - (sum + pay);
       ans = max(ans, lans);
     }
   }
   printf("%.8Lf\n", ans);
 }
