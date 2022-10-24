
 
 
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
 using namespace std;
 
 const int MaxN = 1005;
 const double eps = 1e-10;
 
 int T, n;
 long long X, V;
 long long r[MaxN], c[MaxN];
 
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
         double tmp_V, tmp_X;
         scanf("%d %lf %lf", &n, &tmp_V, &tmp_X);
         V = (long long)(tmp_V * 10000 + 0.5);
         X = (long long)(tmp_X * 10000 + 0.5);
         for (int k = 0; k < n; ++ k) {
             double tmp_r, tmp_c;
             scanf("%lf %lf", &tmp_r, &tmp_c);
             r[k] = (long long)(tmp_r * 10000 + 0.5);
             c[k] = (long long)(tmp_c * 10000 + 0.5);
         }
         for (int i = 0; i < n; ++ i)
             for (int j = i + 1; j < n; ++ j)
                 if (c[i] > c[j]) {
                     swap(r[i], r[j]);
                     swap(c[i], c[j]);
                 }
         
         printf("Case #%d: ", testcase);
         if (X < c[0] || X > c[n - 1]) {
             puts("IMPOSSIBLE");
             continue;
         }
         
         long long v_l = 0, v_h = 0, s_l = 0, s_h = 0;
         for (int k = 0; k < n; ++ k) {
             if (c[k] < X) {
                 v_l += r[k];
                 s_l += r[k] * c[k];
             }
             if (c[k] >= X) {
                 v_h += r[k];
                 s_h += r[k] * c[k];
             }
         }
         
         double cnt = 0;
         if (v_l == 0) {
             printf("%.8lf\n", V * 1.0 / r[0]);
             continue;
         }
         if ((s_l + s_h) < X * (v_l + v_h))
             cnt = v_h + (s_h - X * v_h) * 1.0 / (X * v_l - s_l) * v_l;
         else
             cnt = v_l + (X * v_l - s_l) * 1.0 / (s_h - X * v_h) * v_h;
         printf("%.8lf\n", V / cnt);
     }
     
     return 0;
 }
