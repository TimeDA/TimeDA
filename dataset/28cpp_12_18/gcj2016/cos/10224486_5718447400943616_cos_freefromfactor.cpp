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
 int matrix[20][20];
 
 bool valid(int used1, int used2) {
   REP(i, n) {
     if ((used1 >> i) & 1) { continue; }
     int nused1 = used1 | (1 << i);
     bool ok = false;
     REP(j, n) {
       if ((used2 >> j) & 1 || matrix[i][j] == 0) { continue; }
       ok = true;
       int nused2 = used2 | (1 << j);
       if (!valid(nused1, nused2)) { return false; }
     }
     if (!ok) { return false; }
   }
   return true;
 }
 
 int calc(int depth, int cost) {
   if (depth == n * n) {
     if (valid(0, 0)) { return cost; }
     return n * n;
   }
   int ret = n * n;
   ret = min(ret, calc(depth + 1, cost));
   if (matrix[depth / n][depth % n] == 0) {
     matrix[depth / n][depth % n] = 1;
     ret = min(ret, calc(depth + 1, cost + 1));
     matrix[depth / n][depth % n] = 0;
   }
   return ret;
 }
 
 void solve() {
   scanf("%d", &n);
   REP(y, n) {
     REP(x, n) {
       char c;
       scanf(" %c", &c);
       matrix[y][x] = c == '1' ? 1 : 0;
     }
   }
   int ans = calc(0, 0);
   printf("%d\n", ans);
 }
