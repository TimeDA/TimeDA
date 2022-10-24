
 
 
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
 
 const int MaxN = 105;
 
 int T, n, p, r[4];
 int opt[MaxN][MaxN][MaxN];
 
 int calc() {
     memset(opt, 0, sizeof opt);
     if (p == 3) {
         for (int i = 0; i <= r[1]; ++ i)
             for (int j = 0; j <= r[2]; ++ j) {
                 if (i >= 3) opt[i][j][0] = max(opt[i][j][0], opt[i - 3][j][0] + 1);
                 if (j >= 3) opt[i][j][0] = max(opt[i][j][0], opt[i][j - 3][0] + 1);
                 if (i >= 1 && j >= 1) opt[i][j][0] = max(opt[i][j][0], opt[i - 1][j - 1][0] + 1);
             }
     }
     else {
         for (int i = 0; i <= r[1]; ++ i)
             for (int j = 0; j <= r[2]; ++ j)
                 for (int k = 0; k <= r[3]; ++ k) {
                     if (i >= 4) opt[i][j][k] = max(opt[i][j][k], opt[i - 4][j][k] + 1);
                     if (j >= 2) opt[i][j][k] = max(opt[i][j][k], opt[i][j - 2][k] + 1);
                     if (k >= 4) opt[i][j][k] = max(opt[i][j][k], opt[i][j][k - 4] + 1);
                     if (i >= 1 && k >= 1)
                         opt[i][j][k] = max(opt[i][j][k], opt[i - 1][j][k - 1] + 1);
                     if (i >= 2 && j >= 1)
                         opt[i][j][k] = max(opt[i][j][k], opt[i - 2][j - 1][k] + 1);
                     if (k >= 2 && j >= 1)
                         opt[i][j][k] = max(opt[i][j][k], opt[i][j - 1][k - 2] + 1);
                 }
     }
     return opt[r[1]][r[2]][r[3]];
 }
 
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
         scanf("%d %d", &n, &p);
         memset(r, 0, sizeof r);
         int cnt = 0;
         for (int k = 0; k < n; ++ k) {
             int tmp; scanf("%d", &tmp);
             ++ r[tmp % p];
             cnt = (cnt + tmp) % p;
         }
         int ans = r[0] + (cnt != 0);
         if (p == 2) ans += r[1] / 2;
         else ans += calc();
         
         printf("Case #%d: %d\n", testcase, ans);
     }
     
     return 0;
 }
