
 
 
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
 #include <algorithm>
 #include <vector>
 using namespace std;
 
 const int MaxN = 1000 + 50;
 
 int T, w, h, b;
 int f[MaxN][MaxN], dist[MaxN], x0[MaxN], y0[MaxN], x1[MaxN], y1[MaxN];
 bool v[MaxN];
 
 inline int dist_seg(int l0, int r0, int l1, int r1) {
     if (l0 > l1) {
         swap(l0, l1);
         swap(r0, r1);
     }
     return max(l1 - r0 - 1, 0);
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
     memset(f, 0, sizeof f);
     for (int testcase = 1; testcase <= T; ++ testcase) {
         scanf("%d %d %d", &w, &h, &b);
         for (int k = 1; k <= b; ++ k)
             scanf("%d %d %d %d", x0 + k, y0 + k, x1 + k, y1 + k);
         ++ b;
         x0[0] = x1[0] = -1; 
         x0[b] = x1[b] = w; 
         y0[0] = y0[b] = 0;
         y1[0] = y1[b] = h;
         
         for (int i = 0; i < b; ++ i)
             for (int j = i + 1; j <= b; ++ j)
                 f[i][j] = f[j][i] = max(dist_seg(x0[i], x1[i], x0[j], x1[j]),
                                         dist_seg(y0[i], y1[i], y0[j], y1[j]));
         
         memset(v, 0, sizeof v);
         for (int k = 0; k <= b; ++ k)
             dist[k] = f[0][k];
         for (int k = 0; k < b; ++ k) {
             int cur = -1;
             for (int t = 1; t <= b; ++ t) {
                 if (v[t]) continue;
                 if (cur < 0 || dist[t] < dist[cur]) cur = t;
             }
             
             if (cur < 0) break;
             v[cur] = true;
             for (int t = 1; t <= b; ++ t)
                 dist[t] = min(dist[t], dist[cur] + f[cur][t]);
         }
         printf("Case #%d: %d\n", testcase, dist[b]);
     }
 
     return 0;
 }
