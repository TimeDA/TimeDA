
 
 
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
 
 int T, D;
 int p[MaxN];
 
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
         scanf("%d", &D);
         for (int k = 0; k < D; ++ k)
             scanf("%d", p + k);
 
         int ans = MaxN;
         for (int i = 1; i < ans; ++ i) {
             int cnt = 0;
             for (int j = 0; j < D; ++ j)
                 cnt += (p[j] - 1) / i;
             ans = min(ans, cnt + i);
         }
         printf("Case #%d: %d\n", testcase, ans);
     }
     
     return 0;
 }
