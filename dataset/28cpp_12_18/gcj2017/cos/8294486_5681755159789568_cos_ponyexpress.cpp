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
 
 int n, q;
 ll max_dists[110];
 ll speeds[110];
 ll dists[110][110];
 double times[110][110];
 int froms[110], tos[110];
 
 void solve() {
   REP(i, 110) REP(j, 110) { times[i][j] = 1e+100; }
   scanf("%d %d", &n, &q);
   REP(i, n) {
     scanf("%lld %lld", &max_dists[i], &speeds[i]);
   }
   REP(i, n) REP(j, n) {
     scanf("%lld", &dists[i][j]);
   }
   REP(i, q) {
     scanf("%d %d", &froms[i], &tos[i]);
     froms[i]--; tos[i]--;
   }
   REP(i, n) { dists[i][i] = 0; }
   REP(k, n) REP(i, n) REP(j, n) {
     if (dists[i][k] == -1 || dists[k][j] == -1) { continue; }
     ll d = dists[i][k] + dists[k][j];
     if (dists[i][j] == -1 || dists[i][j] > d) {
       dists[i][j] = d;
     }
   }
   REP(from, n) {
     REP(to, n) {
       if (dists[from][to] > max_dists[from] || dists[from][to] == -1) { continue; }
       times[from][to] = min(times[from][to], (double)dists[from][to] / speeds[from]);
     }
   }
   REP(k, n) REP(i, n) REP(j, n) {
     times[i][j] = min(times[i][j], times[i][k] + times[k][j]);
   }
   REP(i, q) {
     if (i != 0) { putchar(' '); }
     printf("%.8f", times[froms[i]][tos[i]]);
   }
   puts("");
 }
