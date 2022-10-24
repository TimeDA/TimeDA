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
 int J, C;
 struct P {
     int own;
     int s, e;
 };
 vector<P> allp;
 bool cmp(P a, P b)
 {
     if( a.s < b.s)
         return 1;
     return 0;
 }
 int main() {
     freopen("B-small-attempt3.in", "r", stdin);
     freopen("B-small-attempt3.out", "w" , stdout);
     //freopen("B-large.in", "r", stdin);
     //freopen("B-large.out", "w" , stdout);
     int t, T = 1;
     scanf("%d", &t);
     while(t--) {
         allp.clear();
         scanf("%d%d", &C, &J);
         P now;
         int N = J + C;
         for(int i = 0 ; i < C; i++) {
             scanf("%d%d", &now.s, &now.e);
             now.own = 0;
             allp.push_back(now);
         }
         for(int i = 0 ; i < J; i++) {
             scanf("%d%d", &now.s, &now.e);
             now.own = 1;
             allp.push_back(now);
         }
         sort(allp.begin(), allp.end(), cmp);
         // C
         int sum[2] = {0};
         int cut[2] = {0};
         vector<int> pl[2];
         vector<int> pt[2];
         int ans = 0;
         for(int i = 0 ; i < 2; i++) {
             pl[i].clear();
             pt[i].clear();
             for(int j = 0 ; j < N; j++) {
                 if (allp[j].own == i) {
                     int st = allp[j].s;
                     int ed = allp[j].e;
                     int k = j+1;
                     pl[i].PB(j);
                     sum[i] = 0;
                     while (k < N && allp[k].own == i) {
                         if (allp[k].e - st + sum[i] > 720)
                             break;
                         pl[i].PB(k);
                         k++;
                     }
                     sum[i] += allp[pl[i][pl[i].size()-1]].e - st;
                     cut[i]++;
                     pt[i].PB(allp[pl[i][pl[i].size()-1]].e - st);
                     //printf("yyy %d / %04d %2d / %d --> %d\n", i , sum[i], cut[i], j, k-1);
                     j = k-1;
                 }
             }
             int last_idl = pl[i].size()-1;
             int last_idt = pt[i].size()-1;
             if ((pt[i].size()) > 1 &&
                 (pl[i][0] == 0 && pl[i][last_idl] == N-1) &&
                 (pt[i][0] + pt[i][last_idt] + (1420 - allp[N-1].e) + (allp[0].s) <= 720))
                 ans = max(ans, 2*(cut[i]-1));
             else
                 ans = max(ans, 2*cut[i]);
 
         }
         //printf("xxx%d %d\n", sum[0], cut[0]);
         //printf("xxx%d %d\n", sum[1], cut[1]);
         printf("Case #%d: %d\n", T++, ans);
         #if 0
         if (ans == 2 && N == 2)
         //if (ans == 4)
             for(int i = 0 ; i < N; i++) {
                 printf("xx %02d // %04d - %04d // %d\n", i, allp[i].s, allp[i].e, allp[i].own);
             }
         #endif
     }
     return 0;
 }
 /*
 
 511
 2 0
 0463 0522
 0522 0592
 
 2 0
 180 540
 540 900
 
 1 0
 0 720
 2 0
 0 360
 710 1070
 
 2 0
 0 360
 1060 1420
 
 
 1
 3 4
 0 10
 1420 1440
 90 100
 550 600
 900 950
 100 150
 1050 1400
 
 */
 /*
 5
 1 1
 540 600
 840 900
 2 0
 900 1260
 180 540
 1 1
 1439 1440
 0 1
 2 2
 0 1
 1439 1440
 1438 1439
 1 2
 3 4
 0 10
 1420 1440
 90 100
 550 600
 900 950
 100 150
 1050 1400
 */
 /*
 Case #1: 2
 Case #2: 4
 Case #3: 2
 Case #4: 4
 Case #5: 6
 */
