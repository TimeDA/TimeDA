
 
 
 /*
     Prob:   Google Code Jam Round2 2014
     Author: peanut
     Time:   
     Description:
 */
 
 #include <iostream>
 #include <cstdio>
 #include <cstdlib>
 #include <cstring>
 #include <cmath>
 #include <algorithm>
 #include <vector>
 using namespace std;
 
 const int MaxN = 1005;
 
 int T, n;
 int v[MaxN], idx[MaxN], pre[MaxN], pst[MaxN], opt[MaxN][MaxN];
 
 inline int update(int x, int y) {
     if (x < 0) return y;
     if (y < 0) return x;
     return min(x, y);
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
         scanf("%d", &n);
         for (int k = 0; k < n; ++ k)
             scanf("%d", v + k);
         memset(pre, 0, sizeof pre);
         memset(pst, 0, sizeof pst);
         for (int i = 0; i < n; ++ i) {
             int cnt = 0;
             for (int j = 0; j < n; ++ j)
                 cnt += (v[j] < v[i]);
             idx[cnt] = i;
         }
         for (int i = 0; i < n; ++ i)
             for (int j = i + 1; j < n; ++ j)
                 if (v[i] > v[j]) ++ pre[j];
                 else ++ pst[i];
         
         sort(v, v + n);
         opt[0][0] = 0;
         for (int i = 1; i <= n; ++ i)
             for (int j = 0; j <= i; ++ j) {
                 int tmp_u = j > 0 ? opt[i - 1][j - 1] + pre[idx[i - 1]] : -1,
                     tmp_d = j < i ? opt[i - 1][j] + pst[idx[i - 1]] : -1;
                 opt[i][j] = update(tmp_u, tmp_d);
             }
         
         int ans = opt[n][0];
         for (int k = 1; k <= n; ++ k)
             ans = min(ans, opt[n][k]);
         printf("Case #%d: %d\n", testcase, ans);
     }
 
     return 0;
 }
