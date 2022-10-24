
 
 
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
 int num[MaxN];
 
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
         int ans0 = 0, ans1 = 0, diff = 0;
         for (int k = 0; k < n; ++ k) {
             scanf("%d", num + k);
             if (k > 0) {
                 ans0 += max(num[k - 1] - num[k], 0);
                 diff = max(diff, (num[k - 1] - num[k]));
             }
         }
         for (int k = 1; k < n; ++ k)
             ans1 += min(diff, num[k - 1]);
         printf("Case #%d: %d %d\n", testcase, ans0, ans1);
     }
     
     return 0;
 }
