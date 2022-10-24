
 
 
 /*
     Prob:   Google code jam Round 2 2013 A
     Author: peanut
     Time:   01/06/13 22:21
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
 
 const int MaxN = 1005;
 const int mod = 1000002013;
 
 long long n, m, T;
 long long o[MaxN], e[MaxN], pos[MaxN + MaxN], p[MaxN], sum[MaxN];
 
 long long calc(long long d) {
     return ((n + n - d + 1) * d / 2) % mod;
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
         for (int k = 0; k < m; ++ k) {
             scanf("%d %d %d", o + k, e + k, p + k);
             pos[k << 1] = o[k];
             pos[(k << 1) ^ 1] = e[k];
         }
         sort(pos, pos + m + m);
         int size = unique(pos, pos + m + m) - pos;
         
         memset(sum, 0, sizeof sum);
         long long ans = 0;
         for (int k = 0; k < m; ++ k) {
             int s = lower_bound(pos, pos + size, o[k]) - pos,
                 t = lower_bound(pos, pos + size, e[k]) - pos;
             for (int r = s; r < t; ++ r)
                 sum[r] += p[k];
             ans += calc(e[k] - o[k]) * p[k] % mod;
         }
         while (true) {
             int s = 0;
             while (s < size && !sum[s]) ++ s;
             if (s >= size) break;
             int t = s + 1;
             long long min_p = sum[s];
             while (t < size && sum[t]) min_p = min(min_p, sum[t ++]);
             ans -= calc(pos[t] - pos[s]) * (min_p % mod) % mod;
             if (ans < 0) ans += mod;
             for (int r = s; r < t; ++ r)
                 sum[r] -= min_p;
         }
         printf("Case #%d: %d\n", testcase, ans % mod);
     }
     
     return 0;
 }
