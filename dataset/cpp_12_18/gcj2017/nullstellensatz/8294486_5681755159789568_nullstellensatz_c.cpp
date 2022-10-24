
 
 
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
 
 int T, n, q;
 long long e[MaxN], s[MaxN];
 long long d[MaxN][MaxN];
 double h[MaxN][MaxN];
 
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
     
     cin >> T;
     for (int testcase = 1; testcase <= T; ++ testcase) {
         cin >> n >> q;
         for (int k = 1; k <= n; ++ k)
             cin >> e[k] >> s[k];
         for (int i = 1; i <= n; ++ i)
             for (int j = 1; j <= n; ++ j)
                 cin >> d[i][j];
             
         for (int k = 1; k <= n; ++ k)
             for (int i = 1; i <= n; ++ i)
                 for (int j = 1; j <= n; ++ j) {
                     if (d[i][k] < 0 || d[k][j] < 0) continue;
                     if (d[i][j] < 0 || d[i][j] > d[i][k] + d[k][j])
                         d[i][j] = d[i][k] + d[k][j];
                 }
         for (int i = 1; i <= n; ++ i)
             for (int j = 1; j <= n; ++ j) {
                 if (d[i][j] < 0 || d[i][j] > e[i]) h[i][j] = -1;
                 else  h[i][j] = d[i][j] * 1.0 / s[i];
             }
         for (int k = 1; k <= n; ++ k)
             for (int i = 1; i <= n; ++ i)
                 for (int j = 1; j <= n; ++ j) {
                     if (h[i][k] < 0 || h[k][j] < 0) continue;
                     if (h[i][j] < 0 || h[i][j] > h[i][k] + h[k][j])
                         h[i][j] = h[i][k] + h[k][j];
                 }
         
         for (int k = 0; k < q; ++ k) {
             int u, v; cin >> u >> v;
             if (k > 0) printf(" %.8lf", h[u][v]);
             else printf("Case #%d: %.8lf", testcase, h[u][v]);
         }
         puts("");
     }
     
     return 0;
 }
