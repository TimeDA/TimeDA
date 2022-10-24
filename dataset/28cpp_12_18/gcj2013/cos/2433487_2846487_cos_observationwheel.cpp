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
 
 int n;
 double memo[1 << 20];
 double calc(ll bits) {
   if (__builtin_popcount(bits) == n) { return 0; }
   double &ret = memo[bits];
   if (!isnan(ret)) { return ret; }
   ret = 0;
   REP(i, n) {
     int earn = n;
     int index = i;
     while ((bits >> index) & 1) {
       earn--;
       index = (index + 1) % n;
     }
     ll nbits = bits | (1LL << index);
     ret += earn + calc(nbits);
   }
   ret /= n;
   return ret;
 }
 
 void solve() {
   MEMSET(memo, -1);
   char str[1000];
   scanf("%s", str);
   n = strlen(str);
   ll bits = 0;
   REP(i, n) {
     if (str[i] == '.') { continue; }
     bits |= 1LL << i;
   }
   double ans = calc(bits);
   printf("%.10lf\n", ans);
 }
