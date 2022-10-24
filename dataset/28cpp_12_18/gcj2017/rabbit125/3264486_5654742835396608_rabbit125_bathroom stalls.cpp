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
 map<LLI,map<LLI,LLI>> key_map;
 LLI N, K;
 
 void printXmap(LLI now) {
     printf("printting %lld..\n", now);
     LLI sum = 0;
     for (map<LLI,LLI>::iterator mit = key_map[now].begin(); mit != key_map[now].end(); ++mit) {
         printf("%lld %lld\n", mit->first, mit->second);
         sum += mit->second;
     }
     printf("sum %lld\n", sum);
 }
 
 void DFS(LLI n) {
     // touched
     if (key_map.find(n) != key_map.end())
         return;
     if (n == 0) return;
     LLI a = 0, b = 0;
     if (n % 2) {
         a = (n-1) / 2;
         b = (n-1) / 2;
     } else {
         a = n / 2;
         b = n / 2 - 1;
     }
     DFS(a);
     DFS(b);
     map<LLI,LLI> tmp_n_recorder;
     for (map<LLI,LLI>::iterator mit = key_map[a].begin(); mit != key_map[a].end(); ++mit)
         tmp_n_recorder[mit->first] += mit->second;
     for (map<LLI,LLI>::iterator mit = key_map[b].begin(); mit != key_map[b].end(); ++mit)
         tmp_n_recorder[mit->first] += mit->second;
     tmp_n_recorder[n]++;
     key_map[n] = tmp_n_recorder;
     //printXmap(n);
 }
 
 int main() {
     freopen("C-small-1-attempt0.in", "r", stdin);
     freopen("C-small-1-attempt0.out", "w" , stdout);
     //freopen("A-large.in", "r", stdin);
     //freopen("A-large.out", "w" , stdout);
     int t, T = 1;
     scanf("%d", &t);
     while(t--) {
         scanf("%lld%lld", &N, &K);
         key_map.clear();
         DFS(N);
         LLI low_index = N + 1 - K, tans = 0;
         LLI Lrange = 1, Rrange = 0;
         for (map<LLI,LLI>::iterator mit = key_map[N].begin(); mit != key_map[N].end(); ++mit) {
             Rrange += mit->second;
             if (Lrange <= low_index && low_index <= Rrange) {
                 tans = mit->first;
                 break;
             }
             //printf("%lld %lld // L %lld R %lld // Ind %lld\n", mit->first, mit->second, Lrange, Rrange, low_index);
             Lrange += mit->second;
         }
         if (tans % 2)
             printf("Case #%d: %lld %lld\n", T++, (tans-1)/2, (tans-1)/2);
         else
             printf("Case #%d: %lld %lld\n", T++, tans/2, tans/2-1 );
     }
     return 0;
 }
 /*
 5
 4 2
 5 2
 6 2
 1000 1000
 1000 1
 */
 /*
 Case #1: 1 0
 Case #2: 1 0
 Case #3: 1 1
 Case #4: 0 0
 Case #5: 500 499
 */
