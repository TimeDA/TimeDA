
 
 
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
 
 int T, n;
 char c[MaxN];
 
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
         scanf("%d %s", &n, c);
         int cnt = 0, ans = 0;
         for (int k = 0; k <= n; ++ k) {
             ans = max(ans, k - cnt);
             cnt += c[k] - '0';
         }
         printf("Case #%d: %d\n", testcase, ans);
     }
     
     return 0;
 }
