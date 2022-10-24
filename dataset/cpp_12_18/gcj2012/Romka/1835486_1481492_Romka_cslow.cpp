#include <cstdio>
 #include <vector>
 #include <cmath>
 #include <set>
 #include <map>
 #include <algorithm>
 #include <cstring>
 #include <string>
 #include <iostream>
 #include <memory.h>
 using namespace std;
 
 #define forn(i, n) for (int i = 0; i < (int)(n); i++)
 #define foreach(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
 #define pb push_back
 typedef long long ll;
 typedef pair<int, int> pii;
 typedef long double ld;
 
 int M, F, n;
 int cost[210], live[210];
 int f[2000010], best[2000010];
 
 void solve() {
     cin >> M >> F >> n;
     forn(i, n) {
         cin >> cost[i] >> live[i];
     }
 
     forn(i, M+1) best[i] = (int)1e9;
     forn(i, n) best[ live[i] ] = min(best[ live[i] ], cost[i]);
     
     for (int i=M-1; i>=0; i--) best[i] = min(best[i], best[i+1]);
 
     vector<int> totals;
     int total = F + best[0];
     int days = 1;
     while (total <= M) {
         totals.pb(total);
         total += best[days];
         days++;
     }
 
     f[0] = 0;
     for (int i = 1; i <= M; i++) {
         f[i] = f[i-1];
         // int total = F + best[0];
         // int days = 1;
         int id = upper_bound(totals.begin(), totals.end(), i) - totals.begin();
         for (int q = id - 10; q < id + 2; q++)
             if (q >= 0 && q < (int)totals.size()) {
                 if (totals[q] <= i) {
                     f[i] = max(f[i], f[i-totals[q]] + q + 1);
                 }
             }
 /*        while (total <= i) {
             f[i] = max(f[i], f[i-total] + days);
             total += best[days];
             days++;
         } */
     }
 
     printf("%d\n", f[M]);
 }
 
 int main() {
     int tc;
     scanf("%d", &tc);
     for (int q = 1; q <= tc; q++) {
         printf("Case #%d: ", q);
         solve();
     }
 }
