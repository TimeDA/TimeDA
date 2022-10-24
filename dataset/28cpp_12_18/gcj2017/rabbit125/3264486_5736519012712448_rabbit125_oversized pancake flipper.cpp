// Google Code Jam Template by rabbit125 @2015/04/18
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
 char pancakes[MAX] = {};
 int k_flip = 0;
 int main() {
     freopen("A-small-attempt0.in", "r", stdin);
     freopen("A-small-attempt0.out", "w" , stdout);
     //freopen("A-large.in", "r", stdin);
     //freopen("A-large.out", "w" , stdout);
     int t, T = 1;
     scanf("%d", &t);
     while(t--) {
         scanf("%s%d", pancakes, &k_flip);
         int has_ans = 1, ans = 0;
         int p_size = strlen(pancakes);
         int blank = 0;
         for (int i = 0; i < p_size; ++i)
             if(pancakes[i] == '-')
                 blank++;
         if (blank) {
             int checker = 0;
             while (1) {
                 if (checker >= p_size)
                     break;
                 if (pancakes[checker] == '+') {
                     checker++;
                 } else {
                     if (checker + k_flip - 1 < p_size) {
                         for (int i = checker; i < checker + k_flip; ++i)
                             pancakes[i] = pancakes[i] == '+' ? '-' : '+';
                         ans++;
                         checker++;
                     } else {
                         has_ans = 0;
                         break;
                     }
                 }
             }
         }
         if (has_ans)
             printf("Case #%d: %d\n", T++, ans);
         else
             printf("Case #%d: IMPOSSIBLE\n", T++);
     }
     return 0;
 }
 /*
 3
 ---+-++- 3
 +++++ 4
 -+-+- 4
 */
 /*
 Case #1: 3
 Case #2: 0
 Case #3: IMPOSSIBLE
 */
