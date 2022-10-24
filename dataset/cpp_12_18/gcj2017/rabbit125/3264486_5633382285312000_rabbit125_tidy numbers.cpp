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
 #define MAX    1200000
 /* Time Evaluation */
 #define runtime() ((double)clock() / CLOCKS_PER_SEC)
 /* EPS */
 const double eps = 1e-7 ;
 using namespace std ;
 /* Start Code Here */
 long long N = 0;
 int main() {
     freopen("B-small-attempt0.in", "r", stdin);
     freopen("B-small-attempt0.out", "w" , stdout);
     //freopen("A-large.in", "r", stdin);
     //freopen("A-large.out", "w" , stdout);
     int t, T = 1;
     scanf("%d", &t);
     while(t--) {
         scanf("%lld", &N);
         LLI tmpN = N, ans = 0, pos = 1;
 
         while (tmpN > 0) {
             int last_dig = tmpN % 10, pre_dig = tmpN / 10 % 10;
             if (last_dig >= pre_dig) {
                 ans += pos * last_dig;
                 tmpN /= 10;
             } else {
                 ans = pos * 10 - 1;
                 tmpN /= 10;
                 tmpN--;
             }
             pos *= 10;
         }
         printf("Case #%d: %lld\n", T++, ans);
     }
     return 0;
 }
 /*
 4
 132
 1000
 7
 111111111111111110
 */
 /*
 Case #1: 129
 Case #2: 999
 Case #3: 7
 Case #4: 99999999999999999
 */
 
 /*
 // in
 1000
 
 503
 500
 943
 563
 546
 1437
 
 // out
 499
 499
 899
 559
 499
 1399
 
 */
 
 
 
 
 
