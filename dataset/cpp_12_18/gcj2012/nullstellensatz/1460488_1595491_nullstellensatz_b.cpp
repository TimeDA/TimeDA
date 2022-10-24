
 
 
 /*
     Prob:   Google Code Jam 2012 Qualification_Round B
     Author: peanutyk
     Time:   15/04/12 00:08
     Description: ģ
 */
 
 #include <iostream>
 #include <cstdio>
 #include <cstdlib>
 #include <cstring>
 #include <cmath>
 #include <algorithm>
 using namespace std;
 
 const int MaxN = 105;
 
 int T, n, s, p, t;
 
 int main() {
     scanf("%d", &T);
     for (int tc = 1; tc <= T; ++ tc) {
         scanf("%d %d %d", &n, &s, &p);
         int cnt_n = 0, cnt_s = 0;
         for (int k = 1; k <= n; ++ k) {
             scanf("%d", &t);
             if ((max(p - 1, 0) << 1) + p <= t) {
                 ++ cnt_n;
                 continue;
             }
             if ((max(p - 2, 0) << 1) + p <= t) {
                 ++ cnt_s;
                 continue;
             }
         }
         printf("Case #%d: %d\n", tc, cnt_n + min(cnt_s, s));
     }
     
     return 0;
 } 
