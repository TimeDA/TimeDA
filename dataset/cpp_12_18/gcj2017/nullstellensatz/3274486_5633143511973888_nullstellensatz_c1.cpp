
 
 
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
 const double eps = 1e-8;
 
 int T, n, q;
 double D, p[MaxN];
 
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
         scanf("%d %d %lf", &n, &q, &D);
         for (int k = 0; k < n; ++ k)
             scanf("%lf", p + k);
         p[n] = 1.0;
         sort(p, p + n + 1);
         
         while (D > eps) {
             int cnt = 1;
             double del = 0;
             for (int k = 1; k <= n; ++ k)
                 if (p[k] - p[0] > eps) {
                     del = p[k] - p[0];
                     break;
                 }
                 else ++ cnt;
             del = min(del, D / cnt);
             D -= del * cnt;
             for (int k = n - 1; k >= 0; -- k)
                 if (p[k] - p[0] <= eps) p[k] += del;
         }
         
         double ans = 1.0;
         for (int k = 0; k < n; ++ k)
             ans *= p[k];
         printf("Case #%d: %.8f\n", testcase, ans);
     }
     
     return 0;
 }
