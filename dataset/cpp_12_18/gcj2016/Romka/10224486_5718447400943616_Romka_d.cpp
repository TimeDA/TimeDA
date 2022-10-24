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
 
 int n, a[5][5];
 
 bool isok(int mw, int mm) {
     if (mw == 0) return true;
 
     forn(w, n)
         if (mw & (1 << w)) {
             bool have = false;
             forn(m, n)
                 if (a[w][m] && (mm & (1 << m)) > 0) {
                     have = true;
                     if (!isok(mw ^ (1 << w), mm ^ (1 << m))) {
                         return false;
                     }
                 }
             if (!have) return false;
         }
 
     return true;
 }
 
 void solve() {
     scanf("%d", &n);
     char s[110];
     forn(i, n) {
         scanf("%s", s);
         forn(j, n) a[i][j] = s[j] == '1';
     }
 
     int mc = 0;
     forn(i, n)
         forn(j, n)
             if (a[i][j] == 0) {
                 mc ^= 1 << (i * n + j);
             }
 
     int ans = n * n;
 
     for (int m = mc; m >= 0; m = (m - 1) & mc) {
         int price = 0;
         forn(q, n * n) {
             if (m & (1 << q)) {
                 a[q / n][q % n] = 1;
                 price++;
             }
         }
 
         if (price >= ans) {
             forn(q, n * n) {
             if (m & (1 << q)) {
                 a[q / n][q % n] = 0;
             }
         }
             continue;
         }
         if (isok((1 << n) - 1, (1 << n) - 1)) {
             ans = price;
         }
 
         forn(q, n * n) {
             if (m & (1 << q)) {
                 a[q / n][q % n] = 0;
             }
         }
 
         if (m == 0) break;
     }
 
     printf("%d\n", ans);
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
