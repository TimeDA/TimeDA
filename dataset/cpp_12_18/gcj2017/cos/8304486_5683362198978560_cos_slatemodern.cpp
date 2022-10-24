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
 
 struct Point {
   int x;
   int y;
   ll v;
   Point(int x, int y, ll v) : x(x), y(y), v(v) {;}
   Point() {;}
   bool operator<(const Point &rhs) const { return v > rhs.v; }
 };
 
 const ll MOD = 1000000007;
 int h, w, n;
 ll d;
 ll field[210][210];
 void solve() {
   MEMSET(field, -1);
   scanf("%d %d %d %lld", &h, &w, &n, &d);
   priority_queue<Point> que;
   REP(i, n) {
     int y, x;
     ll v;
     scanf("%d %d %lld", &y, &x, &v);
     y--; x--;
     field[y][x] = v;
     que.push(Point(x, y, v));
   }
   ll ans = 0;
   while (!que.empty()) {
     Point p = que.top();
     que.pop();
     ans = (ans + p.v) % MOD;
     REP(dir, 4) {
       const int dx[4] = { 1, 0, -1, 0 };
       const int dy[4] = { 0, 1, 0, -1 };
       int nx = p.x + dx[dir];
       int ny = p.y + dy[dir];
       ll nv = p.v + d;
       if (nx < 0 || nx >= w || ny < 0 || ny >= h) { continue; }
       if (field[ny][nx] != -1) {
         if (abs(p.v - field[ny][nx]) <= d) { continue; }
         goto ng;
       } else {
         field[ny][nx] = nv;
         que.push(Point(nx, ny, nv));
       }
     }
   }
   printf("%lld\n", ans);
   return;
 ng:;
    puts("IMPOSSIBLE");
 }
