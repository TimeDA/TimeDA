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
 
 int n;
 int width, height;
 int loves[1000];
 bool visit[20][20][4];
 int dx[4] = { 1, 0, -1, 0 };
 int dy[4] = { 0, 1, 0, -1 };
 
 int c_x(int v) {
   if (v < width) { return v; }
   if (v < width + height) { return width - 1; }
   if (v < width + height + width) { return width - 1 - (v - width - height); }
   return 0;
 }
 
 int c_y(int v) {
   if (v < width) { return 0; }
   if (v < width + height) { return v - width; }
   if (v < width + height + width) { return height - 1; }
   return height - 1 - (v - width - height - width);
 }
 
 int c_d(int v) {
   if (v < width) { return 3; }
   if (v < width + height) { return 0; }
   if (v < width + height + width) { return 1; }
   return 2;
 }
 
 void dfs(int wall, int x, int y, int d) {
   if (x < 0 || x >= width || y < 0 || y >= height) { return; }
   if (visit[x][y][d]) { return; }
   visit[x][y][d] = true;
   {
     int nx = x + dx[d];
     int ny = y + dy[d];
     int nd = (d + 2) % 4;
     dfs(wall, nx, ny, nd);
   }
   int w = (wall >> (y * width + x)) & 1;
   // \: 0
   // /: 1
   if (w == 0) {
     int conv[4] = { 3, 2, 1, 0 };
     int nd = conv[d];
     dfs(wall, x, y, nd);
   } else {
     int conv[4] = { 1, 0, 3, 2 };
     int nd = conv[d];
     dfs(wall, x, y, nd);
   }
 }
 
 bool valid(int wall) {
   REP(i, n) {
     if (i % 2 == 1) { continue; }
     MEMSET(visit, false);
     int from = loves[i];
     int to = loves[i + 1];
     // cout << from << " " << to << endl;
     // cout << c_x(from) << " " << c_y(from) << " " << c_d(from) << endl;
     // cout << c_x(to) << " " << c_y(to) << " " << c_d(to) << endl;
     dfs(wall, c_x(from), c_y(from), c_d(from));
     if (!visit[c_x(to)][c_y(to)][c_d(to)]) { return false; }
     REP(j, n) {
       if (j == from || j == to) { continue; }
       if (visit[c_x(j)][c_y(j)][c_d(j)]) { return false; }
     }
   }
   return true;
 }
 
 int calc(int depth, int wall) {
   if (depth == width * height) {
     if (valid(wall)) { return wall; }
     return -1;
   }
   int ans = -1;
   REP(i, 2) {
     int nwall = wall | (i << depth);
     ans = max(ans, calc(depth + 1, nwall));
   }
   return ans;
 }
 
 void solve() {
   scanf("%d %d", &height, &width);
   n = width * 2 + height * 2;
   REP(i, n) {
     scanf("%d", &loves[i]);
     loves[i]--;
   }
   int ans = calc(0, 0);
   if (ans == -1) {
     puts("IMPOSSIBLE");
   } else {
     REP(y, height) {
       REP(x, width) {
         int v = (ans >> (y * width + x)) & 1;
         putchar(v ? '/' : '\\');
       }
       puts("");
     }
   }
 }
