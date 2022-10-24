
 
 
 /*
     Prob:   Google code jam Round 2 2013 C
     Author: peanut
     Time:   02/06/13 00:06
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
 
 const int MaxN = 2005;
 
 int n, T;
 int A[MaxN], B[MaxN], c[MaxN], d[MaxN];
 int f[MaxN][MaxN];
 bool v[MaxN];
 
 int main(int argc, char* argv[]) {
     if (argc >= 2) {
         string input_file  = string(argv[1]) + ".in",
                output_file = string(argv[1]) + ".out";
         freopen(input_file.c_str(), "r", stdin);
         freopen(output_file.c_str(), "w", stdout);
     }
     
     scanf("%d", &T);
     for (int testcase = 1; testcase <= T; ++ testcase) {
         memset(d, 0, sizeof d);
         memset(f, 0, sizeof f);
         // f[A][B] means A > B
         scanf("%d", &n);
         for (int k = 1; k <= n; ++ k)
             scanf("%d", A + k);
         for (int k = 1; k <= n; ++ k)
             scanf("%d", B + k);
         for (int k = 1; k <= n; ++ k) {
             int cur = 0;
             for (int r = 1; r < k; ++ r) {
                 if (A[r] >= A[k]) {
                     ++ d[k];
                     ++ f[r][k];
                 }
                 if (A[r] == A[k] - 1) cur = r;
             }
             if (cur) {
                 ++ d[cur];
                 ++ f[k][cur];
             }
         }
         for (int k = n; k >= 1; -- k) {
             int cur = 0;
             for (int r = n; r > k; -- r) {
                 if (B[r] >= B[k]) {
                     ++ d[k];
                     f[r][k] ++;
                 }
                 if (B[r] == B[k] - 1) cur = r;
             }
             if (cur) {
                 ++ d[cur];
                 f[k][cur] ++;
             }
         }
         
         printf("Case #%d:", testcase);
         memset(v, 0, sizeof v);
         for (int k = n; k >= 1; -- k) {
             int cur = 0;
             for (int r = 1; r <= n; ++ r)
                 if (d[r] <= 0 && !v[r]) cur = r;
             c[cur] = k;
             v[cur] = true;
             for (int r = 1; r <= n; ++ r)
                 if (f[cur][r]) d[r] -= f[cur][r];
         }
         for (int k = 1; k <= n; ++ k)
             printf(" %d", c[k]);
         puts("");
     }
     
     return 0;
 }
