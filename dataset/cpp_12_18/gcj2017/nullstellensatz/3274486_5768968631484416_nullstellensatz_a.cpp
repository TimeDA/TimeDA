
 
 
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
 
 const int MaxN = 1005;
 const double pi = acos(-1.0);
 
 int T, n, m;
 double r[MaxN], h[MaxN];
 
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
         scanf("%d %d", &n, &m);
         for (int k = 0; k < n; ++ k)
             scanf("%lf %lf", r + k, h + k);
         for (int i = 0; i < n; ++ i)
             for (int j = i + 1; j < n; ++ j)
                 if (r[i] * h[i] < r[j] * h[j]) {
                     swap(r[i], r[j]);
                     swap(h[i], h[j]);
                 }
         
         double ans = 0;
         for (int i = 0; i < n; ++ i) {
             double cnt = r[i] * r[i] + r[i] * h[i] * 2.0;
             int t = 1;
             for (int j = 0; j < n; ++ j) {
                 if (i == j || t == m) continue;
                 if (r[i] >= r[j]) {
                     ++ t;
                     cnt += r[j] * h[j] * 2.0;
                 }
             }
             if (t == m) ans = max(ans, cnt);
         }
         printf("Case #%d: %.8f\n", testcase, ans * pi);
     }
     
     return 0;
 }
