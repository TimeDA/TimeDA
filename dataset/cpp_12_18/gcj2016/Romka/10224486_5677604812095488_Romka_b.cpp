#include <cstdio>
 #include <vector>
 #include <cmath>
 #include <set>
 #include <map>
 #include <algorithm>
 #include <cstring>
 #include <string>
 #include <iostream>
 #include <cassert>
 #include <memory.h>
 using namespace std;
 
 #define forn(i, n) for (int i = 0; i < (int)(n); i++)
 #define foreach(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
 #define pb push_back
 typedef long long ll;
 typedef pair<int, int> pii;
 typedef long double ld;
 
 void solve() {
     int n, k;
     double p[210];
     double f[17][17];
     scanf("%d %d", &n, &k);
     forn(i, n) scanf("%lf", &p[i]);
     double ans = 0;
     forn(m, 1 << n) {
         memset(f, 0, sizeof(f));
         f[0][0] = 1;
         int c = 0;
         forn(j, n)
             if ((1 << j) & m) {
                 for (int q = 0; q <= c; ++q) {
                     f[c+1][q+1] += f[c][q] * p[j];
                     f[c+1][q] += f[c][q] * (1 - p[j]);
                 }
                 c++;
             }
 
         if (c == k) {
             if (f[c][k / 2] > ans) {
                 ans = f[c][k / 2];
             }
         }
     }
     printf("%.8f\n", ans);
 }
 
 int main() {
     int tc;
     scanf("%d", &tc);
     for (int q = 1; q <= tc; q++) {
         printf("Case #%d: ", q);
         solve();
     }
     return 0;
 }
