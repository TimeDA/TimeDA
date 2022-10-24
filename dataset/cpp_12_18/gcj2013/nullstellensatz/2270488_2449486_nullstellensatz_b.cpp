
 
 
 /*
     Prob:   Google code jam Qualification Round 2013 B
     Author: peanut
     Time:   13/04/13 22:42
     Description:
 */
 
 #include <iostream>
 #include <cstdio>
 #include <cstdlib>
 #include <cstring>
 #include <cmath>
 #include <algorithm>
 using namespace std;
 
 const int MaxN = 105;
 
 int n, m, T;
 int h[MaxN][MaxN];
 bool flag_x[MaxN], flag_y[MaxN];
 
 inline bool check() {
     int lim = 0;
     for (int i = 1; i <= n; ++ i)
         for (int j = 1; j <= m; ++ j)
             lim = max(lim, h[i][j]);
     
     for (int k = lim; k > 1; -- k) {
         memset(flag_x, 0, sizeof flag_x);
         memset(flag_y, 0, sizeof flag_y);
         for (int i = 1; i <= n; ++ i) {
             bool c = true;
             for (int j = 1; j <= m; ++ j)
                 c &= (h[i][j] < lim);
             if (c) flag_x[i] = true;
         }
         for (int j = 1; j <= m; ++ j) {
             bool c = true;
             for (int i = 1; i <= n; ++ i)
                 c &= (h[i][j] < lim);
             if (c) flag_y[j] = true;
         }
         for (int i = 1; i <= n; ++ i)
             for (int j = 1; j <= m; ++ j)
                 if (h[i][j] < lim && !(flag_x[i] || flag_y[j])) return false;
     }
     return true;
 }
 
 int main(int argc, char* argv[]) {
     if (argc >= 2) {
         string input_file  = string(argv[1]) + ".in",
                output_file = string(argv[1]) + ".out";
         freopen(input_file.c_str(), "r", stdin);
         freopen(output_file.c_str(), "w", stdout);
     }
     
     scanf("%d", &T);
     for (int testcase = 1; testcase <= T; ++ testcase) {
         scanf("%d %d", &n, &m);
         for (int i = 1; i <= n; ++ i)
             for (int j = 1; j <= m; ++ j)
                 scanf("%d", &h[i][j]);
         
         printf("Case #%d: ", testcase);
         if (check()) puts("YES"); else puts("NO");
     }
     
     return 0;
 }
