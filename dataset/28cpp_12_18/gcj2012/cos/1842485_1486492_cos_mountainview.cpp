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
     puts("");
     solve();
   }
 }
 
 long long gcd(long long a, long long b) {
   if (b == 0) { return a; }
   return gcd(b, a % b);
 }
 
 const int ITER_CNT = 1000000;
 int n;
 int view[3000];
 ll y[3000];
 
 void solve() {
   scanf("%d", &n);
   REP(i, n - 1) { scanf("%d", &view[i]); view[i]--; }
   REP(i, n) { y[i] = 1e+5 * (i + 1); }
   REP(i, n - 1) {
     FOR(j, i + 1, view[i]) {
       if (view[j] > view[i]) {
         puts("Impossible");
         return;
       }
     }
   }
   REP(iter, ITER_CNT) {
     REP(i, n) {
       y[i] = rand() % (int)1e+9;
     }
     REP(i, n - 1) {
       double maxArg = -1e+9;
       int index = -1;
       FOR(j, i + 1, n) {
         ll d = j - i;
         ll h = y[j] - y[i];
         ll g = gcd(h, d);
         h /= g; d /= g;
         double arg = h / d;
         if (arg > maxArg) {
           maxArg = arg;
           index = j;
         }
       }
       if (index != view[i]) { goto next; }
     }
     break;
 next:;
     if (iter == ITER_CNT - 1) {
       puts("Impossible");
       return;
     }
   }
   REP(i, n) {
     if (i != 0) { putchar(' '); }
     printf("%lld", y[i]);
   }
   puts("");
   /*
   const ll offset = 1e+5;
   REP(i, n - 1) {
     int v = view[i];
     y[v] = min(y[v], y[i] + offset);
     ll d = v - i;
     FOR(j, i + 1, v) {
       ll k = j - i;
       y[j] = min(y[j], k * (y[v] - y[i]) / d + y[i] - 1);
     }
   }
   */
 }
