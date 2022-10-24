
 
 
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
 
 const int MaxN = 10000 + 50;
 
 int T, n, m;
 int size[MaxN];
 
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
         scanf("%d %d", &n, &m);
         for (int k = 0; k < n; ++ k)
             scanf("%d", size + k);
         sort(size, size + n);
         
         int ans = n, l = 0, r = n - 1;
         while (l < r) {
             if (size[l] + size[r] <= m) {
                 ++ l; -- ans;
             }
             -- r;
         }
         printf("Case #%d: %d\n", testcase, ans);
     }
 
     return 0;
 }
