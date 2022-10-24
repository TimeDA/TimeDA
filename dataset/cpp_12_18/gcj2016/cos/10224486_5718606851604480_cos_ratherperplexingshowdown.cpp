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
 
 
 int n, r, p, s;
 string calc(int depth, char target) {
   if (depth == n) {
     string ans = "";
     ans += target;
     return ans;
   }
   string left, right;
   if (target == 'P') {
     left = calc(depth + 1, 'P');
     right = calc(depth + 1, 'R');
   } else if (target == 'R') {
     left = calc(depth + 1, 'R');
     right = calc(depth + 1, 'S');
   } else if (target == 'S') {
     left = calc(depth + 1, 'S');
     right = calc(depth + 1, 'P');
   }
   string ans = min(left + right, right + left);
   if (depth == 0) {
     int cnts[256];
     MEMSET(cnts, 0);
     FORIT(it, ans) { cnts[(int)*it]++; }
     if (cnts['R'] != r || cnts['P'] != p || cnts['S'] != s) { ans = "Z"; }
   }
   return ans;
 }
 void solve() {
   scanf("%d %d %d %d", &n, &r, &p, &s);
   string ans = "Z";
   ans = min(ans, calc(0, 'P'));
   ans = min(ans, calc(0, 'R'));
   ans = min(ans, calc(0, 'S'));
   if (ans[0] == 'Z') {
     puts("IMPOSSIBLE");
   } else {
     FORIT(it, ans) { putchar(*it); }
     puts("");
   }
 }
