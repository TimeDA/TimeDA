#include <stdio.h>
 #include <string.h>
 #include <algorithm>
 #include <iostream>
 #include <math.h>
 #include <assert.h>
 #include <vector>
 #include <queue>
 
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
 
 double square(double x) { return x * x; }
 
 int n, s;
 double px[2000];
 double py[2000];
 double pz[2000];
 double a, b, c;
 double dists[2000][2000];
 bool visit[2000];
 void solve() {
   scanf("%d %d", &n, &s);
   REP(i, n) {
     scanf("%lf %lf %lf %lf %lf %lf", &px[i], &py[i], &pz[i], &a, &b, &c);
   }
   REP(i, n) {
     REP(j, n) {
       dists[i][j] = sqrt(square(px[i] - px[j]) + square(py[i] - py[j]) + square(pz[i] - pz[j]));
     }
   }
   double l = 0.0;
   double r = 1000000.0;
   REP(iter, 300) {
     double mid = (l + r) / 2.0;
     MEMSET(visit, false);
     queue<int> que;
     que.push(1);
     visit[1] = true;
     while (!que.empty()) {
       int from = que.front();
       que.pop();
       REP(to, n) {
         if (visit[to] || dists[from][to] > mid) { continue; }
         // cout << from << " " << to << " " << dists[from][to] << " " << mid << endl;
         visit[to] = true;
         que.push(to);
       }
     }
     if (visit[0]) {
       r = mid;
     } else {
       l = mid;
     }
   }
   printf("%.8f\n", l);
 }
