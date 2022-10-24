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
 
 int n;
 double V, X;
 double vs[300];
 double xs[300];
 void solve() {
   scanf("%d %lf %lf", &n, &V, &X);
   double low = 0;
   double high = 0;
   double same = 0;
   REP(i, n) {
     scanf("%lf %lf", &vs[i], &xs[i]);
     if (xs[i] == X) {
       same += vs[i];
       vs[i] = 0;
     } else if (xs[i] < X) {
       low += vs[i];
     } else {
       high += vs[i];
     }
   }
   if (same == 0 && (low == 0 || high == 0)) {
     puts("IMPOSSIBLE");
     return;
   }
   double ans = 0;
   if (low == 0 || high == 0) {
     ans = V / same;
   } else {
     double v0 = (xs[1] - X) / (xs[1] - xs[0]) * V;
     double v1 = (xs[0] - X) / (xs[0] - xs[1]) * V;
     assert(v0 >= -EPS && v1 >= -EPS);
     ans = max(v0 / vs[0], v1 / vs[1]);
   }
   printf("%.8f\n", ans);
 }
