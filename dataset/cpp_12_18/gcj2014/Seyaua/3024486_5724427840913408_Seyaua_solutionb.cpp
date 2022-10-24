#include <iostream>
 #include <cstdio>
 #include <string>
 #include <cstring>
 #include <bitset>
 #include <queue>
 #include <set>
 #include <map>
 #include <cmath>
 #include <algorithm>
 #include <vector>
 #include <ctime>
 #pragma comment(linker, "/STACK:256000000")
 
 using namespace std;
 
 const int maxN = 210;
 
 int p, q, n;
 int h[maxN];
 int g[maxN];
 int d[110][maxN][1010][2];
 
 int solve(int i, int rest, int have, int move) {
   if (i >= n) return 0;
   if (d[i][rest][have][move] != -1) {
     return d[i][rest][have][move];
   }
 
   if (move == 1) {
     if (rest > q) {
       return d[i][rest][have][move] = solve(i, rest - q, have, 1 - move);
     } else {
       int cans = 0;
       int cvalue = h[i + 1];
       if (i + 1 == n) {
         return d[i][rest][have][move] = 0;
       }
       return d[i][rest][have][move] = solve(i + 1, h[i + 1], have, 1 - move);
     }
   } else {
     int cans = 0;
     cans = max(cans, solve(i, rest, have + 1, 1 - move));
 
     if (rest <= p) {
       cans = max(cans, g[i] + solve(i + 1, h[i + 1], have, 1 - move));
       if (have > 0) {
         cans = max(cans, g[i] + solve(i + 1, h[i + 1], have - 1, move));
       }
     } else {
       cans = max(cans, solve(i, rest - p, have, 1 - move));
       if (have > 0) {
         cans = max(cans, solve(i, rest - p, have - 1, move));
       }
     }
     return d[i][rest][have][move] = cans;
   }
 }
 
 void solve(int tcase) {
   cin >> p >> q >> n;
   for (int i = 0; i < n; ++i) {
     cin >> h[i] >> g[i];
   }
 
   memset(d, -1, sizeof(d));
   int ans = solve(0, h[0], 0, 0);
   printf("Case #%d: %d\n", tcase, ans);
 }
 
 int main() {
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
 
   int t;
   cin >> t;
 
   for (int i = 1; i <= t; ++i) {
     solve(i);
     cerr << i << endl;
   }
 
   return 0;
 }
