
 
 
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
 
 int T, n, D;
 long long v[MaxN], s[MaxN];
 
 double calc(int idx) {
     double dist = (D - s[idx]) * 1.0;
     return D * 1.0 / (dist / v[idx]);
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
     
     cin >> T;
     for (int testcase = 1; testcase <= T; ++ testcase) {
         cin >> D >> n;
         for (int k = 0; k < n; ++ k)
             cin >> s[k] >> v[k];
         
         double ans = calc(0);
         for (int k = 1; k < n; ++ k)
             ans = min(ans, calc(k));
         printf("Case #%d: %.8f\n", testcase, ans);
     }
     
     return 0;
 }
