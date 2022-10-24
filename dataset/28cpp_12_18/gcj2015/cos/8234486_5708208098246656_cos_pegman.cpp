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
 
 int w, h;
 char field[1000][1000];
 int cdirx[300];
 int cdiry[300];
 
 bool exist(int sx, int sy, int c) {
   bool ok = false;
   int dx = cdirx[c];
   int dy = cdiry[c];
   int x = sx + dx;
   int y = sy + dy;
   REP(iter, 100) {
     if (x < 0 || x >= w || y < 0 || y>= h) { break; }
     if (field[y][x] != '.') { ok = true; break; }
     x += dx;
     y += dy;
   }
   return ok;
 }
 
 void solve() {
   cdirx[(int)'>'] = 1;
   cdirx[(int)'v'] = 0;
   cdirx[(int)'<'] = -1;
   cdirx[(int)'^'] = 0;
 
   cdiry[(int)'>'] = 0;
   cdiry[(int)'v'] = 1;
   cdiry[(int)'<'] = 0;
   cdiry[(int)'^'] = -1;
 
   scanf("%d %d", &h, &w);
   REP(y, h) {
     scanf("%s", field[y]);
   }
 
   int ans = 0;
   REP(sy, h) {
     REP(sx, w) {
       int c = field[sy][sx];
       if (c == '.') { continue; }
       if (exist(sx, sy, c)) { continue; }
       ans++;
       int cs[4] = { '>', 'v', '<', '^' };
       REP(i, 4) {
         if (exist(sx, sy, cs[i])) { goto next; }
       }
       goto NG;
 next:;
     }
   }
 
   printf("%d\n", ans);
   return;
 NG:
   puts("IMPOSSIBLE");
 }
