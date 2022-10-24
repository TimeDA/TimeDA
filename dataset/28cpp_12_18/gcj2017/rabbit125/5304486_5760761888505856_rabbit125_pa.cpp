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
 #define MAX        120
 /* Time Evaluation */
 #define runtime() ((double)clock() / CLOCKS_PER_SEC)
 /* EPS */
 const double eps = 1e-7 ;
 using namespace std ;
 /* Start Code Here */
 int R, C;
 char cakes[MAX][MAX];
 char   ans[MAX][MAX];
 set<char> cs;
 vector<char> cv;
 map<int,int> cm;
 int main() {
     freopen("A-small-attempt6.in", "r", stdin);
     //freopen("test.out", "w" , stdout);
     freopen("A-small-attempt6.out", "w" , stdout);
     //freopen("A-large.in", "r", stdin);
     //freopen("A-large.out", "w" , stdout);
     int t, T = 1;
     scanf("%d", &t);
     while(t--) {
         cs.clear();
         cv.clear();
         cm.clear();
         memset(cakes, 0 , sizeof(cakes));
         memset(ans, 0 , sizeof(ans));
         scanf("%d %d", &R, &C);
         for (int i = 0; i < R; ++i) {
             scanf("%s", cakes[i]);
             for(int j = 0; j < C; ++j) {
                 ans[i][j] = cakes[i][j];
                 if(cakes[i][j] != '?')
                     cs.insert(cakes[i][j]);
             }
         }
         for (set<char>::iterator sit = cs.begin(); sit != cs.end(); ++sit)
             cv.push_back(*sit);
         int all_c = cv.size();
         for (int i = 0; i < R; ++i) {
             int c_size = 0;
             char last_c = cakes[i][0];
             for(int j = 0; j <= C; ++j) {
                 if(j != C && cakes[i][j] != '?') last_c = cakes[i][j];
                 if(cakes[i][j] == '?' && j != C) {
                     c_size++;
                 } else if (c_size != 0){
                     if(j != C && last_c == '?') last_c = ans[i][j];
                     if(last_c != '?') {
                         for (int k = 1; k <= c_size ;++k)
                             ans[i][j-k] = last_c;
                     }
                     c_size = 0;
                     if(j != C) last_c = ans[i][j];
                 }
             }
         }
         for (int i = 0; i < R; ++i)
             for (int j = 0; j < C; ++j)
                 cakes[i][j] = ans[i][j];
 
         for (int i = 0; i < C; ++i) {
             int c_size = 0;
             char last_c = cakes[0][i];
             for(int j = 0; j <= R; ++j) {
                 if(j != R && cakes[j][i] != '?') last_c = cakes[j][i];
                 if(cakes[j][i] == '?' && j != R) {
                     c_size++;
                 } else if (c_size != 0){
                     if(j != R && last_c == '?') last_c = ans[j][i];
                     if(last_c != '?') {
                         for (int k = 1; k <= c_size ;++k)
                             ans[j-k][i] = last_c;
                     }
                     c_size = 0;
                     if(j != C) last_c = ans[j][i];
                 }
             }
         }
 
         printf("Case #%d:\n", T++);
         for (int i = 0; i < R; ++i)
             printf("%s\n", ans[i]);
     }
     return 0;
 }
 /*
 3
 3 3
 G??
 ?C?
 ??J
 3 4
 CODE
 ????
 ?JAM
 2 2
 CA
 KE
 4
 1 3
 AB?
 3 4
 ????
 ????
 ABCD
 */
 /*
 Case #1:
 GGJ
 CCJ
 CCJ
 Case #2:
 CODE
 COAE
 JJAM
 Case #3:
 CA
 KE
 */
