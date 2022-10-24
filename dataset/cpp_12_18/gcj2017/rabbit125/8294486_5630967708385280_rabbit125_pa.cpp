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
 #define MAX       1200
 /* Time Evaluation */
 #define runtime() ((double)clock() / CLOCKS_PER_SEC)
 /* EPS */
 const double eps = 1e-7 ;
 using namespace std ;
 /* Start Code Here */
 double D;
 int N;
 double K[MAX], S[MAX];
 int main() {
     freopen("A-small-attempt0.in", "r", stdin);
     freopen("A-small-attempt0.out", "w" , stdout);
     //freopen("A-large.in", "r", stdin);
     //freopen("A-large.out", "w" , stdout);
     int t, T = 1;
     scanf("%d", &t);
     while(t--) {
         scanf("%lf%d", &D, &N);
         double max_t = 0;
         for (int i = 0; i < N ; ++i) {
             scanf("%lf%lf", &K[i], &S[i]);
             max_t = max(max_t, (D-K[i])/S[i]);
         }
 
         double ans = D / max_t;
         printf("Case #%d: %.6lf\n", T++, ans);
     }
     return 0;
 }
 /*
 3
 2525 1
 2400 5
 300 2
 120 60
 60 90
 100 2
 80 100
 70 10
 */
 /*
 output
 */
