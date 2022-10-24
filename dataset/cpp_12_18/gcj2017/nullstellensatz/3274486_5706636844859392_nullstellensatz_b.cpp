
 
 
 /*
     Prob:
     Author: 
     Time:   
     Description:
 */
 
 #include <iostream>
 #include <cstdio>
 #include <cstdlib>
 #include <cstring>
 #include <cmath>
 #include <algorithm>
 #include <string>
 using namespace std;
 
 const int MaxN = 750;
 
 int T, n = 720;
 int d[2], opt[MaxN][MaxN][2][2];
 bool t[MaxN << 1][2];
 
 int main(int argc, char* argv[]) { 
     if (argc >= 2) {
         string post = argv[1][0] == 's' ? 
                       "-small-attempt" + string(argv[2]):
                       "-large";  
         string input_file  = string(argv[0]) + post + ".in",
                output_file = string(argv[0]) + post + ".out";
         freopen(input_file.c_str(), "r", stdin);
         freopen(output_file.c_str(), "w", stdout);
     }
     
     scanf("%d", &T);
     for (int testcase = 1; testcase <= T; ++ testcase) {
         scanf("%d %d", d + 0, d + 1);
         memset(t, 1, sizeof t);
         for (int k = 0; k < 2; ++ k)
             for (int r = 0; r < d[k]; ++ r) {
                 int p, q; scanf("%d %d", &p, &q);
                 for (int s = p; s < q; ++ s)
                     t[s][k] = false;
             }
         
         memset(opt, -1, sizeof opt);
         opt[0][0][0][0] = opt[0][0][1][1] = 0;
         for (int i = 0; i <= n; ++ i)
             for (int j = 0; j <= n; ++ j) {
                 int k = i + j;
                 if (k >= n + n) continue;
                 for (int p = 0; p < 2; ++ p)
                     for (int q = 0; q < 2; ++ q) {
                         if (opt[i][j][p][q] < 0) continue;
                         if (t[k][0] && i < n) {
                             int c = opt[i][j][p][q] + (q == 0 ? 0 : 1);
                             if (opt[i + 1][j][p][0] < 0 || opt[i + 1][j][p][0] > c)
                                 opt[i + 1][j][p][0] = c;
                         }
                         if (t[k][1] && j < n) {
                             int c = opt[i][j][p][q] + (q == 1 ? 0 : 1);
                             if (opt[i][j + 1][p][1] < 0 || opt[i][j + 1][p][1] > c)
                                 opt[i][j + 1][p][1] = c;
                         }
                     }
             }
         int ans = -1;
         for (int p = 0; p < 2; ++ p)
             for (int q = 0; q < 2; ++ q) {
                 if (opt[n][n][p][q] < 0) continue;
                 int c = opt[n][n][p][q] + (p == q ? 0 : 1);
                 if (ans < 0 || ans > c) ans = c;
             }
         printf("Case #%d: %d\n", testcase, ans);
     }
     
     return 0;
 }
