// Google Code Jam Template by rabbit125 @2017/04/08
 /* Libs. */
 #include <algorithm>
 #include <bits/stdc++.h>
 #include <climits>
 #include <cstdarg>
 #include <cstdio>
 #include <cstdlib>
 #include <cstring>
 #include <cmath>
 #include <iostream>
 #include <map>
 #include <queue>
 #include <set>
 #include <stack>
 #include <utility>
 #include <vector>
 /* ShortCut Vars. */
 #if __WIN32__
     #define LLD "%I64d"
 #else
     #define LLD "%lld"
 #endif // __WIN32__
 #define BG   begin
 #define CL   clear
 #define ED   end
 #define FR   first
 #define MP   make_pair
 #define SC   second
 #define SZ   size
 #define PB   push_back
 #define PF   push_front
 #define PPB  pop_back
 #define PPF  pop_front
 #define lg      std::__lg
 #define __count __builtin_popcount
 /* Type ShortCuts */
 typedef unsigned int        UI;
 typedef long long          LLI;
 typedef unsigned long long ULL;
 typedef long double         LD;
 /* Function ShortCuts */
 #define MS0(x) memset(x, 0, sizeof(x))
 #define MS1(x) memset(x, -1, sizeof(x))
 /* C++11 */
 // __cplusplus is a int: 201103
 #if __cplusplus > 201103L
     #include <tuple>
     #define MT make_tuple
     typedef tuple<int, int> TII;
 #endif
 /* Define Value Vars. */
 #define BIT         17
 #define INF 2000000000
 #define MOD 1000000007
 #define STRMAX    1000
 #define MAX       1003
 /* Time Evaluation */
 #define runtime() ((double)clock() / CLOCKS_PER_SEC)
 /* EPS */
 const double eps = 1e-7 ;
 using namespace std ;
 /* Start Code Here */
 const double PI = 4.0 * atan( 1.0 ) ;
 int N, K;
 struct P {
     LLI r, h;
     double c1, c2;
 };
 P p[MAX];
 bool cmp(P a, P b) {
     if (a.c1 > b.c1)
         return 1;
     return 0;
 };
 double dp[MAX][MAX];
 int main() {
     freopen("A-small-attempt0.in", "r", stdin);
     freopen("A-small-attempt0.out", "w" , stdout);
     //freopen("A-large.in", "r", stdin);
     //freopen("A-large.out", "w" , stdout);
     int t, T = 1;
     scanf("%d", &t);
     while(t--) {
         MS0(p);
         scanf("%d%d",&N, &K);
         for(int i = 0; i < N ; ++i) {
             scanf("%lld%lld", &p[i].r, &p[i].h);
             p[i].c1 = (double) p[i].r * p[i].r;
             p[i].c2 = (double) p[i].r * p[i].h * 2.0;
         }
         sort(p, p+N, cmp);
         # if 0
         for(int i = 0; i < N ; ++i) {
             printf("%d %d\n", p[i].r, p[i].h);
         }
         #endif
         MS0(dp);
         for(int i = 0; i < N ; ++i) {
             dp[1][i] = p[i].c1 + p[i].c2;
         }
         for(int i = 2; i <= K ; ++i) {
             for(int j = 0; j < N ; ++j) {
                 for(int k = 0; k < j ; ++k) {
                     dp[i][j] = max(dp[i][j], (dp[i-1][k] + p[j].c2));
                 }
             }
         }
         double ans = 0;
         for(int i = 0; i < N ; ++i) {
             ans = max(ans, dp[K][i]);
             //printf("%d %d\n", i, dp[K][i]);
         }
         printf("Case #%d: %.9lf\n", T++, ans * PI);
     }
     return 0;
 }
 /*
 4
 2 1
 100 20
 200 10
 2 2
 100 20
 200 10
 3 2
 100 10
 100 10
 100 10
 4 2
 9 3
 7 1
 10 1
 8 4
 */
 /*
 Case #1: 138230.076757951
 Case #2: 150796.447372310
 Case #3: 43982.297150257
 Case #4: 625.176938064
 */
