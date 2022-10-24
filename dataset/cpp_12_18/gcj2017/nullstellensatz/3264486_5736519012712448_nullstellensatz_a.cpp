
 
 
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
 
 int T, c;
 string str;
 
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
         cin >> str >> c;
         int ans = 0;
         for (int k = 0; k < str.length(); ++ k)
             if (str[k] == '-') {
                 if (k + c <= str.length()) {
                     ++ ans;
                     for (int t = k; t < k + c; ++ t)
                         if (str[t] == '+') str[t] = '-'; else str[t] = '+';
                 } else ans = -1;
             }
         printf("Case #%d: ", testcase);
         if (ans >= 0) printf("%d\n", ans); else puts("IMPOSSIBLE");
     }
        
     return 0;
 }
